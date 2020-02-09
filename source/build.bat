@echo off

REM NOTE(zak): This is an attempt to find cl if the user doesn't have CL. 
where /q cl
if ERRORLEVEL 1 (
    for /f "delims=" %%a in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -find VC\Auxiliary\Build\vcvarsall.bat') do (%%a x64)
)


IF NOT EXIST ..\build mkdir ..\build

pushd ..\build

cl -nologo -FC -Zi ..\source\win32_tinyengine.c /link user32.lib d3d11.lib dxguid.lib

popd