# TDITEST.SYS - TDI test driver
#
PATH_TO_TOP = ../../..

TARGETNAME=tditest

CFLAGS = -I./include 

RESOURCE_OBJECT = $(TARGETNAME).coff
TDITEST_OBJECTS = tditest/tditest.o

all: objects $(TARGETNAME).sys

objects:
	mkdir objects

$(TARGETNAME).coff: $(TARGETNAME).rc ../../../include/reactos/resource.h

OBJECTS = $(TDITEST_OBJECTS) $(RESOURCE_OBJECT) ../../../ntoskrnl/ntoskrnl.a


ifeq ($(DOSCLI),yes)
CLEAN_FILES = *.o objects\*.o tditest\*.o $(TARGETNAME).coff $(TARGETNAME).o \
              junk.tmp base.tmp temp.exp $(TARGETNAME).sys $(TARGETNAME).sym
else
CLEAN_FILES = *.o objects/*.o tditest/*.o $(TARGETNAME).coff $(TARGETNAME).o \
              junk.tmp base.tmp temp.exp $(TARGETNAME).sys $(TARGETNAME).sym
endif

$(TARGETNAME).sys: $(OBJECTS)
	$(CC) \
		-mdll \
		-specs=../../svc_specs \
		-Wl,-e,_DriverEntry@8 \
		-Wl,--base-file,base.tmp \
		-Wl,--defsym,_end=end  \
		-Wl,--defsym,_edata=__data_end__ \
		-Wl,--defsym,_etext=etext \
        $(OBJECTS) \
        -o junk.tmp
	- $(RM) junk.tmp
	$(DLLTOOL) \
        --dllname $(TARGETNAME).sys \
        --base-file base.tmp \
        --output-exp temp.exp
	- $(RM) base.tmp
	$(CC) \
		-mdll \
		-specs=../../svc_specs \
		-Wl,--image-base,0x10000 \
		-Wl,-e,_DriverEntry@8 \
		-Wl,temp.exp \
        $(OBJECTS) \
        -o $(TARGETNAME).sys
	- $(RM) temp.exp
	$(NM) --numeric-sort $(TARGETNAME).sys > $(TARGETNAME).sym

clean: $(CLEAN_FILES:%=%_clean)

$(CLEAN_FILES:%=%_clean): %_clean:
	- $(RM) $*

.PHONY: clean $(CLEAN_FILES:%=%_clean)

install: $(FLOPPY_DIR)/drivers/$(TARGETNAME).sys

$(FLOPPY_DIR)/drivers/$(TARGETNAME).sys: $(TARGETNAME).sys
	$(CP) $(TARGETNAME).sys $(FLOPPY_DIR)/drivers/$(TARGETNAME).sys

dist: $(DIST_DIR)/drivers/$(TARGETNAME).sys

$(DIST_DIR)/drivers/$(TARGETNAME).sys: $(TARGETNAME).sys
	$(CP) $(TARGETNAME).sys ../../../$(DIST_DIR)/drivers/$(TARGETNAME).sys

include $(PATH_TO_TOP)/rules.mak
