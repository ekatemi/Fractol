#To  use  MiniLibX  functions,  you'll  need  to link your software  with the   MiniLibX  library,
# and    several    system frameworks:
#      -lmlx  -framework OpenGL
#      -framework AppKit
#
 #      You  may  also  need  to specify  the path to the MiniLibX library,  using the -L flag.

#TODO   fix relink, if I change header it doesnt recompile

NAME 	=	fractol
CC	=	gcc
CFLAGS	=	-Wall -Werror -Wextra
OBJ_DIR = obj
OBJ	=	$(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
NAMELIB	=	fractol.a
LINK 	=	-lmlx  -framework OpenGL -framework AppKit -L ./mlx -lm
SRC		=	main.c string_utils.c
COMP	=	$(CC) $(CFLAGS) $(LINK)
RM		=	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	$(RM) -r $(OBJ_DIR)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean