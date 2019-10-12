/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_interne.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:01:05 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/12 18:07:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_INTERNE_H
# define MATHS_INTERNE_H

# include "maths_def.h"

int				ft_parentheses_nbr(char *expr);
int				ft_find_inner_expr(char *expr, size_t *inner_par,
															size_t *end_par);
char			*ft_construct_expansion(char *arg, char *expansion,
												size_t var_pos, size_t var_len);
int				ft_eval(char *expr, int64_t *res);
char			*ft_eval_inner_parentheses(char *expr);
int				ft_int64_convert(int64_t *value, char *expr, char *base);
void			ft_unary_op(t_maths_list *list);
int				ft_get_op_priority(char *op);
size_t			ft_op_len(char *word);
t_ft_maths		*ft_op_func(char *op);
int				ft_get_flag(char side, char *op);
void			ft_push_tokens(char *word, t_maths_list **token_list);
t_maths_list			*ft_maths_lexer(char *expr);
t_maths_token	*ft_init_maths_token(char *word, size_t token_len, char flag);
int				ft_arg_value(char *token, int64_t *value);
char			*ft_itoa64(int64_t nb);
int				ft_build_ast(t_maths_ast *ast, int flag);
int				ft_eval_ast(t_maths_ast *ast, int64_t *res, char flag);
t_maths_ast		*ft_new_mathast_node(t_maths_list *tokens);
int				eval_expression(t_maths_ast *, int64_t *); // a ecrire
size_t			ft_ast_depth(const t_maths_ast *ast);

#endif
