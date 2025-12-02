example:
	@mkdir -p bin
	g++ main.cpp -o bin/main
	./bin/main < example.in

input:
	@mkdir -p bin
	g++ main.cpp -o bin/main
	./bin/main < input.in
