/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:33:14 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:49 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	my_pixel_put_to_image(t_dataview *data, int x
		, int y, t_colorinfo *color)
{
	if (x < data->width && y < data->height && x >= 0 && y >= 0)
	{
		data->data[y * data->sizeline
		+ x * data->bpp / 8] = color->color1;
		data->data[y * data->sizeline
		+ x * data->bpp / 8 + 1] = color->color2;
		data->data[y * data->sizeline
		+ x * data->bpp / 8 + 2] = color->color3;
	}
}

int		checkwalls(t_dataview *data, float vecx, float vecy, int c)
{
	int		i;

	i = 0;
	if (checkwalls_facing(data, vecx, vecy, c))
		return (1);
	if (checkwalls_back(data, vecx, vecy, c))
		return (1);
	return (0);
}

void	initraypoints(t_dataview *data)
{
	data->ccx = 0;
	data->ccy = 0;
	data->rrx = 0;
	data->rry = 0;
	data->mmx = 0;
	data->mmy = 0;
	data->bbx = 0;
	data->bby = 0;
	data->walldistance = 0;
	data->spritex = 0;
	data->spritey = 0;
}
