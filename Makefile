# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <jheath@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 16:20:10 by jheath            #+#    #+#              #
#    Updated: 2018/08/02 16:16:59 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

# Directories for Source files
DIR_LIB = libft/
DIR_SRC = srcs/

# Source Files
LIBFTS = ft_isuma.c ft_memcpy.c ft_putchar.c ft_putstr.c ft_putwstr.c \
	ft_strchr.c ft_strdel.c ft_strdup.c ft_strlen.c ft_strlenpcsn.c \
	ft_strncpy.c
SRCS =	ft_char.c ft_find_spec.c ft_format.c ft_hex.c ft_liter.c \
		ft_nbr.c ft_oct.c ft_point.c ft_printf.c ft_str.c ft_ub.c
# Source file paths
LIBFT = 	$(addprefix $(DIR_LIB),$(LIBFTS))
SRC = 		$(addprefix $(DIR_SRC),$(SRCS))

# Objects
OBJ = 		$(SRCS:.c=.o) $(LIBFTS:.c=.o)

# Flags
FLAGS =		-Wall -Werror -Wextra
HEADER =	-Iincludes

.PHONY =	all clean fclean re

all: $(NAME)

# Compilation
$(NAME):
			@gcc -c $(FLAGS) $(SRC) $(LIBFT) $(HEADER) 
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "Warp in complete!"
			@echo "$(NAME) created!"

# Cleaning up
clean:
			@rm -f $(OBJ)
			@echo "Mineral field depleted!"

fclean:		clean
			@rm -f $(NAME)
			@echo "Nuclear launch detected!"

re:			fclean all
