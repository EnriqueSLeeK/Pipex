# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ensebast <ensebast@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 13:20:00 by ensebast          #+#    #+#              #
#    Updated: 2021/11/20 13:20:01 by ensebast         ###   ########.br        #
#                                                                              #
# **************************************************************************** #

NAME:=pipex

CC:=clang
CFLAG:=-Wall -Werror -Wextra
INCLUDE:=./include

FILES:= check_input.c exec_cmd.c free_mem.c\
		init.c parsing.c fd_managment.c main.c

FILE_B:= check_input_bonus.c exec_cmd_bonus.c\
		 free_mem_bonus.c count_cmd_bonus.c\
		 init_bonus.c tmp_file_bonus.c main_bonus.c\
		 fd_managment_bonus.c parsing_bonus.c

SRC_PATH_B:=./source_bonus/
SRC_B= $(addprefix $(SRC_PATH_B), $(FILE_B))

SRC_PATH:=./source/
SRC= $(addprefix $(SRC_PATH), $(FILES))

LIBFT_PATH:= ./libft/
LIBFT:= $(LIBFT_PATH)libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(SRC) $(INCLUDE) $(LIBFT)
	$(CC) $(CFLAG) -I$(INCLUDE) $(SRC) $(LIBFT) -o $(NAME)

$(LIBFT): $(LIBFT_PATH)
	make -C $(LIBFT_PATH)

bonus: $(SRC_B) $(INCLUDE) $(LIBFT)
	$(CC) $(CFLAG) -I$(INCLUDE) $(SRC_B) $(LIBFT) -o $(NAME)

clean:
	make clean -C libft
	rm -f pipex

fclean: clean
	make fclean -C libft

re: fclean $(NAME)
