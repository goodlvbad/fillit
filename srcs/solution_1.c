/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oearlene <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 23:49:12 by oearlene          #+#    #+#             */
/*   Updated: 2020/01/28 01:41:57 by oearlene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**	Checks if a piece is in the border of the map
**	Returns 1 if check is failed
*/

int		check_bound_y(t_piece *piece, t_map *map, int y)
{
	int i;
	int flag;

	i = 0;
	while (i <= 3)
	{
		flag = 1;
		if (map->size >= piece->y[i] + y + 1)
			flag = 0;
		i++;
	}
	return (flag);
}

int		check_bound_x(t_piece *piece, t_map *map, int x)
{
	int i;
	int flag;

	i = 0;
	while (i <= 3)
	{
		flag = 1;
		if (map->size >= piece->x[i] + x + 1)
			flag = 0;
		i++;
	}
	return (flag);
}

void	del_piece(t_piece *piece, t_map *map, int x, int y)
{
	int		i;
	int		x1;
	int		y1;
	char	letter;

	i = 0;
	letter = '.';
	while (i <= 3)
	{
		x1 = piece->x[i] + x;
		y1 = piece->y[i] + y;
		if (map->array[y1][x1] == piece->letter)
			map->array[y1][x1] = letter;
		++i;
	}
}

void	put_piece(t_piece *piece, t_map *map, int x, int y)
{
	int		i;
	int		x1;
	int		y1;
	char	letter;

	i = 0;
	letter = piece->letter;
	while (i <= 3)
	{
		x1 = piece->x[i] + x;
		y1 = piece->y[i] + y;
		map->array[y1][x1] = letter;
		i++;
	}
}

/*
**	Checks if piece could fit map without going to borders previous piece
**	Calls put_piece func to put this piece on map
**	Returns 1 if check is failed
*/

int		check_piece(t_map *map, t_piece *piece, int x, int y)
{
	int i;
	int x1;
	int y1;

	i = 0;
	x1 = piece->x[i] + x;
	y1 = piece->y[i] + y;
	while (i <= 3 && map->array[y1][x1] == '.')
	{
		++i;
		x1 = piece->x[i] + x;
		y1 = piece->y[i] + y;
	}
	if (i != 4)
		return (1);
	put_piece(piece, map, x, y);
	return (0);
}
