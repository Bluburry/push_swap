# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 18:06:52 by tpinto-e          #+#    #+#              #
#    Updated: 2023/03/30 15:18:28 by tpinto-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

# contains the folders that need to be appended to the files
PRINTF_FLDR = printf
LIBFT_FLDR = lib
GNL_FLDR = gnl

# files that need to be compiled
PRINTF_FILES = ft_printf.c ft_utils.c ft_printhexa.c ft_printptr.c 
GNL_FILES = get_next_line.c get_next_line_bonus.c get_next_line_utils.c
LIBFT_FILES = ft_atoi.c  ft_bzero.c  ft_calloc.c  ft_isalnum.c  ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strlcat.c ft_strchr.c ft_strlcpy.c ft_strncmp.c ft_strdup.c \
	ft_striteri.c ft_strjoin.c ft_strlen.c ft_strmapi.c ft_strnstr.c \
	ft_strrchr.c ft_substr.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c \
	ft_check_alnum.c ft_cmpstr.c

# appending folder to files
PRINTF_SRC = $(addprefix $(PRINTF_FLDR)/, $(PRINTF_FILES))
GNL_SRC = $(addprefix $(GNL_FLDR)/, $(GNL_FILES))
LIBFT_SRC = $(addprefix $(LIBFT_FLDR)/, $(LIBFT_FILES))

PRINTF_OUT = $(PRINTF_SRC:.c=.o)
GNL_OUT = $(GNL_SRC:.c=.o)
LIBFT_OUT = $(LIBFT_SRC:.c=.o)

%.o: %.c
	@$(CC) $(FLAG) -c $< -o $@

all: $(LIBFT_OUT) $(PRINTF_OUT) $(GNL_OUT)
	@ar rcs $(NAME) $(LIBFT_OUT) $(PRINTF_OUT) $(GNL_OUT)

clean : 
	@$(RM) $(LIBFT_OUT) $(PRINTF_OUT) $(GNL_OUT)

fclean : clean
	@$(RM) $(NAME)

re: fclean all

.SILENT:

.PHONY: all, clean, fclean, re, bonus
