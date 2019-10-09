/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_expansion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:48:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 20:43:33 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"






char		*ft_maths_expansion(char *expr)
{
	int				par;
	int64_t			res;

	ft_putendl("entree d'extension");
	if ((par = ft_parentheses_nbr(expr)) < 0)
	{
//		print_errror(PARENTHES_NBR || BRACKET_NBR);
		return (NULL);
	}
	ft_putendl("fin de parenthese test");
	while (par > 0)
	{
		ft_putendl("avant eval inter_parenthes");
		expr = ft_eval_inner_parentheses(expr);
		ft_putendl("apres eval inter_parenthes");
		par--;
	}
	if (ft_eval(expr, &res) == CONV_FAIL)
		return (NULL);
	return (ft_itoa64(res));
}
