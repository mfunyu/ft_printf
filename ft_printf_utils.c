/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/15 10:47:53 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char			*ft_utohex(size_t nb, int upper)
{
	size_t		digits;
	char		*strhex;
	char		*hex;

	hex = "0123456789abcdef";
	digits = get_udigits(nb, 16);
	if (!(strhex = (char *)malloc((digits + 1) * sizeof(char))))
		return (NULL);
	strhex[digits] = '\0';
	if (nb == 0)
		strhex[0] = '0';
	while (nb > 0)
	{
		digits--;
		strhex[digits] = (upper ? ft_toupper(hex[nb % 16]) : hex[nb % 16]);
		nb /= 16;
	}
	return (strhex);
}

char			*ft_uitoa(unsigned int n)
{
	char			*nb;
	unsigned int	len;

	len = get_digits(n, 10);
	if (!(nb = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	nb[len--] = '\0';
	while (n > 9)
	{
		nb[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	nb[len] = n + '0';
	return (nb);
}

int				max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
