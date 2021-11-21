/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 23:46:13 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 13:19:03 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <wait.h>
# include "../libft/libft.h"

typedef struct s_info
{
	int		fd[2];
	int		fd_old[2];
	int		mode;
	int		cmd_quant;
	char	**cmd;
	char	*path;
	char	*cmd_path;
	char	*delim;
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
int		only_space(char *str);
void	free_all_pipex(char **list);
int		input_output(int fd_in, int fd_out, int *pipe, int file);
void	init(t_info *info, char **cmd_quant, char **envp);
int		check_input(char **arg, t_info *info);
int		count_cmd(char **matrix_str);
char	**parsing(char *unparsed);

//Create tmp file for the here document mode
int		tmp_file(int fd_file, char *delim);

// CMD exec
int		exec_cmd(char **cmd, t_info *info);

// CMD parsing
char	**parsing(char *unparsed);

// fd descriptor managment
void	close_pipe(int fd[2]);
int		managment(t_info *info, int cond);

#endif
