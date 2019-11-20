/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:34:42 by tgouedar          #+#    #+#             */
/*   Updated: 2019/11/20 13:56:55 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/maths_module.h"
#include "includes/maths_def.h"
#include <stdio.h>


void	ft_print_ast(t_maths_ast *ast)
{
	static int		i = 0;

	if ((ast))
	{
		ft_print_ast(ast->left_cmd);
		ft_putstr("node nbr: ");
		ft_putnbr(i);
		ft_putstr("		value: ");
		if (ast->tokens != NULL)
		{
			if (((t_maths_token*)(ast->tokens->content))->token != NULL)
				ft_putendl(((t_maths_token*)(ast->tokens->content))->token);
		}
		else
			ft_putendl("vide");
		i++;
		ft_print_ast(ast->right_cmd);
	}
}


int		main(int ac, char **av)
{
	char	*res;

	if (ac > 1)
	{
		if (ft_maths_expansion(av[1], &res) == MATHS_SUCCESS)
			printf("RES = %s\n", res);
		else
			printf("ERROR\n");
	}
	return (0);
}
