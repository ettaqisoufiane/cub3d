/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_drawalls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 21:31:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:16 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	drawsprite_2(t_dataview *data, int x, t_colorinfo *color)
{
	float	b;
	float	f;
	int		offset;

	data->currentimage = data->image_data_4;
	offset = sqrt(pow(data->sprite_x - data->x1, 2)
			+ pow(data->sprite_y - data->y1, 2));
	if (offset <= 63 && offset >= 0)
	{
		f = 0;
		b = 64 / (data->wallheight);
		if (offset >= 0 && offset <= 64)
		{
			while (data->start <= data->end)
			{
				getcolors_(data, color, offset, f);
				if (color->color1 != 0 && color->color2
						!= 0 && color->color3 != 0)
					my_pixel_put_to_image(data, x, data->start, color);
				data->start++;
				f += b;
			}
		}
	}
}

void	drawsprite_1(t_dataview *data, int i)
{
	int				b;
	t_colorinfo		colors;

	data->walldistance = sqrt(pow(data->x - data->newspritex, 2)
						+ pow(data->y - data->newspritey, 2));
	data->wallheight = (float)data->distproplane *
						((float)128 / (float)data->walldistance);
	b = data->wallheight / 2;
	data->start = (data->height / 2) - b;
	data->end = (int)data->start + (int)data->wallheight;
	drawsprite_2(data, i, &colors);
}

void	drawsprite_6(t_dataview *data, int x, t_colorinfo *color)
{
	float	b;
	float	f;
	int		offset;

	data->currentimage = data->image_data_4;
	offset = data->pwpp;
	f = 0;
	b = 64 / (data->wallheight);
	while (data->start <= data->end)
	{
		getcolors_(data, color, 32 - offset, f);
		if (color->color1 != 0 && color->color2
				!= 0 && color->color3 != 0)
			my_pixel_put_to_image(data, x, data->start, color);
		data->start++;
		f += b;
	}
}

void	drawsprite_5(t_dataview *data, int i)
{
	int				b;
	t_colorinfo		colors;

	data->walldistance = sqrt(pow(data->x - data->newspritex, 2)
						+ pow(data->y - data->newspritey, 2));
	data->wallheight = (float)data->distproplane *
						((float)128 / (float)data->walldistance);
	b = data->wallheight / 2;
	data->start = (data->height / 2) - b;
	data->end = (int)data->start + (int)data->wallheight;
	drawsprite_6(data, i, &colors);
}

void	drawalls(t_dataview *data, float angle, int i)
{
	int				k;
	int				b;
	t_colorinfo		colors;

	data->walldistance = cos(DEG(angle)) * sqrt(pow(
		data->x - data->wallx, 2) + pow(data->y - data->wally, 2));
	data->wallheight = (float)data->distproplane * ((float)
		128 / (float)data->walldistance);
	b = data->wallheight / 2;
	data->start = (data->height / 2) - b;
	data->end = (int)data->start + (int)data->wallheight;
	k = 0;
	while (k <= data->start)
		my_pixel_put_to_image(data, i, k++, data->ceil);
	drawtexture(data, i, &colors);
	while (data->end <= data->height)
		my_pixel_put_to_image(data, i, data->end++, data->floor);
}
