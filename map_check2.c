/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:55:47 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/30 18:53:06 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_dispose_map(t_map *tmp_map)
{
	int	i;

	i = -1;
	if(!tmp_map)
		return ;
	while(++i < tmp_map->map_y)
		free(tmp_map->game_map[i]);
	free(tmp_map->game_map);
}


static void	is_reachable(t_map *tmp_map)
{
	int	x;
	int	y;

	y = -1;
	while(++y < tmp_map->map_y)
	{
		x = -1;
		while(++x < tmp_map->map_x)
		{
			if(tmp_map->game_map[y][x] == _EXIT)
			{
				ft_printf("Exit is not reachable!");
				exit(1);
			}
			else if(tmp_map->game_map[y][x] == _COLLECTIBLE)
			{
				ft_printf("Collectible is not reachable!");
				exit(1);
			}
		}
	}
	ft_dispose_map(tmp_map);
}

void	ft_copy_map(t_game *game)
{
	t_map	tmp_map;
	int	i;

	tmp_map.game_map = malloc(sizeof(char *) * game->map->map_y);
	if(!tmp_map.game_map && ft_printf("Failed to allocate memory space!"))
		exit(1);
	i = -1;
	while(++i < game->map->map_y)
		tmp_map.game_map[i] = ft_strdup(game->map->game_map[i]);
	tmp_map.map_x = game->map->map_x;
	tmp_map.map_y = game->map->map_y;
	flood_fill(&tmp_map, game->pos->player_y / 64, game->pos->player_x / 64);
	is_reachable(&tmp_map);
}

void	ft_get_cords(t_game *game)
{
	int	h;
	int	w;

	h = -1;
	game->pos = calloc(1, sizeof(t_locate));
	if(!game->pos && ft_printf("Failed to allocate pos memory space!"))
		exit(1);
	while(++h < game->map->map_y)
	{
		w = -1;
		while(++w < game->map->map_x)
		{
			if (game->map->game_map[h][w] == _PLAYER)
			{
				game->pos->player_x = w * 64;
				game->pos->player_y = h * 64;
			}
			else if (game->map->game_map[h][w] == _EXIT)
			{
				game->pos->exit_x = w * 64;
				game->pos->exit_y = h * 64;
			}
		}
	}
}
