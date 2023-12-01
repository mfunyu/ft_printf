/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_converters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2023/12/01 13:42:38 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <limits.h>
#include "libft.h"

static size_t	get_udigits(size_t n, size_t base)
{
	size_t		cnt;

	cnt = 1;
	while (n >= base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

unsigned int	get_digits(long long nb, unsigned int base)
{
	size_t		cnt;
	size_t		n;

	cnt = 1;
	if (nb < 0)
	{
		n = nb * -1;
		cnt++;
	}
	else
	{
		n = nb;
	}
	while (n >= base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

unsigned int	get_unsigned_digits(size_t nb, unsigned int base)
{
	size_t	cnt;
	size_t	n;

	cnt = 1;
	n = nb;
	while (n >= base)
	{
		n /= base;
		cnt++;
	}
	return (cnt);
}

void	ft_utohex(char *strhex, size_t nb, int upper)
{
	size_t		digits;
	char		*hex;

	hex = "0123456789abcdef";
	digits = get_udigits(nb, 16);
	strhex[digits] = '\0';
	if (nb == 0)
		strhex[0] = '0';
	while (nb > 0)
	{
		digits--;
		if (upper)
			strhex[digits] = ft_toupper(hex[nb % 16]);
		else
			strhex[digits] = hex[nb % 16];
		nb /= 16;
	}
}

void	ft_zuitoa(char *nb, size_t n)
{
	size_t	len;

	len = get_unsigned_digits(n, 10);
	nb[len--] = '\0';
	while (n > 9)
	{
		nb[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	nb[len] = n + '0';
}

void	ft_itoa_stack(char *nb, int n)
{
	int			digit;

	digit = get_digits(n, 10);
	if (n == INT_MIN)
	{
		ft_strlcpy(nb, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		*nb = '-';
	}
	nb[digit--] = '\0';
	while (n > 9)
	{
		nb[digit] = n % 10 + '0';
		digit--;
		n /= 10;
	}
	nb[digit] = n + '0';
}
