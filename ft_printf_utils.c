/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/15 09:54:47 by mfunyu           ###   ########.fr       */
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

char		*ft_utohex(size_t nb, int X)
{
	size_t		digits;
	char		*strhex;
	char		*hex;

	hex = "0123456789abcdef";
	digits = get_udigits(nb, 16);
	strhex = (char *)malloc((digits + 1) * sizeof(char));
	strhex[digits] = '\0';
	if (nb == 0)
		strhex[0] = '0';
	while (nb > 0)
	{
		digits--;
		strhex[digits] = (X ? ft_toupper(hex[nb % 16]) : hex[nb % 16]);
		nb /= 16;
	}
	return (strhex);
}

static void		set_nb(char *nb, unsigned int n, unsigned int len)
{
	nb[len--] = '\0';
	while (n > 9)
	{
		nb[len] = n % 10 + '0';
		n /= 10;
		len--;
	}
	nb[len] = n + '0';
}

char		*ft_uitoa(unsigned int n)
{
	char			*nb;
	unsigned int	len;

	len = get_digits(n, 10);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	set_nb(nb, n, len);
	return (nb);
}
