/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 03:29:17 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:20:18 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	checkfilename(char *filename, t_dataview *datad)
{
	char	**data;
	int		i;
	char	*strn;
	char	*errorc;

	errorc = "Error: File doesn't match the cubfile (i.e example.cub)\n";
	if (filename == 0)
		exiterror(errorc, FAIL, datad);
	data = ft_split(filename, '.');
	i = 0;
	while (data[i] != 0)
		i++;
	if (i != 2)
		exiterror(errorc, FAIL, datad);
	strn = ft_strnstr(data[1], "cub", 3);
	if (strn == 0)
		exiterror(errorc, FAIL, datad);
	if (ft_strlen(strn) != 3)
		exiterror(errorc, FAIL, datad);
	free_after_splitting(&data);
}

void	getresolution(char **arrline, t_dataview *data)
{
	if (arrline[1] != 0 && arrline[2] != 0 && data->width == 0
			&& data->height == 0 && arrline[3] == 0)
	{
		data->width = ft_atoi(arrline[1]);
		data->height = ft_atoi(arrline[2]);
		if (data->width < 0 || data->height < 0)
			exiterror("Error: Resolution should be a positive value\n"
				, FAIL, data);
	}
	else
		exiterror("Error: Can't get the resolution\n", FAIL, data);
}

void	getpaths(char **arrline, t_dataview *data, int b)
{
	if (arrline[1] != 0 && arrline[2] == 0)
	{
		if (b == 0 && data->sprite == 0)
			data->sprite = ft_strdup(arrline[1]);
		else if (b == 1 && data->north == 0)
			data->north = ft_strdup(arrline[1]);
		else if (b == 2 && data->west == 0)
			data->west = ft_strdup(arrline[1]);
		else if (b == 3 && data->south == 0)
			data->south = ft_strdup(arrline[1]);
		else if (b == 4 && data->east == 0)
			data->east = ft_strdup(arrline[1]);
		else
			exiterror("Error: duplicate paths !", FAIL, data);
	}
	else
		exiterror("Error: Can't get paths texture", FAIL, data);
}

int		valuergb(int i, char *value, t_dataview *data)
{
	if (i >= 0 && i <= 255 && valuergbchecker(value, data))
		return (i);
	else
		exiterror("Error: RGB color must be between 0 && 255\n", FAIL, data);
	return (0);
}

void	getflandcecolor(char **arrline, t_dataview *data, int n)
{
	t_colorinfo		*colors;
	char			**clr;

	if (arrline[1] != 0)
	{
		colors = (t_colorinfo*)malloc(sizeof(t_colorinfo) * 1);
		clr = ft_split(arrline[1], ',');
		if (clr[0] != 0 && clr[1] != 0
			&& clr[2] != 0 && clr[3] == 0)
		{
			colors->color3 = valuergb(ft_atoi(clr[0]), clr[0], data);
			colors->color2 = valuergb(ft_atoi(clr[1]), clr[1], data);
			colors->color1 = valuergb(ft_atoi(clr[2]), clr[2], data);
			free_after_splitting(&clr);
			getfloandcecolors_2(n, data, colors);
		}
		else
			exiterror("Error: Can't get colors of floor or ceil\n",
				FAIL, data);
	}
	else
		exiterror("Error: Can't get colors of floor or ceil\n", FAIL, data);
}
