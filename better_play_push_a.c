/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_play_push_a.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 17:45:14 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:55:34 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	better_play_ind_max(t_pile *pileB)
{
	int		k;
	int		j;
	t_pile	*temp;

	k = 0;
	j = 0;
	temp = pileB;
	while (lstsize(pileB) != 0)
	{
		while (pileB->index != ind_le_plus_grand(pileB))
		{
			j++;
			pileB = pileB->next;
		}
		pileB = temp;
		k = lstsize(pileB) - j + 1;
		if (j > k)
			return (1);
		else
			return (2);
	}
	return (0);
}

int	better_play_ind_min(t_pile *pileB)
{
	int		k;
	int		j;
	t_pile	*temp;

	k = 0;
	j = 0;
	temp = pileB;
	while (lstsize(pileB) != 0)
	{
		while (pileB->index != ind_le_plus_petit(pileB))
		{
			j++;
			pileB = pileB->next;
		}
		pileB = temp;
		k = lstsize(pileB) - j + 1;
		if (j > k)
			return (1);
		else
			return (2);
	}
	return (0);
}
