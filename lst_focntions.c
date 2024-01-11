/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_focntions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:14:37 by lgirault          #+#    #+#             */
/*   Updated: 2024/01/10 21:59:33 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//On va a la fin de la liste et on fait pointer le dernier maillon sur le new et new de base pointe sur null donc tout ok
void	lstadd_back(t_pile **lst, t_pile *new)
{
	t_pile	*ptr;

	ptr = *lst;
	if (lst != NULL)
	{
		if (*lst != NULL)
		{
			while (ptr->next != NULL)
			{
				ptr = ptr->next;
			}
			ptr->next = new;
		}
		else
			*lst = new;
	}
}

void	lstadd_front(t_pile **lst, t_pile *new)
{
	if (new != NULL)
	{
		new->next = *lst;
		*lst = new;
	}
}

//On parcourt toute la liste et on met le maillon suivant dans save et on free le maillon actuel on va au suivant grace au save et ainsi de suite
void	lstclear(t_pile **lst)
{
	t_pile	*save;

	if (lst != NULL)
	{
		while ((*lst) != NULL)
		{
			save = (*lst)->next;
			free(*lst);
			(*lst) = save;
		}
	}
}
//On creer un nouveau maillon on va mettre le content au meme nombre que l'argument et pour l'instant l'index a 0 on s'occupe des indexs plus tard
t_pile	*lstnew(long long nbr, int index)
{
	t_pile	*a;

	a = malloc(sizeof(*a));
	if (a == NULL)
		return (NULL);
	a->content = nbr;
	a->index = index;
	a->next = NULL;
	return (a);
}
//Parcourt toute la pile jusqu'a la fin a chaque fois incremente i et retourne i donc i = taille pile
int	lstsize(t_pile *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
