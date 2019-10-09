/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:34:42 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 21:42:59 by tgouedar         ###   ########.fr       */
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
		ft_putstr("node nbr: ");
		ft_putnbr(i);
		ft_putstr("		value: ");
		if ((ast->tokens))
			ft_putendl(((t_maths_token*)ast->tokens->content)->token);
		else
			ft_putendl("operateur");
		i++;
		ft_print_ast(ast->left_cmd);
		ft_print_ast(ast->right_cmd);
	}
}


int		main(int ac, char **av)
{
	if (ac > 1)
		printf("%s = %s\n", av[1], ft_maths_expansion(av[1]));
	return (0);
}
