# src/list/Makefile
.SUFFIXES:
.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic

#SOURCES & BINARIES
ROOT = ../../
SRCDIR =
OBJDIR = $(ROOT)obj/image/
SRC  = $(wildcard $(SRCDIR)*.c)
OBJ  = $(SRC:$(SRCDIR)%.c=$(OBJDIR)%.o)

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC) -o $@ -c $< -I $(ROOT)include/image $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIR)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	rm -rf $(OBJDIR)/*.o *~
