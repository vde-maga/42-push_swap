# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/20 20:33:55 by vde-maga          #+#    #+#              #
#    Updated: 2025/07/09 14:57:44 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g

#SRCS =	srcs/main.c \
	srcs/error/error.c \
	srcs/operations/ft_push.c \
	srcs/operations/ft_rotate.c \
	srcs/operations/ft_swap.c \
	srcs/sort/ft_radix.c \
	srcs/sort/ft_sort_small.c \
	srcs/stack/init.c \
	srcs/stack/radix_stack_utils.c \
	srcs/stack/ft_sort_small_utils.c \
	srcs/stack/stack_utils.c \
	srcs/utils/checkers.c \
	srcs/utils/ft_split.c \
	srcs/utils/libft.c \

SRCS := $(shell find srcs -name "*.c")

OBJDIR = objs
OBJS = $(SRCS:srcs/%.c=$(OBJDIR)/%.o)
INCDIR = includes

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo  "$(CYAN)\n Linking all Objects to Create $(NAME) $(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo  "$(GREEN) Done! Run with ./$(NAME) $(RESET)"

$(OBJDIR)/%.o: srcs/%.c
	@mkdir -p $(dir $@)
	@echo  "$(CYAN)\n Compiling $(RESET)"
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo  "$(GREEN) Done Compiling $(RESET)"

clean:
	@echo  "$(CYAN)\n Cleaning Object Files $(RESET)"
	rm -rf $(OBJDIR)
	@echo  "$(GREEN) Done Cleaning Object Files $(RESET)"

fclean: clean
	@echo  "$(CYAN)\n Removing $(NAME) $(RESET)"
	rm -f $(NAME)
	@echo  "$(GREEN) Removed $(NAME) $(RESET)"

re: fclean all

.PHONY: all clean fclean re
