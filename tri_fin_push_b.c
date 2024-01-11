/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fin_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:24:38 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:57:33 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ind_b(t_pile *pile, int ind, int offset)
{
	while (pile != NULL)
	{
		if ((pile->index > ind - offset
				&& pile->index <= (ind + (10 + ind / 25)) - offset)
			|| (pile->index > ind - (offset - (10 + ind / 25))
				&& pile->index <= (ind + (10 + ind / 25))
				- (offset - (10 + ind / 25))))
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	rotate_or_double(t_pile **pileA, t_pile **pileB, int ind, int offset)
{
	if (lstsize(*pileA) >= (10 + ind / 25))
	{
		if (((*pileB)->index > ind - offset
				&& (*pileB)->index <= (ind + (10 + ind / 25)) - offset)
			&& (better_play(*pileA, ind, offset) == 2)
			&& (lstsize(*pileB) > 1)
			&& (((*pileA)->index <= ind - offset
					&& (*pileA)->index <= (ind + (10 + ind / 25)) - offset)
				|| ((*pileA)->index > ind - (offset - (10 + ind / 25))
					&& (*pileA)->index > (ind + (10 + ind / 25))
					- (offset - (10 + ind / 25)))))
			rotate_a_and_b(pileA, pileB, 0);
		else if ((*pileB)->index > ind - offset
			&& (*pileB)->index <= (ind + (10 + ind / 25)) - offset)
			rotate_b(pileB, 0);
	}
}

void	tri_fin_push_b_play(t_pile **pileA, int ind, int offset)
{
	if (better_play(*pileA, ind, offset) == 1)
		rev_rot_a(pileA, 0);
	else
		rotate_a(pileA, 0);
}
//A lire avec le visualizer a cote pour bien comprendre
//Bon c'est vraimment complique et ca sert a rien de comprendre chaque ligne de code mais dans le globale on a la pile A non trie brut on va passer dans la pile B tout les indexs
//Entre un nombre magique qui evolue en fonction de la taille de la pile de depart mais par exemple on va passer les 20 plus petits nombre dans B donc on va devoir faire monter les
//20 plus petit index en haut de A pour les envoyer dans B donc deja la on va regarde dans les 20 plus petit ou est le plus proche et comme avec le tri 5 si on prend moins de 
//coupde le faire monter par le haut ou par le bas (rotate ou reverse rotate) ensuite quand il est en haut on le met dans B. Ensuite on va chercher le suivant pareil on regarde
//le meiux pour le faire monter et le fait monter et on le met dans B mais dans B on va les trier en 2 partie on va avoir les indexs de 1 a 10 en bas de B et de 11 a 20 en haut
//donc quand on met un nouveau nombre dans B on regarde si il est entre 1 et 10 si c'est le cas on fait un rotate de B pour basculer le nombre en bas de B sinon on fait rien et
//continue a envoyer les 20 plus petit index. derniere opti si dans B on doit faire un rotate car l;index et entre 0 et 10 et que dans A on va aussi devoir faire un rotate pour aller
//chercher le nombre suivant on fait un double rotate et on fait ca pour les index de 0 a 20 ensuite 20 a 40 ainsi de suite jusqu'a ce qu'il reste 3 nombre dans A
void	tri_fin_push_b(t_pile **pileA, t_pile **pileB, int ind)
{
	int	offset;

	offset = ind;
	while (lstsize(*pileA) != 3)
	{
		while (((*pileA)->index > ind - offset
				&& (*pileA)->index <= (ind + (10 + ind / 25))
				- offset && lstsize(*pileA) != 3)
			|| ((*pileA)->index > ind - (offset - (10 + ind / 25))
				&& (*pileA)->index <= (ind + (10 + ind / 25))
				- (offset - (10 + ind / 25)) && lstsize(*pileA) != 3))
		{
			if ((*pileA)->index < ind - 2)
				push_b(pileA, pileB, 0);
			else
				rotate_a(pileA, 0);
			rotate_or_double(pileA, pileB, ind, offset);
			if (check_ind_b(*pileA, ind, offset) == 1)
				offset = offset - ((10 + ind / 25) * 2);
		}
		if (lstsize(*pileA) == 3)
			break ;
		tri_fin_push_b_play(pileA, ind, offset);
	}
}
