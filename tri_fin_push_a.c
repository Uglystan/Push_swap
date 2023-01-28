/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fin_push_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:51:35 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 18:00:12 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ind_a(t_pile *pile, int ind)
{
	while (pile != NULL)
	{
		if (pile->index == ind)
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	check_last_ind(t_pile *pile)
{
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile->index);
}

void	coup_rb_ou_rrb(t_pile **pileB)
{
	if (better_play_ind_max(*pileB) == 1)
		rev_rot_b(pileB, 0);
	else
		rotate_b(pileB, 0);
}

void	tri_fin_push_a(t_pile **pileA, t_pile **pileB, int size)
{
	int	ind;

	while (lstsize(*pileB) != 0)
	{
		ind = ind_le_plus_grand(*pileB);
		while (check_ind_a(*pileB, ind) == 0 && lstsize((*pileB)) != 0)
		{
			while (((*pileB)->index < ind && lstsize(*pileA) >= 1)
				&& (((*pileB)->index > check_last_ind((*pileA)))
					|| (check_last_ind((*pileA)) == size))
				&& lstsize(*pileB) != 0)
			{
				push_a(pileB, pileA);
				rotate_a(pileA, 0);
			}
			if ((*pileB)->index == ind && lstsize(*pileB) != 0)
				push_a(pileB, pileA);
			else if (lstsize(*pileB) != 0)
				coup_rb_ou_rrb(pileB);
			while (lstsize(*pileA) >= 2
				&& check_last_ind((*pileA)) == (*pileA)->index - 1)
				rev_rot_a(pileA, 0);
		}
	}
}
