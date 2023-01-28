/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_pile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:25:52 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:30:46 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*make_pile(char **argv)
{
	int		j;
	t_pile	*pile_a;
	t_pile	*temp;

	j = 2;
	pile_a = lstnew(ft_atoi(argv[1]), 0);
	if (pile_a == NULL)
		return (NULL);
	while (argv[j] != NULL)
	{
		temp = lstnew(ft_atoi(argv[j]), 0);
		if (temp == NULL)
		{
			lstclear(&pile_a);
			return (NULL);
		}
		lstadd_back(&pile_a, temp);
		j++;
	}
	return (pile_a);
}

long long	find_ind_zero(t_pile *pile)
{
	while (pile->index != 0)
	{
		pile = pile->next;
	}
	return (pile->content);
}

void	index_pile(t_pile **pileA)
{
	t_pile		*first;
	t_pile		*temp;
	long long	k;
	int			i;
	int			size;

	first = *pileA;
	size = lstsize(*pileA);
	i = 0;
	while (i <= size)
	{
		k = find_ind_zero((*pileA));
		while ((*pileA) != NULL)
		{
			if ((*pileA)->content <= k && (*pileA)->index == 0)
			{
				k = (*pileA)->content;
				temp = (*pileA);
			}
			(*pileA) = (*pileA)->next;
		}
		temp->index = i;
		i++;
		(*pileA) = first;
	}
}
