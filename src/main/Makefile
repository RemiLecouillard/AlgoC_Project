# src/gameofEXEC/Makefile
.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -ansi -pedantic
LDFLAGS = -limage64 -lm

#DIRECTORIES
ROOT = ../../
BINDIR = $(ROOT)bin/
SRCDIR = $(ROOT)src/
OBJDIR = $(ROOT)obj/
OBJDIRMAIN = $(OBJDIR)main/
LIBS = -L$(ROOT)/lib/

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
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/ -o $(BINDIR)$@ $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC)$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(OBJDIRMAIN)%.o: %.c
	@$(CC) -o $@ -I $(ROOT)include/ -c $< $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
