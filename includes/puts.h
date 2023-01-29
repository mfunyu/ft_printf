/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:00:02 by mfunyu            #+#    #+#             */
/*   Updated: 2023/01/29 13:00:03 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTS_H
# define PUTS_H

int		ft_putnumstr(char *t_str, int len, t_flag *flag, int *cnt);
int		ft_puthexstr(char *t_str, int len, t_flag *flag, int *cnt);
void	put_c(va_list *ap, t_flag *flag, int *cnt);
void	put_s(va_list *ap, t_flag *flag, int *cnt);

#endif /* PUTS_H */
