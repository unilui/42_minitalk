CLIENT_SRCS		=	client_src/client.c \
					client_src/send_str.c \
					client_src/send_bit.c \
					client_src/response_handler.c
CLIENT_OBJS		=	${CLIENT_SRCS:%.c=$(OBJS_DIR)%.o}
CLIENT_NAME		=	client
SERVER_SRCS		=	server_src/server.c
SERVER_OBJS		=	${SERVER_SRCS:%.c=$(OBJS_DIR)%.o}
SERVER_NAME		=	server
OBJS_DIR		=	objects/
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror
LIBS			=	libft/libft.a
RM				=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@ -I includes

all:		libft $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME):	$(SERVER_OBJS)
			@$(CC) $(SERVER_OBJS) -o $(SERVER_NAME) $(LIBS)

$(CLIENT_NAME):	$(CLIENT_OBJS)
			@$(CC) $(CLIENT_OBJS) -o $(CLIENT_NAME) $(LIBS)

libft:
			@make -C libft --no-print-directory

libft_fclean:
			@make fclean -C libft --no-print-directory

clean:		libft_fclean
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(CLIENT_NAME)
			@$(RM) $(SERVER_NAME)

re:			fclean all

.PHONY:		all clean fclean re run libft
