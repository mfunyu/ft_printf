/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 10:06:46 by mfunyu            #+#    #+#             */
/*   Updated: 2023/01/29 12:50:09 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putchar_cnt(char c, int *cnt)
{
	write(1, &c, 1);
	(*cnt)++;
}

void	ft_putstr_cnt_limit(char *s, int len, int *cnt)
{
	if (!s)
		return ;
	write(1, s, len);
	*cnt += len;
}

void	ft_putstr_cnt(char *s, int *cnt)
{
	ft_putstr_cnt_limit(s, ft_strlen(s), cnt);
}

void	ft_putpadding(char c, int n, int *cnt)
{
	while (n-- > 0)
		ft_putchar_cnt(c, cnt);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
