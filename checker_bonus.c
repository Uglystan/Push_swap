/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgirault <lgirault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:25:16 by lgirault          #+#    #+#             */
/*   Updated: 2023/02/01 13:02:39 by lgirault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_tab(char **tab, t_pile **pileA, t_pile **pileB, int bool)
{
	int	j;

	j = 0;
	lstclear(pileA);
	lstclear(pileB);
	while (tab[j] != NULL)
	{
		free(tab[j]);
		j++;
	}
	free(tab);
	if (bool == 1)
		exit(EXIT_FAILURE);
}

char	**read_coup(t_pile **pileA, t_pile **pileB)
{
	char	*str;
	char	*temp;
	char	**tab_coup;

	temp = NULL;
	tab_coup = NULL;
	str = ft_strdup("");
	if (str == NULL)
		free_tab(tab_coup, pileA, pileB, 1);
	temp = get_next_line(0);
	while (temp != NULL)
	{
		str = join(str, temp);
		if (str == NULL)
			free_tab(tab_coup, pileA, pileB, 1);
		temp = get_next_line(0);
	}
	tab_coup = ft_split(str, '\n');
	free(str);
	return (tab_coup);
}

void	is_it_ok(t_pile *pileA, t_pile **pileB, char **tab_coup)
{
	t_pile	*temp;

	temp = pileA;
	if (lstsize(*pileB) >= 1)
	{
		write(1, "KO\n", 3);
		free_tab(tab_coup, &pileA, pileB, 1);
	}
	while (pileA->next != NULL)
	{
		if (pileA->index != pileA->next->index - 1)
		{
			write(1, "KO\n", 3);
			pileA = temp;
			free_tab(tab_coup, &pileA, pileB, 1);
		}
		pileA = pileA->next;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*pile_a;
	t_pile	*pile_b;
	char	**tab_coup;

	pile_b = NULL;
	if (argc >= 2)
	{
		if (check_arg_nbr(argv) == 0)
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		pile_a = make_pile(argv);
		index_pile(&pile_a);
		check(&pile_a);
		tab_coup = read_coup(&pile_a, &pile_b);
		do_coup(&pile_a, &pile_b, tab_coup);
		is_it_ok(pile_a, &pile_b, tab_coup);
		write(1, "OK\n", 3);
		free_tab(tab_coup, &pile_a, &pile_b, 0);
	}
	else
		return (0);
}
