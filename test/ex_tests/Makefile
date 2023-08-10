# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/30 19:02:22 by evoronin      #+#    #+#                  #
#    Updated: 2023/08/10 19:14:31 by codespace     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ex_test_ls.exe ex_test_ls_grep.exe ex_test_string_part.exe
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ../../kotishell/include -g
SRCS_FOLDER = ../../kotishell/src
SRCS_NAMES = \
minilibft/mini_free.c \
minilibft/mini_strlen.c \
minilibft/mini_find.c \
minilibft/mini_assert.c \
minilibft/mini_strcmp.c \
minilibft/mini_strdup.c \
minilibft/mini_malloc.c \
minilibft/mini_putstr_fd.c \
minilibft/mini_concat.c \
minilibft/mini_write.c \
lists/lists_a.c \
execute/execute_b.c \
execute/execute_a.c \
execute/execute_c.c \
execute/execute_d.c \
execute/execute_e.c \
execute/execute_f.c

TEST_SRCS_NAMES =  ex_test_ls.c ex_test_ls_grep.c ex_test_string_part.c
TEST_OBJS = $(addprefix $(OBJS_DIR)/,$(TEST_SRCS_NAMES:.c=.o))
OBJS_DIR = ./objs
ABSOLUTE_SRCS_NAMES = $(addprefix $(SRCS_FOLDER)/,$(SRCS_NAMES))
ABSOLUTE_OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS_NAMES:.c=.o))

all: $(NAME)

$(ABSOLUTE_OBJS): $(OBJS_DIR)/%.o: $(SRCS_FOLDER)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(TEST_OBJS): $(OBJS_DIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME): %.exe: %.o $(ABSOLUTE_OBJS)
	echo $^
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
