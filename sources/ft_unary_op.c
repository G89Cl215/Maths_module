/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unary_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:24:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 17:06:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

void	ft_separation_en_unary_op(t_maths_list **list)
{
	t_maths_list		*sep;
	t_maths_list		*relink;

	sep = NULL;
	relink = (*list)->next;
	

}

void	ft_unary_op(t_maths_list *list)
{
	t_maths_list		*tmp;
	t_maths_list		*voyager;

	if (!(voyager = list)
	|| !(tmp = voyager->next))
		return ;
	if (((t_maths_list)voyager->content)->prio == INCR_PRIO && (tmp->content->prio))
		ft_separation_en_unary_op(&voyager);
	while (voyager)
	{
		tmp = voyager;
		voyager = voyager->next;
		if (voyager->content->prio == INCR_PRIO && (tmp->content->prio))
		{
			if (!(tmp = voyager->next))
				return ; // error missing operand
			if ((tmp->content->prio))
				ft_separation_en_unary_op(&voyager);
		}
	}
}
