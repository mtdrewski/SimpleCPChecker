all:
	g++ -o bin/wzor src/wzor.cpp
	g++ -o bin/gen src/gen.cpp
	g++ -o bin/wzor src/wzor.cpp
	g++ -o bin/spraw src/spraw.cpp

run: 
	./bin/spraw

clean:
	rm bin/*

