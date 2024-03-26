/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:07:07 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/26 19:14:27 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_Printf/ft_printf.h"
# include "lib/Get_Next_Line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include "fcntl.h"

# define _ELEMENTS "10PEC"
# define _PLAYER 'P'
# define _EXIT 'E'
# define _COLLECTIBLE 'C'
# define _WALL '1'
# define _GROUND '0'


typedef struct s_locate
{
	int	player_x;
	int	player_y;
	int	exit_x;
	int	exit_y;
	int	move;
	int	direction;
}			t_locate;

typedef struct s_count
{
	int	c_count;
	int p_count;
	int e_count;
}			t_counter;

typedef struct s_map
{
	char	**game_map;
	int		map_x;
	int		map_y;
}			t_map;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_window;
	t_map		*map;
	t_counter	*counters;
	t_locate	*pos;
}				t_game;


#endif