#
#
#
PATH_TO_TOP = ../../..

OBJECTS= test.o ../../../ntoskrnl/ntoskrnl.a

all: test.sys

.phony: all

clean:
	- $(RM) test.o
	- $(RM) test.a
	- $(RM) junk.tmp
	- $(RM) base.tmp
	- $(RM) temp.exp
	- $(RM) test.sys

.phony: clean

test.sys: test.o
	$(DLLTOOL) --dllname test.sys --output-lib test.a
	$(CC) -specs=$(KM_SPECS) -mdll -o junk.tmp -Wl,--defsym,_end=end \
	      -Wl,--defsym,_edata=__data_end__ -Wl,--defsym,_etext=etext \
	      -Wl,--base-file,base.tmp $(OBJECTS)
	- $(RM) junk.tmp
	$(DLLTOOL) --dllname test.sys --base-file base.tmp \
	           --output-exp temp.exp 
	- $(RM) base.tmp
	$(CC) --verbose -Wl,--image-base,0x10000 -Wl,-e,_DriverEntry -specs=$(KM_SPECS) \
		-mdll -o test.sys $(OBJECTS) -Wl,temp.exp
	- $(RM) temp.exp

