# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: elenavoronin <elnvoronin@gmail.com>          +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/30 19:02:22 by evoronin      #+#    #+#                  #
#    Updated: 2023/07/04 18:06:59 by elenavoroni   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -I ../../../include -fsanitize=address-fno-omit-frame-pointer
NAME = tk_tests
SRCS_NAMES = tk_main.c ../tokenize_a.c ../tokenize_b.c ../../minilibft/mini_malloc.c ../../minilibft/mini_putstr_fd.c \
../../minilibft/mini_strlen.c ../../minilibft/mini_substr.c ../../lists/lists_a.c ../../lists/lists_b.c
OBJS_NAMES = $(SRCS_NAMES:.c=.o)
OBJS = $(OBJS_NAMES)

all:  $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) $(INC) -c $^ -o $@

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm $(OBJS_NAMES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
