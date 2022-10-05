/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:11:02 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 00:14:51 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_enemy(t_params *param)
{
	int		row;
	int		col;

	row = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (param->map.tab[row][col])
		{
			if (param->map.tab[row][col] == 'R')
				param->enemy_exist++;
			col++;
		}
		row++;
	}
	return (0);
}

int	get_enemy_position(t_params *param)
{
	int		row;
	int		col;

	row = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (col <= param->map.size.x)
		{
			if (param->map.tab[row][col] == 'R')
			{
				param->enemy.pos.x = col;
				param->enemy.pos.y = row;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	step_into_enemy(int key, t_params *param)
{
	if ((key == A_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x - 1] == 'R'))
	{
		finish_game(param, "GAME OVER!!!\nTeam Rocket got you!");
	}
	if ((key == D_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x + 1] == 'R'))
	{
		finish_game(param, "GAME OVER!!!\nTeam Rocket got you!");
	}
	if ((key == S_KEY)
		&& (param->map.tab[param->img.pos.y + 1][param->img.pos.x] == 'R'))
	{
		finish_game(param, "GAME OVER!!!\nTeam Rocket got you!");
	}
	if ((key == W_KEY)
		&& (param->map.tab[param->img.pos.y - 1][param->img.pos.x] == 'R'))
	{
		finish_game(param, "GAME OVER!!!\nTeam Rocket got you!");
	}
	return (0);
}

int	enemy_animation(t_params *param)
{
	if (param->enemy.pos.x % 2 == 0)
		param->img.img_ptr = mlx_xpm_file_to_image(param->mlx, \
		"./img/rocket_front.xpm", &param->img.size.x, &param->img.size.y);
	else
		param->img.img_ptr = mlx_xpm_file_to_image(param->mlx, \
		"./img/rocket_side.xpm", &param->img.size.x, &param->img.size.y);
	return (0);
}
