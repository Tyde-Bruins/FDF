# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tbruins <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/12 14:51:01 by tbruins           #+#    #+#              #
#    Updated: 2018/09/19 16:13:14 by tbruins          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

FLAGS = -Wall -Wextra -Werror
LIB = -L libft/ -lft 
MLX = -lmlx -framework OpenGL -framework Appkit
INCLUDE = -I libft/
SRC = draw_line.c \
	  hook.c \
	  main.c \
	  error.c \
	  function.c \

OBJ = $(%.c,obj/%.o $(SRC))

all: $(NAME)

$(NAME): 
	@make -C libft
	@gcc $(FLAGS) $(SRC) $(INCLUDE) $(MLX) $(LIB) -o $(NAME) -g
	#ar rc $(NAME) $(OBJ)
	#ranlib $(NAME)

fclean: clean
	@rm -rf $(NAME)
	@make -C libft/ fclean

clean:
	@rm -rf $(OBJ)
	@make -C libft/ clean


re: fclean all
