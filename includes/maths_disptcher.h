/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_disptcher.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:08:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/02 13:13:15 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_DISPATCHER
# define MATHS_DISPATCHER

typedef struct		s_maths
{
	char			*op;
	int				*ft_op(long, long);
}					t_maths;

#endif
