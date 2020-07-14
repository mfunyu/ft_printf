/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 23:19:41 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_s(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;
	int		need_free;

	need_free = 0;
	t_str = va_arg(*ap, char *);
	t_str = (!t_str ? "(null)" : t_str);
	if (0 <= flag->precision && flag->precision < (int)ft_strlen(t_str))
	{
		need_free = 1;
		if (!(t_str = ft_substr(t_str, 0, flag->precision)))
			return (-1);
	}
	ft_putstr(t_str, ft_strlen(t_str), flag, cnt);
	if (need_free)
		free(t_str);
	return (0);
}

int		set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;
	char			*tmp;

	if (!(t_str = ft_itoa2(va_arg(*ap, int))))
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		if (!(t_str = ft_strdup("")))
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
		if (*t_str == '-')
			flag->precision++;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, 0, cnt);
	free(t_str);
	return (0);
}

int		set_u(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;
	char			*tmp;

	t_uint = va_arg(*ap, unsigned int);
	if (!(t_str = ft_uitoa(t_uint)))
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		if (!(t_str = ft_strdup("")))
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	ft_putnumstr(t_str, ft_strlen(t_str), flag, 0, cnt);
	free(t_str);
	return (0);
}

int		set_p(va_list *ap, t_flag *flag, int *cnt)
{
	void			*t_void;
	char			*t_str;
	char 			*tmp;

	t_void = va_arg(*ap, void *);
	// printf("%d", t_void);
		// printf("%zu\n", (size_t)t_void);
		// printf("c : %c\n", (char)t_void);
	if (!(t_str = itohex((size_t)t_void, (flag->format == 'X' ? 1 : 0))))
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		if (!(t_str = ft_strdup("")))
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	// printf("tstr: %s\n", t_str);
	ft_putnumstr2(t_str, (flag->format == 'p' ? ft_strlen(t_str) + 2 : ft_strlen(t_str)),\
									flag, (flag->format == 'p' ? 1 : 0) , cnt);
	// ft_putnumstr2(t_str, ft_strlen(t_str),
									// flag, (flag->format == 'p' ? 1 : 0) , cnt);
	free(t_str);
	return (0);
}

int		set_hex(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;
	char 			*tmp;

	t_uint = va_arg(*ap, unsigned int);
	if (!(t_str = itohex(t_uint, (flag->format == 'X' ? 1 : 0))))
		return (-1);
	if (!flag->precision && t_str[0] == '0')
	{
		tmp = t_str;
		if (!(t_str = ft_strdup("")))
			return (-1);
		free(tmp);
	}
	if (flag->precision >= 0)
	{
		flag->zero_padding = 0;
	}
	ft_putnumstr2(t_str, (flag->format == 'p' ? ft_strlen(t_str) + 2 : ft_strlen(t_str)),\
									flag, (flag->format == 'p' ? 1 : 0) , cnt);
	// ft_putnumstr2(t_str, ft_strlen(t_str),
									// flag, (flag->format == 'p' ? 1 : 0) , cnt);
	free(t_str);
	return (0);
}

/*
** [width]
**
** Minimum number of characters to be printed.
** If the value to be printed is shorter than this number, the result is padded with blank spaces.
** The value is not truncated even if the result is larger.
**
** The width is not specified in the format string,
** but as an additional integer value argument preceding the argument that has to be formatted.
*/

void		set_min_width(const char **str, va_list *ap, t_flag *flag)
{
	int		tmp;
	const char	*format;

	format = *str;
	if (ft_isdigit(*format))
	{
		flag->min_width = ft_atoi(format);
		*str += get_digits(flag->min_width, 10) - 1;
	}
	else if (*format == '*')
	{
		tmp = va_arg(*ap, int);
		flag->left_justified = (tmp < 0 ? 1 : flag->left_justified);
		flag->min_width = (tmp < 0 ? tmp * -1 : tmp);
	}
}

/*
** For integer specifiers (d, i, o, u, x, X): precision specifies the minimum number of digits to be written.
** If the value to be written is shorter than this number, the result is padded with leading zeros.
** The value is not truncated even if the result is longer. A precision of 0 means that no character is written for the value 0.
** For s: this is the maximum number of characters to be printed.
** By default all characters are printed until the ending null character is encountered.
** If the period is specified without an explicit value for precision, 0 is assumed.
*/

void		set_precision(const char **format, va_list *ap, t_flag *flag)
{
	int		tmp;

	flag->precision = 0;
	// if (*(*format + 1) == '-')
	// 	flag->precision = 0; //初期化更新
	if (*(*format + 1) == '*')
	{
		(*format)++;
		tmp = va_arg(*ap, int);
		flag->precision = (tmp >= 0 ? tmp : -1);
	}
	else
	{
		while (*(*format + 1) == '0')
		{
			(*format)++;
			flag->precision = 0;
		}
		if (ft_isdigit(*(*format + 1)))
		{
			(*format)++;
			// printf("0s: %s\n", *format);
			flag->precision = ft_atoi(*format);
				// printf("prec : %d\n", flag->precision);
			*format += get_digits(flag->precision, 10) - 1;
		}
	}
}
