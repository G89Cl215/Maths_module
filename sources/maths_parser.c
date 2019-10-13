/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unary_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:24:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/13 08:03:08 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths_interne.h"

static void		ft_unary_split(t_maths_list *list)
{
	t_maths_list		*sep;
	t_maths_list		*relink;
	t_maths_token		*token;

	sep = NULL;
	relink = list->next;
	if (!ft_strcmp(list->content->token, "++"))
	{
		free(list->content->token);
		list->content->token = ft_strdup("+");
		token = ft_init_maths_token("+", 1, IS_OP);
	}
	else if (!ft_strcmp(list->content->token, "--"))
	{
		free(list->content->token);
		list->content->token = ft_strdup("-");
		token = ft_init_maths_token("-", 1, IS_OP);
	}
	else
		return ;
	list->next = (t_maths_list*)ft_lstnew(token, sizeof(t_maths_token));
	list->next->next = relink;
	list->content->prio = ADD_PRIO;
}

static int		ft_parse_incr(t_maths_list *list)
{
	t_maths_list		*tmp;
	t_maths_list		*voyager;

	voyager = list;
	if (!(tmp = voyager->next))
		return (voyager->content->prio ? CONV_FAIL : CONV_SUCCESS);
	if (voyager->content->prio == INCR_PRIO && (tmp->content->prio))
		ft_unary_split(voyager);
	while (voyager)
	{
		tmp = voyager;
		voyager = voyager->next;
		if (voyager->content->prio == INCR_PRIO && (tmp->content->prio))
		{
			if (!(tmp = voyager->next))
				return (CONV_FAIL); // error missing operand
			if ((tmp->content->prio))
				ft_unary_split(voyager);
		}
	}
	return (CONV_SUCCESS);
}

static int		ft_parse_assign(t_maths_list *list)
{
	while (list)
	{
		if (list->content->prio == INCR_PRIO)
		{
			while (list && list->content->prio < INCR_PRIO)
				list = list->next;
			if (list && list->content->prio == INCR_PRIO)
				return (CONV_FAIL);
		}
		if (list)
			list = list->next;
	}
	return (CONV_SUCCESS);
}

static void		ft_interpret_incr(t_maths_list *list)
{
	t_maths_list		*tmp;
	t_maths_list		*voyager;

	voyager = list;
	tmp = voyager->next;
	if (voyager->content->prio == INCR_PRIO && !(tmp->content->prio))
		voyager->content->prio == PREINCR_PRIO;
	while (voyager)
	{
		voyager = voyager->next;
		if (voyager->content->prio == INCR_PRIO && !(tmp->content->prio))
			voyager->content->prio == PREINCR_PRIO;
	}
}

int				ft_maths_parser(t_maths_list *list)
{
	if (!list)
		return (CONV_SUCCESS);
	if (ft_parse_assign(list) == CONV_FAIL)
		return (CONV_FAIL); // assignations imbriquees;
	if (ft_parse_incr(list) == CONV_FAIL)
		return (CONV_FAIL);
	ft_interpret_incr(list);
	return (CONV_SUCCESS);
}
