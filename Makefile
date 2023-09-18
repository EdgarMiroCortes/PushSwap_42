################################################################################
#                                  COLORS                       		       #
################################################################################

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

################################################################################
#                                  MAKEFILE                       		       #
################################################################################

NAME		= push_swap
CC			= gcc
FLAGS		= -Wall -Wextra -Werror
MAKE		= make --no-print-directory
LFT			= libft/libft.a
INC			= -I ./inc -I ./libft
LIB			=	-L ./libft
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC        	=   src/moves.c \
				src/moves2.c \
				src/moves3.c \
            	src/utils.c \
            	src/utils2.c \
            	src/sort.c \
            	src/sort2.c \
            	src/push_swap.c\
				src/parsing.c\
				src/magic.c     
             
all:		make_lib $(NAME)

make_lib:
	@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW} LIBFT ${CLR_RMV}..."
	@${MAKE} -C ./libft
	@echo "$(GREEN)LIBFT created[0m ✔️"

${NAME}:	$(OBJ)
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			@$(CC) $(FLAGS) $(LIB) $(OBJ) $(LFT) -o $@
			@echo "$(GREEN)$(NAME) created[0m ✔️"

obj/%.o:	src/%.c Makefile src/push_swap.h
			@mkdir -p obj
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re