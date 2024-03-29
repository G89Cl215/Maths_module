/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unary_op.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 19:24:31 by tgouedar          #+#    #+#             */
/*   Updated: 2019/11/20 15:06:37 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"
#include "libft_add.h"

int				ft_is_varname(char *token)
{
	if (ft_isdigit(*token))
		return (0); //non variable (r_value)
	if (ft_isnumber_base(token, BASE)) // pourquoi ?
		return (1);
	return (0); //variable non alpha num
}


static int		ft_parse_assign(t_maths_list *list)
{
	t_maths_list	*tmp;
	int				i;

	i = 0;
	while (list)
	{
		tmp = list;
		if (list || ++i)
			list = list->next;
		if (list && list->content->prio == ASSIGN_PRIO)
		{
			if (!i)
				return (CONV_FAIL); //assignation sans membre de gauche
			if (i > 1 || !ft_is_varname(tmp->content->token))
				return (CONV_FAIL); //assignation a une expression et non une variable
			while (list && list->content->prio < ASSIGN_PRIO)
				list = list->next;
			if (list && list->content->prio == ASSIGN_PRIO)
				return (CONV_FAIL); // assignations imbriquees;
			i = 0;
		}
	}
	return (CONV_SUCCESS);
}


int				ft_maths_parser(t_maths_list *list)
{
	if (!list)
		return (CONV_SUCCESS);
	if (ft_parse_assign(list) == CONV_FAIL)
		return (CONV_FAIL);
//	if (ft_parse_incr(list) == CONV_FAIL)
//		return (CONV_FAIL);
//	ft_interpret_incr(list);
	return (CONV_SUCCESS);
}
