NAME = libft.a

SRCS =	ft_atoi.c\
		ft_calloc.c\
		ft_strlen.c\
		ft_strrchr.c\
		ft_bzero.c\
		ft_isalnum.c\
		ft_isalpha.c\
		ft_isascii.c\
		ft_isdigit.c\
		ft_isprint.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_memset.c\
		ft_strchr.c\
		ft_strlcat.c\
		ft_strlcpy.c\
		ft_strncmp.c\
		ft_strnstr.c\
		ft_tolower.c\
		ft_toupper.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_strdup.c\

BSRCS = ft_lstmap_bonus.c\
		 ft_lstiter_bonus.c\
		 ft_lstclear_bonus.c\
		 ft_lstdelone_bonus.c\
		 ft_lstadd_back_bonus.c\
		 ft_lstlast_bonus.c\
		 ft_lstsize_bonus.c\
		 ft_lstadd_front_bonus.c\
		 ft_lstnew_bonus.c\

OBJS = $(SRCS:.c=.o)

BOBJS = $(BSRCS:.c=.o)

CC = gcc
FLAGS = -Wall -Wextra -Werror

# no relinking when make bonus
ifdef WITH_BONUS
COMPILE_OBJECTS = $(OBJS) $(BOBJS)
else
COMPILE_OBJECTS = $(OBJS)
endif

all: $(NAME)

.c.o:
	@${CC} -c ${FLAGS} $< -o ${<:.c=.o}

$(NAME): $(COMPILE_OBJECTS)
	@ ar rcs $(NAME) $(COMPILE_OBJECTS)

bonus:
	@ $(MAKE) WITH_BONUS=1 $(NAME)
	@ echo "DONE!"

clean:
	rm -f $(OBJS) $(BOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
