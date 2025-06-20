# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vde-maga <vde-maga@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 15:54:27 by vde-maga          #+#    #+#              #
#    Updated: 2025/06/20 18:02:38 by vde-maga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap 
CC = cc 
CFLAGS = -Wall - Wextra -Werror

SRCS =	srcs/main.c 
	srcs/misc/ranking.c 
	srcs/operations 
	srcs/sort
	srcs/utils/datatypes_utils.c 
	srcs/utils/errors.c
	srcs/utils/ft_split.c 
	srcs/utils/stack_utils.c

OBJS = $(SRCS:.c =.o)

GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[0;33m
CYAN = \033[0;36m
MAGENTA = \033[0;35m
BOLD = \033[1m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS)
	@echo -e "$(CYAN)\n Linking all Objects to Create $(NAME) $(RESET)"
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo -e "$(GREEN) Done! Run with ./$(NAME) $(RESET)"

%.o: %.c
	@echo -e "$(CYAN)\n Compiling $(RESET)"
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@
	@echo -e "$(GREEN) Done Compiling $(RESET)"

clean:
	@echo -e "$(CYAN)\n Cleaning Object Files $(RESET)"
	rm -rf $(OBJS)
	@echo -e "$(GREEN) Done Cleaning Object Files $(RESET)"

fclean: clean
	@echo -e "$(CYAN)\n Removing $(NAME) $(RESET)"
	rm -f $(NAME)
	@echo -e "$(GREEN) Removed $(NAME) $(RESET)"

re: fclean all

.PHONY: all clean fclean re
