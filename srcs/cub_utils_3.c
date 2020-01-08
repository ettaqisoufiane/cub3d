/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 18:28:08 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:44 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int		checkwalls_facing_x(t_dataview *data, float vecy, int c)
{
	int		i;
	float	b;

	i = 0;
	if (c == 1)
	{
		b = vecy / data->speed;
		vecy = 0;
		while (i < data->speed)
		{
			if (data->map[(int)((data->y - vecy * 1.4) / (int)data->gridy)]
			[(int)((data->x) / (int)
			data->gridx)] == '1' || data->map[(int)
			((data->y - vecy * 1.4) / (int)data->gridy)]
			[(int)((data->x) / (int)data->gridx)] == '2')
				return (1);
			vecy += b;
			i++;
		}
	}
	return (0);
}

int		checkwalls_facing_y(t_dataview *data, float vecx, int c)
{
	int		i;
	float	a;

	i = 0;
	if (c == 2)
	{
		a = vecx / data->speed;
		vecx = 0;
		while (i < data->speed)
		{
			if (data->map[(int)((data->y) / (int)data->gridy)]
			[(int)((data->x - vecx * 1.4) / (int)
			data->gridx)] == '1' || data->map[(int)
			((data->y) / (int)data->gridy)]
			[(int)((data->x - vecx * 1.4) / (int)data->gridx)] == '2')
				return (1);
			vecx += a;
			i++;
		}
	}
	return (0);
}

int		checkwalls_facing(t_dataview *data, float vecx, float vecy, int c)
{
	int		i;

	i = 0;
	if (checkwalls_facing_x(data, vecy, c) == 1)
		return (1);
	if (checkwalls_facing_y(data, vecx, c) == 1)
		return (1);
	return (0);
}

int		checkwalls_back(t_dataview *data, float vecx, float vecy, int c)
{
	int		i;
	float	a;
	float	b;

	i = 0;
	if (c == 3)
	{
		a = vecx / data->speed;
		b = vecy / data->speed;
		vecx = 0;
		vecy = 0;
		while (i < data->speed)
		{
			if (data->map[(int)((data->y + vecy * 1.4) / (int)data->gridy)]
			[(int)((data->x + vecx * 1.4) / (int)
			data->gridx)] == '1' || data->map[(int)
			((data->y + vecy * 1.4) / (int)data->gridy)]
			[(int)((data->x + vecx * 1.4) / (int)data->gridx)] == '2')
				return (1);
			vecx += a;
			vecy += b;
			i++;
		}
	}
	return (0);
}
