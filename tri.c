/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:52:21 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/01 16:19:28 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (lstsize((*pileA)) != 3)
	{
		if ((*pileA)->index == ind_le_plus_petit(*pileA))
			push_b(pileA, pileB, 0);
		if (better_play_ind_min(*pileA) == 1)
			rev_rot_a(pileA, 0);
		else
			rotate_a(pileA, 0);
	}
	tri_3(pileA);
	if (lstsize(*pileA) == 2 && (*pileB)->index > (*pileB)->next->index)
		swap_b(pileB, 0);
	push_a(pileB, pileA, 0);
	push_a(pileB, pileA, 0);
}

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

void	tri_fin(t_pile **pileA, t_pile **pileB)
{
	int	ind;
	int	size;

	ind = lstsize(*pileA);
	tri_fin_push_b(pileA, pileB, ind);
	tri_3(pileA);
	size = lstsize(*pileB) + 3;
	tri_fin_push_a(pileA, pileB, size);
}

void	tri(t_pile **pileA, t_pile **pileB)
{
	if (already_tri(*pileA) == 1)
		return ;
	else if (lstsize(*pileA) == 2
		&& (*pileA)->content > (*pileA)->next->content)
		swap_a(pileA, 0);
	else if (lstsize(*pileA) == 3)
		tri_3(pileA);
	else if (lstsize(*pileA) <= 5 && lstsize(*pileA) > 3)
		tri_5(pileA, pileB);
	else
		tri_fin(pileA, pileB);
}
