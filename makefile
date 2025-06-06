.PHONY: cleanObjs build clean all

CC = GCC
CFLAGS = -Wall $(inc) $(lib)

# directories
outDir = ./bin
sDir = ./src
rcDir = ./resource
inc = -Isrc/include
lib = -mwin32 -mwindows

rcFiles = $(wildcard $(rcDir)/*.rc)
cFiles = $(wildcard $(sDir)/*.c)

OBJS = $(cFiles)
buildItems = $(wildcard $(OBJ)) 
appName = TextBlitz

all: build cleanObjs

build: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $(outDir)/$(appName)


resources: $(rcFiles)
	windres $(CFLAGS) $^ 

%.o: %.c
	$(CC) -c $(CFLAGS)  $< -o $@



cleanObjs: 
	rm -rf $(sDir)/*.o

clean: 
	rm -rf $(outDir)/*
	rm -rf $(sDir)/*.o