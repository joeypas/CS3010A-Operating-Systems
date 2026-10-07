CC := clang
CFLAGS := -Wall -Wextra -Wpedantic -Wnull-dereference -fsanitize=address,undefined -g
LDFLAGS := -fsanitize=address,undefined

SRC_DIR := src
BUILD_DIR := build

TARGET := $(BUILD_DIR)/assignment3

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
