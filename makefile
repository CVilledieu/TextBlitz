.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall $(inc) -mwindows
inc = -Isrc/include

SRC_C = $(wildcard src/*.c)
SRC_COMP = $(wildcard src/elements/*.c)
SRC_RC = $(wildcard resource/*.rc)
SRC_WEL = $(wildcard src/Welcome/*.c)

OBJ_C = $(SRC_C:.c=.o)
OBJ_COMP = $(SRC_COMP:.c=.o)
OBJ_WEL = $(SRC_WEL:.c=.o)
OBJ_RC = $(SRC_RC:.rc=.o)
OBJ = $(OBJ_C) $(SRC_WEL) $(OBJ_RC)


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
