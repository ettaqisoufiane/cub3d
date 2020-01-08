/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 03:06:34 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 03:22:01 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	setthemap_2(t_dataview *data, t_list **list
			, char **content, int *mapwidth)
{
	int		i;

	data->map = (char**)malloc(sizeof(char*) * ft_lstsize(*list) + 1);
	data->mapheight = ft_lstsize(*list);
	i = 0;
	*mapwidth = 0;
	*content = (char*)((*list)->content);
	while ((*content)[i] != '\0')
	{
		*content = (char*)((*list)->content);
		if ((*content)[i] != ' ')
			*mapwidth += 1;
		i++;
	}
	data->mapwidth = *mapwidth;
	*mapwidth = ft_strlen(*content);
}

void	setthemap_3(t_dataview *data, t_list **list
			, char **content, int *mapwidth)
{
	int		i;
	int		c;
	int		r;

	i = 0;
	while (*list != 0 && (c = 0) == 0)
	{
		*content = (char*)((*list)->content);
		if (*content != 0 && ft_strlen(*content) != (size_t)*mapwidth)
			exiterror("Error: The length of map width must be the same\n",
					FAIL, data);
		data->map[i] = (char*)malloc(sizeof(char*) * (size_t)(*mapwidth) + 1);
		r = 0;
		while ((*content)[c] != '\0')
		{
			*content = (char*)((*list)->content);
			if ((*content)[c] != ' ')
				data->map[i][r++] = (*content)[c];
			c++;
		}
		data->map[i][r] = '\0';
		setthemap_4(list);
		i++;
	}
	data->map[i] = 0;
}

void	setthemap(t_dataview *data, t_list **list)
{
	int		mapwidth;
	int		i;
	char	*content;

	if (*list != 0)
		setthemap_2(data, list, &content, &mapwidth);
	i = 0;
	if (*list != 0)
		setthemap_3(data, list, &content, &mapwidth);
}

void	treatfilecontent_7(t_dataview *data, char **arrline, int lenght)
{
	if (lenght == 2)
	{
		if (ft_strnstr(arrline[0], "NO", lenght))
			getpaths(arrline, data, 1);
		else if (ft_strnstr(arrline[0], "WE", lenght))
			getpaths(arrline, data, 2);
		else if (ft_strnstr(arrline[0], "SO", lenght))
			getpaths(arrline, data, 3);
		else if (ft_strnstr(arrline[0], "EA", lenght))
			getpaths(arrline, data, 4);
		else
			data->ut = 1;
	}
}

void	treatfilecontent_2(t_dataview *data, char **arrline, int i)
{
	int		lenght;

	lenght = ft_strlen(arrline[0]);
	i = 0;
	if (lenght == 1)
	{
		if (ft_strnstr(arrline[0], "R", 1))
			getresolution(arrline, data);
		else if (ft_strnstr(arrline[0], "S", 1))
			getpaths(arrline, data, 0);
		else if (ft_strnstr(arrline[0], "F", 1))
			getflandcecolor(arrline, data, 0);
		else if (ft_strnstr(arrline[0], "C", 1))
			getflandcecolor(arrline, data, 1);
		else
			data->ut = 1;
	}
	treatfilecontent_7(data, arrline, lenght);
}
