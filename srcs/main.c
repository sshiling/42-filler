/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:31:41 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/06 18:31:43 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_old_field(t_map **map)
{
	int	i;

	i = -1;
	while ((*map)->old[++i])
		free((*map)->old[i]);
	free((*map)->old);
}

void	set_current_field_as_old(t_map **map)
{
	(*map)->old = (*map)->field;
	(*map)->field = NULL;
}

int		read_args_and_give_solutions(t_map **map, char **line, int fd)
{
	int		key;

	key = 1;
	if (get_next_line(fd, line) < 1)
		return (0);
	if (ft_strstr(*line, "Plateau"))
		get_field(map, line, fd);
	if (get_next_line(fd, line) < 1)
		return (0);
	if (ft_strstr(*line, "Piece"))
		key = get_token(map, line, fd);
	if (!key)
	{
		if (find_the_best_solution(*map))
			return (0);
		if ((*map)->old)
			free_old_field(map);
		set_current_field_as_old(map);
		free_token(map);
	}
	return (1);
}

int		main(void)
{
	t_map	*map;
	char	*line;
	int		fd;

	line = NULL;
	fd = 0;
	map = create_map_template();
	map->me = get_player(fd);
	map->he = map->me == 'O' ? 'X' : 'O';
	while (1)
	{
		if (!read_args_and_give_solutions(&map, &line, fd))
			break ;
	}
	return (0);
}
