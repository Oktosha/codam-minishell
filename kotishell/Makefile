# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/12 11:12:29 by evoronin      #+#    #+#                  #
#    Updated: 2023/07/26 14:05:09 by elenavoroni   ########   odam.nl          #
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
endif

NAME = minishell

SRCS_DIR = ./src
SRCS_NAMES = \
expand/expand_a.c \
lex/lex_a.c \
lists/lists_a.c \
parse/parse_a.c \
lifecycle/lifecycle_c.c \
lifecycle/lifecycle_a.c \
lifecycle/lifecycle_b.c \
main.c \
minilibft/mini_strlen.c \
minilibft/mini_assert.c \
minilibft/mini_malloc.c \
minilibft/mini_putstr_fd.c \
execute/execute_a.c \
tokenize/tokenize_d.c \
tokenize/tokenize_c.c \
tokenize/tokenize_b.c \
tokenize/tokenize_a.c

OBJS_NAMES = $(SRCS_NAMES:.c=.o)
OUT_DIR = ./objs
OBJS = $(addprefix $(OUT_DIR)/,$(OBJS_NAMES))
DEPS = $(OBJS:.o=.d)

all:  $(NAME)
-include $(DEPS)

$(OBJS): $(OUT_DIR)/%.o: $(SRCS_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(READLINEFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(READLINELINKFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OUT_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
