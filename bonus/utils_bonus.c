/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:04:14 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 18:02:36 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check(void)
{
	static int	i = 0;

	if (i == 214747832)
		i = 0;
	if (++i % 1077 == 0)
	{
		return (1);
	}
	return (0);
}

void	find_coll(t_game *game)
{
	int			x;
	int			y;
	static int	i = 0;

	y = -1;
	game->image->coll_count = i % 4;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			if (game->map->game_map[y][x] == _COLLECTIBLE)
			{
				if (check())
					i++;
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->coll_img[game->image->coll_count],
					x * 64, y * 64);
			}
		}
	}
}

int	put_anim(t_game *game)
{
	find_coll(game);
	return (0);
}

void	mlxput_img(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->mlx_window,
		game->image->ground_img, x * 64, y * 64);
	if (game->map->game_map[y][x] == _WALL)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->wall_img, x * 64, y * 64);
	if (game->map->game_map[y][x] == _COLLECTIBLE)
		put_anim(game);
	if (game->map->game_map[y][x] == _EXIT)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->exit_img, x * 64, y * 64);
	if (game->map->game_map[y][x] == _ENEMY)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->enemy_r_img, x * 64, y * 64);
}

void	flood_fill(t_map *tmp_map, int y, int x)
{
	if (x < 0 || x > tmp_map->map_x || y < 0 || y > tmp_map->map_y)
		return ;
	if (tmp_map->game_map[y][x] != _WALL && tmp_map->game_map[y][x] != 'F')
	{
		tmp_map->game_map[y][x] = 'F';
		flood_fill(tmp_map, y - 1, x);
		flood_fill(tmp_map, y + 1, x);
		flood_fill(tmp_map, y, x - 1);
		flood_fill(tmp_map, y, x + 1);
	}
}
