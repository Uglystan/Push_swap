/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:11:33 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:31:45 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_pile(t_pile *pile)
{
	while (pile != NULL)
	{
		printf("nbr = %lld et index = %d\n", pile->content, pile->index);
		pile = pile->next;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	if (argc >= 2)
	{
		if (check_arg_nbr(argv) == 0)
		{
			write(2, "Error\n", 6);
			return (0);
		}
		pile_a = make_pile(argv);
		index_pile(&pile_a);
		if (check(pile_a) == 0)
		{
			lstclear(&pile_a);
			return (0);
		}
		tri(&pile_a, &pile_b);
		lstclear(&pile_a);
		lstclear(&pile_b);
	}
	else
		return (0);
}
//modifier atoi protecton overflow