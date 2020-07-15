/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:59:01 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/15 10:14:47 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void		set_min_width(const char **format, va_list *ap, t_flag *flag)
{
	int			width;

	if (ft_isdigit(**format))
	{
		flag->min_width = ft_atoi(*format);
		*format += get_digits(flag->min_width, 10) - 1;
	}
	else if (**format == '*')
	{
		width = va_arg(*ap, int);
		if (width < 0)
		{
			flag->left_justified = 1;
			width *= -1;
		}
		flag->min_width = width;
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
	int		prec;

	flag->precision = 0;
	if (*(*format + 1) == '*')
	{
		(*format)++;
		prec = va_arg(*ap, int);
		flag->precision = (prec >= 0 ? prec : -1);
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
			flag->precision = ft_atoi(*format);
			*format += get_digits(flag->precision, 10) - 1;
		}
	}
}
