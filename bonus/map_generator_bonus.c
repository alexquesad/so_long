/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexa <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:09:54 by alexa             #+#    #+#             */
/*   Updated: 2022/05/02 19:24:36 by alexa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	get_map_size(char **argv)
{
	int		fd;
	char	*row;
	int		linenbr;

	linenbr = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Map not found");
	while (1)
	{	
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		free (row);
		linenbr++;
	}
	close(fd);
	return (linenbr);
}

int	parse_map(t_params *param, char **argv)
{
	int		linenbr;
	int		fd;
	char	*row;

	linenbr = get_map_size(argv);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_error("Map not found");
	param->map.tab = malloc((linenbr + 1) * sizeof(char *));
	param->map.tab[linenbr] = NULL;
	linenbr = 0;
	while (1)
	{	
		row = get_next_line(fd);
		if (row == NULL)
			break ;
		param->map.tab[linenbr] = row;
		linenbr++;
	}
	close(fd);
	param->map.size.y = linenbr;
	param->map.size.x = ft_strlen(param->map.tab[0]);
	check_map(param);
	return (0);
}

int	load_map(t_params param, int row, int col)
{
	if (param.map.tab[row][col] == '1')
		param.img.img_ptr = mlx_xpm_file_to_image(param.mlx, \
		"./img/poketree.xpm", &param.img.size.x, &param.img.size.y);
	else if (param.map.tab[row][col] == '0')
		param.img.img_ptr = mlx_xpm_file_to_image(param.mlx, \
		"./img/grass.xpm", &param.img.size.x, &param.img.size.y);
	else if (param.map.tab[row][col] == 'E')
		param.img.img_ptr = mlx_xpm_file_to_image(param.mlx, \
		"./img/ladder.xpm", &param.img.size.x, &param.img.size.y);
	else if (param.map.tab[row][col] == 'C')
		param.img.img_ptr = mlx_xpm_file_to_image(param.mlx, \
		"./img/pikachu.xpm", &param.img.size.x, &param.img.size.y);
	else if (param.map.tab[row][col] == 'P')
		param.img.img_ptr = mlx_xpm_file_to_image(param.mlx, \
		"./img/ashenano.xpm", &param.img.size.x, &param.img.size.y);
	else if (param.map.tab[row][col] == 'R' && param.enemy_exist > 0)
		enemy_animation(&param);
	mlx_put_image_to_window(param.mlx, param.win, param.img.img_ptr, \
		SPRITE_W * col, SPRITE_H * row);
	mlx_destroy_image(param.mlx, param.img.img_ptr);
	return (0);
}

int	print_map(t_params param)
{
	int		row;
	int		col;

	row = 0;
	while (row < param.map.size.y)
	{
		col = 0;
		while (col < param.map.size.x)
		{
			load_map(param, row, col);
			col++;
		}
		row++;
	}
	return (0);
}
