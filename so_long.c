/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:06:46 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/24 17:05:25 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_get_map_size(char *map_name)
{
	int		fd;
	char	*line;
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game && ft_printf("Failed to allocate memory space!"))
		exit(1);
	game->map = malloc(sizeof(t_map));
	if (!game->map && ft_printf("Failed to allocate memory space!"))
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
	ft_printf("%d\n",game->map->map_x);
	ft_printf("%d",game->map->map_y);
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
