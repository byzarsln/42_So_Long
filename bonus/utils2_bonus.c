/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 16:06:03 by beyarsla          #+#    #+#             */
/*   Updated: 2024/04/01 16:20:43 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_str(t_game *game)
{
	char	*move;

	move = ft_itoa(game->pos->move);
	mlx_string_put(game->mlx, game->mlx_window, 15, 15, 0x000000, "Move Step: ");
	mlx_string_put(game->mlx, game->mlx_window, 90, 15, 0x000000, move);
	free(move);
	return (0);
}