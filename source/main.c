/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:39:53 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 12:38:42 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_usage(void)
{
	ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		err;

	err = 0;
	if (argc == 5)
	{
		err = check_input(argv);
		init(&info, envp);
		exec_cmd(&argv[1], &info);
	}
	else if (argc > 5)
	{
		ft_putstr_fd("Too many args\n", 2);
		print_usage();
		err = -1;
	}
	else
	{
		ft_putstr_fd("Too few args\n", 2);
		print_usage();
		err = -1;
	}
	return (err);
}
