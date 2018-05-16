/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_results.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 14:14:59 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/21 14:15:01 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			we_can_set_figure_here(t_map *map, int x, int y, t_cord *cords)
{
	int	key;

	key = 0;
	while (cords)
	{
		if (key > 1)
			return (0);
		if (cords->y_nil + y >= map->rows || cords->x_nil + x >= map->columns)
			return (0);
		if (map->field[cords->y_nil + y][cords->x_nil + x] == map->he
			|| map->field[cords->y_nil + y][cords->x_nil + x] == map->he + 32)
			return (0);
		if (map->field[cords->y_nil + y][cords->x_nil + x] == map->me)
			key++;
		cords = cords->next;
	}
	if (key)
		return (1);
	return (0);
}

int			calculate_sum(t_res_list *res, t_cord *cords, t_digit_map *map)
{
	while (cords)
	{
		res->sum +=
			map->map[res->y_fact + cords->y_nil][res->x_fact + cords->x_nil];
		cords = cords->next;
	}
	return (res->sum);
}

void		fill_res_node_with_data(t_res_list **cur,
	t_cord *cords, t_digit_map *digital_map)
{
	(*cur)->y_min = cords->y_min;
	(*cur)->x_min = cords->x_min;
	(*cur)->sum = calculate_sum(*cur, cords, digital_map);
	(*cur)->key = 1;
}

void		check_each_element(t_cord *cords, t_map *map,
	t_digit_map *digital_map, t_res_list **head)
{
	int			y;
	int			x;
	t_res_list	*tmp;

	y = -1;
	x = -1;
	tmp = *head;
	while (map->field[++y])
	{
		while (map->field[y][++x])
		{
			if (we_can_set_figure_here(map, x, y, cords))
			{
				if (tmp->key)
				{
					tmp->next = create_new_res_elem();
					tmp = tmp->next;
				}
				tmp->x_fact = x;
				tmp->y_fact = y;
				fill_res_node_with_data(&tmp, cords, digital_map);
			}
		}
		x = -1;
	}
}

t_res_list	*create_valid_results(t_cord *cords,
	t_map *map, t_digit_map *digital_map)
{
	t_res_list	*head;

	head = create_new_res_elem();
	check_each_element(cords, map, digital_map, &head);
	if (!head->key)
	{
		free_res_list(head);
		ft_printf("0 0\n");
		return (NULL);
	}
	return (head);
}
