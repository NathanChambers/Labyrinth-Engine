ispc ispcVec4.ispc -o ../lmIspc/lmVec4.obj --arch=x86 --target=sse4 --math-lib=system
ispc ispcVec3.ispc -o ../lmIspc/lmVec3.obj --arch=x86 --target=sse4 --math-lib=system
ispc ispcVec2.ispc -o ../lmIspc/lmVec2.obj --arch=x86 --target=sse4 --math-lib=system
ispc ispcMatrix4.ispc -o ../lmIspc/lmMatrix4.obj --arch=x86 --target=sse4 --math-lib=system
@echo off
pause
cls
@echo on
CompileIspc.bat

