# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jheath <jheath@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/26 16:20:10 by jheath            #+#    #+#              #
#    Updated: 2018/08/02 12:25:01 by jheath           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =						libftprintf.a

# Flags.
CC =						gcc
CFLAGS =					-Wall -Werror -Wextra
HEADER =					-Iincludes

# Remove.
RM =						rm -f

# SubFolders
DIR_LIBFT =					libft/
DIR_SRC =					srcs/

# Source Files.
LIBFTS = 					ft_isuma.c ft_memcpy.c ft_putchar.c ft_putstr.c ft_putwstr.c \
							ft_strchr.c ft_strdel.c ft_strdup.c ft_strlen.c ft_strlenpcsn.c \
							ft_strncpy.c

SRCS =						ft_char.c ft_find_spec.c ft_format.c ft_hex.c ft_liter.c \
							ft_nbr.c ft_oct.c ft_point.c ft_printf.c ft_str.c ft_ub.c

# File Paths.
LIBFT =						$(addprefix $(DIR_LIBFT),$(LIBFTS))
SRC =						$(addprefix $(DIR_SRC),$(SRCS))

# Obj
OBJ = 		$(SRCS:.c=.o) $(LIBFTS:.c=.o)

all: $(NAME)

# Compilation
$(NAME):
						@$(CC) -c $(CFLAGS) $(SRC) $(LIBFT) $(HEADER)
						@ar rc $(NAME) $(OBJ)
						@ranlib $(NAME)
						@echo "Structure complete!"

# Cleanup duty
clean:
					@$(RM) $(OBJ)
					@echo "Unit lost!"

fclean:					clean
					@$(RM) $(NAME)
					@echo "Pylon lost"

re:						fclean all

.PHONY =					all clean fclean clean re
