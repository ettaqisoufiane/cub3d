/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 17:53:04 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 21:53:38 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

int		key_release(int key, t_dataview *params)
{
	if (key == 13 || key == 1)
	{
		params->movpressed = 0;
		if (key == 13)
			params->movkey_1 = 0;
		if (key == 1)
			params->movkey_2 = 0;
	}
	if (key == 2 || key == 0 || key == 123 || key == 124)
	{
		params->anglepressed = 0;
		if (key == 0 || key == 123)
			params->angkey_1 = 0;
		if (key == 2 || key == 124)
			params->angkey_2 = 0;
	}
	if (key == 53)
	{
		exit(SUCCESS);
		beforeexit(params);
	}
	return (0);
}

int		key_pressed(int key, t_dataview *params)
{
	if (key == 13 || key == 1)
	{
		params->movpressed = 1;
		if (key == 13)
			params->movkey_1 = 126;
		if (key == 1)
			params->movkey_2 = 125;
	}
	if (key == 2 || key == 0 || key == 123 || key == 124)
	{
		params->anglepressed = 1;
		if (key == 0 || key == 123)
			params->angkey_1 = 123;
		if (key == 2 || key == 124)
			params->angkey_2 = 124;
	}
	return (0);
}
