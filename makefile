buildAll:
	@echo "--------------BUILDING PROJECT--------------"
	@gcc -c ./src/gtk3Facade/gtk3Facade.c -o ./build/gtk3Facade.o `pkg-config --cflags gtk+-3.0`
	@gcc -c ./src/devEnvironment.c -o ./build/devEnvironment.o `pkg-config --cflags gtk+-3.0`
	@gcc ./build/gtk3Facade.o ./build/devEnvironment.o -o ./build/devEnvironment `pkg-config --libs gtk+-3.0`

clean: 
	@rm -rf ./build/*

path: 
	@export PATH="/usr/local/bin:/usr/bin:/bin:/opt/bin:/c/Windows/System32:/c/Windows:/c/Windows/System32/Wbem:/c/Windows/System32/WindowsPowerShell/v1.0/:/usr/bin/site_perl:/usr/bin/vendor_perl:/usr/bin/core_perl:/c/msys64/mingw64/bin:/c/Program Files/Microsoft MPI/Bin:/c/Program Files/gnuplot/bin:/c/Program Files/NVIDIA GPU Computing Toolkit/CUDA/v12.3/bin/:/c/Program Files/Microsoft Visual Studio/2022/Community/VC/Tools/MSVC/14.36.32532/bin/Hostx64/x64/:/c/msys64/mingw64/include/gtk-3.0"
	@export PKG_CONFIG_PATH="/usr/lib/pkgconfig:/usr/share/pkgconfig:/lib/pkgconfig:/c/msys64/mingw64/lib/pkgconfig:"

run: 
	@echo "--------------STARTING EXECUTE--------------"
	@./build/devEnvironment