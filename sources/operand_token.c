/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operand_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:41:38 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/11 20:52:00 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths_interne.h"
#include "libft_add.h"

int				ft_isnumber(char *to_test)
{
	size_t	i;

	i = 0;
	while (to_test[i])
	{
		if (!(ft_isdigit(to_test[i])))
			return (0);
		i++;
	}
	return (1);
}

int				ft_isnumber_base(char *to_test, const char *base)
{
	size_t	i;

	i = 0;
	while (to_test[i])
	{
		if (!(ft_isin(to_test[i], base)))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_arg_value_base(char *base, char *nbr, int64_t *value)
{
	char	conv_base[65];
	size_t	base_len;

	*nbr = '\0';
	nbr++;
	base_len = 0;
	if ((ft_strchr(nbr, '#')))
	{
//		print_error("invalid_number"));
		return (CONV_FAIL);
	}
	if (ft_isnumber(base))
		base_len = ft_atoi(base);
	if (base_len < 2 || base_len > 64)
	{
//		print_error("invalid arithmetic base"));
		return (CONV_FAIL);
	}
	ft_memcpy(conv_base, BASE, base_len);
	conv_base[base_len] = '\0';
	ft_putstr("On trouve la base: ");
	ft_putendl(conv_base);
	if (base_len < 37)
		ft_strlower(nbr);
	return (ft_int64_convert(value, nbr, conv_base));
}

int				ft_arg_value(char *token, int64_t *value)
{
	char	*expr;

	*value = 0;
	if ((expr = ft_strchr(token, '#')))
	{
		ft_putendl("Reconnaissance de base");
		return (ft_arg_value_base(token, expr, value));
	}
	
	if (ft_isdigit(*token))
		return (ft_int64_convert(value, token, NULL));
//	expr = get_var(token);
//	if (ft_ismaths(expr))
//		return ();
	if (ft_isnumber(expr))	// pas tout a fait -> evaluation de la variable -> il peut y avoir des bases, des operations...
	{
		*value = ft_int64_convert(value, token, NULL);
		return (CONV_SUCCESS);
	}
//	print_error("value too great for base");
	return (CONV_FAIL);
}
