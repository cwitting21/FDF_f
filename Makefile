NAME = fdf

FLAGS = -c -O3

MLXFLAGS = -lmlx -framework OpenGL -framework OpenCL -framework AppKit -O3

SOURCES = $(shell ls $(SRC_DIR))
INCLUDES = $(addprefix -I, ./includes)

LIB = libft/libft.a

OBJ_DIR = obj

SRC_DIR = src

SRCS = $(addprefix $(SRC_DIR)/,$(SOURCES))

OBJS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.c=.o))

GREEN = \033[0;32m
RED = \033[0;36m
RESET = \033[0m

all: $(LIB) $(NAME)

$(LIB):
			@make -C ./libft

$(NAME):	$(OBJS)
			@gcc -I /usr/local/include $(OBJS) $(LIB) -L /usr/local/lib/ $(MLXFLAGS) -o $(NAME)
			@echo "$(RED)Exec file created$(RESET)"

$(OBJS):	$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
			@mkdir -p $(OBJ_DIR)
			@gcc $(FLAGS) $(INCLUDES) -o $@ $<

clean:
			@/bin/rm -rf $(OBJ_DIR)
			@make clean --directory ./libft
			@echo "$(GREEN)Object files deleted$(RESET)"

fclean: clean
			@/bin/rm -f $(NAME)
			@make fclean --directory ./libft
			@echo "$(GREEN)Exec file deleted$(RESET)"

re: fclean all