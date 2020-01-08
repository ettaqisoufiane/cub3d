/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallinfo_5.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:03:23 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:14:03 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int		checkpoints_com(t_dataview *data, int cas)
{
	if (cas == 3)
	{
		if ((int)((data->cx - 1) / data->gridx) < data->mapwidth && (int)
			(data->cy / data->gridy) < data->mapheight && (int)
			((data->cx - 1) / data->gridx) >= 0 && (int)
			(data->cy / data->gridy) >= 0)
			return (1);
		return (0);
	}
	return (0);
}

int		checkpoints_2_com(t_dataview *data, int cas)
{
	if (cas == 3)
	{
		if ((int)((data->bx - 1) / data->gridx) < data->mapwidth && (int)
		(data->by / data->gridy) < data->mapheight && (int)
		((data->bx - 1) / data->gridx) >= 0 && (int)
		(data->by / data->gridy) >= 0)
			return (1);
		return (0);
	}
	return (0);
}

int		checkpoints(t_dataview *data, int cas)
{
	if (cas == 1)
	{
		if ((int)(data->cx / data->gridx) < data->mapwidth &&
			(int)(data->cy / data->gridy) <
			data->mapheight && (int)(data->cx / data->gridx) >= 0 && (int)
			(data->cy / data->gridy) >= 0)
			return (1);
		return (0);
	}
	if (cas == 2)
	{
		if ((int)(data->cx / data->gridx) < data->mapwidth && (int)
			((data->cy - 1) / data->gridy) < data->mapheight && (int)
			(data->cx / data->gridx) >= 0 && (int)
			((data->cy - 1) / data->gridy) >= 0)
			return (1);
		return (0);
	}
	return (checkpoints_com(data, cas));
}

int		checkpoints_2(t_dataview *data, int cas)
{
	if (cas == 1)
	{
		if ((int)(data->ax / data->gridx) < data->mapwidth && (int)
			(data->ay / data->gridy) < data->mapheight && (int)
			(data->ax / data->gridx) >= 0 && (int)(data->ay / data->gridy) >= 0)
			return (1);
		return (0);
	}
	if (cas == 2)
	{
		if ((int)(data->ax / data->gridx) <= data->mapwidth && (int)
		((data->ay - 1) / data->gridy) <= data->mapheight && (int)
		(data->ax / data->gridx) >= 0 && (int)
		((data->ay - 1) / data->gridy) >= 0)
			return (1);
		return (0);
	}
	return (checkpoints_2_com(data, cas));
}
