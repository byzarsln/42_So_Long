/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 16:05:03 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 17:55:16 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	enemy_cords(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			if (game->map->game_map[y][x] == _ENEMY)
			{
				game->pos->enemy_x = x * 64;
				game->pos->enemy_y = y * 64;
			}
		}
	}
}

void	change_dir(t_game *game, int y, int x)
{
	if (game->map->game_map[y][x] == _WALL || game->map->game_map[y]
		[x] == _COLLECTIBLE || game->map->game_map[y][x] == _EXIT ||
			game->map->game_map[y][x] == _ENEMY)
	{
		if (game->pos->e_direction == _DIR_LEFT)
			game->pos->e_direction = _DIR_UP;
		else if (game->pos->e_direction == _DIR_RIGHT)
			game->pos->e_direction = _DIR_LEFT;
		else if (game->pos->e_direction == _DIR_UP)
			game->pos->e_direction = _DIR_DOWN;
		else if (game->pos->e_direction == _DIR_DOWN)
			game->pos->e_direction = _DIR_RIGHT;
	}
}

int	flood_fill_enemy(t_game *game, int y, int x)
{
	if (game->pos->enemy_x / 64 == game->pos->player_x / 64
		&& game->pos->enemy_y / 64 == game->pos->player_y / 64)
	{
		ft_printf("💀 Game Over! 💀\n");
		exit(1);
	}
	if (y < 0 || y > game->map->map_y || x < 0 || x > game->map->map_x)
		return (0);
	change_dir(game, y, x);
	if (game->map->game_map[y][x] != _EXIT && game->map->game_map[y]
		[x] != _WALL && game->map->game_map[y][x] != _COLLECTIBLE &&
		game->map->game_map[y][x] != _ENEMY)
	{
		game->map->game_map[y][x] = _ENEMY;
		return (1);
	}
	return (0);
}

void	whereisenemy2(t_game *game, int i)
{
	if (game->pos->e_direction == _DIR_UP)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64 - 1,
				game->pos->enemy_x / 64))
			game->map->game_map[game->pos->enemy_y / 64]
			[game->pos->enemy_x / 64] = _GROUND;
	}
	else if (game->pos->e_direction == _DIR_DOWN)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64 + 1,
				game->pos->enemy_x / 64))
			game->map->game_map[game->pos->enemy_y / 64]
			[game->pos->enemy_x / 64] = _GROUND;
	}
}

void	whereisenemy(t_game *game)
{
	static int	i = 0;

	enemy_cords(game);
	i++;
	if (game->pos->e_direction == _DIR_LEFT)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64,
				game->pos->enemy_x / 64 - 1))
			game->map->game_map[game->pos->enemy_y / 64]
			[game->pos->enemy_x / 64] = _GROUND;
	}
	else if (game->pos->e_direction == _DIR_RIGHT)
	{
		if (!(i % 30) && flood_fill_enemy(game, game->pos->enemy_y / 64,
				game->pos->enemy_x / 64 + 1))
			game->map->game_map[game->pos->enemy_y / 64]
			[game->pos->enemy_x / 64] = _GROUND;
	}
	whereisenemy2(game, i);
}
