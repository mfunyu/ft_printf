/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/14 08:30:50 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_digits(unsigned int nb, unsigned int base)
{
	unsigned int		cnt;

	cnt = 1;
	if (nb < 0)
	{
		nb *= -1;
		cnt++;
	}
	while (nb >= base)
	{
		nb /= base;
		cnt++;
	}
	return (cnt);
}

char		*itohex(unsigned int nb, int X)
{
	char			*strhex;
	char			*hex;
	unsigned int	digits;

	hex = "0123456789abcdef";
	digits = get_digits(nb, 16);
	// printf("digits: %d", digits);
	strhex = (char *)malloc((digits + 1) * sizeof(char));
	strhex[digits] = '\0';
	if (nb == 0)
		strhex[0] = '0';
	while (nb > 0)
	{
		// printf("%d, %d\n", digits, ans);
		digits--;
		strhex[digits] = (X ? ft_toupper(hex[nb % 16]) : hex[nb % 16]);
		// printf("%c\n", strhex[digits]);
		nb /= 16;
		// printf("\nstr:%s\n", strhex);
	}
	return (strhex);
}

static void		set_nb(char *nb, unsigned int n, unsigned int len)
{
	nb[len--] = '\0';
	if (n == 0)
		nb[len] = '0';
	while (n > 0)
	{
		nb[len--] = n % 10 + '0';
		n /= 10;
	}
}

char		*ft_uitoa(unsigned int n)
{
	char			*nb;
	unsigned int	len;

	len = get_digits(n, 10);
	// printf("len: %d\n", len);
	nb = (char *)malloc((len + 1) * sizeof(char));
	if (!nb)
		return (NULL);
	// if (n == U_INT_MIN)
	// 	ft_strlcpy(nb, "-2147483648", 12);
	// else
	// {
		if (n < 0)
		{
			n *= -1;
			*nb = '-';
		}
		set_nb(nb, n, len);
	// }
	return (nb);
}


