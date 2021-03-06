# $Id: makefile,v 1.13 2000/11/20 19:59:11 ekohl Exp $
#
# Makefile for ReactOS vgaddi.dll
#
PATH_TO_TOP = ../../../..
TARGET=vgaddi

CFLAGS = -I.
 
ifneq ($(HOST),mingw32-windows)
  ifneq ($(HOST),mingw32-linux)
    DLLTARGET=$(TARGET).a
  else
    DLLTARGET=$(TARGET).dll
  endif
else
  DLLTARGET=$(TARGET).dll
endif

all: $(DLLTARGET)

MAIN_OBJECTS = main/enable.o
OTHER_OBJECTS = objects/screen.o objects/pointer.o objects/lineto.o objects/paint.o objects/bitblt.o \
		vgavideo/vgavideo.o
RESOURCE_OBJECTS = $(TARGET).coff

OBJECTS = $(MAIN_OBJECTS) $(OTHER_OBJECTS) $(RESOURCE_OBJECTS)

$(TARGET).a: $(OBJECTS)
	$(AR) csr $(TARGET).a $(OBJECTS)

$(TARGET).coff: $(TARGET).rc ../../../../include/reactos/resource.h

$(TARGET).dll: $(DLLMAIN) $(OBJECTS) $(TARGET).def
	$(LD) -r $(OBJECTS) -o $(TARGET).o
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--def $(TARGET).def \
		--kill-at \
		--output-lib $(TARGET).a
	$(CC) $(TARGET).o \
		../../../../subsys/win32k/win32k.a \
		../../../../ntoskrnl/ntoskrnl.a \
		-specs=$(TARGET)_specs \
		-mdll \
		-o junk.tmp \
		-Wl,--entry,_DrvEnableDriver \
		-Wl,--base-file,base.tmp
	- $(RM) junk.tmp
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--base-file base.tmp \
		--output-exp temp.exp \
		--def $(TARGET).edf
	- $(RM) base.tmp
	$(CC) $(TARGET).o \
		../../../../subsys/win32k/win32k.a \
		../../../../ntoskrnl/ntoskrnl.a \
		-specs=$(TARGET)_specs \
		-mdll \
		-o $(TARGET).dll \
		-Wl,--entry,_DrvEnableDriver \
		-Wl,--image-base,0x70000000 \
		-Wl,--file-alignment,0x1000 \
		-Wl,--section-alignment,0x1000 \
		-Wl,temp.exp
	- $(RM) temp.exp
	$(NM) --numeric-sort $(TARGET).dll > $(TARGET).sym

ifeq ($(DOSCLI),yes)
CLEAN_FILES = *.o *.coff *.sym *.tmp *.dll main\*.o objects\*.o vgavideo\*.o *.a
else
CLEAN_FILES = *.o *.coff *.sym *.tmp *.dll main/*.o objects/*.o vgavideo/*.o *.a
endif

clean: $(CLEAN_FILES:%=%_clean)

$(CLEAN_FILES:%=%_clean): %_clean:
	- $(RM) $*

.PHONY: clean $(CLEAN_FILES:%=%_clean)

install: $(FLOPPY_DIR)/dlls/$(TARGET).dll

$(FLOPPY_DIR)/dlls/$(TARGET).dll: $(TARGET).dll
	$(CP) $(TARGET).dll $(FLOPPY_DIR)/dlls/$(TARGET).dll

dist: $(DIST_DIR)/dlls/$(TARGET).dll

$(DIST_DIR)/dlls/$(TARGET).dll: $(TARGET).dll
	$(CP) $(TARGET).dll ../../../../$(DIST_DIR)/dlls/$(TARGET).dll

include ../../../../rules.mak

# EOF
