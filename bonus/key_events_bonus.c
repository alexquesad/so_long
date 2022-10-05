/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:58:07 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 02:22:01 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	mlx_close(t_params *param)
{
	finish_game(param, "Game closed! (X)\n");
	return (0);
}

int	key_press(int key, t_params *param)
{
	int	init_steps;

	init_steps = param->game.count_steps;
	if (key == ESC)
	{
		finish_game(param, "Game closed! (ESC)\n");
	}
	else
	{
		if (param->enemy_exist)
			step_into_enemy(key, param);
		move(key, param);
	}
	if (init_steps != param->game.count_steps)
	{
		ft_putstr_fd("Steps: ", 1);
		ft_putnbr_fd(param->game.count_steps, 1);
		ft_putchar_fd('\n', 1);
	}	
	print_map(*param);
	return (0);
}

int	move(int key, t_params *param)
{
	if ((key == A_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x - 1] == 'E'))
		check_collect(param);
	else if ((key == A_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x - 1] != '1'))
		move_left(param);
	if ((key == D_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x + 1] == 'E'))
		check_collect(param);
	else if ((key == D_KEY)
		&& (param->map.tab[param->img.pos.y][param->img.pos.x + 1] != '1'))
		move_right(param);
	if ((key == S_KEY)
		&& (param->map.tab[param->img.pos.y + 1][param->img.pos.x] == 'E'))
		check_collect(param);
	else if ((key == S_KEY)
		&& (param->map.tab[param->img.pos.y + 1][param->img.pos.x] != '1'))
		move_down(param);
	if ((key == W_KEY)
		&& (param->map.tab[param->img.pos.y - 1][param->img.pos.x] == 'E'))
		check_collect(param);
	else if ((key == W_KEY)
		&& (param->map.tab[param->img.pos.y - 1][param->img.pos.x] != '1'))
		move_up(param);
	return (0);
}
