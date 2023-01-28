# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 18:07:37 by lgirault          #+#    #+#              #
#    Updated: 2023/01/28 17:47:27 by lgirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Werror -Wall -Wextra -g3
RM = rm -rf

SRC = push_swap.c \
	check_arg.c \
	make_pile.c \
	instruction_A.c \
	instruction_B.c \
	instruction_A_et_B.c \
	lst_focntions.c \
	tri.c \
	utils.c \
	better_play_push_b.c \
	better_play_push_a.c \
	tri_fin_push_b.c \
	tri_fin_push_a.c \

OBJ = $(SRC:.c=.o) 


all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft_tot/
	$(CC) $(CFLAGS) $(OBJ) libft_tot/libft.a -o $(NAME)

clean:
	$(RM) $(OBJ)
	make clean -C ./libft_tot/

fclean: clean
	$(RM) $(NAME)
	make fclean -C ./libft_tot/

re: fclean all