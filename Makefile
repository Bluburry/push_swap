# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpinto-e <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/30 18:31:45 by tpinto-e          #+#    #+#              #
#    Updated: 2023/03/30 18:37:57 by tpinto-e         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap_lib.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

# location of all the files and folders used in this makefile
SRC_FLDR = src

# contains the folders that need to be appended to the files
STACK_OPS_FLDR = $(SRC_FLDR)/stack_ops
EXTRAS_FDLDR = $(SRC_FLDR)/basic_ops
ALGORITHM_FLDR = $(SRC_FLDR)/algorithms
INSERT_FLDR = $(ALGORITHM_FLDR)/insert

# files that need to be compiled
STACK_OPS_FILES = pushy.c reversy.c rotaty.c swappy.c
EXTRAS_FILES = start_handler.c basic_ops.c basic_squared.c print_list.c
ALGORITHM_FILES = sort_two_three.c sort_four_five.c
INSERT_FILES = new_ops.c smart_ops.c insert_ops.c rot_calcs.c insert_sort.c \
	pos_calcs.c

# appending folder to files
STACK_OPS_SRC = $(addprefix $(STACK_OPS_FLDR)/, $(STACK_OPS_FILES))
EXTRAS_SRC = $(addprefix $(EXTRAS_FDLDR)/, $(EXTRAS_FILES))
ALGORITHM_SRC = $(addprefix $(ALGORITHM_FLDR)/, $(ALGORITHM_FILES))
INSERT_SRC = $(addprefix $(INSERT_FLDR)/, $(INSERT_FILES))

STACK_OPS_OUT = $(STACK_OPS_SRC:.c=.o)
EXTRAS_OUT = $(EXTRAS_SRC:.c=.o)
ALGORITHM_OUT = $(ALGORITHM_SRC:.c=.o)
INSERT_OUT = $(INSERT_SRC:.c=.o)

#%.o: %.c
#	@$(CC) $(FLAG) -c $< -o $@

all : $(STACK_OPS_OUT) $(EXTRAS_OUT) $(ALGORITHM_OUT) $(INSERT_OUT)
	@echo "Entering libft."
	@$(MAKE) -C ./libft
	@cp ./libft/libft.a $(NAME)
	@echo "Creating archive."
	@ar rcs $(NAME) $(STACK_OPS_OUT) $(EXTRAS_OUT) $(ALGORITHM_OUT) $(INSERT_OUT) 
	@echo "Ready to use."

clean :
	@make clean -C ./libft
	@$(RM) $(STACK_OPS_OUT) $(EXTRAS_OUT) $(ALGORITHM_OUT) $(INSERT_OUT)
	@echo "Job done."

fclean : clean
	@make fclean -C ./libft
	@$(RM) $(NAME)
	@echo "Job done, but better."

re : fclean all

# extra makefile rules
checker :
	@echo "Compiling checker."
	@$(CC) $(FLAG) checker.c $(NAME) -o checker

comp :
	@echo "Compiling push swap."
	@$(CC) $(FLAG) push_swap.c $(NAME) -o push_swap

cleanest : fclean
	@$(RM) push_swap checker
	@echo "Job done, but even betterer."

.SILENT:

.PHONY : all, clean, fclean, re, comp, checker, cleanest
