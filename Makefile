# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: evoronin <evoronin@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2023/06/12 11:12:29 by evoronin      #+#    #+#                  #
#    Updated: 2023/06/19 14:33:42 by evoronin      ########   odam.nl          #
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
NAME = minishell
SRCS =  
		
OBJ = $(SRCS:.c=.o)
LIBFT = libft/libft.a
LIBFT_DIR = libft
HEADERS =  ./libft ./include/minishell.h

%.o: %.c $(HEADERS)
	@$(CC) $(CFLAGS) -c $< -o $@

all:  ${NAME} 

${NAME}: ${OBJ} ${HEADERS}
	@make -s -C $(LIBFT_DIR)
	@echo "${BLUE}Compiling ${NAME}${END}"
	@$(CC) $(CFLAGS) $(OBJ) ${LIBFT} -o $(NAME)
	@echo "${GREEN}Done!${END}"

check/norm:
	

clean:
	@make clean -C libft
	@rm -f $(OBJ)
	@echo "${GREEN}Done!${END}"

fclean: clean
	@make fclean -C libft
	@echo "${RED}Removing ${NAME}${END}"
	@rm -rf ${MLX_DIRECTORY}/build
	@rm -rf ${NAME}
	@echo "${GREEN}Done!${END}"

re: fclean all

.PHONY: all clean fclean re