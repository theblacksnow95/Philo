## ============================= NAMES ========================================== ##

NAME = philo

## ============================= FLAGS ========================================== ##

CC = gcc

C_FLAGS = -Wall -Wextra -Werror -g -lpthread

## ============================ DIRECTORIES ==================================== ##

INC_DIR = include

SRC_DIR = src

BIN_DIR = bin

OBJ_DIR = obj

## ============================ SOURCES ======================================= ##

SRC = $(SRC_DIR)/philo.c $(SRC_DIR)/utils.c $(SRC_DIR)/test.c $(SRC_DIR)/free_exit.c \
	$(SRC_DIR)/utils_2.c

TARGET = philo

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# default rule

all: $(BIN_DIR)/$(NAME)

#linking

$(BIN_DIR)/$(NAME): $(OBJ)
	@mkdir -p $(BIN_DIR)
	$(CC) $(C_FLAGS) -I$(INC_DIR) -o $@ $^

#compiling

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(C_FLAGS) -I$(INC_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(BIN_DIR)

test:
	./$(BIN_DIR)/$(TARGET) 6 300 455 533 6

valgrind:
	valgrind --leak-check=full ./$(BIN_DIR)/$(TARGET) 6 300 455 533 6

re: fclean all

.PHONY: all clean fclean re
