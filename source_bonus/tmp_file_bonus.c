/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp_file_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 11:24:28 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 12:56:51 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	tmp_file(int fd_file, char *delim)
{
	int		len;
	char	*buff;

	while (1)
	{
		buff = get_next_line(0);
		len = ft_strlen(buff);
		if (ft_strncmp(delim, buff, len + 1) == -10)
			break ;
		write(fd_file, buff, len);
		free(buff);
		buff = 0;
	}
	if (buff)
		free(buff);
	close(fd_file);
	fd_file = open("/tmp/tmp_f", O_RDONLY);
	return (fd_file);
}
