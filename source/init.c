/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:24:21 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 14:53:49 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	init(t_info *info, char **envp)
{
	info -> path = "/bin/";
	info -> env = envp;
	if (pipe(info -> fd) == -1)
	{
		ft_putstr_fd("Pipe is dead, there is no hope\n", 2);
		exit(2);
	}
}
