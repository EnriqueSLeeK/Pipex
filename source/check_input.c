/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:59:35 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 13:07:06 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	check_cmd(char **arg, int init, int step);

int	check_input(char **arg)
{
	if (access(arg[1], F_OK) == -1)
	{
		perror("File not found");
	}
	return (check_cmd(arg, 2, 2));
}

static int	check_cmd(char **arg, int init, int steps)
{
	int		i;
	int		err;
	char	**tmp_parse;
	char	*cmd;

	i = 0;
	err = 0;
	while (i < steps)
	{
		tmp_parse = parsing(arg[init + i]);
		cmd = ft_strjoin("/bin/", tmp_parse[0]);
		if (access(cmd, X_OK | F_OK) == -1)
			err = 127;
		free_all_pipex(tmp_parse);
		free(cmd);
		if (err)
			break ;
		i += 1;
	}
	return (err);
}

int	only_space(char *str)
{
	while (*str)
	{
		if (*str != ' ')
			return (0);
		str += 1;
	}
	return (1);
}
