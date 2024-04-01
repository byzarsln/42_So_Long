/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyza <beyza@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:06:03 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/02 00:59:23 by beyza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_move(t_game *game)
{
	char	*move;

	move = ft_itoa(game->pos->move);
	mlx_string_put(game->mlx, game->mlx_window, 15, 15, 0x000000, "Move Step: ");
	mlx_string_put(game->mlx, game->mlx_window, 90, 15, 0x000000, move);
	free(move);
	return (0);
}