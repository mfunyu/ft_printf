/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_converters.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:59:32 by mfunyu            #+#    #+#             */
/*   Updated: 2023/01/29 12:59:33 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NUM_CONVERTERS_H
# define NUM_CONVERTERS_H

unsigned int	get_digits(long long nb, unsigned int base);
void			ft_utohex(char *strhex, size_t nb, int upper);
void			ft_uitoa(char *nb, unsigned int n);
void			ft_itoa_stack(char *nb, int n);

#endif /* NUM_CONVERTERS_H */
