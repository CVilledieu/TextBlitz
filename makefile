.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall $(inc) -mwindows
inc = -Isrc/include

SRC_C = $(wildcard src/*.c)
SRC_COMP = $(wildcard src/components/*.c)
SRC_RC = $(wildcard resource/*.rc)

OBJ_C = $(SRC_C:.c=.o)
OBJ_COMP = $(SRC_COMP:.c=.o)
OBJ_RC = $(SRC_RC:.rc=.o)
OBJ = $(OBJ_C) $(SRC_COMP) $(OBJ_RC)


App = TextBlitz

all: $(App) clean

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.rc 
	windres $(inc) $< -o $@

$(App): $(OBJ)
	mkdir -p bin
	$(CC) $(CFLAGS) $(OBJ) -o bin/$@

clean: 
	rm -rf resource/*.o src/*.o
