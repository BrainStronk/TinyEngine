@echo off

REM NOTE(zak): This is an attempt to find cl if the user doesn't have CL. 
where /q cl
if ERRORLEVEL 1 (
    for /f "delims=" %%a in ('"%ProgramFiles(x86)%\Microsoft Visual Studio\Installer\vswhere.exe" -find VC\Auxiliary\Build\vcvarsall.bat') do (%%a x64)
)


IF NOT EXIST ..\build mkdir ..\build

pushd ..\build

set CompilerFlags=-nologo -EHa- -FC -fp:fast -Gm- -GR- -MTd -Od -Oi -W4 -WX -Z7
set OffErrors=-wd4201 -wd4100 -wd4189 -wd4505

fxc -nologo -EVS -Tvs_4_0 -Foshaders.fxc ..\source\shaders.hlsl

cl %CompilerFlags% %OffErrors% -DTINY_ENGINE_DEBUG=1 ..\source\win32_tinyengine.c /link user32.lib d3d11.lib dxguid.lib ole32.lib xinput.lib

popd