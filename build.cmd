mkdir tmp
bin\scpp.exe main.c tmp/cc.i
bin\scc.exe tmp/cc.i tmp/cc.asm
bin\asm.exe tmp/cc.asm edit.exe tmp/cc.map