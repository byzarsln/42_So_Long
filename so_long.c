/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:06:46 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/25 18:45:46 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_char_count_cont(t_game *game)
{
	if (game->counters->p_count != 1 && ft_printf("There must be one player in the game!"))
		exit(1);
	if (game->counters->e_count != 1 && ft_printf("There must be one exit in the game!"))
		exit(1);
	if (game->counters->c_count < 1 && ft_printf("At least one must be collectible!"))
		exit(1);
	ft_printf("%d\n", game->counters->p_count);
	ft_printf("%d\n", game->counters->e_count);
	ft_printf("%d\n", game->counters->c_count);
}

void ft_map_char_cont(t_game *game)
{
	int	x;
	int	y;
	
	y = -1;
	game->counters = malloc(sizeof(t_counter));
	if(!game->counters 
		&& ft_printf("Failed to allocate counters memory space!"))
		exit(1);
	while(y++ < game->map->map_y)
	{
		x = -1;
		while(x++ < game->map->map_x)
		{
			if((ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0 )
				&& ft_printf("Unrecognized character in map file %d %d\n", y, x))
				exit(1);
			else if(game->map->game_map[y][x] == _PLAYER)
				game->counters->p_count++;
			else if(game->map->game_map[y][x] == _EXIT)
				game->counters->e_count++;
			else if(game->map->game_map[y][x] == _COLLECTIBLE)
				game->counters->c_count++;
		}
	}
	ft_char_count_cont(game);
}

void ft_window_size(t_game *game)
{
	if (game->map->map_x > 25 || game->map->map_y > 15)
	{
		ft_printf("Window size is too big!");
		exit(1);
	}
}

static void ft_game_map_check(t_game *game)
{
	int	y;
	int	control_line;

	y = 0;
	while(y < game->map->map_y)
	{
		control_line = ft_strlen(game->map->game_map[y++]);
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
	while(y < game->map->map_y)
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
	game->map = malloc(sizeof(t_map));
	if (!game->map && ft_printf("Failed to allocate map memory space!"))
		exit(1);
	fd = open(map_name, O_RDONLY);
	game->map->map_y = 0;
	game->map->map_x = 0;
	while(1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
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

int	main(int argc, char **argv)
{
	if (argc == 2)
		ber_check(argv[1]);
	else
		ft_printf("Invalid arguments");
}
