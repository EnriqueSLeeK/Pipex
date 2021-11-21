/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 00:24:21 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 16:35:42 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init(t_info *info, char **cmd, char **envp)
{
	info -> path = "/bin/";
	info -> cmd_quant = count_cmd(cmd) - info -> mode;
	info -> env = envp;
	info -> fd[0] = 0;
	info -> fd[1] = 0;
	info -> fd_old[0] = 0;
	info -> fd_old[1] = 0;
}
