/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 21:39:53 by ensebast          #+#    #+#             */
/*   Updated: 2021/11/20 12:43:17 by ensebast         ###   ########.br       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	print_usage(void)
{
	ft_putstr_fd("./pipex file1 cmd1 cmd2 ... cmdn file2\n", 2);
}

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	int		err;

	err = 0;
	if (argc >= 5)
	{
		err = check_input(&argv[1], &info);
		init(&info, &argv[1], envp);
		exec_cmd(&argv[1 + info.mode], &info);
	}
	else
	{
		ft_putstr_fd("Too few args\n", 2);
		print_usage();
		err = -1;
	}
	return (err);
}
