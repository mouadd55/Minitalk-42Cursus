# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moudrib <moudrib@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/19 12:42:23 by moudrib           #+#    #+#              #
#    Updated: 2023/01/27 01:07:09 by moudrib          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	minitalk.a
SERVER			=	server
CLIENT			=	client
SERVER_BONUS	=	server_bonus
CLIENT_BONUS	=	client_bonus
CC         		=	cc
CFLAGS	   		=	-Wall -Wextra -Werror


SRC1	   =	server.c
SRC2       =	client.c
BONUS_SRC1 =	server_bonus.c
BONUS_SRC2 =	client_bonus.c
SRC_UTILS  =	utils.c

OBJ1       =	$(SRC1:.c=.o)
OBJ2       =	$(SRC2:.c=.o)
BONUS_OBJ1 =	$(BONUS_SRC1:.c=.o)
BONUS_OBJ2 =	$(BONUS_SRC2:.c=.o)
OBJ_UTILS  = 	$(SRC_UTILS:.c=.o)



all: $(NAME) $(SERVER) $(CLIENT)

%.o: %.c minitalk.h
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJ_UTILS)
	ar rc $(NAME) $(OBJ_UTILS)

$(SERVER): $(OBJ1)
	$(CC) $(CFLAGS) $(SRC1) $(NAME) -o $(SERVER)

$(CLIENT): $(OBJ2)
	$(CC) $(CFLAGS) $(SRC2) $(NAME) -o $(CLIENT)

bonus: $(NAME) $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS): $(BONUS_OBJ1)
	$(CC) $(CFLAGS) $(BONUS_SRC1) $(NAME) -o $(SERVER_BONUS)

$(CLIENT_BONUS): $(BONUS_OBJ2)
	$(CC) $(CFLAGS) $(BONUS_SRC2) $(NAME) -o $(CLIENT_BONUS)

clean:
	rm -f $(OBJ1) $(OBJ2) $(BONUS_OBJ1) $(BONUS_OBJ2) $(OBJ_UTILS)

fclean: clean
	rm -f $(SERVER) $(CLIENT) $(SERVER_BONUS) $(CLIENT_BONUS) $(NAME)

re: fclean all

re_bonus: fclean bonus

.PHONY: all clean fclean re bonus re_bonus