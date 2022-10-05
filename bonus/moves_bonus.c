/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:34:30 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 00:09:47 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	move_left(t_params *param)
{
	param->map.tab[param->img.pos.y][param->img.pos.x] = '0';
	param->img.pos.x -= 1;
	param->map.tab[param->img.pos.y][param->img.pos.x] = 'P';
	param->game.count_steps++;
	return (0);
}

int	move_right(t_params *param)
{
	param->map.tab[param->img.pos.y][param->img.pos.x] = '0';
	param->img.pos.x += 1;
	param->map.tab[param->img.pos.y][param->img.pos.x] = 'P';
	param->game.count_steps++;
	return (0);
}

int	move_down(t_params *param)
{
	param->map.tab[param->img.pos.y][param->img.pos.x] = '0';
	param->img.pos.y += 1;
	param->map.tab[param->img.pos.y][param->img.pos.x] = 'P';
	param->game.count_steps++;
	return (0);
}

int	move_up(t_params *param)
{
	param->map.tab[param->img.pos.y][param->img.pos.x] = '0';
	param->img.pos.y -= 1;
	param->map.tab[param->img.pos.y][param->img.pos.x] = 'P';
	param->game.count_steps++;
	return (0);
}
