/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 17:57:05 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

//cspdiuxX%

t_flag	*init_struct()
{
	t_flag	*flag;

	flag = (t_flag *)malloc(sizeof(t_flag));

	flag->left_justified = 0;
	flag->justified = 0;
	flag->right_justified = 0;
	flag->zero_padding = 0;
	flag->precision = 0;
	flag->digits = 0;

	return (flag);
}

int		parse_format_str(const char *format, va_list *ap, t_flag *flag, int *cnt)
{
	int		i;
	// int		type;
	int		t_int;
	char	*t_str;
	unsigned long long	t_uint;

	i = 0;

	if (format[i] == 'c')
	{
		t_int = va_arg(*ap, int);
		ft_putchr(t_int, flag, cnt);
	}
	if (format[i] == 's')
	{
		t_str = va_arg(*ap, char *);
		flag->precision = 0;
		if (!t_str)
			t_str = "(null)";
		ft_putstr(t_str, ft_strlen(t_str), flag, 0, cnt);
	}
	if (format[i] == 'p')
	{
		t_uint = va_arg(*ap, unsigned int);
		t_str = itohex(t_uint, 0);
		ft_putstr(t_str, ft_strlen(t_str) + 2, flag, 1, cnt);
	}
	if (format[i] == 'd' || format[i] == 'i')
	{
		int		len;

		t_str = ft_itoa(va_arg(*ap, int));
		len = (flag->precision > (int)ft_strlen(t_str) ? flag->precision : ft_strlen(t_str));
		ft_putstr(t_str, len, flag, 0, cnt);
	}
	if (format[i] == 'u')
	{
		unsigned long long	t_uintry;
		// t_str = va_arg(*ap, char *);
		t_uintry = va_arg(*ap, unsigned long long);
		// printf("%s", t_str);
		printf("%lld\n", t_uintry);
		if (t_uintry < 0)
			t_uintry *= -1;
		// printf("%d\n", t_uint);
		t_str = ft_itoa(t_uintry);
		// printf("s: %s\n", t_str);
		// ft_putnbr_fd(t_uint, 1);
		ft_putstr(t_str, ft_strlen(t_str), flag, 0, cnt);
		//cntまだ
	}
	if (format[i] == 'x')
	{
		t_uint = va_arg(*ap, unsigned int);
		t_str = itohex(t_uint, 0);
		ft_putstr(t_str, ft_strlen(t_str), flag, 0, cnt);
	}
	if (format[i] == 'X')
	{
		t_uint = va_arg(*ap, unsigned int);
		t_str = itohex(t_uint, 1);
		ft_putstr(t_str, ft_strlen(t_str), flag, 0, cnt);
	}
	if (format[i] == '%')
	{
		ft_putchar_fd(format[i], 1);
		(*cnt)++;
	}
	return (0);
}

/* flags to be managed : "-0.*" */

const char	*parse_flags(const char *format, va_list *ap, t_flag *flag)
{
	int		i;

	i = 0;
	while (ft_strchr("-0.*", format[i]) || ft_isdigit(format[i]))
	{
		if (format[i] == '-')
		{
			flag->left_justified = 1;
			flag->justified = 1;
		}
		else if (format[i] == '0')
		{
			flag->justified = 1;
			flag->zero_padding = 1;
		}
		else if (format[i] == '.')
		{
			if (ft_isdigit(format[i + 1]))
			{
				i++;
				flag->precision = ft_atoi(format + i);
				i += ft_strlen(ft_itoa(flag->precision)) - 1;
				flag->zero_padding = 0;
				// flag->justified = 1;
			}
		}
		else if (format[i] == '*')
		{
			flag->digits = va_arg(*ap, int);
			if (flag->digits < 0)
			{
				flag->digits *= -1;
				flag->left_justified = 1;
			}
			flag->justified = 1;
		}
		else if (ft_isdigit(format[i]))
		{
			flag->justified = 1;
			flag->digits = ft_atoi(format + i);
			i += ft_strlen(ft_itoa(flag->digits)) - 1;
		}
		i++;
	}
	if (flag->left_justified)
	{
		flag->zero_padding = 0;
	}
	return (format + i);
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
			ft_putchar_fd(*str, 1);
			str++;
			cnt++;
		}
	}
	va_end(ap);
	return (cnt);
}
