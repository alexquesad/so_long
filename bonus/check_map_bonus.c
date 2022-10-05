/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 20:24:23 by alexa             #+#    #+#             */
/*   Updated: 2022/06/30 23:09:09 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_walls(t_params *param)
{
	int		row;
	int		col;

	row = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		if (row == 0 || row == (param->map.size.y - 1))
		{
			while (param->map.tab[row][col])
			{
				if (param->map.tab[row][col] != '1')
					exit_and_free(param, "Error!\n top/down wall\n");
				col++;
			}
		}
		if (param->map.tab[row][0] != '1'
			|| param->map.tab[row][param->map.size.x - 1] != '1')
			exit_and_free(param, "Error!\n lateral wall\n");
		row++;
	}
	return (0);
}

int	check_player(t_params *param)
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
			if (param->map.tab[row][col] == 'P')
				flag = 1;
			col++;
		}
		row++;
	}
	if (flag != 1)
		exit_and_free(param, "Error!\n Misssing player\n");
	return (0);
}

int	check_rectangle(t_params *param)
{
	int		row;

	row = 0;
	while (row < param->map.size.y)
	{
		if (param->map.size.x != (int)ft_strlen(param->map.tab[row]))
			exit_and_free(param, "Error!\n Map not a rectangle\n");
		row++;
	}
	return (0);
}

int	check_elements(t_params *param)
{
	int		row;
	int		col;	

	row = 0;
	while (row < param->map.size.y)
	{
		col = 0;
		while (param->map.tab[row][col])
		{
			if (param->map.tab[row][col] != '0' \
				&& param->map.tab[row][col] != '1' \
				&& param->map.tab[row][col] != 'P' \
				&& param->map.tab[row][col] != 'E' \
				&& param->map.tab[row][col] != 'C' \
				&& param->map.tab[row][col] != 'R')
				exit_and_free(param, "Error!\n Unknown char\n");
			col++;
		}
		row++;
	}
	return (0);
}

int	check_map(t_params *param)
{
	check_walls(param);
	check_player(param);
	check_exit(param);
	check_collectible(param);
	check_rectangle(param);
	check_elements(param);
	return (0);
}
