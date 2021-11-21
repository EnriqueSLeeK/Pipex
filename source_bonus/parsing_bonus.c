/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/14 18:02:10 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 16:38:03 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// mode = 0 init struct t_parse_flag var
// mode = 1 update the flags in t_parse_flag
static void	init_or_update(t_parse_flag *flag, char c, int mode)
{
	if (mode)
	{
		flag -> sp_quote = 0;
		flag -> db_quote = 0;
		flag -> segment_flag = 0;
	}
	else
	{
		if (c == '\'')
			flag -> sp_quote = !(flag -> sp_quote);
		else if (c == '\"')
			flag -> db_quote = !(flag -> db_quote);
	}
}

static int	count_segment(char *str)
{
	t_parse_flag	parse_flag;
	int				count;
	int				i;

	i = 0;
	count = 0;
	init_or_update(&parse_flag, 0, 1);
	while (str[i])
	{
		init_or_update(&parse_flag, str[i], 0);
		if (str[i] != ' ' && parse_flag.segment_flag == 0)
		{
			parse_flag.segment_flag = 1;
			count += 1;
		}
		else if (str[i] == ' '
			&& parse_flag.sp_quote == 0
			&& parse_flag.db_quote == 0)
		{
			parse_flag.segment_flag = 0;
		}
		i += 1;
	}
	return (count);
}

static int	get_segment(char **str, char ***buff_split, char *buff)
{
	t_parse_flag	parse_flag;
	int				count;

	count = 0;
	init_or_update(&parse_flag, 0, 1);
	while (**str)
	{
		init_or_update(&parse_flag, **str, 0);
		if (**str == ' '
			&& parse_flag.sp_quote == 0
			&& parse_flag.db_quote == 0)
		{
			break ;
		}
		if (buff != NULL)
		{
			*buff = **str;
			buff += 1;
		}
		count += 1;
		*str += 1;
	}
	if (buff_split != NULL)
		*buff_split += 1;
	return (count);
}

static char	**alloc_mem(char *str)
{
	char	**mem;
	int		count;
	int		i;

	i = 0;
	count = count_segment(str);
	mem = ft_calloc(count_segment(str) + 1, sizeof(char *));
	if (mem == 0)
		perror("Malloc failed");
	while (i < count)
	{
		if (*str != ' ')
		{
			mem[i] = ft_calloc(get_segment(&str, NULL, NULL) + 1, sizeof(char));
			if (mem[i] == 0)
				perror("Malloc failed");
			i += 1;
		}
		else
			str += 1;
	}
	return (mem);
}

char	**parsing(char *unparsed)
{
	char			**parsed;
	char			**ptr_head;

	if (only_space(unparsed))
	{
		parsed = ft_calloc(2, sizeof(char *));
		parsed[0] = ft_strdup(" ");
		return (parsed);
	}
	parsed = alloc_mem(unparsed);
	if (parsed == 0)
		return (0);
	ptr_head = parsed;
	while (*unparsed)
	{
		if (*unparsed != ' ')
			get_segment(&unparsed, &parsed, *parsed);
		else
			unparsed += 1;
	}
	return (ptr_head);
}
