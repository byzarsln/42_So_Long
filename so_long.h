/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyarsla <beyarsla@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 13:07:07 by beyarsla          #+#    #+#             */
/*   Updated: 2024/03/24 16:22:37 by beyarsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_Printf/ft_printf.h"
# include "lib/Get_Next_Line/get_next_line.h"
# include "lib/libft/libft.h"
# include "lib/mlx/mlx.h"
# include "fcntl.h"


typedef struct s_map
{
	char	**game_map;
	int		map_x;
	int		map_y;
}			t_map;

typedef struct s_game
{
	void	*mlx;
	void	*mlx_window;
	t_map	*map;
}				t_game;


#endif