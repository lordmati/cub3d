LIBFT_DIR         = libft/
LIBFT             = libft.a
NAME              = cub3D
CC                = clang -g #-fsanitize=address 
CFLAGS            = -Wall -Werror -Wextra 
RM                = rm -rf

SRC_DIR           = srcs/
OBJ_DIR           = obj/

FILES_SRC         = main.c \
					check_all.c \
					error_exit.c \
					save_fd.c \
					utils.c \

SRC               = $(addprefix $(SRC_DIR),$(FILES_SRC))
OBJ_SRC           = $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

MAKEFLAGS += s

vpath %.c $(SRC_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ_SRC)
	@$(MAKE) -C $(LIBFT_DIR) all gnl
	$(CC) $(OBJ_SRC) -L$(LIBFT_DIR) -lft -o $@

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
