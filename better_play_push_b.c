/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_play_push_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 20:38:44 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:25:18 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_ind_big(t_pile *pile, int ind, int offset)
{
	while (pile != NULL)
	{
		if (pile->index > ind - (offset - (10 + ind / 25))
			&& pile->index <= (ind + (10 + ind / 25))
			- (offset - (10 + ind / 25)))
			return (0);
		pile = pile->next;
	}
	return (1);
}

int	coup_pour_rra(t_pile *pileA, int ind, int offset, int big)
{
	int		k;
	int		j;
	t_pile	*temp;

	k = 1;
	j = 1;
	temp = pileA;
	while (pileA != NULL)
	{
		if (pileA->index > ind - (offset - big)
			&& pileA->index <= (ind + (10 + ind / 25)) - (offset - big))
			k = j;
		j++;
		pileA = pileA->next;
	}
	pileA = temp;
	k = lstsize(pileA) - (k - 1);
	return (k);
}

int	coup_pour_rr(t_pile *pileA, int ind, int offset, int big)
{
	int	i;

	i = 1;
	while (pileA != NULL)
	{
		if (pileA->index > ind - (offset - big)
			&& pileA->index <= (ind + (10 + ind / 25)) - (offset - big))
			break ;
		i++;
		pileA = pileA->next;
	}
	return (i);
}

int	better_play(t_pile *pileA, int ind, int offset)
{
	int	big;
	int	better_for_big;
	int	better_for_lit;

	big = (10 + ind / 25);
	if (coup_pour_rr(pileA, ind, offset, big)
		> coup_pour_rra(pileA, ind, offset, big))
		better_for_big = coup_pour_rra(pileA, ind, offset, big);
	else
		better_for_big = coup_pour_rr(pileA, ind, offset, big);
	big = 0;
	if (coup_pour_rr(pileA, ind, offset, big)
		> coup_pour_rra(pileA, ind, offset, big))
		better_for_lit = coup_pour_rra(pileA, ind, offset, big);
	else
		better_for_lit = coup_pour_rr(pileA, ind, offset, big);
	if (better_for_big > better_for_lit)
		big = 0;
	else
		big = (10 + ind / 25);
	if (coup_pour_rr(pileA, ind, offset, big)
		> coup_pour_rra(pileA, ind, offset, big))
		return (1);
	else
		return (2);
}
