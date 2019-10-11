/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitwise.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 14:17:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 14:25:27 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

int				ft_bitwise_neg(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		right;

	(void)left_cmd;
	if (ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = ~right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_bitwise_and(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = left & right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_bitwise_or(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = left | right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_bitwise_xor(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = left ^ right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}
