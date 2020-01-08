/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:04:51 by settaqi           #+#    #+#             */
/*   Updated: 2019/12/09 01:27:02 by settaqi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include "../headers/cub3d.h"
# define BUFFER_SIZE 10

int		ft_walo(int fd, char **data);
int		get_next_line(int fd, char **tvg);
char	*ft_strjoint(char const *s1, char const *s2);
int		ft_strchrs(const char *str, int c, int cas);
char	*get_line(char **data, int *v);
char	*ft_substrt(char const *s, unsigned int start, int len);

#endif
