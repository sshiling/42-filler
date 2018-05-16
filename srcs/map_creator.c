/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creator.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/20 14:28:37 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/20 14:28:38 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

char	get_player(int fd)
{
	char	player;
	char	*line;

	line = NULL;
	get_next_line(fd, &line);
	player = ft_atoi(&line[10]) == 1 ? 'O' : 'X';
	ft_strdel(&line);
	return (player);
}

void	read_field_lines(t_map **m, int fd)
{
	char	*line;
	t_map	*map;
	int		i;

	i = -1;
	map = *m;
	line = NULL;
	while (++i < map->rows)
	{
		get_next_line(fd, &line);
		if (map->field[i] != NULL)
			free(map->field[i]);
		map->field[i] = ft_strdup(&(line)[4]);
		ft_strdel(&line);
	}
}

void	get_field(t_map **m, char **line, int fd)
{
	t_map	*map;
	char	**args;
	int		i;

	i = -1;
	map = *m;
	args = ft_strsplit(*line, ' ');
	ft_strdel(line);
	(*m)->rows = ft_atoi(args[1]);
	(*m)->columns = ft_atoi(args[2]);
	free_double_array(args);
	get_next_line(fd, line);
	ft_strdel(line);
	map->field = (char**)malloc(sizeof(char*) * (map->rows + 1));
	map->field[map->rows] = 0;
	while (++i < map->rows)
		map->field[i] = (char*)malloc(sizeof(char) * (map->columns + 1));
	read_field_lines(&map, fd);
}

void	read_token_lines(t_map **m, int rows, int fd)
{
	char	*line;
	t_map	*map;
	int		i;

	i = -1;
	map = *m;
	line = NULL;
	while (++i < rows)
	{
		get_next_line(fd, &line);
		if (map->token[i] != NULL)
			free(map->token[i]);
		map->token[i] = ft_strdup(line);
		ft_strdel(&line);
	}
}

int		get_token(t_map **m, char **line, int fd)
{
	t_map	*map;
	char	**args;
	int		rows;
	int		columns;
	int		i;

	i = -1;
	map = *m;
	args = ft_strsplit(*line, ' ');
	ft_strdel(line);
	rows = ft_atoi(args[1]);
	columns = ft_atoi(args[2]);
	free_double_array(args);
	map->token = (char**)malloc(sizeof(char*) * (rows + 1));
	map->token[rows] = 0;
	while (++i < rows)
		map->token[i] = (char*)malloc(sizeof(char) * (columns + 1));
	read_token_lines(&map, rows, fd);
	return (0);
}
