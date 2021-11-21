/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/13 14:40:30 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/11 19:26:36 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1

typedef struct s_link_lst
{
	int					fd;
	char				buff_c;
	struct s_link_lst	*next;
}	t_link;

char	*get_next_line(int fd);
t_link	*create_node(char c, int fd);
t_link	*read_and_add(char *tmp, t_link *node, int fd);
char	*copy_and_free(char *line, t_link *node, t_link **head, int fd);

//line utils
int		line_size(t_link *head, int fd);
t_link	*copy(t_link *node, int fd, char *buff_t, int flag[]);

//free utils
t_link	*free_node(t_link *prev, t_link *node);
t_link	*free_all(t_link *node, int fd);
t_link	*free_case(t_link *prev, t_link *node);
#endif
