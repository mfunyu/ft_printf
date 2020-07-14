/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 15:58:54 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;

	t_str = ft_itoa2(va_arg(*ap, int));
	// printf("tstr: %s\n\n", t_str);
	if (!flag->precision && t_str[0] == '0')
	{
		t_str = ft_strdup("");
	}
	if (flag->precision > 0)
	{
		flag->zero_padding = 0;
		if (*t_str == '-')
			flag->precision++;
	}
	// printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n", flag->min_width);
	// printf("prec : %d\n", flag->precision);
	// printf("tstr: %s\n\n", t_str);
	ft_putstr2(t_str, ft_strlen(t_str), flag, cnt);
}

void		set_u(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;

	t_uint = va_arg(*ap, unsigned int);
	t_str = ft_uitoa(t_uint);
	ft_putstr2(t_str, ft_strlen(t_str), flag, cnt);
}

void		set_hex(va_list *ap, t_flag *flag, int *cnt)
{
	unsigned int t_uint;
	char			*t_str;

	t_uint = va_arg(*ap, unsigned int);
	t_str = itohex(t_uint, (flag->format == 'X' ? 1 : 0));
	ft_putstr(t_str, (flag->format == 'p' ? ft_strlen(t_str) + 2 : ft_strlen(t_str)),\
	flag, (flag->format == 'p' ? 1 : 0) , cnt);
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

	flag->precision = -1; //初期化更新
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
	// printf("prec0 : %d\n\n", flag->precision);
	// {
	// 	// format++;
	// 	// tmp = (ft_isdigit(*(format)) ? ft_atoi(format) : va_arg(*ap, int));
	// 	// flag->precision = (tmp >= 0 ? tmp : -1);
	// 	// *str += (ft_isdigit(*(format)) ? get_digits(flag->precision, 10) - 1 : 0);
	// 	// flag->zero_padding = 0;
	// 	// flag->justified = 1;
	// }
		// printf("s: %s\n", *format);
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
	// printf("min0 : %d\n\n", flag->min_width);
	// flag->min_width = va_arg(*ap, int);
	// tmp = (ft_isdigit(*format) ? ft_atoi(format) : va_arg(*ap, int));
	// // // printf("tmp : %d\n", tmp);
	// if (tmp < 0)
	// {
	// 	flag->left_justified = 1;
	// }
	// flag->min_width = (tmp > 0 ? tmp : tmp * -1);
	// 	// // printf("%d\n", flag->min_width);
	// *str += (ft_isdigit(*format) ? get_digits(flag->min_width, 10) - 1 : 0 );
	// printf("s: %s\n", *str);
}
