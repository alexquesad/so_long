/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:22:02 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 02:24:27 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	enemy_move_right(t_params *param)
{
	if (param->map.tab[param->enemy.pos.y][param->enemy.pos.x + 1] == 'P')
		finish_game(param, "GAME OVER!!\n Team Rocket got you!");
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = '0';
	param->enemy.pos.x += 1;
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = 'R';
	param->game.count_enemy++;
	return (0);
}

int	enemy_move_down(t_params *param)
{
	if (param->map.tab[param->enemy.pos.y + 1][param->enemy.pos.x] == 'P')
		finish_game(param, "GAME OVER!!\n Team Rocket got you!");
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = '0';
	param->enemy.pos.y += 1;
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = 'R';
	param->game.count_enemy++;
	return (0);
}

int	enemy_move_left(t_params *param)
{
	if (param->map.tab[param->enemy.pos.y][param->enemy.pos.x - 1] == 'P')
		finish_game(param, "GAME OVER!!\n Team Rocket got you!");
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = '0';
	param->enemy.pos.x -= 1;
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = 'R';
	param->game.count_enemy++;
	return (0);
}

int	enemy_move_up(t_params *param)
{
	if (param->map.tab[param->enemy.pos.y - 1][param->enemy.pos.x] == 'P')
		finish_game(param, "GAME OVER!!\n Team Rocket got you!");
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = '0';
	param->enemy.pos.y -= 1;
	param->map.tab[param->enemy.pos.y][param->enemy.pos.x] = 'R';
	param->game.count_enemy++;
	return (0);
}

int	enemy_attack(t_params *param)
{
	usleep(200000);
	get_enemy_position(param);
	if ((param->map.tab[param->enemy.pos.y][param->enemy.pos.x + 1] == '0'
		|| param->map.tab[param->enemy.pos.y][param->enemy.pos.x + 1] == 'P')
		&& param->game.count_enemy < param->map.size.x)
		enemy_move_right(param);
	else if ((param->map.tab[param->enemy.pos.y + 1][param->enemy.pos.x] == '0'
		|| param->map.tab[param->enemy.pos.y + 1][param->enemy.pos.x] == 'P')
		&& param->game.count_enemy < (param->map.size.x + param->map.size.y))
		enemy_move_down(param);
	else if ((param->map.tab[param->enemy.pos.y][param->enemy.pos.x - 1] == '0'
		|| param->map.tab[param->enemy.pos.y][param->enemy.pos.x - 1] == 'P')
		&& param->game.count_enemy < ((2 * param->map.size.x) \
		+ param->map.size.y))
		enemy_move_left(param);
	else if ((param->map.tab[param->enemy.pos.y - 1][param->enemy.pos.x] == '0'
		|| param->map.tab[param->enemy.pos.y - 1][param->enemy.pos.x] == 'P')
		&& param->game.count_enemy < (2 * (param->map.size.x \
		+ param->map.size.y)))
		enemy_move_up(param);
	else
		param->game.count_enemy = 0;
	print_map(*param);
	print_steps(param);
	return (0);
}
