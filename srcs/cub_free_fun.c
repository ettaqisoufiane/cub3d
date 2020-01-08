/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free_fun.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/24 02:22:19 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:15:45 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	exiterror(char *error, int errorn, t_dataview *data)
{
	ft_putstr_fd(error, 1);
	data->pwpp = 0;
	exit(errorn);
}

void	beforeexit(t_dataview *data)
{
	free(data->floor);
	free(data->ceil);
	free(data->north);
	free(data->east);
	free(data->west);
	free(data->south);
	mlx_destroy_image(data->mlx_ptr, data->image->image);
	free(data->image);
	mlx_destroy_image(data->mlx_ptr, data->image_1->image);
	free(data->image_1);
	mlx_destroy_image(data->mlx_ptr, data->image_2->image);
	free(data->image_2);
	mlx_destroy_image(data->mlx_ptr, data->image_3->image);
	free(data->image_3);
	mlx_destroy_image(data->mlx_ptr, data->image_4->image);
	free(data->image_4);
	free(data->image_data);
	free(data->image_data_1);
	free(data->image_data_2);
	free(data->image_data_3);
	free(data->image_data_4);
	free_after_splitting(&data->map);
}

void	setthemap_4(t_list **list)
{
	t_list	*tmp;

	free((char*)((*list)->content));
	tmp = *list;
	*list = (*list)->next;
	free(tmp);
}

void	treatfilecontent_4(char **line, char ***arrline, int c)
{
	if (c == 1)
	{
		free(*arrline);
		*arrline = 0;
		free(*line);
		*line = 0;
	}
	if (c == 2)
	{
		free_after_splitting(arrline);
		arrline = 0;
		free(*line);
		*line = 0;
	}
}
