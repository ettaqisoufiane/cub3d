/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_map_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 03:33:31 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/26 02:50:17 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

void	free_after_splitting(char ***data)
{
	int		i;

	i = 0;
	if (*data != 0)
	{
		while ((*data)[i])
		{
			free((*data)[i]);
			(*data)[i] = 0;
			i++;
		}
		free((*data));
		(*data) = 0;
	}
}

void	treatfilecontent_3(char *line, t_list **list, t_dataview *data)
{
	getmap(line, list);
	data->signalsp = 1;
}

void	treatfilecontent_5(int *rtgnl, int *i, t_list **list, t_dataview *data)
{
	*rtgnl = 1;
	*list = 0;
	*i = 0;
	data->signalsp = 0;
}

void	treatfilecontent_6(t_list **list, t_dataview *data)
{
	setthemap(data, list);
	ft_lstclear(list, &free);
	list = 0;
}

void	treatfilecontent(int fd, t_dataview *data)
{
	char	*line;
	int		rtgnl;
	char	**arrline;
	t_list	*list;
	int		i;

	treatfilecontent_5(&rtgnl, &i, &list, data);
	while (rtgnl > 0)
	{
		rtgnl = get_next_line(fd, &line);
		arrline = ft_split(line, ' ');
		if (arrline[0] != 0)
		{
			if (arrline[0][0] == '1')
				treatfilecontent_3(line, &list, data);
			else if (arrline[0][0] != '1')
				treatfilecontent_2(data, arrline, i);
			else if (data->signalsp == 1)
				exiterror("File must end with the map\n", FAIL, data);
			treatfilecontent_4(&line, &arrline, 2);
		}
		treatfilecontent_4(&line, &arrline, 1);
		i++;
	}
	treatfilecontent_6(&list, data);
}
