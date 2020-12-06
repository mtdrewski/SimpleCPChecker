all:
	mkdir -p bin
	mkdir -p files
	g++ -o bin/wzor src/wzor.cpp
	g++ -o bin/gen src/gen.cpp
	g++ -o bin/brut src/brut.cpp
	g++ -o bin/spraw src/spraw.cpp

run: 
	./bin/spraw

clean:
	rm -f bin/*
	rm -f files/*