/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:04:33 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/09 01:27:07 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			returnvalue(char **tvg, char *data, int v)
{
	if (*tvg == NULL && v == -1)
	{
		return (-1);
	}
	if (data == NULL && *tvg == NULL)
	{
		*tvg = ft_strjoint("", "");
		return (0);
	}
	if (v == 1)
		return (0);
	return (1);
}

char		*ft_strjoint(char const *s1, char const *s2)
{
	char	*string;
	char	*savestr;

	if (!s1 || !s2)
		return (0);
	if (!(string = (char*)malloc((ft_strlen((char*)s1) +
				ft_strlen((char*)s2) + 1) * sizeof(char))))
		return (0);
	savestr = string;
	while (*s1)
		*string++ = *s1++;
	while (*s2)
		*string++ = *s2++;
	*string = '\0';
	return (savestr);
}

int			get_next_line(int fd, char **tvg)
{
	static char		*data;
	int				i;
	int				v;

	if (fd < 0 || tvg == NULL || BUFFER_SIZE == 0)
		return (-1);
	v = 0;
	i = ft_walo(fd, &data);
	if (i == -1)
		return (-1);
	*tvg = get_line(&data, &v);
	if (v == 1)
	{
		free(data);
		data = NULL;
	}
	return (returnvalue(tvg, data, v));
}
