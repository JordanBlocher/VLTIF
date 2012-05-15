


check:
	mkdir -p build
	g++ src/test/unit_test.cpp -o build/unit_test
	./build/unit_test
