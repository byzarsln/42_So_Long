/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:06:03 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/05 18:00:00 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_direction(t_game *game)
{
	if (game->pos->direction == 1)
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_left_img, game->pos->player_x,
			game->pos->player_y);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_window,
			game->image->player_right_img, game->pos->player_x,
			game->pos->player_y);
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

void	ft_xpm_control2(void)
{
	int	fd;

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
}

int	put_move(t_game *game)
{
	char	*move;

	move = ft_itoa(game->pos->move);
	mlx_string_put(game->mlx, game->mlx_window, 15, 15,
		0x000000, "Move Step: ");
	mlx_string_put(game->mlx, game->mlx_window, 90, 15, 0x000000, move);
	free(move);
	return (0);
}
