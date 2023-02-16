SERVER	=	server
CLIENT	=	client

CC		=	gcc
RM		=	rm -f
FLAGS	=	-Wall -Werror -Wextra

NAME	=	server client

all: $(NAME) 

server:		server.o		
	$(CC) $(CFLAGS) server.c ft_itoa.c -o $(SERVER)

client:		client.o
	$(CC) $(CFLAGS) client.c ft_itoa.c ./utils/ft_atoi.c -o $(CLIENT)

clean:
	$(RM) server client *.o

fclean: 	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re
