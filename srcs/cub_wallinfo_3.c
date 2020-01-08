/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 16:59:19 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:57 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	upangle_1(t_dataview *data, float ang)
{
	sumupanddown_1(data, 0, ang);
	if (checkpoints_2(data, 1))
		if (data->map[(int)((data->ay) / data->gridy)][
			(int)(data->ax / data->gridx)] == '2')
		{
			data->ccx = data->ax;
			data->ccy = data->ay;
		}
	while (data->cx < 64 * data->mapwidth && data->cx >= 0 && (data->cy)
		>= 0 && (data->cy) < 64 * data->mapheight && data->ccx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)((data->cy) / data->gridy)][
				(int)(data->cx / data->gridx)] == '2')
			{
				data->ccx = data->cx;
				data->ccy = data->cy;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	downangle_1(t_dataview *data, float ang)
{
	sumupanddown_1(data, 1, ang);
	if (checkpoints_2(data, 1))
		if (data->map[(int)(data->ay / data->gridy)][
			(int)(data->ax / data->gridx)] == '2')
		{
			data->bbx = data->ax;
			data->bby = data->ay;
		}
	while (data->cx < 64 * data->mapwidth && data->cx >= 0 && data->cy
			>= 0 && data->cy < 64 * data->mapheight && data->bbx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)(data->cy / data->gridy)][
				(int)(data->cx / data->gridx)] == '2')
			{
				data->bbx = data->cx;
				data->bby = data->cy;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	rightangle_1(t_dataview *data, float ang)
{
	sumrightandleft_1(data, 1, ang);
	if ((int)(data->bx / data->gridx) < data->mapwidth && (int)
		(data->by / data->gridy) < data->mapheight && (int)
		(data->bx / data->gridx) >= 0 && (int)
		(data->by / data->gridy) >= 0)
		if (data->map[(int)(data->by / data->gridy)][(int)
			(data->bx / data->gridx)] == '2')
		{
			data->rrx = data->bx;
			data->rry = data->by;
		}
	while (data->cx < 64 * data->mapwidth && data->cx >= 0 && data->cy
			>= 0 && data->cy < 64 * data->mapheight && data->rrx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)(data->cy / data->gridy)][
				(int)(data->cx / data->gridx)] == '2')
			{
				data->rrx = data->cx;
				data->rry = data->cy;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	leftangle_1(t_dataview *data, float ang)
{
	sumrightandleft_1(data, 2, ang);
	if ((int)((data->bx) / data->gridx) < data->mapwidth && (int)
		(data->by / data->gridy) < data->mapheight && (int)
		((data->bx) / data->gridx) >= 0 && (int)(data->by / data->gridy) >= 0)
		if (data->map[(int)(data->by / data->gridy)][(int)
			((data->bx) / data->gridx)] == '2')
		{
			data->mmx = data->bx;
			data->mmy = data->by;
		}
	while ((data->cx) < 64 * data->mapwidth && (data->cx) >= 0 && data->cy
			>= 0 && data->cy < 64 * data->mapheight && data->mmx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)(data->cy / data->gridy)][
				(int)((data->cx) / data->gridx)] == '2')
			{
				data->mmx = data->cx;
				data->mmy = data->cy;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}
