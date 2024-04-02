/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyza <beyza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:06:30 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/02 13:51:51 by beyza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(int err)
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
	if (err == _EXIT_XPM && ft_printf("exit.xpm not found!"))
		exit(1);
	if (err == _ENEMY_R_XPM && ft_printf("enemy_r.xpm not found!"))
		exit(1);
	if (err == _ENEMY_L_XPM && ft_printf("enemy_l.xpm not found!"))
		exit(1);
	// EXITFULL KONTROLÜ VE TANIMLAMASI YAP!!!!!!
}

static int	ft_xpm_control()
{
	int	fd;

	fd = open("./textures/bonus/collect.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_COLLECT_XPM);
	fd = open("./textures/bonus/wall.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_WALL_XPM);
	fd = open("./textures/bonus/ground.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_GROUND_XPM);
	fd = open("./textures/bonus/player_l.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_PLAYER_L_XPM);
	fd = open("./textures/bonus/player_r.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_PLAYER_R_XPM);
	fd = open("./textures/bonus/exit.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_EXIT_XPM);
	fd = open("./textures/bonus/enemy_l.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_ENEMY_L_XPM);
	fd = open("./textures/bonus/enemy_r.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_ENEMY_R_XPM);
	return (1);
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image = ft_calloc(1, sizeof(t_textures));
	if (ft_xpm_control())
	{
		game->image->coll_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/collect.xpm", &x, &y);
		game->image->ground_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/ground.xpm", &x, &y);
		game->image->player_left_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/player_l.xpm", &x, &y);
		game->image->player_right_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/player_r.xpm", &x, &y);
		game->image->wall_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/wall.xpm", &x, &y);
		game->image->exit_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/exit.xpm", &x, &y);
		game->image->enemy_l_img = mlx_xpm_file_to_image(game->mlx,
				"./texture/bonus/enemy_l.xpm", &x, &y);
		game->image->enemy_r_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/bonus/enemy_r.xpm", &x, &y);
	}
}
