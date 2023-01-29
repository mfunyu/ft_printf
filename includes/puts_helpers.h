/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:59:58 by mfunyu            #+#    #+#             */
/*   Updated: 2023/01/29 13:00:00 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTS_HELPERS_H
# define PUTS_HELPERS_H

void	ft_putchar_cnt(char c, int *cnt);
void	ft_putstr_cnt_limit(char *s, int len, int *cnt);
void	ft_putstr_cnt(char *s, int *cnt);
void	ft_putpadding(char c, int n, int *cnt);
int		max(int a, int b);

#endif /* PUTS_HELPERS_H */
