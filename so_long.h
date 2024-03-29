/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:07:07 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/29 17:35:43 by beyarsla         ###   ########.fr       */
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
# define _COLLECT_XPM 1
# define _WALL_XPM 2
# define _GROUND_XPM 3
# define _PLAYER_L_XPM 4
# define _PLAYER_R_XPM 5
# define _EXIT_XPM 6

# define _KEY_EXIT 17

# ifndef _KEY_A
#  define _KEY_A 0
# endif

# ifndef _KEY_S
#  define _KEY_S 1
# endif

# ifndef _KEY_D
#  define _KEY_D 2
# endif

# ifndef _KEY_W
#  define _KEY_W 13
# endif




# ifndef _KEY_ESC
#  define _KEY_ESC 53
# endif


typedef struct s_texture
{
	void	*player_right_img;
	void	*player_left_img;
	void	*exit_img;
	void	*exit_full_img;
	void	*coll_img;
	void	*ground_img;
	void	*wall_img;
	
}			t_textures;


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
	t_textures	*image;
}				t_game;


#endif