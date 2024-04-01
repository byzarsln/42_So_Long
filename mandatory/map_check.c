/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 17:39:43 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/01 14:25:22 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_game_map_check(t_game *game)
{
	int	y;
	int	control_line;

	y = -1;
	while (++y < game->map->map_y)
	{
		control_line = ft_strlen(game->map->game_map[y]);
		if ((control_line != game->map->map_x)
			&& ft_printf("The map length is inconsistent"))
			exit(1);
	}
	ft_window_size(game);
	ft_map_char_cont(game);
}

static void	ft_read_map(char *map, t_game *game)
{
	int	y;
	int	fd;

	y = 0;
	game->map->game_map = malloc(sizeof(char *) * game->map->map_y);
	if (!game->map->game_map
		&& ft_printf("Failed to allocate map memory space!"))
		exit(1);
	fd = open(map, O_RDONLY);
	while (y < game->map->map_y)
		game->map->game_map[y++] = get_next_line(fd);
	close(fd);
	ft_game_map_check(game);
}

static void	ft_get_map_size(char *map_name)
{
	int		fd;
	char	*line;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game && ft_printf("Failed to allocate game memory space!"))
		exit(1);
	game->map = ft_calloc(1, sizeof(t_map));
	if (!game->map && ft_printf("Failed to allocate map memory space!"))
		exit(1);
	fd = open(map_name, O_RDONLY);
	game->map->map_y = 0;
	game->map->map_x = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map->map_x = ft_strlen(line);
		game->map->map_y++;
		free(line);
	}
	free(line);
	close(fd);
	ft_read_map(map_name, game);
}

void	ber_check(char *map_name)
{
	int	i;
	int	fd;

	i = ft_strlen(map_name);
	if ((i >= 4) && map_name[--i] == 'r' && map_name[--i] == 'e'
		&& map_name[--i] == 'b' && map_name[--i] == '.')
	{
		fd = open(map_name, O_RDONLY);
		if (fd < 3 && close(fd) && ft_printf("Map cannot be opened!"))
			exit(1);
		else
		{
			close(fd);
			ft_get_map_size(map_name);
		}
	}
	else
	{
		if (!map_name[0])
			ft_printf("Map name cannot be left blank!");
		else
			ft_printf("Invalid file extension");
		exit(1);
	}
}
