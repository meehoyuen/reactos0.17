#
#
#
PATH_TO_TOP = ../..

OBJECTS = vmtest.o
PROGS = vmtest.exe
LIBS = 
CLEAN_FILES = vmtest.o vmtest.exe

all: vmtest.exe

clean: $(CLEAN_FILES:%=%_clean)

$(CLEAN_FILES:%=%_clean): %_clean:
	- $(RM) $*

.phony: clean $(CLEAN_FILES:%=%_clean)

floppy: $(PROGS:%=$(FLOPPY_DIR)/apps/%)

$(PROGS:%=$(FLOPPY_DIR)/apps/%): $(FLOPPY_DIR)/apps/%: %
	$(CP) $* $(FLOPPY_DIR)/apps/$*

dist: $(PROGS:%=../../$(DIST_DIR)/apps/%)

$(PROGS:%=../../$(DIST_DIR)/apps/%): ../../$(DIST_DIR)/apps/%: %
	$(CP) $* ../../$(DIST_DIR)/apps/$*

vmtest.exe: $(OBJECTS)
	$(CC) $(OBJECTS) -o vmtest.exe

include ../../rules.mak
