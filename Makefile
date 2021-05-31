# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: feschall <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 17:56:43 by feschall          #+#    #+#              #
#    Updated: 2021/05/31 13:49:36 by feschall         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -c -g

SRCS	= ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
		ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c \
		ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
		ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
		ft_putstr_fd.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_atoi_o.c

OBJDIR	:= .objlib
OBJS	:= $(SRCS:%.c=$(OBJDIR)/%.o)

all:	$(NAME)

$(NAME):	$(OBJS)
	@echo "$(FONT1)Создан$(FONT4)$@$(FONT99)"
	@ar rc $@ $(OBJS)
	@ranlib $@
	
$(OBJDIR)/%.o: %.c | $(OBJDIR)
	@echo "$(FONT1)Создан$(FONT5)$@$(FONT99)"
	@$(CC) $(CFLAGS) -o $@ $<

$(OBJDIR):
	@mkdir -p $@
	
clean:
	@rm -rf $(OBJDIR)

fclean:	clean
	@echo "$(FONT1)Очистка$(FONT6)libft$(FONT99)"
	@rm -rf $(NAME)

re:	fclean all

.PHONY: re all clean fclean

#-c говорит не запускать линкер, потому что нет main
#-g порождает отладочную информацию в родном формате операционной системы
#включает использование дополнительной отладочной информации, 
#которую может использовать только GDB; 
#эта дополнительная отладочная информация делает работу отладки в GDB лучше, но может, 
#вероятно испортить работу других отладчиков, или помешать им прочитать программу.

FONT99 = \033[0m #сброс цвета
FONT00 = \033[1m #жирный шрифт
FONT01 = \033[4m #подчеркивание
#COLOR12 = \033[6;35m - можно совмещать \033[6 - цвет шрифта ;35m - цвет фона
COLOR0 = \033[47m #серый цвет фона
FONT0 = \033[37m #серый цвет шрифта
COLOR1 = \033[46m #цвет морской волны фона		
FONT1 = \033[36m #цвет морской волны шрифта
COLOR2 = \033[45m #фиолетовый цвет фона
FONT2 = \033[35m #фиолетовый цвет шрифта
COLOR3 = \033[44m #синий цвет фона
FONT3 = \033[34m #синий цвет шрифта
COLOR4 = \033[43m #желтый цвет фона
FONT4 = \033[33m #желтый цвет шрифта
COLOR5 = \033[42m #зелёный цвет фона
FONT5 = \033[32m #зелёный цвет шрифта
COLOR6 = \033[41m #красный цвет фона
FONT6 = \033[31m #красный цвет шрифта
COLOR7 = \033[40m #чёрный цвет фона
FONT7 = \033[30m #чёрный цвет шрифта