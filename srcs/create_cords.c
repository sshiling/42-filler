/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 16:29:50 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 16:29:52 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_cord			*create_new_cords_elem(void)
{
	t_cord	*new;

	new = (t_cord*)malloc(sizeof(t_cord));
	new->key = 0;
	new->next = NULL;
	return (new);
}

void			fill_list_of_cords_with_data(char **token, t_cord **head)
{
	t_cord	*tmp;
	int		x;
	int		y;

	x = -1;
	y = -1;
	tmp = *head;
	while (token[++y])
	{
		while (token[y][++x])
		{
			if (token[y][x] == '*')
			{
				if (tmp->key)
				{
					tmp->next = create_new_cords_elem();
					tmp = tmp->next;
				}
				tmp->y_cur = y;
				tmp->x_cur = x;
				tmp->key = 1;
			}
		}
		x = -1;
	}
}

t_cord			*create_list_of_figure_cords(char **token)
{
	t_cord	*head;

	head = create_new_cords_elem();
	fill_list_of_cords_with_data(token, &head);
	simplify_cords(&head);
	return (head);
}
