# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 06:04:46 by mguerra           #+#    #+#              #
#    Updated: 2022/05/03 21:34:02 by mguerra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)
CC = clang
C_FLAGS = -Wall -Wextra -Werror -g3 -MMD
INCLUDES = -I includes/

_RESET="\033[0m"
_BOLD="\033[1m"
_GREEN="\033[32m"

all: $(NAME)

-include $(DEP)
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	@echo $(_BOLD)$(notdir $<): $(_GREEN)✔$(_RESET)
	@$(CC) $(C_FLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@echo $(_BOLD)LIBFT: $(_GREEN)Done$(_RESET)

.PHONY: clean
clean:
	@rm -f $(OBJ)

.PHONY: fclean
fclean: clean
	@rm -f $(NAME)
	@echo $(_BOLD)LIBFT: $(_GREEN)Cleaned$(_RESET)

.PHONY: re
re: fclean all


test:
	echo $(SRC)