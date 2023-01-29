/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 12:59:05 by mfunyu            #+#    #+#             */
/*   Updated: 2023/01/29 12:59:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLAG_H
# define FLAG_H

typedef struct s_flag
{
	char	format;
	int		left_justified;
	int		zero_padding;
	int		min_width;
	int		precision;
}			t_flag;

#endif /* FLAG_H */
