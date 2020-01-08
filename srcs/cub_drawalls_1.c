/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_drawalls_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:15:09 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:23:05 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	getcolors_(t_dataview *data, t_colorinfo *color, int x, int y)
{
	if (x < 64 && y < 64 && x >= 0 && y >= 0)
	{
		color->color1 = data->currentimage->dataimage[y * data->
		currentimage->tx_sl + x * data->currentimage->tx_bpp / 8];
		color->color2 = data->currentimage->dataimage[y * data->
		currentimage->tx_sl + x * data->currentimage->tx_bpp / 8 + 1];
		color->color3 = data->currentimage->dataimage[y * data->
		currentimage->tx_sl + x * data->currentimage->tx_bpp / 8 + 2];
	}
}

void	getcurrenttexture_1(t_dataview *data)
{
	if (data->isvert == 3)
	{
		data->currentimage = data->image_data;
		data->currentimage_1 = data->image;
	}
	else
	{
		data->currentimage = data->image_data_1;
		data->currentimage_1 = data->image_1;
	}
}

void	getcurrenttexture(t_dataview *data, int *offset)
{
	if (data->isvert == 3 || data->isvert == 2)
	{
		*offset = (int)(data->wally) % 64;
		getcurrenttexture_1(data);
	}
	else if (data->ishort == 0 || data->ishort == 1)
	{
		*offset = (int)(data->wallx) % 64;
		if (data->ishort == 0)
		{
			data->currentimage = data->image_data_2;
			data->currentimage_1 = data->image_2;
		}
		else
		{
			data->currentimage = data->image_data_3;
			data->currentimage_1 = data->image_3;
		}
	}
}

void	drawtexture(t_dataview *data, int x, t_colorinfo *color)
{
	float	b;
	float	f;
	int		offset;

	getcurrenttexture(data, &offset);
	f = 0;
	b = 64 / data->wallheight;
	getcolors_(data, color, offset, b);
	while (data->start <= data->end)
	{
		getcolors_(data, color, offset, f);
		my_pixel_put_to_image(data, x, data->start++, color);
		if (data->start > data->height)
			break ;
		f += b;
	}
}
