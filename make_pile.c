/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:25:52 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 22:09:18 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*make_pile(char **argv)
{
	int		j;
	t_pile	*pile_a;
	t_pile	*temp;

	j = 2;
	//Initialisation du premier maillon avec lstnew on va donner argv[1] soit le premier nombre de la pile (le sommet)
	pile_a = lstnew(ft_atoi(argv[1], &pile_a), 0);
	//lstnew malloc donc on protege
	if (pile_a == NULL)
		return (NULL);
	//On ajoute tout les autrees arguments
	while (argv[j] != NULL)
	{
		//On cree un maillon temporaire avec le nouvelle argument
		temp = lstnew(ft_atoi(argv[j], &pile_a), 0);
		//Si pb de malloc on clear toute la list et on quitte
		if (temp == NULL)
		{
			lstclear(&pile_a);
			exit(EXIT_FAILURE);
		}
		//On ajoute le maillon temporaire a la liste
		lstadd_back(&pile_a, temp);
		//On passe au nbr suivant
		j++;
	}
	return (pile_a);
}
//Cherche dans une pile le premier nombre qui a un index a 0 et return se nombre
long long	find_ind_zero(t_pile *pile)
{
	while (pile->index != 0)
	{
		pile = pile->next;
	}
	return (pile->content);
}
//On index la pile ici
void	index_pile(t_pile **pileA)
{
	t_pile		*first;
	t_pile		*temp;
	long long	k;
	int			i;
	int			size;
	//On cree un first pour ne pas perdre le debut de notre pile
	first = *pileA;
	//On calcul la taille de notre pile
	size = lstsize(*pileA);
	i = 0;
	//Ici on va indexer pour l'instant on a tout les contents qui sont set avec les arguments et tout les index a 0 c'est important que tout les index soit a 0
	//On va faire ca tant que i <= size donc tant qu'on a pas indexe tout la liste car a chaque fois qu'on aura indexe un nombre on augmente i
	while (i <= size)
	{
		//On attribut a k le premier nombre qu'on trouve qui n'a pas d'index donc un index a 0 donc au debut se sera le premier nombre
		k = find_ind_zero((*pileA));
		//On parcour toute la pile
		while ((*pileA) != NULL)
		{
			//Si on a un nombre dans la pile plus petit que le nombre actuel et qui lui aussi est a 0 k prend sa valeur et temp = le maillon en question
			if ((*pileA)->content <= k && (*pileA)->index == 0)
			{
				k = (*pileA)->content;
				temp = (*pileA);
			}
			//On passe de maillon en maillon ce qui fait que apres avoir parcourut tout notre pile k = le plus petit nombre avec un index a 0
			(*pileA) = (*pileA)->next;
		}
		//Donc on index le maillon le plus petit sans index avec i pour debut ce sera 0
		temp->index = i;
		//augmente i car on a index un nombre donc l'index du suivant sera 1 ainsi de suite
		i++;
		//On fait revenir la pile au debut car comme on l'a parcourut on a un pointeur sur le dernier maillon
		(*pileA) = first;
	}
}
