/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_managment_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 18:05:43 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 16:35:42 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	close_pipe(int fd[2])
{
	if (close(fd[0]))
		perror("Fd[0] failed closing");
	if (close(fd[1]))
		perror("Fd[1] failed closing");
}

static int	open_pipe(int fd[2], t_info *info)
{
	if (pipe(fd) == -1)
	{
		perror("Pipe has failed, aborting");
		free_all_pipex(info -> cmd);
		free(info -> cmd_path);
		exit(2);
	}
	return (1);
}

int	input_output(int fd_in, int fd_out, int *pipe, int file)
{
	if (dup2(fd_out, STDOUT_FILENO) < 0)
	{
		perror("dup2 out failed");
		return (-1);
	}
	if (dup2(fd_in, STDIN_FILENO) < 0)
	{
		perror("dup2 in failed");
		return (-1);
	}
	if (file > -1)
		if (close(file))
			perror("Failed closing file fd");
	close_pipe(pipe);
	return (0);
}

int	managment(t_info *info, int condition)
{
	int	tmp_fd[2];

	tmp_fd[0] = info -> fd_old[0];
	tmp_fd[1] = info -> fd_old[1];
	info -> fd_old[0] = info -> fd[0];
	info -> fd_old[1] = info -> fd[1];
	if (condition)
	{
		open_pipe(info -> fd, info);
	}
	if (tmp_fd[0] != info -> fd_old[0]
		&& tmp_fd[0] != info -> fd[0]
		&& tmp_fd[0] > 0)
	{
		close_pipe(tmp_fd);
	}
	return (1);
}
