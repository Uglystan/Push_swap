/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fin_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:51:35 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/11 09:40:03 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ind_a(t_pile *pile, int ind)
{
	while (pile != NULL)
	{
		if (pile->index == ind)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	check_last_ind(t_pile *pile)
{
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile->index);
}

void	coup_rb_ou_rrb(t_pile **pileB)
{
	if (better_play_ind_max(*pileB) == 1)
		rev_rot_b(pileB, 0);
	else
		rotate_b(pileB, 0);
}
//A voir avec le visualizer ce sera bien plus simple
//ENsuite on va remettre les nombre dans A de maniere opti toujour donc on a des paquets d'index de 10 dasn B qui sont pas trie mais presque (voir visualizer quand apres le
//tri des 3 dernier nombre de A) donc on va remettre dans A et on va prendre un index qui fait partie des 10 plus grand par forcement le plus grand et on le met dans A
//Si c'est pas le bon nombre c'est a dire qu'il est plus petit que celui qui aurait du venir on rotate A pour le mettre en dessous et dans B maintenant on cherche un index qui
//est plus petit que l'index du premeir nombre de la pile A mais plus grand que le dernier de la pile A (Je rappel dernier de la pile A c'est pas le plus grand puisqu'on a rotate)
//On fait cette recherche de maniere opti comme d'hab on regarde si il vaut mieux rotate ou reverse rotate pour faire monter le nombre au sommet de B et si il faut rotate dans B pour
//faire monter le nombre et dans A pour faire passer le nombre du dessus qui est pas a sa place en dessous on fait un double rotate bref on fait ca jusqu'a qu'on ait mis le nombre 
//qu'il fallait au dessus de A et a ce moment on vient checker en dessous de A (tu remarqueras ils sont tries dasn l'odre croissant certe avec peut etre des trou mais trie) si
//jamais par hasard y'a pas le nombre qui vient juste au dessus et si c'est le cas on fait juste un reverse rotate et on verifie encore en dessous de A si y'a pas encore le nombre
//qu'il faut et si y'a pas on reprend dans B on cherche le nombre plus petit que le premeir de A et plus grands que le dernier de A ainsi de suite
void	tri_fin_push_a(t_pile **pileA, t_pile **pileB, int size)
{
	int	ind;

	while (lstsize(*pileB) != 0)
	{
		ind = ind_le_plus_grand(*pileB);
		while (check_ind_a(*pileB, ind) == 0 && lstsize((*pileB)) != 0)
		{
			while (((*pileB)->index < ind && lstsize(*pileA) >= 1)
				&& (((*pileB)->index > check_last_ind((*pileA)))
					|| (check_last_ind((*pileA)) == size))
				&& lstsize(*pileB) != 0)
			{
				push_a(pileB, pileA, 0);
				rotate_a(pileA, 0);
			}
			if ((*pileB)->index == ind && lstsize(*pileB) != 0)
				push_a(pileB, pileA, 0);
			else if (lstsize(*pileB) != 0)
				coup_rb_ou_rrb(pileB);
			while (lstsize(*pileA) >= 2
				&& check_last_ind((*pileA)) == (*pileA)->index - 1)
				rev_rot_a(pileA, 0);
		}
	}
}
