ispc ispcVec4.ispc -o ../lmVectors/lmVec4.obj --arch=x86 --target=sse4 --math-lib=system
ispc ispcVec3.ispc -o ../lmVectors/lmVec3.obj --arch=x86 --target=sse4 --math-lib=system
ispc ispcVec2.ispc -o ../lmVectors/lmVec2.obj --arch=x86 --target=sse4 --math-lib=system
@echo off
pause
cls
CompileIspc.bat
@echo on
