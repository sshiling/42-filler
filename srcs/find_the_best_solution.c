/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_best_solution.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:33:23 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/20 14:33:25 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			find_the_latest_opponent_move(t_map **map)
{
	int		x;
	int		y;
	int		key;

	x = -1;
	y = -1;
	key = (*map)->he == 'O' ? 0 : 1;
	while (++y < (*map)->rows)
	{
		while (++x < (*map)->columns)
		{
			if ((*map)->field[y][x] == 'X' &&
				(*map)->old[y][x] != 'X' && key)
				(*map)->field[y][x] = (*map)->field[y][x] + 32;
			else if ((*map)->field[y][x] == 'O' &&
				(*map)->old[y][x] != 'O' && !key)
				(*map)->field[y][x] = (*map)->field[y][x] + 32;
		}
		x = -1;
	}
}

void			simplify_cords(t_cord **cords)
{
	int		min_x;
	int		min_y;
	t_cord	*tmp;

	tmp = *cords;
	min_x = ME;
	min_y = ME;
	while (tmp)
	{
		if (tmp->x_cur < min_x)
			min_x = tmp->x_cur;
		if (tmp->y_cur < min_y)
			min_y = tmp->y_cur;
		tmp = tmp->next;
	}
	tmp = *cords;
	while (tmp)
	{
		tmp->x_min = min_x;
		tmp->y_min = min_y;
		tmp->x_nil = tmp->x_cur - min_x;
		tmp->y_nil = tmp->y_cur - min_y;
		tmp = tmp->next;
	}
}

void			chose_the_best_result_and_print_it(t_res_list *res)
{
	int			sum;
	t_res_list	*tmp;

	tmp = res;
	sum = res->sum;
	while (tmp)
	{
		if (tmp->sum < sum)
			sum = tmp->sum;
		tmp = tmp->next;
	}
	tmp = res;
	while (tmp)
	{
		if (tmp->sum == sum)
		{
			ft_printf("%i %i\n",
				tmp->y_fact - tmp->y_min, tmp->x_fact - tmp->x_min);
			return ;
		}
		tmp = tmp->next;
	}
}

int				find_the_best_solution(t_map *map)
{
	t_res_list		*res;
	t_digit_map		*digital_map;
	t_cord			*cords;

	if (map->old)
		find_the_latest_opponent_move(&map);
	digital_map = create_digital_map(map);
	digital_map = fill_with_distance(digital_map);
	cords = create_list_of_figure_cords(map->token);
	if (!(res = create_valid_results(cords, map, digital_map)))
	{
		free_digital_map(digital_map);
		free_cords(cords);
		ft_printf("0 0\n");
		return (1);
	}
	chose_the_best_result_and_print_it(res);
	free_res_list(res);
	free_digital_map(digital_map);
	free_cords(cords);
	return (0);
}
