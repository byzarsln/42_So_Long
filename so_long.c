/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:06:46 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/29 18:01:44 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_mouse_exit(t_game *game)
{
	ft_printf("Exit Successful");
	exit(1);
}

void	ft_pos_control(t_game *game)
{
	if(game->map->game_map[game->pos->player_y / 64][game->pos->player_x / 64] == _COLLECTIBLE && game->counters->c_count--)
		game->map->game_map[game->pos->player_y / 64][game->pos->player_x / 64] = _GROUND;
	if(game->map->game_map[game->pos->player_y / 64][game->pos->player_x / 64] == _EXIT && game->counters->c_count == 0)
	{
		ft_printf("Look Up! You're Flying :)");
	}
}

int	is_move(int keycode, t_game *game)
{
	if(keycode == _KEY_A)
		if(game->map->game_map[game->pos->player_y / 64][game->pos->player_x / 64 - 1] != _WALL)
			return(1);
	if(keycode == _KEY_D)
		if(game->map->game_map[game->pos->player_y / 64][game->pos->player_x / 64 + 1] != _WALL)
			return(1);
	if(keycode == _KEY_W)
		if(game->map->game_map[game->pos->player_y / 64 - 1][game->pos->player_x / 64] != _WALL)
			return(1);
	if(keycode == _KEY_S)
		if(game->map->game_map[game->pos->player_y / 64 + 1][game->pos->player_x / 64] != _WALL)
			return(1);
	return(0);
}

void	ft_key_a_d(int keycode, t_game *game)
{
	if(keycode == _KEY_A)
	{
		if(is_move(keycode, game) && ft_printf("Move Step: %d\n",
		game->pos->move++))
		{
			game->pos->direction = 1;
			game->pos->player_x -= 64;
		}
	}
	if(keycode == _KEY_D)
	{
		if(is_move(keycode, game) && ft_printf("Move Step: %d\n",
		game->pos->move++))
		{
			game->pos->direction = 0;
			game->pos->player_x += 64;
		}
	}
}

int	ft_get_keycode(int keycode, t_game *game)
{
	if (keycode == _KEY_EXIT || keycode == _KEY_ESC)
	{
		ft_printf("Exit Successful");
		exit(1);
	}
	if (keycode == _KEY_S)
		if(is_move(keycode, game) && ft_printf("Move Step: %d\n",
			game->pos->move++))
			game->pos->player_y += 64;
	if(keycode == _KEY_W)
		if(is_move(keycode, game) && ft_printf("Move Step: %d\n",
			game->pos->move++))
			game->pos->player_y -= 64;
	if(keycode == _KEY_A || keycode == _KEY_D)
		ft_key_a_d(keycode, game);
	ft_pos_control(game);
	return(0);
}

static void	ft_direction(t_game *game)
{
	if(game->pos->direction == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_left_img, game->pos->player_x, game->pos->player_y);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_right_img, game->pos->player_x, game->pos->player_y);
	if(game->counters->c_count > 0)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->coll_img, game->pos->exit_x, game->pos->exit_y);
	//ELSE KOY!!!!!!!!
}
static int	ft_put_image(t_game *game)
{
	int	x;
	int	y;

	mlx_clear_window(game->mlx, game->mlx_window);
	y = -1;
	while(++y < game->map->map_y)
	{
		x = -1;
		while(++x < game->map->map_x)
		{
			mlx_put_image_to_window(game->mlx, game->mlx_window,
				game->image->ground_img, x * 64, y * 64);
			if(game->map->game_map[y][x] == _WALL)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->wall_img, x * 64, y * 64);
			if(game->map->game_map[y][x] == _COLLECTIBLE)
				mlx_put_image_to_window(game->mlx, game->mlx_window,
					game->image->coll_img, x * 64, y * 64);
		}
	}
	ft_direction(game);
	return(0);
}

void	ft_exit(int err, t_game *game)
{
	if (err == _COLLECT_XPM && ft_printf("collect.xpm not found!"))
		exit(1);
	if (err == _GROUND_XPM && ft_printf("ground.xpm not found!"))
		exit(1);
	if (err == _WALL_XPM && ft_printf("wall.xpm not found!"))
		exit(1);
	if (err == _PLAYER_L_XPM && ft_printf("player_l.xpm not found!"))
		exit(1);
	if (err == _PLAYER_R_XPM && ft_printf("player_r.xpm not found!"))
		exit(1);
	// if (err == _EXIT_XPM && ft_printf("exit.xpm not found!"))
	// 	exit(1);
	// EXITFULL KONTROLÜ VE TANIMLAMASI YAP!!!!!!
}

static int	ft_xpm_control(t_game *game)
{
	int	fd;

	fd = open("textures/collect.xpm", O_RDONLY);
	if(fd < 0 && close(fd))
		ft_exit(_COLLECT_XPM,game);
	fd = open("textures/wall.xpm", O_RDONLY);
	if(fd < 0 && close(fd))
		ft_exit(_WALL_XPM,game);
	fd = open("textures/ground.xpm", O_RDONLY);
	if(fd < 0 && close(fd))
		ft_exit(_GROUND_XPM,game);
	fd = open("textures/player_l.xpm", O_RDONLY);
	if(fd < 0 && close(fd))
		ft_exit(_PLAYER_L_XPM,game);
	fd = open("textures/player_r.xpm", O_RDONLY);
	if(fd < 0 && close(fd))
		ft_exit(_PLAYER_R_XPM,game);
	fd = open("textures/exit.xpm", O_RDONLY);
	// if(fd < 0 && close(fd))
	// 	ft_exit(_EXIT_XPM,game);
	return (1);
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;
	
	game->image = ft_calloc(1, sizeof(t_textures));
	if(ft_xpm_control(game))
	{
		game->image->coll_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collect.xpm", &x, &y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,
			"textures/ground.xpm", &x, &y);
		game->image->player_left_img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_l.xpm", &x, &y);
		game->image->player_right_img = mlx_xpm_file_to_image(game->mlx,
			"textures/player_r.xpm", &x, &y);
		game->image->wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &x, &y);
	}
}

void	ft_dispose_map(t_map *tmp_map)
{
	int	i;

	i = -1;
	if(!tmp_map)
		return ;
	while(++i < tmp_map->map_y)
		free(tmp_map->game_map[i]);
	free(tmp_map->game_map);
}

void	is_reachable(t_map *tmp_map)
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

void	ft_frame_control(t_game *game)
{
	int	x;
	int	y;

	x = -1;
	y = -1;
	while(++y < game->map->map_y)
	{
		if(game->map->game_map[y][0] != _WALL
			|| game->map->game_map[y][game->map->map_x - 1] != _WALL)
		{
			ft_printf("The borders of the map have to be a wall!");
			exit(1);
		}
	}
	while(++x < game->map->map_x)
	{
		if(game->map->game_map[0][x] != _WALL
			|| game->map->game_map[game->map->map_y - 1][x] != _WALL)
		{
			ft_printf("The borders of the map have to be a wall!");
			exit(1);
		}
	}
	ft_create_window(game);
}

void	ft_char_count_cont(t_game *game)
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
	ft_frame_control(game);
}

void	ft_map_char_cont(t_game *game)
{
	int	x;
	int	y;
	
	y = -1;
	game->counters = ft_calloc(1, sizeof(t_counter));
	if(!game->counters 
		&& ft_printf("Failed to allocate counters memory space!"))
		exit(1);
	while(++y < game->map->map_y)
	{
		x = -1;
		while(++x < game->map->map_x)
		{
			if((ft_strchr(_ELEMENTS, game->map->game_map[y][x]) == 0 )
				&& ft_printf("Unrecognized character in map file"))
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

void	ft_window_size(t_game *game)
{
	if (game->map->map_x > 25 || game->map->map_y > 15)
	{
		ft_printf("Window size is too big!");
		exit(1);
	}
	else if (game->map->map_x == 0 || game->map->map_y == 0)
	{
		ft_printf("Map file cannot be left empty!");
		exit(1);
	}
	
}

static void	ft_game_map_check(t_game *game)
{
	int	y;
	int	control_line;

	y = -1;
	while(++y < game->map->map_y)
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
	game->map = ft_calloc(1, sizeof(t_map));
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
