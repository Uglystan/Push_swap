# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/10 18:07:37 by lgirault          #+#    #+#              #
#    Updated: 2023/02/02 10:52:24 by lgirault         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAMEB = checker
CC = cc
CFLAGS = -Werror -Wall -Wextra
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

BONUSRC = checker_bonus.c \
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
	do_coup_bonus.c \

OBJ = $(SRC:.c=.o) 

BONUSOBJ = $(BONUSRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) ./push_swap.h
	make -C ./libft_tot/
	$(CC) $(CFLAGS) $(OBJ) libft_tot/libft.a -o $(NAME)

clean:
	$(RM) $(OBJ) $(BONUSOBJ)
	make clean -C ./libft_tot/

fclean: clean
	$(RM) $(NAME) $(NAMEB)
	make fclean -C ./libft_tot/

re: fclean all

bonus: $(NAMEB)
	
$(NAMEB): $(BONUSOBJ) ./push_swap.h
	make -C ./libft_tot/
	$(CC) $(CFLAGS) $(BONUSOBJ) libft_tot/libft.a -o $(NAMEB)

.PHONY: all fclean clean re