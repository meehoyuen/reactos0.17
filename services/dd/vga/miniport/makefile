# $Id: makefile,v 1.5 2000/11/20 19:59:11 ekohl Exp $
#
#
PATH_TO_TOP = ../../../..
CFLAGS = 

MP_OBJECTS = vgamp.o initvga.o vgavideo.o vgamp.coff ../../../../ntoskrnl/ntoskrnl.a ../../vidport/vidport.a

all: vgamp.sys

.phony: all

clean:
	- $(RM) *.o
	- $(RM) junk.tmp
	- $(RM) base.tmp
	- $(RM) temp.exp
	- $(RM) *.sys
	- $(RM) *.coff

.phony: clean

vgamp.sys: $(MP_OBJECTS)
	$(CC) \
		-specs=../../../svc_specs \
		-mdll \
		-o junk.tmp \
		-Wl,--defsym,_end=end \
		-Wl,--defsym,_edata=__data_end__ \
		-Wl,--defsym,_etext=etext \
		-Wl,--base-file,base.tmp \
		$(MP_OBJECTS)
	- $(RM) junk.tmp
	$(DLLTOOL) \
		--dllname vgamp.sys \
		--base-file base.tmp \
		--output-exp temp.exp \
		--kill-at
	- $(RM) base.tmp
	$(CC) \
		--verbose \
		-Wl,--image-base,0x10000 \
		-Wl,-e,_DriverEntry@8 \
		-Wl,temp.exp \
		-specs=../../../svc_specs \
		-mdll \
		-o vgamp.sys \
		$(MP_OBJECTS)
	- $(RM) temp.exp

install: $(FLOPPY_DIR)/drivers/vgamp.sys

$(FLOPPY_DIR)/drivers/vgamp.sys: vgamp.sys
	$(CP) vgamp.sys $(FLOPPY_DIR)/drivers/vgamp.sys

dist: ../../../../$(DIST_DIR)/drivers/vgamp.sys

../../../../$(DIST_DIR)/drivers/vgamp.sys: vgamp.sys
	$(CP) vgamp.sys ../../../../$(DIST_DIR)/drivers/vgamp.sys

include ../../../../rules.mak

