/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:48:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 15:18:12 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"

char		*ft_maths_expansion(char *expr)
{
	int				par;
	int64_t			res;

	if ((par = ft_parentheses_nbr(expr)) < 0)
	{
//		print_errror(PARENTHES_NBR || BRACKET_NBR);
		return (NULL);
	}
	while (par > 0)
	{
		expr = ft_eval_inner_parentheses(expr);
		par--;
	}
	if (ft_eval(expr, &res) == CONV_FAIL)
		return (NULL);
	return (ft_itoa64(res));
}
