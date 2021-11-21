/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:45:08 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 12:14:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	final_proc(t_info *info, char **cmd, int i)
{
	int	fd_file;

	fd_file = open(cmd[i + 2],
			O_WRONLY | FD_CLOEXEC | O_TRUNC | O_CREAT, 0000644);
	if (fd_file < 0)
		return (9);
	if (access(info -> cmd_path, X_OK))
	{
		perror("Command not found");
		close(fd_file);
		return (EXIT_FAILURE);
	}
	input_output(info -> fd[0], fd_file, info -> fd, fd_file);
	if (execve(info -> cmd_path, info -> cmd, info -> env))
		perror("Exec failed");
	return (EXIT_FAILURE);
}

static int	first_proc(t_info *info, char **cmd)
{
	int	fd_file;

	fd_file = open(cmd[0], O_RDONLY);
	if (fd_file < 0)
		return (9);
	if (access(info -> cmd_path, X_OK))
	{
		perror("Command not found");
		close(fd_file);
		return (EXIT_FAILURE);
	}
	input_output(fd_file, info -> fd[1], info -> fd, fd_file);
	if (execve(info -> cmd_path, info -> cmd, info -> env))
		perror("Exec failed");
	return (EXIT_FAILURE);
}

void	execute(t_info *info, char **cmd, int i)
{
	int	err;

	if (i == 0)
		err = first_proc(info, cmd);
	else
		err = final_proc(info, cmd, i);
	free_all_pipex(info -> cmd);
	free(info -> cmd_path);
	exit(err);
}

int	exec_cmd(char **cmd, t_info *info)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (i < 2)
	{
		info -> cmd = parsing(cmd[i + 1]);
		info -> cmd_path = ft_strjoin(info -> path, info -> cmd[0]);
		pid = fork();
		if (pid == 0)
			execute(info, cmd, i);
		free_all_pipex(info -> cmd);
		free(info -> cmd_path);
		i += 1;
	}
	close_pipe(info -> fd);
	return (0);
}
