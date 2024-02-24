#To  use  MiniLibX  functions,  you'll  need  to link your software  with the   MiniLibX  library,
# and    several    system frameworks:
#      -lmlx  -framework OpenGL
#      -framework AppKit
#
 #      You  may  also  need  to specify  the path to the MiniLibX library,  using the -L flag.

#TODO   fix relink, if I change header it doesnt recompile

NAME    = fractol
CC      = gcc
CFLAGS  = -Wall -Werror -Wextra
OBJ_DIR = obj
OBJ     = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))
HEADER  = fractol.h
LINK    = -framework OpenGL -framework AppKit -lm
LIBS    = -L./mlx -lmlx
SRC     = main.c string_utils.c init.c key_handlers.c
COMP    = $(CC) $(CFLAGS)
RM      = rm -f

all: $(NAME) mlx

mlx:
	@echo "Compiling mlx"
	@$(MAKE) -C mlx

$(NAME): $(OBJ)
	$(COMP) $(OBJ) -o $(NAME) $(LINK) $(LIBS)

$(OBJ_DIR)/%.o: %.c $(HEADER) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	@$(MAKE) -C mlx clean
	$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(MAKE) -C mlx fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean