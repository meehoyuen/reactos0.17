# $Id: makefile,v 1.3 2000/11/20 19:59:11 ekohl Exp $
#
#
TARGET = mouclass

PATH_TO_TOP = ../../..

OBJECTS = $(TARGET).o $(TARGET).coff ../../../ntoskrnl/ntoskrnl.a

CFLAGS = -O2 -I.

all: $(TARGET).sys

.phony: all

clean:
	- $(RM) $(TARGET).o
	- $(RM) $(TARGET).coff
	- $(RM) junk.tmp
	- $(RM) base.tmp
	- $(RM) temp.exp
	- $(RM) mouclass.sys

.phony: clean

install: $(FLOPPY_DIR)/drivers/$(TARGET).sys

$(FLOPPY_DIR)/drivers/$(TARGET).sys: $(TARGET).sys
	$(CP) $(TARGET).sys $(FLOPPY_DIR)/drivers/$(TARGET).sys

dist: ../../../$(DIST_DIR)/drivers/$(TARGET).sys

../../../$(DIST_DIR)/drivers/$(TARGET).sys: $(TARGET).sys
	$(CP) $(TARGET).sys ../../../$(DIST_DIR)/drivers/$(TARGET).sys

$(TARGET).sys: $(OBJECTS)
	$(CC) \
		-specs=../../svc_specs \
		-mdll \
		-o junk.tmp \
		-Wl,--defsym,_end=end \
		-Wl,--defsym,_edata=__data_end__ \
		-Wl,--defsym,_etext=etext \
		-Wl,--base-file,base.tmp \
		$(OBJECTS)
	- $(RM) junk.tmp
	$(DLLTOOL) \
		--dllname $(TARGET).sys \
		--base-file base.tmp \
		--output-exp temp.exp \
		--kill-at
	- $(RM) base.tmp
	$(CC) \
		--verbose \
		-Wl,--image-base,0x10000 \
		-Wl,-e,_DriverEntry@8 \
		-Wl,temp.exp \
		-specs=../../svc_specs \
		-mdll \
		-o $(TARGET).sys \
		$(OBJECTS)
	- $(RM) temp.exp


include ../../../rules.mak
