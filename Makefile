SRC = server.c client.c
OBJS = $(SRC=.c=.o)
NAME = minitalk
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror

CLIENT = client
SERVER = server

all: $(NAME)

$(NAME) : $(SERVER) $(CLIENT)

$(SERVER): server.c minitalk.h
	$(CC) $(CFLAGS) -o server server.c

$(CLIENT): client.c minitalk.h
	$(CC) $(CFLAGS) -o client client.c

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean

re: fclean all

.PHONY: all clean fclean re