# src/list/Makefile
.SUFFIXES:
.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic -fPIC

#SOURCES & BINARIES
ROOT = ../../
SRCDIR =
OBJDIR = $(ROOT)obj/
LIB = $(ROOT)lib
SRC  = $(wildcard $(SRCDIR)*.c)
OBJ  = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)
LIBSTAT = $(LIB)libimage64.a

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ) $(LIBSTAT)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< -I $(ROOT)include/image $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIR)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

$(LIBSTAT):
	#@$(CC) -shared -o $@ $(OBJDIR)image.o
	@ar rcs $(LIBSTAT) $(OBJDIR)image.o
	@echo "Library $(CFILE)libimage64.a generated"

clean:
	rm -rf $(OBJDIR)/*.o *~
