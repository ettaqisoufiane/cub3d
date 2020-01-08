/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_wallhandle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:15:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:13:51 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	handle_walls(t_dataview *data, float *ang)
{
	int				angl;

	initraypoints(data);
	angl = anglecalcul(*ang, 180, data);
	if (angl == 1)
		upangle(data, *ang);
	if (angl == 0)
		downangle(data, *ang);
	angl = anglecalcul(*ang, 90, data);
	if (angl == 2)
		rightangle(data, *ang);
	if (angl == 3)
		leftangle(data, *ang);
	angl = anglecalcul(*ang, 45, data);
	getwallcoordinates(data, angl);
}

void	handle_sprite(t_dataview *data, float *ang)
{
	int				angl;

	initraypoints(data);
	angl = anglecalcul(*ang, 180, data);
	if (angl == 1)
		upangle_1(data, *ang);
	if (angl == 0)
		downangle_1(data, *ang);
	angl = anglecalcul(*ang, 90, data);
	if (angl == 2)
		rightangle_1(data, *ang);
	if (angl == 3)
		leftangle_1(data, *ang);
	angl = anglecalcul(*ang, 45, data);
}
