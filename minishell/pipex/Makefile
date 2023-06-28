# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evoronin <evoronin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/02/03 11:47:21 by evoronin      #+#    #+#                  #
#    Updated: 2023/05/07 14:51:57 by mbp14         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

RED=\033[1;31m
GREEN=\033[1;32m
YELLOW=\033[1;33m
BLUE=\033[1;34m
MAGENTA=\033[1;35m
CYAN=\033[1;36m
END=\033[0m

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -fsanitize=address
NAME = pipex
SRCS = pipex.c\
		split_cmd.c\
		pipex_utils.c\
		
LIBFT = libft/libft.a
DIR_I = ../pipex

${NAME}: ${SRCS}
	@make -s -C ./libft
	@echo "${BLUE}Compiling ${NAME}${END}"
	@${CC} ${CFLAGS} ${SRCS} ${LIBFT} -I ${DIR_I} -o ${NAME}
	@echo "${GREEN}Done!${END}"

all: ${NAME}

clean:
	@make clean -C libft
	@echo "${RED}Removing in/outfile${END}"
	@rm -rf test
	@rm -rf output
	@echo "${GREEN}Done!${END}"

fclean: clean
	@make fclean -C libft
	@echo "${RED}Removing ${NAME}${END}"
	@rm -rf ${NAME}
	@echo "${GREEN}Done!${END}"

re: fclean all

.PHONY: all clean fclean re