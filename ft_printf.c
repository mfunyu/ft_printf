/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 23:14:39 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//cspdiuxX%

t_flag	*init_struct()
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));

	flag->format = 0;
	flag->left_justified = 0;
	flag->justified = 0;
	flag->right_justified = 0;
	flag->zero_padding = 0;
	flag->precision = -1;
	flag->digits = 0;

	return (flag);
}

int		parse_format_str(const char *format, va_list *ap, t_flag *flag, int *cnt)
{
	flag->format = *format;
	if (*format == 'c')
		write_c(ap, flag, cnt);
	else if (*format == 's')
		write_s(ap, flag, cnt);
	else if (*format == 'd' || *format == 'i')
		set_di(ap, flag, cnt);
	else if (*format == 'u')
		set_u(ap, flag, cnt);
	else if ((*format == 'p' || *format == 'x' || *format == 'X'))
		set_hex(ap, flag, cnt);
	else if (*format == '%')
		ft_putchar_cnt('%', cnt);
	return (0);
}

/* flags to be managed : "-0.*" */

const char	*parse_flags(const char *format, va_list *ap, t_flag *flag)
{
	while (ft_strchr("-0.*", *format) || ft_isdigit(*format))
	{
		if (*format == '-' || *format == '0')
		{
			flag->justified = 1;
			(*format == '-') ? (flag->left_justified = 1) : (flag->zero_padding = 1);
		}
		else if (*format == '.')
		{
			if (ft_isdigit(*(format + 1)) || *(format + 1) == '*')
			{
				format++;
				int tmp;
				tmp = (ft_isdigit(*(format)) ? ft_atoi(format) : va_arg(*ap, int));
				flag->precision = (tmp > 0 ? tmp : 0);
				format += ft_strlen(ft_itoa(flag->precision)) - 1;
				// flag->zero_padding = 0;
				// flag->justified = 1;
			}
			else if (*(format + 1) == '*')
			{
				int tmp;
				format++;
				tmp = va_arg(*ap, int);
				if (tmp > 0)
				{
					flag->precision = tmp;
					format += ft_strlen(ft_itoa(flag->precision)) - 1;
					// flag->zero_padding = 0;
				}
			}
		}
		else if (*format == '*')
		{
			flag->digits = va_arg(*ap, int);
			if (flag->digits < 0)
			{
				flag->digits *= -1;
				flag->left_justified = 1;
			}
			flag->justified = 1;
		}
		else if (ft_isdigit(*format))
		{
			flag->justified = 1;
			flag->digits = ft_atoi(format);
			format += ft_strlen(ft_itoa(flag->digits)) - 1;
		}
		format++;
	}
	if (flag->left_justified)
	{
		flag->zero_padding = 0;
	}
	return (format);
}

int		ft_printf(const char *str, ...)
{
	va_list		ap;
	t_flag		*flag;
	int			cnt;

	cnt = 0;
	va_start(ap, str);
	flag = init_struct();
	while (*str)
	{
		if (*str == '%')
		{
			str = parse_flags(str + 1, &ap, flag);
			parse_format_str(str, &ap, flag, &cnt);
			str++;
		}
		else
		{
			ft_putchar_cnt(*(str++), &cnt);
		}
	}
	va_end(ap);
	return (cnt);
}
