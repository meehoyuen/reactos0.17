# $Id: makefile,v 1.42 2001/01/20 12:17:51 ekohl Exp $
#
# ReactOS Operating System
#
PATH_TO_TOP = ../..

TARGET = kernel32

KERNEL32_BASE = 0x77f00000

CFLAGS = -DKERNEL32_BASE=$(KERNEL32_BASE)

DLLTARGET=$(TARGET).dll

all: $(DLLTARGET)

SYNCH_OBJECTS = synch/critical.o synch/event.o synch/intrlck.o synch/mutex.o \
                synch/sem.o synch/timer.o synch/wait.o

MISC_OBJECTS = misc/error.o misc/atom.o misc/handle.o misc/env.o misc/dllmain.o \
		misc/console.o misc/time.o misc/stubs.o misc/rtl.o misc/ldr.o misc/res.o \
		misc/debug.o misc/sysinfo.o

FILE_OBJECTS = file/file.o file/curdir.o file/lfile.o file/dir.o \
               file/iocompl.o file/volume.o file/deviceio.o file/dosdev.o \
	       file/create.o file/find.o file/copy.o file/pipe.o \
	       file/move.o file/lock.o file/rw.o file/delete.o \
	       file/npipe.o

MEM_OBJECTS = mem/global.o mem/heap.o mem/utils.o mem/section.o mem/isbad.o \
              mem/procmem.o mem/virtual.o

NLS_OBJECTS =  nls/codepage.o nls/cpmisc.o nls/cptable.o\
 nls/cp37.o nls/cp437.o nls/cp500.o nls/cp737.o nls/cp775.o nls/cp850.o nls/cp852.o nls/cp855.o nls/cp857.o\
 nls/cp860.o nls/cp861.o nls/cp863.o nls/cp865.o nls/cp866.o nls/cp869.o nls/cp875.o nls/cp1026.o\
 nls/cp1250.o nls/cp1251.o nls/cp1252.o nls/cp1253.o nls/cp1254.o nls/cp1255.o nls/cp1256.o nls/cp1257.o\
 nls/cp10000.o nls/cp10006.o nls/cp10007.o nls/cp10029.o nls/cp10079.o nls/cp10081.o\
 nls/lctable.o\
 nls/lcAFK.o nls/lcBEL.o nls/lcBGR.o nls/lcCAT.o nls/lcCSY.o nls/lcDAN.o\
 nls/lcDEA.o nls/lcDEC.o nls/lcDEL.o nls/lcDES.o nls/lcDEU.o\
 nls/lcELL.o\
 nls/lcENA.o nls/lcENB.o nls/lcENC.o nls/lcENG.o nls/lcENI.o nls/lcENJ.o nls/lcENL.o nls/lcENS.o nls/lcENT.o\
 nls/lcENU.o nls/lcENZ.o\
 nls/lcESA.o nls/lcESB.o nls/lcESC.o nls/lcESD.o nls/lcESE.o nls/lcESF.o nls/lcESG.o nls/lcESH.o nls/lcESI.o\
 nls/lcESL.o nls/lcESM.o nls/lcESN.o nls/lcESO.o nls/lcESP.o nls/lcESR.o nls/lcESS.o nls/lcESU.o nls/lcESV.o\
 nls/lcESY.o nls/lcESZ.o\
 nls/lcETI.o nls/lcEUQ.o nls/lcFIN.o nls/lcFOS.o\
 nls/lcFRA.o nls/lcFRB.o nls/lcFRC.o nls/lcFRL.o nls/lcFRS.o\
 nls/lcHRV.o nls/lcHUN.o nls/lcIND.o nls/lcISL.o nls/lcITA.o nls/lcITS.o nls/lcLTH.o nls/lcLVI.o nls/lcNLB.o\
 nls/lcNLD.o nls/lcNON.o nls/lcNOR.o nls/lcPLK.o nls/lcPTB.o nls/lcPTG.o nls/lcROM.o nls/lcRUS.o nls/lcSKY.o\
 nls/lcSLV.o nls/lcSQI.o nls/lcSRB.o nls/lcSRL.o nls/lcSVE.o nls/lcSVF.o nls/lcTRK.o nls/lcUKR.o\
 nls/locale.o nls/mbtowc.o nls/wctomb.o nls/ole2nls.o

THREAD_OBJECTS = \
	thread/fiber.o	\
	thread/thread.o	\
	thread/tls.o

PROCESS_OBJECTS = \
	process/proc.o \
	process/cmdline.o \
	process/create.o

STRING_OBJECTS = string/lstring.o

EXCEPT_OBJECTS = except/except.o

RESOURCE_OBJECT = $(TARGET).coff


OBJECTS = $(MISC_OBJECTS) $(FILE_OBJECTS) $(THREAD_OBJECTS) \
          $(PROCESS_OBJECTS) $(STRING_OBJECTS) $(MEM_OBJECTS) \
          $(SYNCH_OBJECTS) $(EXCEPT_OBJECTS) $(RESOURCE_OBJECT)

ifeq ($(DOSCLI),yes)
CLEAN_FILES = except\*.o file\*.o mem\*.o misc\*.o nls\*.o \
              process\*.o string\*.o synch\*.o thread\*.o \
              $(TARGET).o $(TARGET).a junk.tmp base.tmp temp.exp \
	      $(TARGET).dll $(TARGET).sym $(TARGET).coff
else
CLEAN_FILES = except/*.o file/*.o mem/*.o misc/*.o nls/*.o  \
              process/*.o string/*.o synch/*.o thread/*.o  \
              $(TARGET).o $(TARGET).a junk.tmp base.tmp temp.exp \
	      $(TARGET).dll $(TARGET).sym $(TARGET).coff
endif

nls/ole2nls.o: nls/ole2nls.c
	$(CC) $(CFLAGS) -I. nls/ole2nls.c

$(TARGET).coff: $(TARGET).rc ../../include/reactos/resource.h

$(TARGET).a: $(OBJECTS)
	$(AR) csr $(TARGET).a $(OBJECTS)

$(TARGET).dll: $(DLLMAIN) $(OBJECTS) $(TARGET).def
	$(LD) \
		-r $(OBJECTS) \
		-o $(TARGET).o
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--def $(TARGET).def \
		--kill-at \
		--output-lib $(TARGET).a
	$(CC) \
		-nostartfiles -nostdlib \
		-mdll \
		-o junk.tmp \
		-Wl,--base-file,base.tmp \
		$(TARGET).o \
		../ntdll/ntdll.a -lgcc
	- $(RM) junk.tmp
	$(DLLTOOL) \
		--dllname $(TARGET).dll \
		--base-file base.tmp \
		--output-exp temp.exp \
		--def $(TARGET).edf
	- $(RM) base.tmp
	$(CC) \
		-nostartfiles -nostdlib \
		-mdll \
		-o $(TARGET).dll \
		$(TARGET).o \
		../ntdll/ntdll.a -lgcc \
		-Wl,--image-base,$(KERNEL32_BASE) \
		-Wl,--file-alignment,0x1000 \
		-Wl,--section-alignment,0x1000 \
		-Wl,temp.exp
	- $(RM) temp.exp
	$(NM) --numeric-sort $(TARGET).dll > $(TARGET).sym

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

WITH_DEBUGGING=yes
#WARNINGS_ARE_ERRORS = yes
include ../../rules.mak
