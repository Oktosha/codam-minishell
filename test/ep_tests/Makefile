# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/30 19:02:22 by evoronin      #+#    #+#                  #
#    Updated: 2023/08/15 12:29:27 by evoronin      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = ep_tests
CC = cc
CFLAGS = -Wall -Wextra -Werror -I ../../kotishell/include -g
SRCS_FOLDER = ../../kotishell/src
SRCS_NAMES = expand/expand_a.c expand/expand_b.c expand/expand_c.c\
lex/lex_a.c lex/lex_b.c lex/lex_c.c \
tokenize/tokenize_a.c tokenize/tokenize_b.c tokenize/tokenize_c.c \
tokenize/tokenize_d.c \
lists/lists_a.c \
minilibft/mini_strlen.c \
minilibft/mini_malloc.c \
minilibft/mini_putstr_fd.c\
minilibft/mini_assert.c \
minilibft/mini_write.c \
minilibft/mini_substr.c

TEST_SRCS_NAMES = ep_main.c
TEST_OBJS = $(addprefix $(OBJS_DIR)/,$(TEST_SRCS_NAMES:.c=.o))
OBJS_DIR = ./objs
ABSOLUTE_SRCS_NAMES = $(addprefix $(SRCS_FOLDER)/,$(SRCS_NAMES))
ABSOLUTE_OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS_NAMES:.c=.o))

all:  $(NAME)

$(ABSOLUTE_OBJS): $(OBJS_DIR)/%.o: $(SRCS_FOLDER)/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $^ -o $@

$(TEST_OBJS): $(OBJS_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $^ -o $@

OBJS=$(TEST_OBJS) $(ABSOLUTE_OBJS)

$(NAME): $(OBJS)
	echo $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
