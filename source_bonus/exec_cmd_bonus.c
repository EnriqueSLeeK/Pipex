/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 19:45:08 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 13:17:01 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	final_proc(t_info *info, char **cmd, int i)
{
	int	fd_file;

	fd_file = open(cmd[i + 2],
			O_WRONLY | O_CREAT | O_TRUNC * !(info -> mode)
			| O_APPEND * info -> mode,
			0000644);
	if (fd_file < 0)
		return (9);
	input_output(info -> fd[0], fd_file, info -> fd, fd_file);
	if (execve(info -> cmd_path, info -> cmd, info -> env))
		perror("Exec failed");
	return (-1);
}

static int	middle_proc(t_info *info)
{
	dup2(info -> fd_old[0], STDIN_FILENO);
	dup2(info -> fd[1], STDOUT_FILENO);
	close_pipe(info -> fd);
	close_pipe(info -> fd_old);
	if (execve(info -> cmd_path, info -> cmd, info -> env))
		perror("Exec failed");
	return (EXIT_FAILURE);
}

static int	first_proc(t_info *info, char **cmd)
{
	int	fd_file;

	if (info -> mode)
		fd_file = tmp_file(
				open("/tmp/tmp_f", O_CREAT | O_WRONLY, 0000644), cmd[0]);
	else
		fd_file = open(cmd[0], O_RDONLY);
	if (fd_file < 0)
		return (9);
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
	else if (i < info -> cmd_quant - 1)
		err = middle_proc(info);
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
	while (i < info -> cmd_quant)
	{
		managment(info, info -> cmd_quant - 1 != i);
		info -> cmd = parsing(cmd[i + 1]);
		info -> cmd_path = ft_strjoin(info -> path, info -> cmd[0]);
		pid = fork();
		if (pid == 0)
			execute(info, cmd, i);
		if (info -> mode && i == 0)
			waitpid(pid, NULL, 0);
		free_all_pipex(info -> cmd);
		free(info -> cmd_path);
		i += 1;
	}
	close_pipe(info -> fd);
	unlink("/tmp/tmp_f");
	return (0);
}
