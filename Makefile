# Makefile racine

#DIRECTORIES
SRCDIR = src/
MAINDIR = main
SUBDIR = $(addprefix $(SRCDIR), fct)

all:
	@for dir in $(SUBDIR) ; do make -s -C $$dir ; done
	@(make -s -C $(SRCDIR)$(MAINDIR))

clean:
	@for dir in $(SUBDIR) ; do make -s -C $$dir clean ; done
	@(cd $(SRCDIR)$(MAINDIR) && make -s clean)
	@rm -rf $(OBJDIR)*.o
	@echo "project cleaned"

mrproper: clean
	@(cd $(SRCDIR)$(MAINDIR) && make -s mrproper)
