/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:22:07 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 15:22:10 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_token(t_map **map)
{
	int	i;

	i = -1;
	while ((*map)->token[++i])
		free((*map)->token[i]);
	free((*map)->token);
}

void	free_res_list(t_res_list *head)
{
	t_res_list	*del;

	while (head)
	{
		del = head;
		head = head->next;
		free(del);
	}
}

void	free_cords(t_cord *head)
{
	t_cord	*del;

	while (head)
	{
		del = head;
		head = head->next;
		free(del);
	}
}

void	free_digital_map(t_digit_map *map)
{
	int		i;

	i = -1;
	while (++i < map->rows)
		free(map->map[i]);
	free(map->map);
	free(map);
}

void	free_double_array(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}
