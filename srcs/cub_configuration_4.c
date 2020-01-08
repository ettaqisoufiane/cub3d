/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_configuration_4.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 03:18:19 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:20:39 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		getplayerposition_1(t_dataview *data, float x, float y)
{
	if (data->map[(int)y][(int)x] == 'N'
			|| data->map[(int)y][(int)x] == 'S'
			|| data->map[(int)y][(int)x] == 'W'
			|| data->map[(int)y][(int)x] == 'E')
	{
		if (data->y != 0 && data->x != 0)
			exiterror("Error: Player defined more than once !\n"
				, FAIL, data);
		if (data->map[(int)y][(int)x] == 'N')
			data->angle = 90;
		if (data->map[(int)y][(int)x] == 'S')
			data->angle = 270;
		if (data->map[(int)y][(int)x] == 'W')
			data->angle = 180;
		if (data->map[(int)y][(int)x] == 'E')
			data->angle = 0;
		data->y = y * data->gridy + data->gridy / 2;
		data->x = x * data->gridx + data->gridx / 2;
		return (1);
	}
	return (0);
}

int		valuergbchecker(char *value, t_dataview *data)
{
	int		c;
	int		k;
	char	*chars;
	int		d;

	c = 0;
	chars = "0123456789 ";
	while (value[c])
	{
		k = 0;
		d = 0;
		while (chars[k])
		{
			if (chars[k++] == value[c])
				d = 1;
		}
		if (d != 1)
			exiterror("Error: RGB color must be a number without sym\n"
			, FAIL, data);
		c++;
	}
	return (1);
}

void	getmap(char *line, t_list **list)
{
	if (*list == 0)
	{
		if (line != 0)
			*list = ft_lstnew(ft_strdup(line));
	}
	else if (*list != 0)
	{
		if (line != 0)
			ft_lstadd_back(list, ft_lstnew(ft_strdup(line)));
	}
}
