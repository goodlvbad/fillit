/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 23:05:13 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/28 01:23:18 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t			count_pieces(t_piece *list)
{
	size_t		count;

	count = 0;
	while (list)
	{
		list = list->next;
		count++;
	}
	return (count);
}

int				high_sqrt(int nbr)
{
	int			size;

	size = 2;
	while (size * size < nbr)
		size++;
	return (size);
}

int				backtracking(t_map *map, t_piece *piece)
{
	int			x;
	int			y;
	t_piece		*ptr;

	if (piece == NULL)
		return (1);
	ptr = piece;
	y = 0;
	while (!check_bound_y(ptr, map, y))
	{
		x = 0;
		while (!check_bound_x(ptr, map, x))
		{
			if (!check_piece(map, ptr, x, y))
			{
				if (backtracking(map, piece->next))
					return (1);
				else
					del_piece(ptr, map, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

/*
** Start with the smallest map
*/

t_map			*solve(t_piece *list)
{
	t_map		*map;
	int			map_size;

	map_size = high_sqrt(count_pieces(list) * 4);
	map = new_map(map_size);
	while (!backtracking(map, list))
	{
		free_map(map);
		map_size++;
		map = new_map(map_size);
	}
	return (map);
}
