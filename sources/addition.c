/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:03:34 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 17:41:04 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

int				ft_add(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS)
			*res = left + right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}

int				ft_sub(void *left_cmd, void *right_cmd, int64_t *res)
{
	int64_t		left;
	int64_t		right;

	if (ft_eval_ast(left_cmd, &left) == CONV_SUCCESS
	&& ft_eval_ast(right_cmd, &right) == CONV_SUCCESS)
	{
		*res = left - right;
		return (CONV_SUCCESS);
	}
	return (CONV_FAIL);
}
