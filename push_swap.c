/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:11:33 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/31 14:45:15 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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
			exit(EXIT_FAILURE);
		}
		pile_a = make_pile(argv);
		index_pile(&pile_a);
		check(&pile_a);
		tri(&pile_a, &pile_b);
		lstclear(&pile_a);
		lstclear(&pile_b);
	}
	else
		return (0);
}

//sortie d'erreur pour les erreurs