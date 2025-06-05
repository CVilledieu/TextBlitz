.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall $(inc) $(lib)

# directories
outDir = ./bin
sDir = ./src
inc = -Isrc/include
lib = -mwin32 -mwindows


cFiles = $(wildcard $(sDir)/*.c)

OBJS = $(cFiles) 
appName = TextBlitz

all: build cleanObjs

build: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(outDir)/$(appName)

%.o: %.c
	$(CC) -c $(CFLAGS)  $< -o $@


cleanObjs: 
	rm -rf $(sDir)/*.o

clean: 
	rm -rf $(outDir)/*
	rm -rf $(sDir)/*.o