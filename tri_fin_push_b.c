/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri_fin_push_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 11:24:38 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/01 17:24:53 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ind_b(t_pile *pile, int ind, int offset)
{
	while (pile != NULL)
	{
		if ((pile->index > ind - offset
				&& pile->index <= (ind + (10 + ind / 25)) - offset)
			|| (pile->index > ind - (offset - (10 + ind / 25))
				&& pile->index <= (ind + (10 + ind / 25))
				- (offset - (10 + ind / 25))))
			return (0);
		pile = pile->next;
	}
	return (1);
}

void	rotate_or_double(t_pile **pileA, t_pile **pileB, int ind, int offset)
{
	if (lstsize(*pileA) >= (10 + ind / 25))
	{
		if (((*pileB)->index > ind - offset
				&& (*pileB)->index <= (ind + (10 + ind / 25)) - offset)
			&& (better_play(*pileA, ind, offset) == 2)
			&& (lstsize(*pileB) > 1)
			&& (((*pileA)->index <= ind - offset
					&& (*pileA)->index <= (ind + (10 + ind / 25)) - offset)
				|| ((*pileA)->index > ind - (offset - (10 + ind / 25))
					&& (*pileA)->index > (ind + (10 + ind / 25))
					- (offset - (10 + ind / 25)))))
			rotate_a_and_b(pileA, pileB, 0);
		else if ((*pileB)->index > ind - offset
			&& (*pileB)->index <= (ind + (10 + ind / 25)) - offset)
			rotate_b(pileB, 0);
	}
}

void	tri_fin_push_b_play(t_pile **pileA, int ind, int offset)
{
	if (better_play(*pileA, ind, offset) == 1)
		rev_rot_a(pileA, 0);
	else
		rotate_a(pileA, 0);
}

void	tri_fin_push_b(t_pile **pileA, t_pile **pileB, int ind)
{
	int	offset;

	offset = ind;
	while (lstsize(*pileA) != 3)
	{
		while (((*pileA)->index > ind - offset
				&& (*pileA)->index <= (ind + (10 + ind / 25))
				- offset && lstsize(*pileA) != 3)
			|| ((*pileA)->index > ind - (offset - (10 + ind / 25))
				&& (*pileA)->index <= (ind + (10 + ind / 25))
				- (offset - (10 + ind / 25)) && lstsize(*pileA) != 3))
		{
			if ((*pileA)->index < ind - 2)
				push_b(pileA, pileB, 0);
			else
				rotate_a(pileA, 0);
			rotate_or_double(pileA, pileB, ind, offset);
			if (check_ind_b(*pileA, ind, offset) == 1)
				offset = offset - ((10 + ind / 25) * 2);
		}
		if (lstsize(*pileA) == 3)
			break ;
		tri_fin_push_b_play(pileA, ind, offset);
	}
}
