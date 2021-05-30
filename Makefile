# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feschall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 17:56:43 by feschall          #+#    #+#              #
#    Updated: 2021/05/30 20:25:37 by feschall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi_o.c

OBJ	:= $(SRCS:%.c=%.o)
OBJDIR	:= .obj

all:	$(NAME)

$(NAME):	$(OBJ) $(OBJDIR)
	@echo Сборка libft
	@$(CC) $(CFLAGS) $(SRCS) -c
	@ar rc $@ $(OBJ)
	@mv $(OBJ) $(OBJDIR)
	
$(OBJDIR):
	@mkdir -p $@

clean:
	@rm -rf $(OBJDIR) *.o

fclean:	clean
	@echo Очистка libft
	@rm -rf $(NAME)

re:	fclean all

.PHONY: re all clean fclean

