/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 15:22:26 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 15:22:29 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_res_list	*create_new_res_elem(void)
{
	t_res_list	*new;

	new = (t_res_list*)malloc(sizeof(t_res_list));
	new->key = 0;
	new->sum = 0;
	new->next = NULL;
	return (new);
}

t_map		*create_map_template(void)
{
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	map->field = NULL;
	map->old = NULL;
	map->token = NULL;
	map->figure = NULL;
	map->stop = 0;
	return (map);
}
