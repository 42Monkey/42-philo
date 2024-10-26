################################################################################
## VARIABLES
NAME		= philo

################################################################################
## DIRECTORIES
DIR_INC		= ./include/
DIR_SRC		= ./source/

################################################################################
## COMPILATION & FLAGS
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wunreachable-code -pthread
AR 			= ar rcs
RM			= rm -rf

################################################################################
## SOURCES
SRCS 		=		$(DIR_SRC)philo.c \
					$(DIR_SRC)initializer.c \
					$(DIR_SRC)utils.c

OBJS		=		$(SRCS:.c=.o)

################################################################################
## RULES

all:				$(NAME)

$(NAME):			$(OBJS)
					@echo "$(YELLOW)Linking$(NC) $(NAME)"
					$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
					@echo "$(GREEN)Build completed: $(NAME)$(NC)"

$(DIR_SRC)%.o:		$(DIR_SRC)%.c
					@echo "$(YELLOW)Compiling$(NC) $<"
					$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@
					@echo "$(GREEN)Compiled$(NC) $<"

clean:
					@echo "$(YELLOW)Cleaning object files$(NC)"
					$(RM) $(OBJS)
					@echo "$(GREEN)Clean completed$(NC)"

fclean:				clean
					@echo "$(YELLOW)Cleaning executable$(NC)"
					$(RM) $(NAME)
					@echo "$(GREEN)Executable removed$(NC)"

re:					fclean all

.PHONY: 			all clean fclean re

################################################################################
## COLORS
GREEN		= \033[0;32m
YELLOW		= \033[0;33m
NC			= \033[0m
