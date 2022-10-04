all:
	scons platform=linux -j10

clean:
	scons platform=linux --clean

compile_commands:
	scons --compiledb= compiledb platform=linux
