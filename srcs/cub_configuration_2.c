/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_configuration_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 23:39:53 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 21:52:36 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int		checkforupdates(t_dataview *params)
{
	mlx_hook(params->win_ptr, 2, 0, &key_pressed, (void*)params);
	mlx_hook(params->win_ptr, 3, 0, &key_release, (void*)params);
	mlx_hook(params->win_ptr, 17, 0, &exit_button, (void*)params);
	setupimages_andupdates(params);
	return (0);
}

void	init_data_(t_dataview *data, int sizeline, int bpp)
{
	data->distproplane = (float)(data->width / 2) * (float)tan(DEG(FOV / 2));
	data->sizeline = sizeline;
	data->bpp = bpp;
	data->newspritex = 0;
	data->newspritey = 0;
	data->signalsp = 0;
}

int		setupimages_andupdates(t_dataview *data)
{
	int			bpp;
	int			sizeline;
	int			endian;

	data->image_ptr = mlx_new_image(data->mlx_ptr, data->width, data->height);
	data->data = mlx_get_data_addr(data->image_ptr, &bpp, &sizeline, &endian);
	updatedirectionplayer(data);
	updateplayerposition(data);
	getrayvectors(data, sizeline, bpp);
	if (data->saveimage == 1)
	{
		saveimage(data);
		mlx_destroy_image(data->mlx_ptr, data->image_ptr);
		beforeexit(data);
		exit(SUCCESS);
	}
	else
	{
		mlx_put_image_to_window(data->mlx_ptr
		, data->win_ptr, data->image_ptr, 0, 0);
		mlx_destroy_image(data->mlx_ptr, data->image_ptr);
	}
	return (0);
}
