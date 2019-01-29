OBJECT=build/color.o build/cursor.o build/ytime.o build/pos.o build/who.o \
       build/file_processor.o
COMPILER=g++
CXXFLAGS=-Wall -Werror -Wshadow -O2 -DNDEBUG -I ../include/
TESTCASE=test/input test/ytime test/who test/file_processor

all: build-dir ${OBJECT}

test: build-dir ${OBJECT} test-dir ${TESTCASE}

build-dir:
	mkdir -p build

build/color.o: color.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/cursor.o: cursor.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/ytime.o: ytime.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/pos.o: pos.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/input.o: input.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/who.o: who.cpp
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

build/file_processor.o: file_processor.c
	${COMPILER} ${CXXFLAGS} -c $^ -o $@

test-dir:
	mkdir -p test

test/input: build/ytime.o build/input.o test-input.cpp
	${COMPILER} ${CXXFLAGS} $^ -o $@

test/ytime: build/input.o build/ytime.o test-ytime.cpp
	${COMPILER} ${CXXFLAGS} $^ -o $@

test/who: build/who.o test-who.cpp
	${COMPILER} ${CXXFLAGS} $^ -o $@

test/file_processor: build/file_processor.o test-file_processor.c
	${COMPILER} ${CXXFLAGS} $^ -o $@

clean:
	rm -rf test build
