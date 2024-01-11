/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_play_push_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:45:14 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:31:26 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_play_ind_max(t_pile *pileB)
{
	int		k;
	int		j;
	t_pile	*temp;

	k = 0;
	j = 0;
	temp = pileB;
	while (lstsize(pileB) != 0)
	{
		while (pileB->index != ind_le_plus_grand(pileB))
		{
			j++;
			pileB = pileB->next;
		}
		pileB = temp;
		k = lstsize(pileB) - j + 1;
		if (j > k)
			return (1);
		else
			return (2);
	}
	return (0);
}
//Cette fonction sert a savoir si dans une pile pour faire venir l'index le plus petit en haut de la pile il vaut mieux faire des rotate ou des reverse rotate
int	better_play_ind_min(t_pile *pileB)
{
	int		k;
	int		j;
	t_pile	*temp;

	k = 0;
	j = 0;
	temp = pileB;
	//Je parcours toute la pile j'ai mis B mais peut inporte ca marche pour les deux
	while (lstsize(pileB) != 0)
	{
		//donc je pars de en haut et tant que je suis pas a l'index le plus petit j'increment j donc je sais combien j'ai de nombre dans ma pile entre le sommet et
		//l'index le plus petit
		while (pileB->index != ind_le_plus_petit(pileB))
		{
			j++;
			pileB = pileB->next;
		}
		//Je remet pile B au debut
		pileB = temp;
		//Et ici je prend la taille de ma pile et je fais - j + 1 pour savoir a combien de nombre j'ai entre mon haut de pile et mon index le plus petit mais
		//en passant par le bas
		k = lstsize(pileB) - j + 1;
		//Si j > k j'ai donc plus de nombre entre le sommet et l'index le plus bas en passant par le haut que si jamais je passe par le bas donc pour mettre mon index
		//le plus petit au sommet j'ai interet a faire reverse rotate
		if (j > k)
			return (1);
		//cas contraire j'ai moins de nombre entre le sommet et l'index le plsu bas en passant par le haut donc je devrais plutot faire des rotates pour fair monter mon
		//index le plus bas au sommet de ma pile
		else
			return (2);
	}
	return (0);
}
