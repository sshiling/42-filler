/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map_with_distance.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:35:21 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 16:35:23 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				check_map_for_possible_moves(t_digit_map *map, int x, int y)
{
	if (x != 0 && map->map[y][x - 1] == -2)
		return (1);
	if (x + 1 < map->columns && map->map[y][x + 1] == -2)
		return (1);
	if (y != 0 && map->map[y - 1][x] == -2)
		return (1);
	if (y + 1 < map->rows && map->map[y + 1][x] == -2)
		return (1);
	if (x != 0 && y != 0 && map->map[y - 1][x - 1] == -2)
		return (1);
	if (x + 1 < map->columns && y != 0 && map->map[y - 1][x + 1] == -2)
		return (1);
	if (x != 0 && y + 1 < map->rows && map->map[y + 1][x - 1] == -2)
		return (1);
	if (x + 1 < map->columns && y + 1 <
		map->rows && map->map[y + 1][x + 1] == -2)
		return (1);
	return (0);
}

int				there_are_more_possible_moves(t_digit_map *map, int filler)
{
	int		x;
	int		y;

	x = -1;
	y = -1;
	while (++y < map->rows)
	{
		while (++x < map->columns)
		{
			if (map->map[y][x] == filler)
			{
				if (check_map_for_possible_moves(map, x, y))
					return (1);
			}
		}
		x = -1;
	}
	return (0);
}

t_digit_map		*fill_map_with_filler(t_digit_map *map,
	int x, int y, int filler)
{
	if (x != 0 && map->map[y][x - 1] == -2)
		map->map[y][x - 1] = filler;
	if (x + 1 < map->columns && map->map[y][x + 1] == -2)
		map->map[y][x + 1] = filler;
	if (y != 0 && map->map[y - 1][x] == -2)
		map->map[y - 1][x] = filler;
	if (y + 1 < map->rows && map->map[y + 1][x] == -2)
		map->map[y + 1][x] = filler;
	if (x != 0 && y != 0 && map->map[y - 1][x - 1] == -2)
		map->map[y - 1][x - 1] = filler;
	if (x + 1 < map->columns && y != 0 && map->map[y - 1][x + 1] == -2)
		map->map[y - 1][x + 1] = filler;
	if (x != 0 && y + 1 < map->rows && map->map[y + 1][x - 1] == -2)
		map->map[y + 1][x - 1] = filler;
	if (x + 1 < map->columns && y + 1 <
		map->rows && map->map[y + 1][x + 1] == -2)
		map->map[y + 1][x + 1] = filler;
	return (map);
}

int				find_current_filler(t_digit_map *map)
{
	int		y;
	int		x;

	y = -1;
	x = -1;
	while (++y < map->rows)
	{
		while (++x < map->columns)
		{
			if (map->map[y][x] == 0)
				return (0);
		}
		x = -1;
	}
	return (1);
}

t_digit_map		*fill_with_distance(t_digit_map *digital_map)
{
	int		x;
	int		y;
	int		filler;

	x = -1;
	y = -1;
	filler = find_current_filler(digital_map);
	while (there_are_more_possible_moves(digital_map, filler))
	{
		while (++y < digital_map->rows)
		{
			while (++x < digital_map->columns)
			{
				if (digital_map->map[y][x] == filler)
					digital_map =
				fill_map_with_filler(digital_map, x, y, filler + 1);
			}
			x = -1;
		}
		filler++;
		y = -1;
	}
	return (digital_map);
}
