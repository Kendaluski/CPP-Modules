# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/01 08:00:21 by jjaen-mo          #+#    #+#              #
#    Updated: 2024/11/06 18:21:06 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rpn
FILES = $(shell find . -name "*.cpp")
OBJS = $(FILES:.cpp=.o)
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

$(NAME): $(OBJS)
	@c++ -Wall -Wextra -Werror -std=c++98 $(FILES) -o $(NAME)
	@echo "$(GREEN) Program compiled! $(END)"

$(OBJS): $(FILES)
	@c++ -Wall -Wextra -Werror -c $< -o $@

fclean:
	@rm -f $(NAME) $(OBJS)
	@echo "$(RED) Program and objects deleted! $(END)"

clean:
	@rm -f $(OBJS)
	@echo "$(RED) Objects deleted! $(END)"

re: fclean $(NAME)

.PHONY: clean fclean