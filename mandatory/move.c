/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:14:42 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 18:04:45 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_pos_control(t_game *game)
{
	if (game->map->game_map[game->pos->player_y / 64]
		[game->pos->player_x / 64] == _COLLECTIBLE && game->counters->c_count--)
		game->map->game_map[game->pos->player_y / 64]
		[game->pos->player_x / 64] = _GROUND;
	if (game->map->game_map[game->pos->player_y / 64]
		[game->pos->player_x / 64] == _EXIT && game->counters->c_count == 0)
	{
		ft_printf("Look Up! You're Flying 🎈🥳");
		exit(0);
	}
}

int	is_move(int keycode, t_game *game)
{
	if (keycode == _KEY_A)
		if (game->map->game_map[game->pos->player_y / 64]
			[game->pos->player_x / 64 - 1] != _WALL)
			return (1);
	if (keycode == _KEY_D)
		if (game->map->game_map[game->pos->player_y / 64]
			[game->pos->player_x / 64 + 1] != _WALL)
			return (1);
	if (keycode == _KEY_W)
		if (game->map->game_map[game->pos->player_y / 64 - 1]
			[game->pos->player_x / 64] != _WALL)
			return (1);
	if (keycode == _KEY_S)
		if (game->map->game_map[game->pos->player_y / 64 + 1]
			[game->pos->player_x / 64] != _WALL)
			return (1);
	return (0);
}

void	ft_key_a_d(int keycode, t_game *game)
{
	if (keycode == _KEY_A)
	{
		if (is_move(keycode, game) && ft_printf("Move Step: %d\n",
				game->pos->move++))
		{
			game->pos->direction = 1;
			game->pos->player_x -= 64;
		}
	}
	if (keycode == _KEY_D)
	{
		if (is_move(keycode, game) && ft_printf("Move Step: %d\n",
				game->pos->move++))
		{
			game->pos->direction = 0;
			game->pos->player_x += 64;
		}
	}
}
