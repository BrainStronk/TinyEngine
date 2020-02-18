#!/bin/bash 
set -x

function assertInstalled()
{
    for var in "$@"; do
        if ! which $var &> /dev/null; then
            echo "Install $var!"
            exit 1
        fi
    done
}


if [[ "$OSTYPE" == "linux-gnu" ]]; then
CC=x86_64-w64-mingw32-gcc ;
elif [[ "$OSTYPE" == "darwin"* ]]; then
CC=x86_64-w64-mingw32-gcc ;
elif [[ "$OSTYPE" == "cygwin" ]]; then
CC=gcc ;
elif [[ "$OSTYPE" == "msys" ]]; then
CC=gcc ;
elif [[ "$OSTYPE" == "win32" ]]; then
CC=gcc ;
elif [[ "$OSTYPE" == "freebsd"* ]]; then
CC=x86_64-w64-mingw32-gcc ;
else
echo "unknown OS"
exit 1
fi

assertInstalled $CC
mkdir -p ../build

function shaders()
{
	assertInstalled glslangValidator
	glslangValidator -V ./shaders/basic.vert.glsl -o ./shaders/Vbasic.spv
	glslangValidator -V ./shaders/basic.frag.glsl -o ./shaders/Fbasic.spv
	exit 0
}

function cross()
{
	$CC win32_tinyengine.c -luser32 -ld3d11 -ldxguid -o ../build/tinyengine.exe
	exit 0
}

function linuxx11()
{
	assertInstalled gcc
	gcc -O3 -g -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
	shaders
	exit 0
}

function linuxx11tcc()
{
	assertInstalled tcc
	tcc -O3 -g -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
	shaders
	exit 0
}

function help()
{
	set +o xtrace
	echo "Please specify target."
	echo "Options:"
	echo "./build.sh cross"
	echo "./build.sh linuxx11"
	echo "./build.sh linuxx11tcc"
	echo "1. windows build with cross compiler (linux & windows)"
	echo "2. linux X11 build with gcc"
	echo "3. linux X11 build with tcc"
}

"$@"
help

