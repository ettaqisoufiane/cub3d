/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_savebitmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/25 00:17:18 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/25 04:16:26 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../headers/cub3d.h"

unsigned char	vif(t_dataview *data, int x, int y, int d)
{
	if (d == 1)
		return (data->data[y * data->sizeline + x * data->bpp / 8]);
	if (d == 2)
		return (data->data[y * data->sizeline + x * data->bpp / 8 + 1]);
	if (d == 3)
		return (data->data[y * data->sizeline + x * data->bpp / 8 + 2]);
	return (0);
}

void			writeonthefile(int *datas, unsigned char *buf
			, unsigned char *header)
{
	datas[0] = open("./screen.bmp", O_WRONLY | O_APPEND | O_CREAT, 0644);
	write(datas[0], header, 54);
	write(datas[0], buf, datas[5]);
	free(buf);
}

void			filltheimagebuff(int *datas, t_dataview *data,
				unsigned char *header)
{
	unsigned char	*buf;
	int				c;

	buf = malloc(datas[5]);
	c = 0;
	datas[10] = datas[2] - 1;
	while (datas[10] >= 0)
	{
		datas[11] = 0;
		while (datas[11] < datas[1])
		{
			buf[datas[10] * datas[4] + datas[11] * 3 + 0] =
					vif(data, datas[11], c, 1);
			buf[datas[10] * datas[4] + datas[11] * 3 + 1] =
					vif(data, datas[11], c, 2);
			buf[datas[10] * datas[4] + datas[11] * 3 + 2] =
					vif(data, datas[11], c, 3);
			datas[11] += 1;
		}
		datas[10] -= 1;
		c++;
	}
	writeonthefile(datas, buf, header);
}

void			saveimage(t_dataview *data)
{
	int				datas[12];
	unsigned char	*header;

	header = ft_calloc(54, sizeof(char));
	datas[1] = data->width;
	datas[2] = data->height;
	datas[3] = 24;
	datas[4] = ((datas[1] * datas[3] + 31) / 32) * 4;
	datas[5] = datas[4] * datas[2];
	datas[6] = 40;
	datas[7] = 54;
	datas[8] = 54 + datas[5];
	datas[9] = 1;
	ft_memcpy(header, "BM", 2);
	ft_memcpy(header + 2, &datas[8], 4);
	ft_memcpy(header + 10, &datas[7], 4);
	ft_memcpy(header + 14, &datas[6], 4);
	ft_memcpy(header + 18, &datas[1], 4);
	ft_memcpy(header + 22, &datas[2], 4);
	ft_memcpy(header + 26, &datas[9], 2);
	ft_memcpy(header + 28, &datas[3], 2);
	ft_memcpy(header + 34, &datas[5], 4);
	filltheimagebuff(datas, data, header);
}
