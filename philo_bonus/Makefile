HEADER_NAME		=	philo_bonus.h
NAME_PH			=	philo_bonus

INC_DIR			=	./includes/
SRC_DIR			=	./sources/
OBJ_DIR			=	./obj/

SRC_NAME_PH		=	main.c	actions.c	exit.c	parser.c	time.c	utils.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_PH			=	$(addprefix $(SRC_DIR), $(SRC_NAME_PH))
OBJ_PH			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_PH:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

all: $(NAME_PH)

$(NAME_PH): $(OBJ_DIR) $(OBJ_PH) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_PH) -o $(NAME_PH)
	@echo "🍝 \033[32mPhilo_bonus Compiled! 🍝\n"

$(OBJ_DIR):
	@echo "\033[33m----Compiling----"
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME_PH)
	@echo "\n ⛔ \033[31mDeleting EVERYTHING! ⛔\n"

re: fclean all