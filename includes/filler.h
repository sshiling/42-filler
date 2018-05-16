/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:04:58 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 14:05:04 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# include "structures.h"
# include <stdio.h>
# define ME 999999999

char		get_player(int fd);
void		get_field(t_map **m, char **line, int fd);
int			get_token(t_map **m, char **line, int fd);
int			find_the_best_solution(t_map *map);
t_res_list	*create_valid_results(t_cord *cords, t_map *map,
	t_digit_map *digital_map);
void		free_token(t_map **map);
void		free_res_list(t_res_list *head);
void		free_cords(t_cord *head);
void		free_digital_map(t_digit_map *map);
void		free_double_array(char **array);
void		free_old_field(t_map **map);
void		fill_digital_map_with_data(t_map *map,
	t_digit_map **digital_map, int key);
t_digit_map	*create_digital_map(t_map *map);
t_cord		*create_new_cords_elem(void);
void		fill_list_of_cords_with_data(char **token, t_cord **head);
t_cord		*create_list_of_figure_cords(char **token);
int			check_map_for_possible_moves(t_digit_map *map, int x, int y);
int			there_are_more_possible_moves(t_digit_map *map, int filler);
t_digit_map	*fill_map_with_filler(t_digit_map *map, int x, int y, int filler);
int			find_current_filler(t_digit_map *map);
t_digit_map	*fill_with_distance(t_digit_map *digital_map);
void		find_the_latest_opponent_move(t_map **map);
void		simplify_cords(t_cord **cords);
void		chose_the_best_result_and_print_it(t_res_list *res);
int			find_the_best_solution(t_map *map);
t_map		*create_map_template(void);
t_res_list	*create_new_res_elem(void);

#endif
