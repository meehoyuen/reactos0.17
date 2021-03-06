mkdir -p $1/reactos
mkdir -p $1/reactos/system32
mkdir -p $1/reactos/system32/drivers
mkdir -p $1/reactos/bin
./install-system.sh $1
cp services/dd/floppy/floppy.sys $1/reactos/system32/drivers/
cp services/input/keyboard/keyboard.sys $1/reactos/system32/drivers
cp services/dd/blue/blue.sys $1/reactos/system32/drivers
cp services/dd/vga/miniport/vgamp.sys $1/reactos/system32/drivers
cp services/dd/vga/display/vgaddi.dll $1/reactos/system32/drivers
cp services/dd/vidport/vidport.sys $1/reactos/system32/drivers
cp services/fs/minix/minixfs.sys $1/reactos/system32/drivers
cp apps/system/shell/shell.exe $1/reactos/system32
cp apps/system/winlogon/winlogon.exe $1/reactos/system32/
cp apps/system/services/services.exe $1/reactos/system32/
cp lib/ntdll/ntdll.dll $1/reactos/system32
cp lib/kernel32/kernel32.dll $1/reactos/system32
cp lib/crtdll/crtdll.dll $1/reactos/system32
cp lib/fmifs/fmifs.dll $1/reactos/system32
cp lib/gdi32/gdi32.dll $1/reactos/system32
cp lib/advapi32/advapi32.dll $1/reactos/system32
cp apps/hello/hello.exe $1/reactos/bin
cp apps/args/args.exe $1/reactos/bin
cp apps/bench/bench-thread.exe $1/reactos/bin
cp apps/cat/cat.exe $1/reactos/bin
cp subsys/smss/smss.exe $1/reactos/system32
cp subsys/csrss/csrss.exe $1/reactos/system32
cp subsys/win32k/win32k.sys $1/reactos/system32/drivers
cp apps/apc/apc.exe $1/reactos/bin
cp apps/shm/shmsrv.exe $1/reactos/bin
cp apps/shm/shmclt.exe $1/reactos/bin
cp apps/lpc/lpcsrv.exe $1/reactos/bin
cp apps/lpc/lpcclt.exe $1/reactos/bin
cp apps/thread/thread.exe $1/reactos/bin
cp apps/event/event.exe $1/reactos/bin
cp apps/file/file.exe $1/reactos/bin
cp apps/pteb/pteb.exe $1/reactos/bin
cp apps/consume/consume.exe $1/reactos/bin
cp apps/float/float.exe $1/reactos/bin
cp apps/dump_shared_data/dump_shared_data.exe $1/reactos/bin
cp apps/vmtest/vmtest.exe $1/reactos/bin
cp apps/uitest/uitest.exe $1/reactos/bin/
cp apps/gditest/gditest.exe $1/reactos/bin/
cp apps/ptest/ptest.exe $1/reactos/bin/
cp apps/timer/timer.exe $1/reactos/bin/