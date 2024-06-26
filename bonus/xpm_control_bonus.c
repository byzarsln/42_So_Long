/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 18:06:30 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 18:02:06 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_exit(int err)
{
	if (err == _COLLECT_XPM && ft_printf("collect.xpm not found!"))
		exit(1);
	if (err == _COLLECT1_XPM && ft_printf("collect1.xpm not found!"))
		exit(1);
	if (err == _COLLECT2_XPM && ft_printf("collect2.xpm not found!"))
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
}

static int	ft_xpm_control(void)
{
	int	fd;

	fd = open("./textures/bonus/collect.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_COLLECT_XPM);
	fd = open("./textures/bonus/collect1.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_COLLECT1_XPM);
	fd = open("./textures/bonus/collect2.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_COLLECT2_XPM);
	fd = open("./textures/bonus/enemy_l.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_ENEMY_L_XPM);
	fd = open("./textures/bonus/enemy_r.xpm", O_RDONLY);
	if (fd < 0 && close(fd))
		ft_exit(_ENEMY_R_XPM);
	ft_xpm_control2();
	return (1);
}

static void	ft_get_path_xpm2(t_game *game)
{
	int	x;
	int	y;

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
}

void	ft_get_path_xpm(t_game *game)
{
	int	x;
	int	y;

	game->image = ft_calloc(1, sizeof(t_textures));
	if (ft_xpm_control())
	{
		game->image->coll_img = ft_calloc(4, sizeof(void *));
		game->image->coll_img[0] = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/collect1.xpm", &x, &y);
		game->image->coll_img[1] = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/collect.xpm", &x, &y);
		game->image->coll_img[2] = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/collect2.xpm", &x, &y);
		game->image->coll_img[3] = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/collect.xpm", &x, &y);
		game->image->enemy_l_img = mlx_xpm_file_to_image(game->mlx,
				"./texture/bonus/enemy_l.xpm", &x, &y);
		game->image->enemy_r_img = mlx_xpm_file_to_image(game->mlx,
				"./textures/bonus/enemy_r.xpm", &x, &y);
		ft_get_path_xpm2(game);
	}
}
