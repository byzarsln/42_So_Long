/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyza <beyza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:07:07 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/02 13:48:59 by beyza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../lib/ft_Printf/ft_printf.h"
# include "../lib/Get_Next_Line/get_next_line.h"
# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include "fcntl.h"

# define _ELEMENTS "10PECX"
# define _PLAYER 'P'
# define _EXIT 'E'
# define _COLLECTIBLE 'C'
# define _ENEMY 'X'
# define _WALL '1'
# define _GROUND '0'
# define _COLLECT_XPM 1
# define _WALL_XPM 2
# define _GROUND_XPM 3
# define _PLAYER_L_XPM 4
# define _PLAYER_R_XPM 5
# define _EXIT_XPM 6
# define _ENEMY_L_XPM 7
# define _ENEMY_R_XPM 7

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
	void	*enemy_l_img;
	void	*enemy_r_img;
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
	int	p_count;
	int	e_count;
}		t_counter;

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

void	ber_check(char *map_name);
void	ft_window_size(t_game *game);
void	ft_map_char_cont(t_game *game);
void	ft_create_window(t_game *game);
void	ft_get_cords(t_game *game);
void	ft_copy_map(t_game *game);
void	flood_fill(t_map *tmp_map, int y, int x);
void	ft_get_path_xpm(t_game *game);
void	ft_direction(t_game *game);
int		is_move(int keycode, t_game *game);
void	ft_key_a_d(int keycode, t_game *game);
void	ft_pos_control(t_game *game);
int		put_move(t_game *game);

#endif