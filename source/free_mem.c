/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:22:13 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/12 01:14:39 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all_pipex(char **list)
{
	int	i;

	if (list == 0)
		return ;
	i = 0;
	while (list[i])
	{
		free(list[i]);
		i += 1;
	}
	free(list);
}
