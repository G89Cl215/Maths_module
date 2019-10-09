/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_ast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:51:16 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 18:04:47 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//int				ft_parse_into_struct(t_meta_parse *to_parse, char flag)
//{
//	t_list		*voyager;
//	t_list		*end_of_cmd;
//
//	if (!(end_of_cmd = to_parse->tokens)
//	&& flag != NO_DELIM && flag != SEMI_COL)
//		return (1); // erreur de parsing -> une des section de la commande en bout de ligne est vide
//	if (!(voyager = ft_priority_meta(to_parse->tokens, &flag)))
//		return (0);
//	ft_putendl("\n ON DETECTE LES METACHARS");
//	to_parse->exec_func = ft_meta_function(voyager->delim);
//	to_parse->right_cmd = ft_new_parse_struct(voyager->next);
//	if (voyager == end_of_cmd)
//		return (1); //erreur de parsing -> on commence par un metachar / deux meta d'affilee
//	else
//	{
//		while (end_of_cmd->next != voyager)
//			end_of_cmd = end_of_cmd->next;
//		end_of_cmd->next = NULL;
//	}
//	ft_listfreeone(&voyager);
//	to_parse->left_cmd = ft_new_parse_struct(to_parse->tokens);
//	to_parse->tokens = NULL;
//	return (ft_parse_into_struct(to_parse->left_cmd, flag) || ft_parse_into_struct(to_parse->right_cmd, flag));
//}

t_maths_ast		*ft_new_mathast_node(t_list *tokens)
{
	t_maths_ast		*new_node;

	/*ft_memcheck*/parse_struct = (t_meta_parse*)malloc(sizeof(*parse_struct));
	parse_struct->tokens = tokens;
	parse_struct->exec_func = NULL;
	parse_struct->left_cmd = NULL;
	parse_struct->right_cmd = NULL;
	return (parse_struct);
}

t_list	*ft_get_max_prio(t_list *list)
{
	int		prio;
	int		cur_prio;
	t_list	*res;

	prio = -1;
	res = NULL;
	while (list)
	{
		cur_prio = list->content->prio;
		if ((cur_prio) && cur_prio > prio)
			res = list;
		list = list->next;
	}
	return (res);
}

int		ft_build_ast(t_maths_ast *ast)
{
	t_list		*mid_op;
	t_list		*list;

	list = ast->tokens;
	if (!(list)) // considerer le cas des operateurs unitaires (et surtout l'incrementation)
	{
		//"syntax error: missing operator"
		return (CONV_FAIL)
	}
	mid_op = ft_get_max_prio(list);
	if (!mid_op)
	{
		if (!(t_list->next))
			return (CONV_SUCCESS);
		//"syntax error: missing operand"
		return (CONV_FAIL)
	}

	ast->calc_func = ft_op_func(mid_op->content->token);
	ast->right_cmd = ft_new_mathast_node(mid_op->next);
	while (list->next != mid_op)
		list = list->next;
	list->next = NULL;
	ft_listfreeone(&mid_op);
	ast->left_cmd = ft_new_mathast_node(ast->tokens);
	ast->tokens = NULL;

	return (ft_build_ast(ast->left_cmd) == CONV_SUCCESS
			&& ft_build_ast(ast->right_cmd) == CONV_SUCCESS);
}
