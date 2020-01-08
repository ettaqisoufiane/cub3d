/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo_6.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:07:23 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:14:06 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	getwallcoordinates_1(t_dataview *data, int angl)
{
	t_wallinfo	coor;

	if (angl == 5)
	{
		coor.horix = data->bbx;
		coor.horiy = data->bby;
		coor.vertx = data->mmx;
		coor.verty = data->mmy;
		wallinfo(data, &coor);
		if (data->isvert == 1)
			data->isvert = 3;
		else
			data->ishort = 1;
	}
}

void	getwallcoordinates_2(t_dataview *data, int angl)
{
	t_wallinfo	coor;

	if (angl == 6)
	{
		coor.horix = data->ccx;
		coor.horiy = data->ccy;
		coor.vertx = data->mmx;
		coor.verty = data->mmy;
		wallinfo(data, &coor);
		if (data->isvert == 1)
			data->isvert = 3;
		else
			data->ishort = 0;
	}
}

void	getwallcoordinates_3(t_dataview *data, int angl)
{
	t_wallinfo	coor;

	if (angl == 4)
	{
		coor.horix = data->bbx;
		coor.horiy = data->bby;
		coor.vertx = data->rrx;
		coor.verty = data->rry;
		wallinfo(data, &coor);
		if (data->isvert == 1)
			data->isvert = 2;
		else
			data->ishort = 1;
	}
}

void	getwallcoordinates_4(t_dataview *data, int angl)
{
	t_wallinfo	coor;

	if (angl == 7)
	{
		coor.horix = data->ccx;
		coor.horiy = data->ccy;
		coor.vertx = data->rrx;
		coor.verty = data->rry;
		wallinfo(data, &coor);
		if (data->isvert == 1)
			data->isvert = 2;
		else
			data->ishort = 0;
	}
}

void	getwallcoordinates(t_dataview *data, int angl)
{
	getwallcoordinates_1(data, angl);
	getwallcoordinates_2(data, angl);
	getwallcoordinates_3(data, angl);
	getwallcoordinates_4(data, angl);
}
