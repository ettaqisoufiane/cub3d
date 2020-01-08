/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_playerupdates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:41:08 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 17:51:23 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	updateplayerposition_forward(t_dataview *data, float vecx, float vecy)
{
	if (data->movkey_1 == 126 && data->movpressed)
	{
		if (checkwalls(data, vecx * 3, vecy * 3, 1) != 1)
		{
			data->y -= vecy;
			data->directiony -= vecy;
		}
		if (checkwalls(data, vecx * 3, vecy * 3, 2) != 1)
		{
			data->x -= vecx;
			data->directionx -= vecx;
		}
	}
}

void	updateplayerposition_returning(t_dataview *data, float vecx, float vecy)
{
	if (data->movkey_2 == 125 && data->movpressed)
	{
		if (checkwalls(data, vecx * 3, vecy * 3, 3) != 1)
		{
			data->x += vecx;
			data->y += vecy;
			data->directionx += vecx;
			data->directiony += vecy;
		}
	}
}

void	updateplayerposition(t_dataview *data)
{
	float	vecx;
	float	vecy;

	vecx = data->x - data->directionx;
	vecy = data->y - data->directiony;
	updateplayerposition_forward(data, vecx, vecy);
	updateplayerposition_returning(data, vecx, vecy);
	data->directionoriginx = data->x + data->speed;
	data->directionoriginy = data->y;
	data->camerax = (data->directionx - data->x)
				* cos(DEG(90)) -
				(data->directiony - data->y)
				* sin(DEG(90)) + data->x;
	data->cameray = (data->directionx - data->x)
				* sin(DEG(90)) +
				(data->directiony - data->y)
				* cos(DEG(90)) + data->y;
}

void	updatedirectionplayer(t_dataview *data)
{
	if (data->angkey_1 == 123 && data->anglepressed)
	{
		data->angle -= 5;
		if (data->angle < (float)360 * data->rotatelen - 360)
			data->rotatelen--;
	}
	if (data->angkey_2 == 124 && data->anglepressed)
	{
		data->angle += 5;
		if (data->angle > (float)360 * data->rotatelen + 360)
			data->rotatelen++;
	}
	data->directionx = (data->directionoriginx - data->x)
				* cos(DEG(-data->angle)) -
				(data->directionoriginy - data->y)
				* sin(DEG(-data->angle)) + data->x;
	data->directiony = (data->directionoriginx - data->x)
				* sin(DEG(-data->angle)) +
				(data->directionoriginy - data->y)
				* cos(DEG(-data->angle)) + data->y;
}
