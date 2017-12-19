# src/gameofEXEC/Makefile
.PHONY: clean

CC = gcc
CFLAGS = -W -Wall -pedantic
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
TESTMOMENTS = test_moments
TESTLIST = test_linkedlist
TESTRAG = test_rag
TESTREG = test_region

#DISPLAY
CEXEC = \033[0;32m
CDIR = \033[0;36m
CNONE = \033[0m
CFILE = \033[0;34m

all: $(EXEC) $(TESTMOMENTS) $(TESTLIST) $(TESTRAG) $(TESTREG)

$(EXEC): $(OBJDIRMAIN)$(EXEC).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/image -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(EXEC).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(TESTMOMENTS): $(OBJDIRMAIN)$(TESTMOMENTS).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/ -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTMOMENTS).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(TESTLIST): $(OBJDIRMAIN)$(TESTLIST).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/ -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTLIST).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(TESTRAG): $(OBJDIRMAIN)$(TESTRAG).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/ -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTRAG).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(TESTREG): $(OBJDIRMAIN)$(TESTREG).o $(OTHOBJ)
	@if [ ! -d $(ROOT)bin ]; then mkdir $(ROOT)bin;fi
	@$(CC) $^ -I $(ROOT)include/ -o $(BINDIR)$@.out $(LIBS) $(LDFLAGS)
	@echo  "\t$(CEXEC)$(TESTREG).out$(CNONE) Compiled in $(CDIR)$(BINDIR:$(ROOT)%=%)$(CNONE)"

$(OBJDIRMAIN)%.o: %.c
	@$(CC) -o $@ -I $(ROOT)include/ -c $< $(CFLAGS)
	@echo "$(CFILE)$(@:$(OBJDIRMAIN)%=%)$(CNONE) from $(CFILE)$<$(CNONE)"

clean:
	@rm -rf $(OBJDIRMAIN)*.o *~

mrproper: clean
	@rm -rf $(BINDIR)$(EXEC) $(BINDIR)$(TEST)
