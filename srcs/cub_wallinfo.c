/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 19:02:35 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:14:09 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	upangle(t_dataview *data, float ang)
{
	sumupanddown(data, 0, ang);
	if (checkpoints_2(data, 2))
		if (data->map[(int)((data->ay - 1) / data->gridy)][
			(int)(data->ax / data->gridx)] == '1')
		{
			data->ccx = data->ax;
			data->ccy = data->ay;
		}
	while (data->cx <= 64 * data->mapwidth && data->cx >= 0 && (data->cy - 1)
		>= 0 && (data->cy - 1) <= 64 * data->mapheight && data->ccx == 0)
	{
		if (checkpoints(data, 2))
			if (data->map[(int)((data->cy - 1) / data->gridy)][
				(int)(data->cx / data->gridx)] == '1')
			{
				data->ccx = data->cx;
				data->ccy = data->cy;
				break ;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	downangle(t_dataview *data, float ang)
{
	sumupanddown(data, 1, ang);
	if ((int)(data->ax / data->gridx) <= data->mapwidth && (int)
		(data->ay / data->gridy) <= data->mapheight && (int)
		(data->ax / data->gridx) >= 0 && (int)(data->ay / data->gridy) >= 0)
		if (data->map[(int)(data->ay / data->gridy)][(int)
			(data->ax / data->gridx)] == '1')
		{
			data->bbx = data->ax;
			data->bby = data->ay;
		}
	while (data->cx <= 64 * data->mapwidth && data->cx >= 0 && data->cy
			>= 0 && data->cy <= 64 * data->mapheight && data->bbx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)(data->cy / data->gridy)][
				(int)(data->cx / data->gridx)] == '1')
			{
				data->bbx = data->cx;
				data->bby = data->cy;
				break ;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	rightangle(t_dataview *data, float ang)
{
	sumrightandleft(data, 1, ang);
	if ((int)(data->bx / data->gridx) < data->mapwidth && (int)
		(data->by / data->gridy) < data->mapheight && (int)
		(data->bx / data->gridx) >= 0 && (int)(data->by / data->gridy) >= 0)
		if (data->map[(int)(data->by / data->gridy)][
			(int)(data->bx / data->gridx)] == '1')
		{
			data->rrx = data->bx;
			data->rry = data->by;
		}
	while (data->cx < 64 * data->mapwidth && data->cx >= 0 && data->cy
			>= 0 && data->cy < 64 * data->mapheight && data->rrx == 0)
	{
		if (checkpoints(data, 1))
			if (data->map[(int)(data->cy / data->gridy)][
				(int)(data->cx / data->gridx)] == '1')
			{
				data->rrx = data->cx;
				data->rry = data->cy;
				break ;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}

void	leftangle(t_dataview *data, float ang)
{
	sumrightandleft(data, 0, ang);
	if (checkpoints_2(data, 3))
		if (data->map[(int)(data->by / data->gridy)][
			(int)((data->bx - 1) / data->gridx)] == '1')
		{
			data->mmx = data->bx;
			data->mmy = data->by;
		}
	while ((data->cx - 1) < 64 * data->mapwidth && (data->cx - 1)
			>= 0 && data->cy >= 0 && data->cy < 64 * data->mapheight
			&& data->mmx == 0)
	{
		if ((int)((data->cx - 1) / data->gridx) < data->mapwidth && (int)
			(data->cy / data->gridy) < data->mapheight && (int)
((data->cx - 1) / data->gridx) >= 0 && (int)(data->cy / data->gridy) >= 0)
			if (data->map[(int)(data->cy / data->gridy)][
				(int)((data->cx - 1) / data->gridx)] == '1')
			{
				data->mmx = data->cx;
				data->mmy = data->cy;
				break ;
			}
		data->cx = data->cx + (float)data->xa;
		data->cy = data->cy + (float)data->ya;
	}
}
