/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eval.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:33:24 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 14:33:53 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths_interne.h"
#include "libft.h"

void	ft_print_ast(t_maths_ast *ast);

int		ft_eval_ast(t_maths_ast *ast, int64_t *res)
{
	if ((ast->calc_func))
		return (ast->calc_func(ast->left_cmd, ast->right_cmd, res));
	ft_putstr("\nEvaluation du token: ");
	ft_putendl(((t_maths_token*)ast->tokens->content)->token);
	return (ft_arg_value(((t_maths_token*)ast->tokens->content)->token, res));
}

char	*ft_construct_expansion(char *arg, char *expansion, size_t var_pos,
																size_t var_len)
{
	size_t		len;
	char		*res;

	len = ft_strlen(expansion);
	/*ft_memcheck(*/res = ft_strnew(len + ft_strlen(arg) - var_len);
	ft_memcpy(res, arg, var_pos);
	ft_memcpy(res + var_pos, expansion, len);
	ft_memcpy(res + len + var_pos, arg + var_len + var_pos,
											ft_strlen(arg + var_pos + var_len));
	free(expansion);
	return (res);
}

int			ft_eval(char *expr, int64_t *res)
{
//	int				sig;
	t_list			*list;
	t_maths_ast		*ast;

	*res = 0;
		ft_putendl("\navant lexer");
	if (!(list = ft_maths_lexer(expr)))
		return (CONV_FAIL);
	ft_putendl("apres lexer\n");
	//ft_unary_op(list); //suite de + et de -
	ast = ft_new_mathast_node(list);

	{
	ft_putendl("=== LIST ===");
	while (list)
	{
		ft_putendl(((t_maths_token*)list->content)->token);
		list = list->next;
	}

	ft_putendl("=== END ===");
	}

	if (ft_build_ast(ast) == CONV_FAIL)
	{
		ft_putendl("ast build fail");
//		print_errror(sig); syntax error, DIV par zero, error de var
		return (CONV_FAIL);
	}
	ft_putendl("ast succes finish");
	ft_print_ast(ast);
	if (ft_eval_ast(ast, res) == CONV_FAIL)
	{
		ft_putendl("ast eval fail");
//		print_errror(sig); syntax error, DIV par zero, error de var
		return (CONV_FAIL);
	}
	return (CONV_SUCCESS);
}

char		*ft_eval_inner_parentheses(char *expr)
{
	size_t		len;
	size_t		inner_par;
	size_t		end_par;
	int64_t		conv;
	char		*res;

	if (ft_find_inner_expr(expr, &inner_par, &end_par))
	{
		expr[end_par] = '\0';
		len = ft_strlen(expr + inner_par);
		if (ft_eval(expr + inner_par + 1, &conv) == CONV_FAIL)
		{
//			print_error(error de conv)
			return (NULL);
		}
		res = ft_itoa64(conv);
		res = ft_construct_expansion(expr, res, inner_par, len + 1);
//		ft_strdel(&expr);
		return (res);
	}
	else
		return (NULL); //erreur de parentheses
}
