/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:23:30 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:18:10 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void			start_drawsprite(t_dataview *data,
				t_pntsprite *pnts, int i)
{
	t_sprite		sprt;
	int				anl;

	setpnts(data, pnts);
	free(pnts);
	pnts = 0;
	if (data->spritex != 0 || data->spritey != 0)
	{
		if (sqrt(pow(data->x - data->spritex, 2)
			+ pow(data->y - data->spritey, 2)) < sqrt(pow(data->x - data->wallx
			, 2) + pow(data->y - data->wally, 2)))
		{
			calculscirclepoints(data, &sprt);
			anl = RADTODEG(atan2(data->x - data->camerax
						, data->y - data->cameray));
			if (anl == 0 || anl == 180)
				angle_z_pi(data, i);
			else
				allangles(data, i, &sprt);
		}
	}
}

void			setpnts(t_dataview *data, t_pntsprite *pnts)
{
	data->spritex = pnts->pnt1;
	data->spritey = pnts->pnt2;
}

void			freelist(void *data)
{
	free(data);
}

t_pntsprite		*jointwopoints(float pnt1, float pnt2)
{
	t_pntsprite		*twopoints;

	twopoints = malloc(sizeof(t_pntsprite) * 1);
	twopoints->pnt1 = pnt1;
	twopoints->pnt2 = pnt2;
	return (twopoints);
}

void			getrayvectors(t_dataview *data, int sizeline, int bpp)
{
	float			angle;
	int				i;
	float			ang;

	angle = (float)-FOV / (float)2;
	i = 0;
	init_data_(data, sizeline, bpp);
	data->signalsp = 0;
	while (angle <= (float)FOV / (float)2)
	{
		ang = data->angle + angle;
		data->ang = ang;
		handle_walls(data, &ang);
		drawalls(data, angle, i);
		handle_sprite(data, &ang);
		start_drawsprite(data, jointwopoints(data->ccx, data->ccy), i);
		start_drawsprite(data, jointwopoints(data->bbx, data->bby), i);
		start_drawsprite(data, jointwopoints(data->mmx, data->mmy), i);
		start_drawsprite(data, jointwopoints(data->rrx, data->rry), i);
		angle = angle + (float)FOV / ((float)data->width);
		i++;
	}
}
