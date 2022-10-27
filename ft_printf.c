/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2022/10/27 17:29:43 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_struct(t_flag *flag)
{
	flag->format = 0;
	flag->left_justified = 0;
	flag->zero_padding = 0;
	flag->min_width = 0;
	flag->precision = -1;
}

/*
** format strings to be managed : cspdiuxX%
**
** c		Character	a
** s		String of characters	sample
** p		Pointer address	b8000000
** d or i	Signed decimal integer	392
** u		Unsigned decimal integer	7235
** x		Unsigned hexadecimal integer	7fa
** X		Unsigned hexadecimal integer (uppercase)	7FA
** % A % followed by another % character will write a single % to the stream.
*/

static int	parse_format_str(const char *format, va_list *ap, \
										t_flag *flag, int *cnt)
{
	int		error;

	error = 0;
	flag->format = *format;
	if (*format == 'c')
		put_c(ap, flag, cnt);
	else if (*format == 's')
		error = set_s(ap, flag, cnt);
	else if (*format == 'd' || *format == 'i')
		error = set_di(ap, flag, cnt);
	else if (*format == 'u')
		error = set_u(ap, flag, cnt);
	else if (*format == 'p' || *format == 'x' || *format == 'X')
		error = set_hex(ap, flag, cnt);
	else if (*format == '%')
		ft_putstr("%", 1, flag, cnt);
	else
		return (-1);
	return (error);
}

/*
** flags to be managed : "-0.*"
** 1. parsing flag, width, and precision
** 2. parsing format strings : cspdiuxX%
**
** - : Left-justify within the given field width;
** Right justification is the default (see width sub-specifier).
** 0 : Left-pads the number with zeroes (0)
** instead of spaces when padding is specified.
*/

static int	parse_format_specifiers(const char **format, \
						va_list *ap, t_flag *flag, int *cnt)
{
	while (*format && (ft_strchr("-0.*", **format) || ft_isdigit(**format)))
	{
		if (**format == '-')
		{
			flag->left_justified = 1;
		}
		else if (**format == '0')
		{
			flag->zero_padding = 1;
		}
		else if (ft_isdigit(**format) || **format == '*')
		{
			set_min_width(format, ap, flag);
		}
		else if (**format == '.')
		{
			set_precision(format, ap, flag);
		}
		(*format)++;
	}
	if (flag->left_justified)
		flag->zero_padding = 0;
	if (!format || parse_format_str((*format)++, ap, flag, cnt))
		return (-1);
	return (0);
}

/*
** [printf return value]
**
** On success, the "total number of characters written (cnt)" is returned.
** If a writing error occurs, "a negative number (-1)" is returned.
**
** [printf format]
**
** A format specifier follows this prototype: [see compatibility note below]
** %[flags][width][.precision][length]specifier
*/

int	ft_printf(const char *str, ...)
{
	va_list		ap;
	t_flag		*flag;
	int			cnt;

	cnt = 0;
	flag = (t_flag *)malloc(sizeof(t_flag));
	if (!flag)
		return (-1);
	va_start(ap, str);
	while (*str)
	{
		init_struct(flag);
		if (*str == '%')
		{
			str++;
			if (parse_format_specifiers(&str, &ap, flag, &cnt))
				return (-1);
		}
		else
			ft_putchar_cnt(*str++, &cnt);
	}
	free(flag);
	va_end(ap);
	return (cnt);
}
