/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:35:39 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 21:22:42 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATHS_DEF_H
# define MATHS_DEF_H

# include "libft.h"

# define BASE "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@_"
# define DEF_BASE "0123456789"
# define OCT_BASE "01234567"
# define HEX_BASE "0123456789abcdef"
# define IFS			" \t"
# define OPERATOR		"+-*/%=<>&|(),^!~"
//# define OPERATOR		"++--"

# define IS_OP			1
# define IS_ARG			0

# define INCR_PRIO		1
# define POSTCR_PRIO	1
# define PRECR_PRIO		2
# define NEG_PRIO		3
# define MUL_PRIO		5
# define ADD_PRIO		6
# define SH_PRIO		7
# define CMP_PRIO		8
# define EQ_PRIO		9
# define BWAND_PRIO		10
# define BWXOR_PRIO		11
# define BWOR_PRIO		12
# define LOGAND_PRIO	13
# define LOGOR_PRIO		14
# define ASSIGN_PRIO	16
# define COMMA_PRIO		17

# define CONV_SUCCESS	1
# define CONV_FAIL		0

typedef int64_t			(t_ft_maths)(int64_t , int64_t );

typedef struct			s_maths_op
{
	char				*op;
	t_ft_maths			*ft_op;
	int					priority;
}						t_maths_op;

typedef struct			s_maths_token
{
	char				*token;
	int					prio;
}						t_maths_token;

typedef struct			s_maths_ast
{
	t_list				*tokens;
	int64_t				res;
	t_ft_maths			*calc_func;
	struct s_maths_ast	*left_cmd;
	struct s_maths_ast	*right_cmd;
}						t_maths_ast;

#endif
