/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multiplication.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 12:47:32 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 14:35:01 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

int				ft_mul(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = left * right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_exp(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		if (left == 0 || right < 0)
			*res = 0;
		else if (right == 0)
			*res = 1;
		else
			*res = ft_pow(left, right);
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}
int				ft_div(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		if (right != 0)
		{
			*res = left / right;
			return (CONV_SUCCESS);
		}
		//print_error("div by zero");
	}
	return (CONV_FAIL);
}

int				ft_mod(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		if (right != 0)
		{
			*res = left / right;
			return (CONV_SUCCESS);
		}
		//print_error("div by zero");
	}
	return (CONV_FAIL);
}