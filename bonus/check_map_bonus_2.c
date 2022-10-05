/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 00:08:46 by alexa             #+#    #+#             */
/*   Updated: 2022/09/28 01:42:41 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_exit(t_params *param)
{
	int		row;
	int		col;
	int		flag;

	row = 0;
	flag = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (col <= param->map.size.x)
		{
			if (param->map.tab[row][col] == 'E')
				flag = 1;
			col++;
		}
		row++;
	}
	if (flag != 1)
		exit_and_free(param, "Error map: misssing exit\n");
	return (0);
}

int	check_collectible(t_params *param)
{
	int		row;
	int		col;
	int		flag;

	row = 0;
	flag = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (col <= param->map.size.x)
		{
			if (param->map.tab[row][col] == 'C')
				flag = 1;
			col++;
		}
		row++;
	}
	if (flag != 1)
		exit_and_free(param, "Error map: misssing collectible\n");
	return (0);
}
