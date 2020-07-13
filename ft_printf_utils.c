/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/06 21:23:13 by mfunyu            #+#    #+#             */
/*   Updated: 2020/07/13 17:27:26 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_hexdigits(int nb)
{
	int		cnt;

	cnt = 1;
	while (nb >= 16)
	{
		nb /= 16;
		cnt++;
	}
	return (cnt);
}

char		*itohex(unsigned int nb, int X)
{
	char			*strhex;
	char			*hex;
	unsigned int	digits;
	unsigned int	ans;

	hex = "abcdef";
	digits = get_hexdigits(nb);
	// printf("digits: %d", digits);
	strhex = (char *)malloc((digits + 1) * sizeof(char));
	strhex[digits] = '\0';
	if (nb == 0)
		strhex[0] = '0';
	while (nb > 0)
	{
		digits--;
		ans = nb % 16;
		// printf("%d, %d\n", digits, ans);
		nb /= 16;
		if (ans < 10)
			strhex[digits] = ans + '0';
		else
		{
			strhex[digits] = hex[ans - 10] - X * 32;
		}
		// printf("\nstr:%s\n", strhex);
	}
	return (strhex);
}

// char		*ft_utoa(int n)
// {
// 	char		*nb;
// 	int			len;

// 	len = cnt_len(n);
// 	nb = (char *)malloc((len + 1) * sizeof(char));
// 	if (!nb)
// 		return (NULL);
// 	if (n == INT_MIN)
// 		ft_strlcpy(nb, "-2147483648", 12);
// 	else
// 	{
// 		if (n < 0)
// 		{
// 			n *= -1;
// 			*nb = '-';
// 		}
// 		set_nb(nb, n, len);
// 	}
// 	return (nb);
// }
