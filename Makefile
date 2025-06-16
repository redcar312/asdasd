# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurtamo <mhurtamo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/16 19:38:50 by mhurtamo          #+#    #+#              #
#    Updated: 2025/02/16 20:01:25 by mhurtamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= main.c events.c init.c mathops.c parser_utils.c render_fractal.c

HEAD	= ./

OBJS	= ${SRCS:.c=.o}

NAME	= fractol

RM	= rm -f

CC	= cc

MAKE	= make -sC

CFLAGS	= -Wall -Wextra -Werror

LIBXDIR = ./minilibx-linux

MLX = ${LIBXDIR}/libmlx_Linux.a

LINKER = -lmlx -lm -lz -lXext -lX11 -L ${LIBXDIR}

all:	${MLX} ${NAME}

c.o: ${CC} ${CFLAGS} -c -I ${HEAD} $< -o ${<:.c=.o}

${MLX}:
	${MAKE} ${LIBXDIR}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} ${LINKER} -o ${NAME}
		
clean:
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}
	${MAKE} ${LIBXDIR} clean 

re:	fclean all bonus clean



.PHONY:	all clean fclean re bonus
