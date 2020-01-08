/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:45:58 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:54 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	wallinfo_1(t_dataview *data, t_wallinfo *coor, int c)
{
	if (c == 1)
	{
		data->wallx = coor->vertx;
		data->wally = coor->verty;
		data->isvert = 1;
		data->ishort = 0;
	}
	else if (c == 2)
	{
		data->wallx = coor->horix;
		data->wally = coor->horiy;
		data->isvert = 0;
		data->ishort = 1;
	}
}

void	wallinfo(t_dataview *data, t_wallinfo *coor)
{
	if (coor->horiy != 0 && coor->horix != 0
		&& coor->verty != 0 && coor->vertx != 0)
	{
		if (sqrt(pow(data->x - coor->vertx, 2) + pow(coor->verty - data->y, 2))
		< sqrt(pow(data->x - coor->horix, 2) + pow(coor->horiy - data->y, 2)))
			wallinfo_1(data, coor, 1);
		else
			wallinfo_1(data, coor, 2);
	}
	else if (coor->horiy == 0 || coor->horix == 0
			|| coor->verty == 0 || coor->vertx == 0)
	{
		if (coor->vertx == 0 || coor->verty == 0)
			wallinfo_1(data, coor, 2);
		else if (coor->horix == 0 || coor->horiy == 0)
			wallinfo_1(data, coor, 1);
	}
}

void	wallinfo1_1(t_dataview *data, t_wallinfo *coor, int c)
{
	if (c == 1)
	{
		data->spritex = coor->vertx;
		data->spritey = coor->verty;
		data->isvert = 1;
		data->ishort = 0;
	}
	else if (c == 2)
	{
		data->spritex = coor->horix;
		data->spritey = coor->horiy;
		data->isvert = 0;
		data->ishort = 1;
	}
}

void	wallinfo1(t_dataview *data, t_wallinfo *coor)
{
	if (coor->horiy != 0 && coor->horix != 0
		&& coor->verty != 0 && coor->vertx != 0)
	{
		if (sqrt(pow(data->x - coor->vertx, 2) + pow(coor->verty - data->y, 2))
		< sqrt(pow(data->x - coor->horix, 2) + pow(coor->horiy - data->y, 2)))
			wallinfo1_1(data, coor, 1);
		else
			wallinfo1_1(data, coor, 2);
	}
	else if (coor->horiy == 0 || coor->horix == 0
			|| coor->verty == 0 || coor->vertx == 0)
	{
		if (coor->vertx == 0 || coor->verty == 0)
			wallinfo1_1(data, coor, 2);
		else if (coor->horix == 0 || coor->horiy == 0)
			wallinfo1_1(data, coor, 1);
	}
}
