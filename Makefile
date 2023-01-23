# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 12:42:23 by moudrib           #+#    #+#              #
#    Updated: 2023/01/21 14:25:22 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = minitalk.a
# CC = cc
# CFLAGS = -Wall -Wextra -Werror
# SRC = client.c server.c utils.c
# OBJ = $(SRC:.c=.o)

# all : $(NAME) 

# $(NAME) : $(OBJ)
# 	ar rc $(NAME) $(OBJ)

# %.o : %.c minitalk.h
# 	$(CC) $(CFLAGS) -c $<

# clean :
# 	rm -f $(OBJ)

# fclean : clean
# 	rm -f $(NAME)

# re : fclean all

all :
	gcc server.c minitalk.a -o server
	gcc client.c minitalk.a -o client