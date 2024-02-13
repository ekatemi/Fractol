#To  use  MiniLibX  functions,  you'll  need  to link your software  with the   MiniLibX  library,
# and    several    system frameworks:
#      -lmlx  -framework OpenGL
#      -framework AppKit
#
 #      You  may  also  need  to specify  the path to the MiniLibX library,  using the -L flag.

NAME 	=	fractol

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra

OBJ	=	$(SRC:.c=.o)

NAMELIB	=	libftfractol.a

LIB 	=	libft/libft.a

LINK 	=	-lmlx  -framework OpenGL -framework AppKit -L ./minilibx_opengl_20191021

SRC		=	main.c

COMP	=	$(CC) $(CFLAGS) $(LIB) $(LINK)

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
				$(MAKE) bonus -C ./libft
				$(COMP) $(OBJ) -o $(NAME)
clean:
	$(RM) $(OBJ)
	$(MAKE) fclean -C ./libft

fclean:	clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re:			fclean all

.PHONY: all re clean fclean