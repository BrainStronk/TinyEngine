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
}

function hexshaders()
{
	assertInstalled glslangValidator
	glslangValidator -V ./shaders/basic.vert.glsl -o ./shaders/Vbasic.h --vn Vbasic
	glslangValidator -V ./shaders/basic.frag.glsl -o ./shaders/Fbasic.h --vn Fbasic
}

function cross()
{
	$CC win32_tinyengine.c -luser32 -ld3d11 -ldxguid -o ../build/tinyengine.exe
	exit 0
}

function linuxx11()
{
	if [ "$1" == "1" ]
	then
		hexshaders
		gcc -O3 -g  -DHEX_SHADERS -I./shaders -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -pthread -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
		exit 0
	fi
	shaders
	assertInstalled gcc
	gcc -O3 -g -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -pthread -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
	exit 0
}

function linuxx11tcc()
{
	if [ "$1" == "1" ]
	then
		hexshaders
		tcc -O3 -g  -DHEX_SHADERS -I./shaders -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -pthread -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
		exit 0
	fi
	shaders
	assertInstalled gcc
	tcc -O3 -g -I/usr/X11R6/include -L/usr/X11R6/lib -lX11 -lXext -lm -pthread -ldl linux_x11_tinyengine.c -o ../build/tinyengine.exe
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
	echo "./build.sh linuxx11 1"
	echo "./build.sh linuxx11tcc 1"
	echo "1. windows build with cross compiler (linux & windows)"
	echo "2. linux X11 build with gcc"
	echo "3. linux X11 build with tcc"
	echo "4. linux X11 build with gcc and compile shaders to hex .h file"
	echo "5. linux X11 build with tcc and compile shaders to hex .h file"
}

"$@"
help

