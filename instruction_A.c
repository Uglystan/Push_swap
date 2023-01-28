/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_A.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:50:14 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:28:09 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_pile **pileA, int ind)
{
	t_pile	*swap;
	t_pile	*temp;

	if (lstsize(*pileA) <= 1)
		return (1);
	swap = (*pileA)->next;
	temp = *pileA;
	temp->next = swap->next;
	*pileA = swap;
	(*pileA)->next = temp;
	if (ind == 0)
		ft_printf("sa\n");
	return (1);
}

int	push_a(t_pile **pile_pushB, t_pile **pile_destA)
{
	t_pile	*temp;

	if (lstsize(*pile_pushB) == 0)
		return (0);
	if (*pile_destA == NULL || lstsize(*pile_destA) == 0)
	{
		(*pile_destA) = lstnew((*pile_pushB)->content, (*pile_pushB)->index);
		temp = (*pile_pushB)->next;
		free((*pile_pushB));
		*pile_pushB = temp;
	}
	else
	{
		temp = (*pile_destA);
		*pile_destA = *pile_pushB;
		*pile_pushB = (*pile_pushB)->next;
		(*pile_destA)->next = temp;
	}
	ft_printf("pa\n");
	return (1);
}

int	rotate_a(t_pile **pileA, int ind)
{
	t_pile	*first;
	t_pile	*second;

	if (lstsize((*pileA)) <= 1)
		return (0);
	first = *pileA;
	second = (*pileA)->next;
	(*pileA) = (*pileA)->next;
	while ((*pileA)->next != NULL)
	{
		(*pileA) = (*pileA)->next;
	}
	(*pileA)->next = first;
	(*pileA)->next->next = NULL;
	(*pileA) = second;
	if (ind == 0)
		ft_printf("ra\n");
	return (1);
}

int	rev_rot_a(t_pile **pileA, int ind)
{
	t_pile	*temp;
	t_pile	*der;

	if (lstsize((*pileA)) <= 1)
		return (0);
	temp = *pileA;
	while ((*pileA)->next->next != NULL)
	{
		(*pileA) = (*pileA)->next;
	}
	der = (*pileA)->next;
	(*pileA)->next = NULL;
	(*pileA) = der;
	(*pileA)->next = temp;
	if (ind == 0)
		ft_printf("rra\n");
	return (1);
}
