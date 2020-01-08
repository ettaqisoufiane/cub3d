/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 16:27:34 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 18:21:29 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	checkmapwalls(t_dataview *data)
{
	int		i;
	int		k;

	i = 0;
	if (data->map != 0)
		while (data->map[i])
		{
			if (data->map[i][0] != '1')
				exiterror("Error: Map surrounding should be set to 1"
				, FAIL, data);
			if (data->map[i][data->mapwidth - 1] != '1')
				exiterror("Error: Map surrounding should be set to 1"
				, FAIL, data);
			k = 0;
			if (i == 0 || i == data->mapheight - 1)
			{
				while (k < data->mapwidth)
				{
					if (data->map[i][k++] != '1')
						exiterror("Error: Map surrounding should be set to 1"
							, FAIL, data);
				}
			}
			i++;
		}
}

void	getfloandcecolors_2(int n, t_dataview *data, t_colorinfo *colors)
{
	if (n == 0 && data->floor == 0)
		data->floor = colors;
	else if (n == 1 && data->ceil == 0)
		data->ceil = colors;
	else
		exiterror("Error: duplicate colors !\n",
		FAIL, data);
}
