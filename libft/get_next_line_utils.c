/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 17:18:29 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/11 19:27:00 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_link	*copy(t_link *node, int fd, char *buff_t, int flag_code[])
{
	t_link	*root;
	t_link	*tmp;

	root = node;
	while (node -> next)
		node = node -> next;
	while (flag_code[2] < flag_code[1])
	{
		flag_code[2] += 1;
		tmp = create_node(buff_t[flag_code[2] - 1], fd);
		if (tmp == 0)
		{
			free_all(node, fd);
			return (0);
		}
		node -> next = tmp;
		node = node -> next;
		if (node -> buff_c == '\n')
			flag_code[0] = 0;
	}
	node = root;
	return (root);
}

/*
 * flag_code [0] = flag
 * flag_code [1] = read_code
 * flag_code [2] = index
 */
t_link	*read_and_add(char *tmp, t_link *node, int fd)
{
	int		flag_code[3];

	if (tmp == 0)
		return (0);
	flag_code[0] = 1;
	while (flag_code[0])
	{
		flag_code[2] = 0;
		flag_code[1] = read(fd, tmp, BUFFER_SIZE);
		if (flag_code[1] == -1 || flag_code[1] == 0)
		{
			free(tmp);
			if (flag_code[1] == -1)
				return (free_all(node, fd));
			return (node);
		}
		if (node == 0)
			node = create_node(tmp[flag_code[2]++], fd);
		copy(node, fd, tmp, flag_code);
		if (flag_code[1] != BUFFER_SIZE)
			flag_code[0] = 0;
	}
	free(tmp);
	return (node);
}

//Create nodes
t_link	*create_node(char c, int fd)
{
	t_link		*node;

	node = malloc(sizeof(t_link));
	if (node == 0)
		return (0);
	node -> buff_c = c;
	node -> next = 0;
	node -> fd = fd;
	return (node);
}

t_link	*free_node(t_link *prev, t_link *node)
{
	t_link	*tmp;

	tmp = node;
	if (!(prev))
	{
		node = node -> next;
		free(tmp);
		return (node);
	}
	else if (prev)
	{
		if (node -> next == 0)
		{
			prev -> next = 0;
			free(tmp);
			return (0);
		}
		prev -> next = node -> next;
		free(tmp);
		return (prev -> next);
	}
	return (0);
}

int	line_size(t_link *head, int fd)
{
	int	i;

	i = 0;
	while (head)
	{
		if (head -> fd == fd)
			i += 1;
		if (head -> buff_c == '\n')
			break ;
		head = head -> next;
	}
	return (i);
}
