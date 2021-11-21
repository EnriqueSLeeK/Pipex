/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:46:13 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/19 15:06:54 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_info
{
	char	**cmd;
	char	*path;
	char	*cmd_path;
	int		fd[2];
	char	**env;
}	t_info;

typedef struct s_parse_flag
{
	int	sp_quote;
	int	db_quote;
	int	segment_flag;
}	t_parse_flag;

// Error message print
void	print_usage(void);

// Util misc
int		input_output(int fd_in, int fd_out, int *close_pipe, int file);
void	init(t_info *info, char **envp);
int		ft_count_str(char **matrix_str);
void	free_all_pipex(char **list);
char	**parsing(char *unparsed);
int		check_input(char **arg);
int		only_space(char *str);

// CMD exec
int		exec_cmd(char **cmd, t_info *info);

// fd descriptor managment
void	close_pipe(int fd[2]);

#endif
