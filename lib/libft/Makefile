# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mguerra <mguerra@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/03 06:04:46 by mguerra           #+#    #+#              #
#    Updated: 2023/02/16 16:00:45 by mguerra          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_DIR = src
OBJ_DIR = obj
SRC = src/ft_printf/display_base.c src/ft_printf/display_hex.c src/ft_printf/ft_printf.c src/garbage_collector/gc_utils.c \
src/garbage_collector/gc_strtrim.c src/garbage_collector/gc_split.c src/garbage_collector/gc_lstnew.c src/garbage_collector/gc_substr.c \
src/garbage_collector/garbage_collector.c src/garbage_collector/gc_gnl.c src/garbage_collector/gc_strreplace.c src/garbage_collector/gc_itoa.c \
src/garbage_collector/gc_strnjoin.c src/garbage_collector/gc_strdup.c src/garbage_collector/gc_calloc.c src/garbage_collector/gc_get_next_line.c \
src/garbage_collector/gc_strjoin.c src/garbage_collector/gc_strmapi.c src/garbage_collector/gc_lst_to_matrix.c src/garbage_collector/gc_strndup.c \
src/garbage_collector/gc_lstmap.c src/matrix/ft_free_matrix.c src/matrix/ft_matrix_len.c src/mem/ft_memcmp.c \
src/mem/ft_memcpy.c src/mem/ft_calloc.c src/mem/ft_memmove.c src/mem/ft_bzero.c \
src/mem/ft_memset.c src/mem/ft_memchr.c src/char/ft_isalpha.c src/char/ft_isalnum.c \
src/char/ft_isdigit.c src/char/ft_isprint.c src/char/ft_tolower.c src/char/ft_toupper.c \
src/char/ft_has_char.c src/char/ft_iswhitespace.c src/char/ft_isascii.c src/char/ft_islower.c \
src/char/ft_isupper.c src/char/ft_indexof.c src/char/ft_has_non_printable_char.c src/str/ft_strndup.c \
src/str/ft_strnstr.c src/str/ft_strstr.c src/str/ft_strtrim.c src/str/ft_strcmp.c \
src/str/ft_strncmp.c src/str/ft_strlen.c src/str/ft_strreplace.c src/str/ft_atol.c \
src/str/ft_substr.c src/str/ft_strmapi.c src/str/ft_strchr.c src/str/ft_atoi.c \
src/str/ft_itoa.c src/str/ft_strjoin.c src/str/ft_split.c src/str/is_numeric.c \
src/str/ft_strlcat.c src/str/ft_strrchr.c src/str/ft_striteri.c src/str/ft_strdup.c \
src/str/ft_strlcpy.c src/list/ft_lstdelone.c src/list/ft_lstadd_front.c src/list/ft_lstclear.c \
src/list/ft_lstadd_back.c src/list/ft_lstnew.c src/list/ft_lstsize.c src/list/ft_lstiter.c \
src/list/ft_lstmap.c src/list/ft_lst_to_matrix.c src/list/ft_lstlast.c src/fd/ft_putendl_fd.c \
src/fd/ft_putstr_fd.c src/fd/ft_putchar_fd.c src/fd/ft_putnbr_fd.c src/numbers/ft_max_factor.c
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

.PHONY: src
src:
	@echo -n "SRC = "
	@find src -name "*.c" | tr '\n' ' ' | sed --expression="s, , \\\\\n,4;P;D" 
	@echo 
test:
	echo $(SRC)