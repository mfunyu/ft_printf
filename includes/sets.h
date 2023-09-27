/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 13:00:06 by mfunyu            #+#    #+#             */
/*   Updated: 2023/09/27 14:55:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SETS_H
# define SETS_H

int		set_di(va_list *ap, t_flag *flag, int *cnt);
int		set_u(va_list *ap, t_flag *flag, int *cnt);
int		set_zu(va_list *ap, t_flag *flag, int *cnt);
int		set_p(va_list *ap, t_flag *flag, int *cnt);
int		set_hex(va_list *ap, t_flag *flag, int *cnt);
void	set_precision(const char **str, va_list *ap, t_flag *flag);
void	set_min_width(const char **str, va_list *ap, t_flag *flag);

#endif /* SETS_H */
