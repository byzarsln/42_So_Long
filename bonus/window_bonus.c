/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:48:55 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 18:25:13 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_mouse_exit(void)
{
	ft_printf("Exit Successful");
	exit(1);
}

static int	ft_get_keycode(int keycode, t_game *game)
{
	if (keycode == _KEY_EXIT || keycode == _KEY_ESC)
	{
		ft_printf("Exit Successful");
		exit(1);
	}
	if (keycode == _KEY_S)
	{
		if (is_move(keycode, game))
		{
			game->pos->player_y += 64;
			game->pos->move++;
		}
	}
	if (keycode == _KEY_W)
	{
		if (is_move(keycode, game))
		{
			game->pos->player_y -= 64;
			game->pos->move++;
		}
	}
	if (keycode == _KEY_A || keycode == _KEY_D)
		ft_key_a_d(keycode, game);
	ft_pos_control(game);
	return (0);
}

static int	ft_put_image(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->mlx_window);
	whereisenemy(game);
	y = -1;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			mlxput_img(game, x, y);
		}
	}
	ft_direction(game);
	put_move(game);
	return (0);
}

void	ft_create_window(t_game *game)
{
	game->mlx = mlx_init();
	ft_get_cords(game);
	ft_copy_map(game);
	game->mlx_window = mlx_new_window(game->mlx, game->map->map_x * 64,
			game->map->map_y * 64, "SO_LONG");
	ft_get_path_xpm(game);
	mlx_loop_hook(game->mlx, ft_put_image, game);
	mlx_key_hook(game->mlx_window, ft_get_keycode, game);
	mlx_hook(game->mlx_window, 17, 0, ft_mouse_exit, game);
	mlx_loop(game->mlx);
}
