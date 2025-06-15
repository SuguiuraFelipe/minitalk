# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fsuguiur <fsuguiur@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/15 13:06:54 by fsuguiur          #+#    #+#              #
#    Updated: 2025/06/15 13:07:00 by fsuguiur         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server
CLIENT = client
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCDIR = src

OBJS_COMMON = $(SRCDIR)/utils.o

all: $(SERVER) $(CLIENT)

$(SERVER): $(SRCDIR)/server.o $(OBJS_COMMON)
	$(CC) $(CFLAGS) $^ -o $(SERVER)

$(CLIENT): $(SRCDIR)/client.o $(OBJS_COMMON)
	$(CC) $(CFLAGS) $^ -o $(CLIENT)

$(SRCDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(SRCDIR)/*.o

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re