HEADER_NAME		=	philo.h
NAME_PH			=	philo

INC_DIR			=	./includes/
SRC_DIR			=	./sources/
OBJ_DIR			=	./obj/

SRC_NAME_PH		=	main.c	helper.c	initialization.c	actions.c

HEADER			=	$(addprefix $(INC_DIR), $(HEADER_NAME))

SRC_PH			=	$(addprefix $(SRC_DIR), $(SRC_NAME_PH))
OBJ_PH			=	$(addprefix $(OBJ_DIR), $(SRC_NAME_PH:.c=.o))

CC				=	gcc
FLAGS			=	-Wall -Wextra -Werror

all: $(NAME_PH)

$(NAME_PH): $(OBJ_DIR) $(OBJ_PH) $(NAME_LIB) $(HEADER)
	@$(CC) $(GCC_LIBFT) $(addprefix -I, $(INC_DIR)) $(OBJ_PH) -o $(NAME_PH)
	@echo "\033[32mPhilo Compiled! ᕦ(\033[31m♥\033[32m_\033[31m♥\033[32m)ᕤ\n"

$(OBJ_DIR):
	@mkdir -p obj

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER)
	$(CC) -c -I $(INC_DIR) $(FLAGS) $< -o $@

clean:
	@/bin/rm -rf $(OBJ_DIR)

fclean: clean
	@/bin/rm -f $(NAME_PH)
	@echo "\n\033[31mDeleting EVERYTHING! ⌐(ಠ۾ಠ)¬\n"

re: fclean all

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"