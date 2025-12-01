default:
	@make main

%:
	@mkdir -p bin
	g++ $*.cpp -o bin/$*
	./bin/$* < example.in
