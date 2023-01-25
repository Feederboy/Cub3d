# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/06 23:40:58 by ykeciri           #+#    #+#              #
#    Updated: 2022/07/16 21:38:29 by mguerra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC_DIR = src
OBJ_DIR = obj
SRC = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(SRC_DIR)/*/*.c)
OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))
DEP = $(OBJ:.o=.d)
CC = clang
C_FLAGS = -Wall -Wextra -Werror -g3 -MMD
INCLUDES = -I includes/

LIB_DIR = ./lib

LIBFT_DIR = $(LIB_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBFT_INC = -L$(LIBFT_DIR) -lft

MLX = mlx
MLX_DIR = $(LIB_DIR)/$(MLX)
MLX_LIB = $(MLX_DIR)/libmlx.a
MLX_OBJ_INC = -I/usr/include -I$(MLX_DIR)
MLX_INC = -I$(MLX_DIR) -L$(MLX_DIR) -l$(MLX) -L/usr/lib -lXext -lX11 -lm -lz
MLX_INC_MACOS = -I$(MLX_DIR) -L$(MLX_DIR) -l$(MLX) -L/usr/lib -framework OpenGL -framework AppKit -lm -lz

.PHONY: all
all: $(NAME)

-include $(DEP)
obj/%.o: src/%.c
	@mkdir -p $(dir $@)
	$(CC) $(C_FLAGS) $(INCLUDES) -O3 -c $< -o $@

$(NAME): $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) $(C_FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT_INC) $(MLX_INC)

$(LIBFT):
	@make -sC $(LIBFT_DIR)
	@echo LIBFT: COMPILED

$(MLX_LIB):
	make -C $(MLX_DIR)

mac: $(LIBFT) $(MLX_LIB) $(OBJ)
	$(CC) $(C_FLAGS) $(INCLUDES) $(OBJ) -o $(NAME) $(LIBFT_INC) $(MLX_INC_MACOS)

.PHONY: clean
clean:
	rm -rf obj/

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	@make fclean -sC $(LIBFT_DIR)
	@echo LIBFT: DELETED

.PHONY: re
re: fclean all

.PHONY: src
src:
	@echo -n "SRC = "
	@find src -name "*.c" | tr '\n' ' ' | sed --expression="s, , \\\\\n,4;P;D" 
	@echo 

.PHONY: rsrc
rsrc:
	@echo "SRC = \$$(wildcard \$$(SRC_DIR)/*.c) \$$(wildcard \$$(SRC_DIR)/*/*.c)"

.PHONY: check
check:
	@norminette | grep Error && echo "Norme: KO" || echo "OK"
	@cat Makefile | grep SRC | grep wildcard | grep -v '"SRC' || echo "Wildcard: OK"
	@nm -u $(NAME) | grep 'printf' && echo "Unauthorized functions: KO" || echo "Unauthorized functions: OK"
