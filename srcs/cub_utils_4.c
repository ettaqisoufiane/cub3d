/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:16:14 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:16:48 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	angle_z_pi(t_dataview *data, int i)
{
	t_sprite_1		ut;

	ut.m1 = (data->y - data->spritey) / (data->x - data->spritex);
	ut.b1 = data->y - ut.m1 * data->x;
	ut.m2 = -1 / ut.m1;
	ut.b2 = data->newspritey - ut.m2 * data->newspritex;
	ut.x = (ut.b1 - ut.b2) / (ut.m2 - ut.m1);
	ut.y = ut.m2 * ut.x + ut.b2;
	data->pwpp = sqrt(pow(data->newspritex - ut.x
		, 2) + pow(data->newspritey - ut.y, 2));
	if (data->pwpp <= 32)
		drawsprite_5(data, i);
}

void	allangles_1(t_dataview *data, int i, t_sprite *sprt)
{
	int				anl;

	i = 0;
	anl = RADTODEG(atan2(data->x - data->camerax
						, data->y - data->cameray));
	if (anl < 0)
	{
		data->x1 = sprt->x2;
		data->y1 = sprt->y2;
	}
	else if (anl > 0)
	{
		data->x1 = sprt->x1;
		data->y1 = sprt->y1;
	}
}

void	allangles(t_dataview *data, int i, t_sprite *sprt)
{
	if (data->pwpp <= 32)
	{
		if (data->signalsp == 0)
		{
			data->a = (1 + pow(sprt->m2, 2));
			data->b = (2 * sprt->m2 * sprt->b2 - 2 * sprt->m2
						* data->newspritey - 2 * data->newspritex);
			data->c = (pow((sprt->b2 - data->newspritey), 2)
						+ pow(data->newspritex, 2) - pow(32, 2));
			sprt->delta = pow(data->b, 2) - 4 * data->a * data->c;
			sprt->x1 = (-data->b - sqrt(sprt->delta))
							/ (2 * data->a);
			sprt->x2 = (-data->b + sqrt(sprt->delta))
							/ (2 * data->a);
			sprt->y1 = sprt->x1 * sprt->m2 + sprt->b2;
			sprt->y2 = sprt->x2 * sprt->m2 + sprt->b2;
			allangles_1(data, i, sprt);
		}
		data->sprite_x = sprt->x;
		data->sprite_y = sprt->y;
		drawsprite_1(data, i);
	}
}

void	calculscirclepoints(t_dataview *data, t_sprite *sprt)
{
	data->newspritex = floor(data->spritex / 64) * 64 + 32;
	data->newspritey = floor(data->spritey / 64) * 64 + 32;
	sprt->m1 = (data->y - data->newspritey)
				/ (data->x - data->newspritex);
	sprt->b1 = data->y - sprt->m1 * data->x;
	sprt->m2 = (data->y - data->cameray) / (data->x - data->camerax);
	sprt->b2 = data->newspritey - sprt->m2 * data->newspritex;
	sprt->m3 = (data->y - data->spritey) / (data->x - data->spritex);
	sprt->b3 = data->spritey - sprt->m3 * data->spritex;
	sprt->x = (sprt->b3 - sprt->b2) / (sprt->m2 - sprt->m3);
	sprt->y = sprt->m3 * sprt->x + sprt->b3;
	data->pwpp = sqrt(pow(data->newspritex - sprt->x
	, 2) + pow(data->newspritey - sprt->y, 2));
}
