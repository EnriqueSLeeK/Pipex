/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_managment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:15:37 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 13:19:11 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	close_pipe(int fd[2])
{
	if (close(fd[0]))
		perror("Error at closing FD[0]");
	if (close(fd[1]))
		perror("Error at closing FD[1]");
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
			perror("Error at closing file fd");
	close_pipe(pipe);
	return (0);
}
