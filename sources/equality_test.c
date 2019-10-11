/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equality_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:23:29 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 13:54:07 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

int				ft_eq_test(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = (left == right);
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_diff_test(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = (left != right);
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}
