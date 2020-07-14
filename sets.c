/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 14:05:24 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		set_di(va_list *ap, t_flag *flag, int *cnt)
{
	char			*t_str;

	t_str = ft_itoa(va_arg(*ap, int));
	if (!flag->precision && t_str[0] == '0')
	{
		t_str = ft_strdup("");
	}
	if (flag->precision > 0)
		flag->zero_padding = 0;
	// printf("zero : %d\n", flag->zero_padding);
	// printf("left : %d\n", flag->left_justified);
	// printf("min : %d\n\n", flag->min_width);
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

void		set_precision(const char **str, va_list *ap, t_flag *flag)
{
	int		tmp;
	const char	*format;

	format = *str;
	flag->precision = -1; //初期化更新
	if (ft_isdigit(*(format + 1)) || *(format + 1) == '*')
	{
		format++;
		tmp = (ft_isdigit(*(format)) ? ft_atoi(format) : va_arg(*ap, int));
		flag->precision = (tmp >= 0 ? tmp : -1);
		format += (ft_isdigit(*(format)) ? get_digits(flag->precision, 10) - 1 : 0);
		// flag->zero_padding = 0;
		// flag->justified = 1;
	}
}

void		set_min_width(const char **str, va_list *ap, t_flag *flag)
{
	int		tmp;
	const char	*format;

	format = *str;
	// flag->min_width = va_arg(*ap, int);
	tmp = (ft_isdigit(*format) ? ft_atoi(format) : va_arg(*ap, int));
	// printf("tmp : %d\n", tmp);
	if (tmp < 0)
	{
		flag->left_justified = 1;
	}
	flag->min_width = (tmp > 0 ? tmp : tmp * -1);
		// printf("%d\n", flag->min_width);
	*str += (ft_isdigit(*format) ? get_digits(flag->min_width, 10) - 1 : 0 );
}
