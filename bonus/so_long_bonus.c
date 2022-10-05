/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:51:40 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 00:15:45 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_expose(t_params *param)
{
	print_map(*param);
	return (0);
}

int	init_game_params(t_params *param)
{	
	param->map.size.x = 0;
	param->map.size.y = 0;
	param->game.count_steps = 0;
	param->enemy_exist = 0;
	param->enemy.pos.x = 0;
	param->enemy.pos.y = 0;
	param->game.count_enemy = 0;
	return (0);
}

int	input_check(int argc, char **argv)
{
	if (argc < 2)
		ft_error("Error!\nNo map");
	if (argc > 2)
		ft_error("Error!\nToo many arguments." );
	if (ft_strstr(argv[1], ".ber") == NULL)
		ft_error("Error!\nInvalid map extension. Use .ber");
	return (0);
}

int	main(int argc, char **argv)
{
	t_params	param;

	input_check(argc, argv);
	init_game_params(&param);
	parse_map(&param, argv);
	param.mlx = mlx_init();
	param.win = mlx_new_window(param.mlx, param.map.size.x * SPRITE_W, \
		param.map.size.y * SPRITE_H, "So long");
	player_init_pos(&param);
	check_enemy(&param);
	count_collect(&param);
	print_map(param);
	mlx_hook(param.win, X_EVENT_KEY_PRESS, 1L << 0, key_press, &param);
	mlx_hook(param.win, X_EVENT_KEY_EXIT, 1L << 0, mlx_close, &param);
	mlx_expose_hook(param.win, ft_expose, &param);
	if (param.enemy_exist)
		mlx_loop_hook(param.mlx, enemy_attack, &param);
	mlx_loop(param.mlx);
}
