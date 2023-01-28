/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_focntions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:14:37 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:28:52 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
