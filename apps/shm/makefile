#
#
#
PATH_TO_TOP = ../..

SRV_OBJECTS= ../common/crt0.o shmsrv.o
CLT_OBJECTS= ../common/crt0.o shmclt.o

PROGS= shmsrv.exe shmclt.exe

BASE_CFLAGS = -I../../include
LIBS = ../../lib/crtdll/crtdll.a ../../lib/kernel32/kernel32.a \
       ../../lib/ntdll/ntdll.a

all: $(PROGS)

.phony: all

clean:
	- $(RM) *.o
	- $(RM) *.exe
	- $(RM) *.sym

.phony: clean

install: $(PROGS:%=$(FLOPPY_DIR)/apps/%)

$(PROGS:%=$(FLOPPY_DIR)/apps/%): $(FLOPPY_DIR)/apps/%: %
	$(CP) $* $(FLOPPY_DIR)/apps/$*

dist: $(PROGS:%=../../$(DIST_DIR)/apps/%)

$(PROGS:%=../../$(DIST_DIR)/apps/%): ../../$(DIST_DIR)/apps/%: %
	$(CP) $* ../../$(DIST_DIR)/apps/$*

shmsrv.exe: $(SRV_OBJECTS) $(LIBS)
	$(LD) $(SRV_OBJECTS) $(LIBS) -o shmsrv.exe
	$(NM) --numeric-sort shmsrv.exe > shmsrv.sym

shmclt.exe: $(CLT_OBJECTS) $(LIBS)
	$(LD) $(CLT_OBJECTS) $(LIBS) -o shmclt.exe
	$(NM) --numeric-sort shmsrv.exe > shmclt.sym


include ../../rules.mak
