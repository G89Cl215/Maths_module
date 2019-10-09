/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unary_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:24:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 18:15:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

void	ft_separation_en_unary_op(t_list **list)
{
	t_list		*sep;
	t_list		*relink;

	sep = NULL;
	relink = (*list)->next;
	

}

void	ft_unary_op(t_list *list)
{
	t_list		*tmp;
	t_list		*voyager;

	if (!(voyager = list)
	||!(tmp = voyager->next))
		return ;
	if (((t_list)voyager->content)->prio == INCR_PRIO && (tmp->content->prio))
		ft_separation_en_unary_op();
	while (voyager)
	{
		tmp = voyager;
		voyager = voyager->next;
		if (voyager->content->prio == INCR_PRIO && (tmp->content->prio))
		{
			if (!(tmp = voyager->next))
				return ; // error missing operand
			if ((tmp->content->prio))
				ft_separation_en_unary_op();
		}
	}
}
