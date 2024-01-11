/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:52:21 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:58:33 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//CHaque cas est fait a la mano je vais pas expliquer c'est logique mais en tout cas max 2 coups
void	tri_3(t_pile **pileA)
{
	int	i;
	int	j;
	int	k;

	i = (*pileA)->content;
	j = (*pileA)->next->content;
	k = (*pileA)->next->next->content;
	if (i > j && j < k && i < k)
		swap_a(pileA, 0);
	if (i > j && j > k && i > k)
	{
		swap_a(pileA, 0);
		rev_rot_a(pileA, 0);
	}
	if (i > j && j < k && i > k)
		rotate_a(pileA, 0);
	if (i < j && j > k && i < k)
	{
		swap_a(pileA, 0);
		rotate_a(pileA, 0);
	}
	if (i < j && j > k && i > k)
		rev_rot_a(pileA, 0);
}

void	tri_5(t_pile **pileA, t_pile **pileB)
{
	//On va mettre dans B les 2 plus petits indexs
	while (lstsize((*pileA)) != 3)
	{
		//Cette fonction ind_le_plus_petit ultra utile je lui envoie la pile et elle me dit qu'elle est l'index le plus petit a l'interieur donc ici si l'index le plus
		//petit c'est mon premier element je le met dans B
		if ((*pileA)->index == ind_le_plus_petit(*pileA))
			push_b(pileA, pileB, 0);
		//Better_play_ind_min me dis quel coup privilegier pour faire monter l'index le plus petit au sommet de ma pile rotate ou reverse rotate
		if (better_play_ind_min(*pileA) == 1)
			rev_rot_a(pileA, 0);
		else
			rotate_a(pileA, 0);
	}
	//Quand je n'ai plus que 3 nombre dans la pile a j'utilise le tri_3 donc ma pile  et forcement bien trie
	tri_3(pileA);
	//SI les 2 nombre que j'ai dans B ne sont pas triee je les swap
	if (lstsize(*pileA) == 2 && (*pileB)->index > (*pileB)->next->index)
		swap_b(pileB, 0);
	//Et je remet dans la pile A
	push_a(pileB, pileA, 0);
	push_a(pileB, pileA, 0);
}
//Pour verifier si deja tire on parcourt la liste et on vient verifier si le maillon actuel et plus petit que le maillon suivant si a un moment c'est pas le cas c'est que la liste
//est pas triee
int	already_tri(t_pile *pileA)
{
	while (pileA->next != NULL)
	{
		if (pileA->content > pileA->next->content)
			return (0);
		pileA = pileA->next;
	}
	return (1);
}
//Tri de 500 a 5000 valeurs de maniere opti
void	tri_fin(t_pile **pileA, t_pile **pileB)
{
	int	ind;
	int	size;

	ind = lstsize(*pileA);
	//Premiere partie du trie on met quai tout dans B
	tri_fin_push_b(pileA, pileB, ind);
	//Il reste que # nombre dans A donc on fait un tri_3 a l'ancienne
	tri_3(pileA);
	size = lstsize(*pileB) + 3;
	//Et la on fait derniere partit du tri
	tri_fin_push_a(pileA, pileB, size);
}
//Ici on a tout les cas possible
void	tri(t_pile **pileA, t_pile **pileB)
{
	//Si deja trie on stop direct aucune action de faite
	if (already_tri(*pileA) == 1)
		return ;
	//Si seulement 2 nombre et que le premier > le deuxieme en 1 coup on trie en faisant un swap de a
	else if (lstsize(*pileA) == 2
		&& (*pileA)->content > (*pileA)->next->content)
		swap_a(pileA, 0);
	//Si 3 nbr on appel fonction tri_3
	else if (lstsize(*pileA) == 3)
		tri_3(pileA);
	//si on a 5 ou 4 nombre on utilise tri_5
	else if (lstsize(*pileA) <= 5 && lstsize(*pileA) > 3)
		tri_5(pileA, pileB);
	//tri au dessus de 5 donc opti pour 500 et 5000 valeurs
	else
		tri_fin(pileA, pileB);
}
