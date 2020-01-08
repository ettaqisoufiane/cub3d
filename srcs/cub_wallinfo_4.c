/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:00:21 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:14:00 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	sumupanddown(t_dataview *data, int c, float ang)
{
	int		a;

	a = (int)(data->y / data->gridy);
	data->ay = (float)a * (float)64 + (c == 1 ? 64 : 0);
	data->ax = data->x + (data->y - data->ay) / tan(DEG(ang));
	data->ya = (c == 1 ? (float)64 : (float)-64);
	data->xa = (c == 1 ? (float)-64 : (float)64) / tan(DEG(ang));
	data->cx = data->ax + (float)data->xa;
	data->cy = data->ay + (float)data->ya;
}

void	sumupanddown_1(t_dataview *data, int c, float ang)
{
	int		a;

	a = (int)(data->y / data->gridy);
	data->ay = (float)a * (float)64 + (c == 1 ? 64 : -1);
	data->ax = data->x + (data->y - data->ay) / tan(DEG(ang));
	data->ya = (c == 1 ? (float)64 : (float)-64);
	data->xa = (c == 1 ? (float)-64 : (float)64) / tan(DEG(ang));
	data->cx = data->ax + (float)data->xa;
	data->cy = data->ay + (float)data->ya;
}

void	sumrightandleft(t_dataview *data, int c, float ang)
{
	int		a;

	a = (int)(data->x / data->gridx);
	data->bx = (float)a * (float)(64) + (c == 1 ? 64 : 0);
	data->by = data->y + (data->x - data->bx) * tan(DEG(ang));
	data->xa = (c == 1 ? 64 : -64);
	data->ya = (c == 1 ? -64 : 64) * tan(DEG(ang));
	data->cx = data->bx + (float)data->xa;
	data->cy = data->by + (float)data->ya;
}

void	sumrightandleft_1(t_dataview *data, int c, float ang)
{
	int		a;

	a = (int)(data->x / data->gridx);
	data->bx = (float)a * (float)(64) + (c == 1 ? 64 : -1);
	data->by = data->y + (data->x - data->bx) * tan(DEG(ang));
	data->xa = (c == 1 ? 64 : -64);
	data->ya = (c == 1 ? -64 : 64) * tan(DEG(ang));
	data->cx = data->bx + (float)data->xa;
	data->cy = data->by + (float)data->ya;
}
