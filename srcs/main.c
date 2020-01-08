/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:57:12 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 21:52:20 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int		exit_button(void)
{
	exit(SUCCESS);
	return (0);
}

void	startgameorsave(t_dataview *data, char **argc, int argv, int f)
{
	if (f == 1)
	{
		initmap(data, argc, argv);
		data->startgame = 1;
	}
	if (f == 2)
	{
		data->saveimage = 1;
		if (data->startgame == 0)
			exiterror("Error: should give the file cub\n", FAIL, data);
	}
}

void	checkargs(t_dataview *data, int argv, char **argc)
{
	int		i;
	char	**datas;

	i = 1;
	data->saveimage = 0;
	data->startgame = 0;
	while (i < argv)
	{
		datas = ft_split(argc[i], '.');
		if (datas[1] != 0)
		{
			if (ft_strncmp(datas[1], "cub", 3) == 0)
				startgameorsave(data, argc, argv, 1);
			free_after_splitting(&datas);
		}
		else if (ft_strncmp(argc[i], "--save", 6) == 0)
		{
			startgameorsave(data, argc, argv, 2);
		}
		i++;
	}
}

int		main(int argv, char **argc)
{
	t_dataview		data;
	int				rtvalue;

	checkargs(&data, argv, argc);
	rtvalue = initgame(&data);
	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr,
				data.width, data.height, "Cub3d");
	settextureimage(&data);
	mlx_loop_hook(data.mlx_ptr,
			&checkforupdates, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
