SRCS =		ft_isalnum.c	ft_isalpha.c	ft_isascii.c	\
			ft_isdigit.c	ft_isprint.c	ft_strlen.c		\
			ft_bzero.c		ft_memcpy.c		ft_memmove.c	\
			ft_memset.c		ft_strlcat.c	ft_strlcpy.c	\
			ft_toupper.c	ft_tolower.c	ft_strchr.c		\
			ft_strrchr.c	ft_strncmp.c	ft_memchr.c		\
			ft_memcmp.c		ft_strnstr.c	ft_atoi.c		\
			ft_strdup.c		ft_calloc.c		ft_substr.c		\
			ft_strjoin.c	ft_strtrim.c	ft_split.c		\
			ft_itoa.c		ft_strmapi.c	ft_striteri.c	\
			ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
			ft_putnbr_fd.c	ft_chrpst.c		ft_printf.c		\
			ft_put_ptr.c	ft_put_u_nbr.c	ft_putchar.c	\
			ft_putnbr.c		ft_putstr.c		get_next_line.c	\
			ft_printf_utils/placeholder.c					\
			ft_printf_utils/replace_handler.c				\
			ft_printf_utils/replace_nbr.c					\
			ft_printf_utils/replace_str.c

HEADER		=	libft.h
OBJS		=	${SRCS:%.c=$(OBJS_DIR)%.o}
OBJS_DIR	=	objects/
NAME		=	libft.a
CC			=	cc
AR			=	ar rc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

$(OBJS_DIR)%.o:	%.c
			@mkdir -p $(dir $@)
			@$(CC) $(CFLAGS) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@$(AR) $(NAME) $(OBJS) $(HEADER)

clean:
			@$(RM) $(OBJS_DIR)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
