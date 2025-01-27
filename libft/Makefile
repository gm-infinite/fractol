# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kuzyilma <kuzyilma@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 11:20:24 by kuzyilma          #+#    #+#              #
#    Updated: 2024/12/06 10:30:50 by kuzyilma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFILES = ft_isalnum.c    ft_isdigit.c    ft_memset.c     ft_strlcpy.c    ft_toupper.c \
ft_isalpha.c    ft_isprint.c    ft_strchr.c     ft_strlen.c		ft_strrchr.c		\
ft_isascii.c    ft_memmove.c    ft_strlcat.c    ft_tolower.c	ft_bzero.c	ft_memcpy.c	\
ft_strncmp.c	ft_memchr.c		ft_memcmp.c		ft_strnstr.c	ft_atoi.c	ft_calloc.c \
ft_strdup.c		ft_substr.c		ft_strjoin.c	ft_strtrim.c	ft_split.c	ft_itoa.c \
ft_strmapi.c	ft_striteri.c	ft_putchar_fd.c	ft_putstr_fd.c	ft_putendl_fd.c	\
ft_putnbr_fd.c \
ft_lstadd_back_bonus.c  ft_lstdelone_bonus.c    ft_lstmap_bonus.c \
ft_lstadd_front_bonus.c ft_lstiter_bonus.c      ft_lstnew_bonus.c  \
ft_lstclear_bonus.c     ft_lstlast_bonus.c      ft_lstsize_bonus.c

PRINTFFILES = ft_char_size.c	    ft_mstrchr.c       ft_putpointer.c	     ft_vavalue_reset.c \
ft_deci_int_size.c  ft_pointer_size.c  ft_putunsnbr.c	     ft_vavalue_set.c \
ft_flag_reset.c     ft_printf.c        ft_string_size.c      ft_vputchar.c \
ft_flag_set.c	    ft_puthexa.c       ft_trueprint_reset.c  ft_vputstr.c \
ft_hexa_size.c	    ft_putHEXAu.c      ft_trueprint_set.c \
ft_len_putstr.c     ft_putnbr.c        ft_unsint_size.c

CFILES = $(addprefix libft_src/, $(LIBFILES)) $(addprefix printf_src/, $(PRINTFFILES))

OFILES = $(CFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re