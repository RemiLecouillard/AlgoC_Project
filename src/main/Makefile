# src/gameofEXEC/Makefile
.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
LDFLAGS = -lm

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/
OBJDIRMAIN = $(OBJDIR)main/

#SOURCES & BINARIES
SRC  = $(wildcard *.c)
OBJ  = $(SRC:%.c=$(OBJDIR)%.o)
OTHOBJ = $(wildcard $(OBJDIR)*.o)

#MAIN'S SOURCES
EXEC = segmentate

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(EXEC) $(TEST)

$(EXEC): $(OBJDIRMAIN)$(EXEC).o $(OTHOBJ)
	@$(CC) $^ $(LDFLAGS) -o $(BINDIR)$@
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(OBJDIRMAIN)%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
