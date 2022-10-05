/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:59:17 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 02:19:06 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	player_init_pos(t_params *param)
{
	int		row;
	int		col;

	row = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (col <= param->map.size.x)
		{
			if (param->map.tab[row][col] == 'P')
			{
				param->img.pos.x = col;
				param->img.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	count_collect(t_params *param)
{
	int		row;
	int		col;

	row = 0;
	param->game.count_collec = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (col <= param->map.size.x)
		{
			if (param->map.tab[row][col] == 'C')
				param->game.count_collec++;
			col++;
		}
		row++;
	}
	return (param->game.count_collec);
}

int	check_collect(t_params *param)
{
	if (count_collect(param) == 0)
	{
		finish_game(param, "YOU WON!!!!!\n");
	}
	else
		ft_putstr_fd("Gotta catch them all!\n", 1);
	return (0);
}

int	print_steps(t_params *param)
{
	char	*str;

	str = ft_itoa(param->game.count_steps);
	mlx_string_put(param->mlx, param->win, (param->img.pos.x * SPRITE_W) + 5,
		(param->img.pos.y * SPRITE_H) + 10, 0x833000, str);
	free(str);
	return (0);
}

int	finish_game(t_params *param, char *msg)
{
	ft_putstr_fd(msg, 1);
	free_map(param);
	exit(EXIT_SUCCESS);
}
