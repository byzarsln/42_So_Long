/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:42:50 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 14:27:57 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	ft_frame_control(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while (++y < game->map->map_y)
	{
		if (game->map->game_map[y][0] != _WALL
			|| game->map->game_map[y][game->map->map_x - 1] != _WALL)
		{
			ft_printf("The borders of the map have to be a wall!");
			exit(1);
		}
	}
	while (++x < game->map->map_x)
	{
		if (game->map->game_map[0][x] != _WALL
			|| game->map->game_map[game->map->map_y - 1][x] != _WALL)
		{
			ft_printf("The borders of the map have to be a wall!");
			exit(1);
		}
	}
	ft_create_window(game);
}

static void	ft_char_count_cont(t_game *game)
{
	if (game->counters->p_count != 1
		&& ft_printf("There must be one player in the game!"))
		exit(1);
	if (game->counters->e_count != 1
		&& ft_printf("There must be one exit in the game!"))
		exit(1);
	if (game->counters->c_count < 1
		&& ft_printf("At least one must be collectible!"))
		exit(1);
	if (game->counters->x_count != 1
		&& ft_printf("There must be one enemy in the game!"))
		exit(1);
	ft_frame_control(game);
}

void	ft_map_char_cont2(t_game *game, int x, int y)
{
	if ((ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0)
		&& ft_printf("Unrecognized character in map file"))
		exit(1);
	else if (game->map->game_map[y][x] == _PLAYER)
		game->counters->p_count++;
	else if (game->map->game_map[y][x] == _EXIT)
		game->counters->e_count++;
	else if (game->map->game_map[y][x] == _COLLECTIBLE)
		game->counters->c_count++;
	else if (game->map->game_map[y][x] == _ENEMY)
		game->counters->x_count++;
}

void	ft_map_char_cont(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	game->counters = ft_calloc(1, sizeof(t_counter));
	if (!game->counters
		&& ft_printf("Failed to allocate counters memory space!"))
		exit(1);
	while (++y < game->map->map_y)
	{
		x = -1;
		while (++x < game->map->map_x)
		{
			ft_map_char_cont2(game, x, y);
		}
	}
	ft_char_count_cont(game);
}
