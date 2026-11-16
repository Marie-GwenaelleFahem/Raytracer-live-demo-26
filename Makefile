.PHONY: build run test clean

build:
	cmake -B build -DCMAKE_BUILD_TYPE=Debug
	cmake --build build

run: build
	./build/raytracer

test: build
	ctest --test-dir build --output-on-failure

clean:
	rm -rf build
