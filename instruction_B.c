/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_B.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:57:52 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:28:43 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_b(t_pile **pileB, int ind)
{
	t_pile	*swap;
	t_pile	*temp;

	if (lstsize(*pileB) <= 1)
		return (1);
	swap = (*pileB)->next;
	temp = *pileB;
	temp->next = swap->next;
	*pileB = swap;
	(*pileB)->next = temp;
	if (ind == 0)
		ft_printf("sb\n");
	return (1);
}

int	push_b(t_pile **pile_pushA, t_pile **pile_destB)
{
	t_pile	*temp;

	if (lstsize(*pile_pushA) == 0)
		return (0);
	if (*pile_destB == NULL || lstsize(*pile_destB) == 0)
	{
		(*pile_destB) = lstnew((*pile_pushA)->content, (*pile_pushA)->index);
		temp = (*pile_pushA)->next;
		free((*pile_pushA));
		*pile_pushA = temp;
	}
	else
	{
		temp = (*pile_destB);
		*pile_destB = *pile_pushA;
		*pile_pushA = (*pile_pushA)->next;
		(*pile_destB)->next = temp;
	}
	ft_printf("pb\n");
	return (1);
}

int	rotate_b(t_pile **pileB, int ind)
{
	t_pile	*first;
	t_pile	*second;

	if (lstsize((*pileB)) <= 1)
		return (0);
	first = *pileB;
	second = (*pileB)->next;
	(*pileB) = (*pileB)->next;
	while ((*pileB)->next != NULL)
	{
		(*pileB) = (*pileB)->next;
	}
	(*pileB)->next = first;
	(*pileB)->next->next = NULL;
	(*pileB) = second;
	if (ind == 0)
		ft_printf("rb\n");
	return (1);
}

int	rev_rot_b(t_pile **pileB, int ind)
{
	t_pile	*temp;
	t_pile	*der;

	if (lstsize((*pileB)) <= 1)
		return (0);
	temp = *pileB;
	while ((*pileB)->next->next != NULL)
	{
		(*pileB) = (*pileB)->next;
	}
	der = (*pileB)->next;
	(*pileB)->next = NULL;
	(*pileB) = der;
	(*pileB)->next = temp;
	if (ind == 0)
		ft_printf("rrb\n");
	return (1);
}
