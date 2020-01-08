/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_anglerotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 23:50:38 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:01 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		anglecalcul_1(float ang, int c, t_dataview *data)
{
	if (c == 180)
	{
		if ((ang >= 360 * data->rotatelen + (float)0
			&& ang <= 360 * data->rotatelen + (float)180)
			|| (ang < 360 * data->rotatelen + (float)-180
			&& ang > 360 * data->rotatelen + (float)-360)
			|| (ang > 360 * data->rotatelen + (float)360
			&& ang < 360 * data->rotatelen + (float)540))
			return (1);
		if ((ang < 360 * data->rotatelen + (float)0
			&& ang > 360 * data->rotatelen + (float)-180)
			|| (ang > 360 * data->rotatelen + (float)180
			&& ang < 360 * data->rotatelen + (float)360)
			|| (ang > 360 * data->rotatelen + (float)-540
			&& ang < 360 * data->rotatelen + (float)-360))
			return (0);
	}
	return (70);
}

int		anglecalcul_2(float ang, int c, t_dataview *data)
{
	if (c == 90)
	{
		if ((ang > 360 * data->rotatelen + (float)-90
			&& ang < 360 * data->rotatelen + (float)90)
			|| (ang < 360 * data->rotatelen + (float)-270
			&& ang > 360 * data->rotatelen + (float)-450)
			|| (ang > 360 * data->rotatelen + (float)270
			&& ang < 360 * data->rotatelen + (float)450))
			return (2);
		if ((ang < 360 * data->rotatelen + (float)-90
			&& ang > 360 * data->rotatelen + (float)-270)
			|| (ang > 360 * data->rotatelen + (float)90
			&& ang < 360 * data->rotatelen + (float)270))
			return (3);
	}
	return (70);
}

int		anglecalcul_4(float ang, t_dataview *data)
{
	if ((ang > 360 * data->rotatelen + (float)0
			&& ang < 360 * data->rotatelen + (float)90)
			|| (ang > 360 * data->rotatelen + (float)360
			&& ang < 360 * data->rotatelen + (float)450)
			|| (ang > 360 * data->rotatelen + (float)-360
			&& ang < 360 * data->rotatelen + (float)-270))
		return (1);
	return (0);
}

int		anglecalcul_3(float ang, int c, t_dataview *data)
{
	if (c == 45)
	{
		if ((ang > 360 * data->rotatelen + (float)-90
			&& ang < 360 * data->rotatelen + (float)0)
			|| (ang > 360 * data->rotatelen + (float)270
			&& ang < 360 * data->rotatelen + (float)360) ||
			(ang > 360 * data->rotatelen + (float)-450
			&& ang < 360 * data->rotatelen + (float)-360))
			return (4);
		if ((ang > 360 * data->rotatelen + (float)-180
			&& ang < 360 * data->rotatelen + (float)-90)
			|| (ang > 360 * data->rotatelen + (float)180
			&& ang < 360 * data->rotatelen + (float)270))
			return (5);
		if ((ang > 360 * data->rotatelen + (float)90
			&& ang < 360 * data->rotatelen + (float)180)
			|| (ang > 360 * data->rotatelen + (float)-270
			&& ang < 360 * data->rotatelen + (float)-180))
			return (6);
		if (anglecalcul_4(ang, data))
			return (7);
	}
	return (70);
}

int		anglecalcul(float ang, int c, t_dataview *data)
{
	int		ret;

	ret = anglecalcul_1(ang, c, data);
	if (ret != 70)
		return (ret);
	ret = anglecalcul_2(ang, c, data);
	if (ret != 70)
		return (ret);
	ret = anglecalcul_3(ang, c, data);
	if (ret != 70)
		return (ret);
	return (70);
}
