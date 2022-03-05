##
# Things that i always forget
# @ -> On the left of ":"
# ^ -> Dependencies (on the right of ":").
# < -> Who caused the action.
# % -> Anything.
##

.PHONY: all cls clean clc clear info

COMP	 := g++
# COMP	 := clang++

CC       := $(COMP) -std=c++17 -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -Werror
CCFLAGS  := -Wall -Wextra -pedantic-errors
LIBS     :=
SRC_DIR  := src
INC_DIR  := include
BIN_DIR	 := bin
OBJ_DIR  := $(BIN_DIR)/obj
EXE_NAME := $(BIN_DIR)/exe 
SOURCES := $(shell find $(SRC_DIR) -type f) # Calling the shell to find all the files.
# SOURCES  := $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS  := $(subst .cpp,.o,$(SOURCES))
OBJECTS  := $(subst $(SRC_DIR),$(OBJ_DIR),$(OBJECTS))
 
ifdef REL
CCFLAGS += -O3
else
CCFLAGS += -g
endif


all: $(OBJ_DIR)/ $(EXE_NAME)

$(OBJ_DIR)/:
	mkdir -p $(OBJ_DIR)

$(EXE_NAME): $(OBJECTS) main.cpp
	$(CC) $(CCFLAGS) -o $@ $^ $(LIBS) -I$(INC_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.cpp
	$(CC) -o $@ -c $^ -I$(INC_DIR) $(CCFLAGS)

cls : clean

clc : clean

clear: clean

clean:
	rm -rf $(BIN_DIR)

info:
	$(info $(SOURCES))
	$(info $(OBJECTS))