# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: settaqi <settaqi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/25 04:07:06 by settaqi           #+#    #+#              #
#    Updated: 2019/12/26 03:29:07 by settaqi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

file_srcslibft = $(wildcard srcs/*.c GNL/*.c Libft/*.c)

all: $(NAME)

$(NAME):
	@gcc -Wextra -Werror -Wall $(file_srcslibft) -I mlx -L OpenGL -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:
	@/bin/rm -rf $(NAME)

fclean: clean

re: fclean all

.PHONY: clean fclean all re
