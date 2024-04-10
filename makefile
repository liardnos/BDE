NAME = bde

MAKE_FLAGS = -j32


all: setNiceValue build

setNiceValue:
	echo renice -n 19 -p $${PPID}
	renice -n 19 -p $${PPID}

clearBuild: setNiceValue
	rm -rf build

clear:
	clear

build: clear setNiceValue
	cd build && cmake .. && make $(MAKE_FLAGS)

re: clear setNiceValue clear
	mkdir -p build
	cd build && cmake .. && make $(MAKE_FLAGS)

run: clear setNiceValue build
	./build/$(NAME) exec

valgrind: setNiceValue build
	valgrind valgrind --track-origins=yes --num-callers=500 ./build/$(NAME) exec

install: build
	sudo cp ./build/$(NAME) /bin
