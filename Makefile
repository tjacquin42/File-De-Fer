# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tjacquin <tjacquin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/12 23:32:52 by tjacquin          #+#    #+#              #
#    Updated: 2017/02/13 03:43:25 by tjacquin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = srcs/main.c \
	  srcs/seg_tracer.c \
	  srcs/print_errors.c \
	  srcs/events_script.c \
	  srcs/send_to_trace.c \
	  srcs/display.c \
	  srcs/more_functions.c \

SRCO = main.o \
	   seg_tracer.o \
	   print_errors.o \
	   events_script.o \
	   send_to_trace.o \
	   display.o \
	   more_functions.o \

INCLUDE = includes/fdf.h \

COMPILE = -lm -L libft/ -lft -lmlx -framework OpenGL -framework AppKit

FLAGS = -Wall -Wextra -Werror

$(NAME):
	make -C libft/
	gcc $(FLAGS) -I $(INCLUDE) -c $(SRC)
	gcc $(SRCO) -o $(NAME) $(COMPILE)

all: $(NAME)

clean:
	/bin/rm -f $(SRCO)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
