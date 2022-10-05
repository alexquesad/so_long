/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 21:02:14 by alexa             #+#    #+#             */
/*   Updated: 2022/07/01 02:21:12 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	free_map(t_params *param)
{
	int	row;

	row = 0;
	mlx_destroy_window(param->mlx, param->win);
	mlx_destroy_display(param->mlx);
	free(param->mlx);
	while (row < param->map.size.y)
	{
		free(param->map.tab[row]);
		row++;
	}
	free(param->map.tab);
	return (0);
}

int	exit_and_free(t_params *param, char *msg)
{	
	int	row;

	row = 0;
	while (row < param->map.size.y)
	{
		free(param->map.tab[row]);
		row++;
	}
	free(param->map.tab);
	ft_putstr_fd(msg, 2);
	exit(EXIT_FAILURE);
	return (1);
}
