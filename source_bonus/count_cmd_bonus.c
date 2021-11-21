/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_cmd_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 01:48:21 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 13:06:24 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	count_cmd(char **matrix_str)
{
	int	i;

	if (matrix_str == 0)
		return (-1);
	i = 0;
	while (matrix_str[i])
	{
		i += 1;
	}
	return (i - 2);
}
