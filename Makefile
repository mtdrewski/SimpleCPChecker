SHELL := /bin/bash

.SILENT: run 

all:
	mkdir -p bin
	mkdir -p files
	g++ -o bin/wzor src/wzor.cpp
	g++ -o bin/gen src/gen.cpp
	g++ -o bin/brut src/brut.cpp


run: 	 
	for i in `seq 1 1000`;\
	do\
		echo $$i;\
		./bin/gen > files/_in;\
		./bin/brut < files/_in > files/_brout;\
		./bin/wzor < files/_in > files/_wzout;\
		out=$$(diff -EZ files/_wzout files/_brout);\
		if test "$$out"; then\
			echo "Nie dziala :((";\
			echo "$$out";\
			cat files/_in;\
			break;\
		fi;\
	done;\

clean:
	rm -f bin/*
	rm -f files/*