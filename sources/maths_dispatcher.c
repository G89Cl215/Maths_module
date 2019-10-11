/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maths_dispatcher.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 13:08:40 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 15:13:54 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_dispatcher.h"
#include "maths_def.h"


t_maths_op		g_maths[] =
{
//	{">>=", ft_r_shift_assign, ASSIGN_PRIO},
//	{"<<=", ft_l_shift_assign, ASSIGN_PRIO},
//	{"+=", ft_add_assign, ASSIGN_PRIO},
//	{"-=", ft_sub_assign, ASSIGN_PRIO},
//	{"*=", ft_mul_assign, ASSIGN_PRIO},
//	{"/=", ft_div_assign, ASSIGN_PRIO},
//	{"%=", ft_mod_assign, ASSIGN_PRIO},
//	{"&=", ft_bitwiseand_assign, ASSIGN_PRIO},
//	{"^=", ft_bitwisexor_assign, ASSIGN_PRIO},
//	{"|=", ft_bitwiseor_assign, ASSIGN_PRIO},
//	{"++", ft_incr, INCR_PRIO},
//	{"--", ft_decr, DECR_PRIO},
	{"**", ft_exp, EXP_PRIO},
	{">>", ft_r_shift, SH_PRIO},
	{"<<", ft_l_shift, SH_PRIO},
	{"||", ft_logic_or, LOGOR_PRIO},
	{"&&", ft_logic_and, LOGAND_PRIO},
	{"!=", ft_diff_test, EQ_PRIO},
	{"==", ft_eq_test, EQ_PRIO},
	{"<=", ft_cmpinfeq_test, CMP_PRIO},
	{">=", ft_cmpsupeq_test, CMP_PRIO},
	{"<", ft_cmpinf_test, CMP_PRIO},
	{">", ft_cmpsup_test, CMP_PRIO},
	{"+", ft_add, ADD_PRIO},
	{"-", ft_sub, ADD_PRIO},
	{"*", ft_mul, MUL_PRIO},
	{"/", ft_div, MUL_PRIO},
	{"%", ft_mod, MUL_PRIO},
	{"!", ft_logic_neg, NEG_PRIO},
	{"~", ft_bitwise_neg, NEG_PRIO},
	{"|", ft_bitwise_or, BWAND_PRIO},
	{"&", ft_bitwise_and, BWOR_PRIO},
	{"^", ft_bitwise_xor, BWXOR_PRIO},
	{NULL, NULL, 0}
};

int		ft_get_op_priority(char *op)
{
	size_t		i;

	i = 0;
	while ((g_maths[i].op))
	{
		if (!(ft_strcmp(g_maths[i].op, op)))
			return (g_maths[i].priority);
		i++;
	}
	return (0);
}

size_t		ft_op_len(char *word)
{
	size_t		i;
	size_t		len;

	i = 0;
	while ((g_maths[i].op))
	{
		len = ft_strlen(g_maths[i].op);
		if (!(ft_strncmp(g_maths[i].op, word, len)))
			return (len);
		i++;
	}
	return (1);
}

t_ft_maths		*ft_op_func(char *op)
{
	size_t		i;

	i = 0;
	while ((g_maths[i].op))
	{
		if (!(ft_strcmp(g_maths[i].op, op)))
			return (g_maths[i].ft_op);
		i++;
	}
	return (NULL);

}
