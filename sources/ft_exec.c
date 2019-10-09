/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgouedar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 20:54:15 by tgouedar          #+#    #+#             */
/*   Updated: 2019/10/09 11:40:50 by tgouedar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include "signal_manager.h"
#include "line_edit.h"
#include "shell.h"
#include "libft.h"


static int		ft_no_fork_exec(t_data *data, char **av)
{
	char		*execpath;
	t_env		*env_exec;

	env_exec = (data->env_exec)->value ? data->env_exec : data->env;
	if ((execpath = ft_find_exec(data->env, av[0])))
		execve(execpath, av, env_exec->value);	//return status si non-executable/faillure to execute
	else
		data->status = NOT_A_CMD;
	return (EXEC_FAILURE);
}
int				ft_exec(t_data *data, char **cmd_av, char to_fork)
{
	int		signal;

	signal = ft_built_in(data, cmd_av);
	if (signal == NOT_BI)
	{
		if (to_fork == FORK)
			signal = ft_fork_and_exec(data, cmd_av);
		else if (to_fork == NO_FORK)
		{
//			ft_putendl_fd("\n exec_sans_fork", 2);
			signal = ft_no_fork_exec(data, cmd_av);
			ft_unset_env_var(data->env, "_");
		}
		if (signal == EXEC_FAILURE && data->status != NOT_A_CMD)
			data->status = WEXITSTATUS(data->status);
	}
	return (signal);
}
