/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_configuration.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:18:12 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:19:09 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	initmap(t_dataview *data, char **argc, int argv)
{
	int		fd;

	argv = 0;
	checkfilename(argc[1], data);
	data->maxwidth = 2560;
	data->maxheight = 1440;
	fd = open(argc[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error");
		exit(FAIL);
	}
	treatfilecontent(fd, data);
	if (data->ut == 1)
		exiterror("Error: Invalid data.\n", FAIL, data);
	if (data->width > data->maxwidth)
		data->width = data->maxwidth;
	if (data->height > data->maxheight)
		data->height = data->maxheight;
}

void	checkmap_2(t_dataview *data)
{
	float	y;
	float	x;

	y = 0;
	if (data->map != 0)
		while (data->map[(int)y])
		{
			x = 0;
			while (data->map[(int)y][(int)x])
			{
				if (data->map[(int)y][(int)x] != '0'
				&& data->map[(int)y][(int)x] != '1' &&
				data->map[(int)y][(int)x] != '2'
				&& data->map[(int)y][(int)x] != 'N' &&
				data->map[(int)y][(int)x] != 'S' &&
				data->map[(int)y][(int)x] != 'E' &&
				data->map[(int)y][(int)x] != 'W')
				{
					exiterror("Error: Map contain undefined value\n"
					, FAIL, data);
				}
				x++;
			}
			y++;
		}
}

void	getplayerposition(t_dataview *data)
{
	float	y;
	float	x;

	y = 0;
	while (data->map[(int)y])
	{
		x = 0;
		while (data->map[(int)y][(int)x])
		{
			getplayerposition_1(data, x, y);
			x++;
		}
		y++;
	}
	if (data->x == 0 || data->y == 0)
		exiterror("Error: You need to put a position for player in the map\n"
		, FAIL, data);
}

void	handlewallsandspritetexture(t_dataview *data)
{
	if (data->west == 0)
		exiterror("Error: must have the west texture\n", FAIL, data);
	if (data->north == 0)
		exiterror("Error: must have the north texture\n", FAIL, data);
	if (data->east == 0)
		exiterror("Error: must have the east texture\n", FAIL, data);
	if (data->south == 0)
		exiterror("Error: must have the south texture\n", FAIL, data);
	if (data->sprite == 0)
		exiterror("Error: must have the sprite texture\n", FAIL, data);
}

int		initgame(t_dataview *data)
{
	data->firsthitsprite = 0;
	data->movpressed = 0;
	data->anglepressed = 0;
	data->rotatelen = 0;
	data->gridx = 64;
	data->gridy = 64;
	data->speed = 15;
	checkmap_2(data);
	checkmapwalls(data);
	handleallerrors(data);
	getplayerposition(data);
	data->directionoriginx = data->x + data->speed;
	data->directionoriginy = data->y;
	return (0);
}
