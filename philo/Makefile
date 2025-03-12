# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumendes <gumendes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/27 12:10:21 by gumendes          #+#    #+#              #
#    Updated: 2025/03/12 16:05:09 by gumendes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#==============================================================================#
#                                  COMPILER AND FLAGS                          #
#==============================================================================#

CC			=	cc
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -pthread -g
LEAK		=	-fsanitize=thread

#==============================================================================#
#                                  PATHS       					               #
#==============================================================================#

SRC_PATH		=	srcs
BUILD_PATH		=   .build
INCLUDE_PATH	=	includes
#==============================================================================#
#                                  INCLUDES			                           #
#==============================================================================#

INCLUDES    =   -I$(INCLUDE_PATH)

#==============================================================================#
#                                  PROJECT NAME                                #
#==============================================================================#

NAME		=	philo

#==============================================================================#
#                                  SOURCE AND OBJECT FILES                     #
#==============================================================================#

SRC			=	$(SRC_PATH)/actions.c $(SRC_PATH)/errors.c $(SRC_PATH)/init.c $(SRC_PATH)/main.c $(SRC_PATH)/parsing.c $(SRC_PATH)/routine.c \
				$(SRC_PATH)/time.c $(SRC_PATH)/utils.c
OBJ         =   $(SRC:$(SRC_PATH)/%.c=$(BUILD_PATH)/%.o)

#==============================================================================#
#                                  RULES                                       #
#==============================================================================#

all: $(NAME)

# Build the philo program
$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(LEAK) -o $(NAME) $(OBJ)
	@echo "$(GRN)[PROJECT BUILT]$(END)"

# Rule to create object files in the .build folder
$(BUILD_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(BUILD_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

# Clean object files
clean:
	@if [ -d "$(BUILD_PATH)" ]; \
		then echo "$(RED)[REMOVED OBJECT FILES]$(END)"; \
		else echo "$(YEL)[NOTHING TO BE CLEANED]$(END)"; \
	fi
	@$(RM) $(BUILD_PATH)

# Full clean
fclean: clean
	@if [ -f "$(NAME)" ]; \
		then echo "$(RED)[REMOVED EXECUTABLE]$(END)"; \
		else echo "$(YEL)[EXECUTABLE ALREADY CLEANED]$(END)"; \
	fi
	@$(RM) $(NAME)

# Rebuild the project
re: fclean all

# Phony targets
.PHONY: all clean fclean re

#==============================================================================#
#                                  UTILS                                       #
#==============================================================================#

# Colors
#
# Run the following command to get list of available colors
# bash -c 'for c in {0..255}; do tput setaf $c; tput setaf $c | cat -v; echo =$c; done'
#
B  		= $(shell tput bold)
BLA		= $(shell tput setaf 0)
RED		= $(shell tput setaf 1)
GRN		= $(shell tput setaf 2)
BRW		= $(shell tput setaf 3)
BLU		= $(shell tput setaf 4)
PRP		= $(shell tput setaf 5)
CYA		= $(shell tput setaf 6)
WHI		= $(shell tput setaf 15)
GREY	= $(shell tput setaf 8)
ORAN 	= $(shell tput setaf 9)
LIME	= $(shell tput setaf 10)
YEL		= $(shell tput setaf 11)
BBLU	= $(shell tput setaf 12)
BMAG	= $(shell tput setaf 13)
BCYA	= $(shell tput setaf 14)
D 		= $(shell tput sgr0)
BEL 	= $(shell tput bel)
CLR 	= $(shell tput el 1)
