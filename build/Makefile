

run:
	# g++ ../*.cpp -Wall -o ./build/cars -static -Ofast -march=native -std=c++20

	# Windows
	g++ ../*.cpp -Wall -g -o cars.exe -Ofast -static -I ../include/ -L ../lib/ -lraylib -lpthread -lopengl32 -lgdi32 -lwinmm -march=native -std=c++20
	./cars

	# Linux after installing raylib
	# g++ ../*.cpp -Wall -o cars -Ofast -march=native -std=c++2a -lraylib -lpthread -ldl
	#./cars

build-release:
	# Linux after installing raylib
	cd build
	g++ *.cpp -Wall -o build/cars -Ofast -march=native -std=c++2a -lraylib -lpthread -ldl

build-debug:
	# Linux after installing raylib
	cd build
	g++ *.cpp -Wall -g -o build/cars -march=native -std=c++2a -lraylib -lpthread -ldl

all: build-release run
