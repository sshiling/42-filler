/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_digital_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:31:18 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 16:31:20 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			fill_digital_map_with_data(t_map *map,
	t_digit_map **digital_map, int key)
{
	int			y;
	int			x;

	y = -1;
	x = -1;
	while (++y < map->rows)
	{
		while (++x < map->columns)
		{
			if ((map->field[y][x] == 'O' && !key)
				|| (map->field[y][x] == 'X' && key))
				(*digital_map)->map[y][x] = ME;
			else if (map->field[y][x] == 'X' || map->field[y][x] == 'O')
				(*digital_map)->map[y][x] = 1;
			else if (map->field[y][x] == 'x' || map->field[y][x] == 'o')
				(*digital_map)->map[y][x] = 0;
			else
				(*digital_map)->map[y][x] = -2;
		}
		x = -1;
	}
}

t_digit_map		*create_digital_map(t_map *map)
{
	t_digit_map	*digital_map;
	int			key;
	int			i;

	i = -1;
	key = map->me == 'O' ? 0 : 1;
	digital_map = (t_digit_map*)malloc(sizeof(t_digit_map));
	digital_map->map = (int**)malloc(sizeof(int*) * map->rows);
	while (++i < map->rows)
		digital_map->map[i] = (int*)malloc(sizeof(int) * (map->columns));
	fill_digital_map_with_data(map, &digital_map, key);
	digital_map->columns = map->columns;
	digital_map->rows = map->rows;
	return (digital_map);
}
