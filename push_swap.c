/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 18:11:33 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:14:46 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	//Creation des 2 piles
	t_pile	*pile_a;
	t_pile	*pile_b;

	pile_b = NULL;
	if (argc >= 2)
	{
		//Check des arguments si uniquement des digits
		if (check_arg_nbr(argv) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		//On construit la pile A. On va mettre tout les nombres a l'interieur de la liste chaine ou chaque maillon reprensente un nombre dans la pile
		pile_a = make_pile(argv);
		//On index la pile pour pour l'instant on a  [content : 290] [content : 304] [content : 2] [content : 100] on va avoir
		//[content : 290, index : 3] [content : 304, index : 4] [content : 2, index : 1] [content : 100, index : 2]
		index_pile(&pile_a);
		//On va verifier les doublons
		check(&pile_a);
		//Ici on va faire tout le tri
		tri(&pile_a, &pile_b);
		lstclear(&pile_a);
		lstclear(&pile_b);
	}
	else
		return (0);
}

//sortie d'erreur pour les erreurs