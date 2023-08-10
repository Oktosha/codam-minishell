# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/12 11:12:29 by evoronin      #+#    #+#                  #
#    Updated: 2023/08/10 16:50:28 by codespace     ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ./include

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Darwin)
	READLINELINKFLAGS := -lreadline -L $(shell brew --prefix readline)/lib
else
	READLINELINKFLAGS := -lreadline
endif

ifeq ($(UNAME_S), Darwin)
	READLINEFLAGS ?= -I $(shell brew --prefix readline)/include
else
	READLINEFLAGS ?= -I/usr/include
endif

NAME = minishell

SRCS_DIR = ./src
SRCS_NAMES = \
execute/execute_a.c \
execute/execute_b.c \
execute/execute_c.c \
execute/execute_d.c \
execute/execute_e.c \
execute/execute_f.c \
expand/expand_a.c \
expand/expand_b.c \
lex/lex_a.c \
lex/lex_b.c \
lex/lex_c.c \
lifecycle/lifecycle_a.c \
lifecycle/lifecycle_b.c \
lifecycle/lifecycle_c.c \
lists/lists_a.c \
main.c \
minilibft/mini_assert.c \
minilibft/mini_concat.c \
minilibft/mini_find.c \
minilibft/mini_free.c \
minilibft/mini_malloc.c \
minilibft/mini_putstr_fd.c \
minilibft/mini_strcmp.c \
minilibft/mini_strdup.c \
minilibft/mini_strlen.c \
minilibft/mini_substr.c \
minilibft/mini_write.c \
parse/parse_a.c \
parse/parse_b.c \
parse/parse_c.c \
parse/parse_d.c \
tokenize/tokenize_a.c \
tokenize/tokenize_b.c \
tokenize/tokenize_c.c \
tokenize/tokenize_d.c

OBJS_NAMES = $(SRCS_NAMES:.c=.o)
OUT_DIR = ./objs
OBJS = $(addprefix $(OUT_DIR)/,$(OBJS_NAMES))
DEPS = $(OBJS:.o=.d)

all:  $(NAME)
-include $(DEPS)

$(OBJS): $(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ $(READLINEFLAGS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(READLINELINKFLAGS)

clean:
	rm -rf $(OUT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
