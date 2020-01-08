/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_configuration_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 01:57:14 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:05 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	handleallerrors(t_dataview *data)
{
	if (data->map == 0)
		exiterror("Error: must have map in the filecub\n", FAIL, data);
	if (data->west == 0 || data->north == 0 ||
		data->east == 0 || data->south == 0 || data->sprite == 0)
		handlewallsandspritetexture(data);
	if (data->width == 0 || data->height == 0)
		exiterror("Error: must have the resolution of the window\n",
		FAIL, data);
	if (data->ceil == 0 || data->ceil->color1 < 0
		|| data->ceil->color2 < 0 || data->ceil->color3 < 0)
		exiterror("Error: Enter the ceil colors, or colors must be positive\n"
			, FAIL, data);
	if (data->floor == 0 || data->floor->color1 < 0
		|| data->floor->color2 < 0 || data->floor->color3 < 0)
		exiterror("Error: Enter the ceil colors, or colors must be positive\n"
			, FAIL, data);
}
