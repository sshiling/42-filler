/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshiling <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/22 14:13:05 by sshiling          #+#    #+#             */
/*   Updated: 2018/03/22 14:13:07 by sshiling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct			s_map
{
	char				**field;
	char				**old;
	char				**token;
	char				**figure;
	char				me;
	char				he;
	int					stop;
	int					columns;
	int					rows;
}						t_map;

typedef struct			s_digit_map
{
	int					**map;
	int					columns;
	int					rows;
}						t_digit_map;

typedef struct			s_res_list
{
	int					x_min;
	int					y_min;
	int					x_fact;
	int					y_fact;
	int					sum;
	int					key;
	struct s_res_list	*next;
}						t_res_list;

typedef struct			s_cord
{
	int					x_cur;
	int					y_cur;
	int					x_nil;
	int					y_nil;
	int					x_min;
	int					y_min;
	int					key;
	struct s_cord		*next;
}						t_cord;

#endif
