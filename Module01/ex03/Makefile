# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjaen-mo <jjaen-mo@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/19 22:38:03 by jjaen-mo          #+#    #+#              #
#    Updated: 2024/03/20 02:25:01 by jjaen-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = violence
FILES = $(shell find src -type f -name "*.cpp")
OBJS = $(FILES:.cpp=.o)
GREEN=\033[0;32m
RED=\033[0;31m
END=\033[0m

$(NAME): $(OBJS)
	@c++ -Wall -Wextra -Werror -g $(FILES) -o $(NAME)
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