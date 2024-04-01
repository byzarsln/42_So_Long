/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:04:14 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/01 14:38:57 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_direction(t_game *game)
{
	if (game->pos->direction == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_left_img, game->pos->player_x,
			game->pos->player_y);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_right_img, game->pos->player_x,
			game->pos->player_y);
	if (game->counters->c_count > 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->exit_img, game->pos->exit_x, game->pos->exit_y);
	//ELSE KOY!!!!!!!!
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
