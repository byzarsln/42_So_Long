/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:48:55 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/01 16:16:43 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	ft_mouse_exit(t_game *game)
{
	(void)game;
	ft_printf("Exit Successful");
	return (1);
}

static int	ft_get_keycode(int keycode, t_game *game)
{
	if (keycode == _KEY_EXIT || keycode == _KEY_ESC)
	{
		//system("leaks a.out");
		ft_printf("Exit Successful");
		exit(1);
	}
	if (keycode == _KEY_S)
		if (is_move(keycode, game) && ft_printf("Move Step: %d\n",
				game->pos->move++))
			game->pos->player_y += 64;
	if (keycode == _KEY_W)
		if (is_move(keycode, game) && ft_printf("Move Step: %d\n",
				game->pos->move++))
			game->pos->player_y -= 64;
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
	y = -1;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->image->ground_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _WALL)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->wall_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->coll_img, x * 64, y * 64);
			if (game->map->game_map[y][x] == _EXIT)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->exit_img, x * 64, y * 64);
		}
	}
	ft_direction(game);
	put_str(game);
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
