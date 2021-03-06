# $Id: makefile,v 1.14 2000/11/20 19:59:09 ekohl Exp $
#
# ReactOS Operating System
#
# Makefile for user32.dll
#
PATH_TO_TOP = ../..

BASE_CFLAGS = -I../../include

include ../../rules.mak

TARGET=user32

DLLTARGET=$(TARGET).dll

all: $(DLLTARGET)

INTERNAL_OBJECTS = \
	internal/menu.o		\
	internal/heapdup.o	\
	internal/nc.o		\
	internal/win.o		\
	internal/dce.o		\
	internal/msg.o		\
	internal/queue.o	\
	internal/signal.o	\
	internal/event.o	\
	internal/timer.o	\
	internal/region.o	\
	internal/text.o		\
	internal/defwnd.o	\
	internal/paint.o	\
	internal/uitools.o	\
	internal/dialog.o	\
	internal/winpos.o

MISC_OBJECTS = \
	misc/sprintf.o		\
	misc/dllmain.o		\
	misc/string.o		\
	misc/sysmetr.o		\
	misc/winstat.o		\
	misc/bitmap.o		\
	misc/cursor.o		\
	misc/vk.o		\
	misc/stubs.o		\
	misc/stubsa.o		\
	misc/stubsw.o


WINDOWS_OBJECTS = \
	windows/wndproc.o	\
	windows/win.o		\
	windows/hook.o		\
	windows/spy.o		\
	windows/queue.o		\
	windows/winpos.o	\
	windows/class.o		\
	windows/dc.o		\
	windows/timer.o		\
	windows/rect.o		\
	windows/msg.o		\
	windows/input.o		\
	windows/property.o	\
	windows/focus.o		\
	windows/paint.o		\
	windows/msgbox.o	\
	windows/dialog.o	\
	windows/scroll.o	\
	windows/defdlg.o 

GRAPHICS_OBJECTS = \
	graphics/rect.o		\
	graphics/caret.o	\
	graphics/text.o		\
	graphics/syscol.o	\
	graphics/fill.o		\
	graphics/draw.o		\
	graphics/icon.o

CONTROLS_OBJECTS = \
	controls/button.o	\
	controls/combo.o	\
	controls/edit.o		\
	controls/icontitle.o	\
	controls/listbox.o	\
	controls/widgets.o	\
	controls/menu.o		\
	controls/scroll.o	\
	controls/static.o

RESOURCE_OBJECTS = \
	resources/sysres.o

RESOURCE_OBJECT = $(TARGET).coff

OBJECTS = $(MISC_OBJECTS) $(INTERNAL_OBJECTS) $(GRAPHICS_OBJECTS) $(RESOURCE_OBJECTS) $(RESOURCE_OBJECT)\
	$(CONTROLS_OBJECTS) $(WINDOWS_OBJECTS)

ifeq ($(DOSCLI),yes)
CLEAN_FILES = misc\*.o windows\*.o internal\*.o controls\*.o graphics\*.o resources\*.o \
              $(TARGET).o $(TARGET).a junk.tmp base.tmp temp.exp $(TARGET).dll $(TARGET).sym
else
CLEAN_FILES = misc/*.o windows/*.o internal/*.o controls/*.o graphics/*.o resources/*.o \
              $(TARGET).o $(TARGET).a junk.tmp base.tmp temp.exp $(TARGET).dll $(TARGET).sym
endif

$(TARGET).coff: $(TARGET).rc ../../include/reactos/resource.h

$(TARGET).a: $(OBJECTS)
	$(AR) csr $(TARGET).a $(OBJECTS)

$(TARGET).dll: $(DLLMAIN) $(OBJECTS) $(TARGET).def
	$(LD) -r $(OBJECTS) -o $(TARGET).o
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--def $(TARGET).def \
		--output-lib $(TARGET).a \
		--kill-at
	$(CC) $(TARGET).o \
		../ntdll/ntdll.a \
		../kernel32/kernel32.a \
		../gdi32/gdi32.a \
		-specs=$(TARGET)_specs \
		-mdll \
		-o junk.tmp \
		-Wl,--base-file,base.tmp 
	- $(RM) junk.tmp
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--base-file base.tmp \
	        --output-exp temp.exp \
		--def $(TARGET).edf
	- $(RM) base.tmp
	$(CC) $(TARGET).o \
		../ntdll/ntdll.a\
		../kernel32/kernel32.a \
		../gdi32/gdi32.a \
		-specs=$(TARGET)_specs \
		-mdll \
		-o $(TARGET).dll \
		-Wl,--image-base,0x77e70000 \
		-Wl,--file-alignment,0x1000 \
		-Wl,--section-alignment,0x1000 \
		-Wl,temp.exp
	- $(RM) temp.exp
	$(NM) --numeric-sort $(TARGET).dll > $(TARGET).sym

$(TARGET).coff: $(TARGET).rc

clean: $(CLEAN_FILES:%=%_clean)

$(CLEAN_FILES:%=%_clean): %_clean:
	- $(RM) $*

.PHONY: clean $(CLEAN_FILES:%=%_clean)

install: $(FLOPPY_DIR)/dlls/$(TARGET).dll

$(FLOPPY_DIR)/dlls/$(TARGET).dll: $(TARGET).dll
	$(CP) $(TARGET).dll $(FLOPPY_DIR)/dlls/$(TARGET).dll

dist: $(DIST_DIR)/dlls/$(TARGET).dll

$(DIST_DIR)/dlls/$(TARGET).dll: $(TARGET).dll
	$(CP) $(TARGET).dll ../../$(DIST_DIR)/dlls/$(TARGET).dll

# EOF
