/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:54:44 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 14:08:06 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

int				ft_logic_neg(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		right;

	(void)left_cmd; // verif sur gauche vide ?
	if (ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = (right) ? 0 : 1;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_logic_and(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS)
	{
		if ((left))
		{
			if (ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
			{
				*res = (right);
				return (CONV_SUCCESS);
			}
			return (CONV_FAIL);
		}
		*res = 0;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_logic_or(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS)
	{
		if (!(left))
		{
			if (ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
			{
				*res = (right);
				return (CONV_SUCCESS);
			}
			return (CONV_FAIL);
		}
		*res = 1;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}
