/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_textureimage.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:48:51 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 15:53:26 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	checktextureifexist(char *path, t_dataview *data)
{
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exiterror("Error: One of your texture path doesn't exist\n"
			, FAIL, data);
}

void	settextureimage_getadd(t_dataview *data)
{
	data->image_data = malloc(sizeof(t_imagedata) * 1);
	getimagedata(data->image_data, data->image->image);
	data->image_data_1 = malloc(sizeof(t_imagedata) * 1);
	getimagedata(data->image_data_1, data->image_1->image);
	data->image_data_2 = malloc(sizeof(t_imagedata) * 1);
	getimagedata(data->image_data_2, data->image_2->image);
	data->image_data_3 = malloc(sizeof(t_imagedata) * 1);
	getimagedata(data->image_data_3, data->image_3->image);
	data->image_data_4 = malloc(sizeof(t_imagedata) * 1);
	getimagedata(data->image_data_4, data->image_4->image);
}

void	getimagevoid(t_voidimage *image, char *path_image, t_dataview *data)
{
	int		widthimage;
	int		heightimage;

	image->image = mlx_xpm_file_to_image(data->mlx_ptr
	, path_image, &widthimage, &heightimage);
	image->textureheight = heightimage;
	image->texturewidth = widthimage;
}

void	settextureimage(t_dataview *data)
{
	checktextureifexist(data->west, data);
	checktextureifexist(data->east, data);
	checktextureifexist(data->north, data);
	checktextureifexist(data->south, data);
	checktextureifexist(data->sprite, data);
	data->image = malloc(sizeof(t_voidimage) * 1);
	getimagevoid(data->image, data->west, data);
	data->image_1 = malloc(sizeof(t_voidimage) * 1);
	getimagevoid(data->image_1, data->east, data);
	data->image_2 = malloc(sizeof(t_voidimage) * 1);
	getimagevoid(data->image_2, data->north, data);
	data->image_3 = malloc(sizeof(t_voidimage) * 1);
	getimagevoid(data->image_3, data->south, data);
	data->image_4 = malloc(sizeof(t_voidimage) * 1);
	getimagevoid(data->image_4, data->sprite, data);
	settextureimage_getadd(data);
}

void	getimagedata(t_imagedata *imagedata, void *image)
{
	int		bpp;
	int		sizeline;
	int		endian;

	imagedata->dataimage = mlx_get_data_addr(image, &bpp, &sizeline, &endian);
	imagedata->tx_bpp = bpp;
	imagedata->tx_sl = sizeline;
	imagedata->tx_end = endian;
}
