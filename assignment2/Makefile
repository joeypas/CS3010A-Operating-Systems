CC := clang

SRC_DIR := src
INCLUDE_DIR := include
BUILD_DIR := build

CFLAGS := -Wall -Wextra -Wpedantic -Wnull-dereference -fsanitize=address,undefined -g -I $(INCLUDE_DIR)
LDFLAGS := -fsanitize=address,undefined

TARGET := $(BUILD_DIR)/assignment2

SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(LDFLAGS) -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)
