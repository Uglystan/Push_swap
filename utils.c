/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:08:48 by lgirault          #+#    #+#             */
/*   Updated: 2023/01/28 17:39:10 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pos_list(t_pile *pile, int index)
{
	int	size;
	int	i;

	size = lstsize(pile);
	i = 0;
	while (pile->index != index)
	{
		i++;
		pile = pile->next;
	}
	if (i > size / 2)
		return (1);
	else
		return (2);
}

int	verif_pile(t_pile *pile, int limit)
{
	int	i;

	i = 0;
	while (i != limit)
	{
		if (pile == NULL)
			return (0);
		pile = pile->next;
		i++;
	}
	return (1);
}

int	ind_le_plus_grand(t_pile *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index > i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}

int	ind_le_plus_petit(t_pile *pile)
{
	int	i;

	i = pile->index;
	while (pile != NULL)
	{
		if (pile->index < i)
			i = pile->index;
		pile = pile->next;
	}
	return (i);
}
