SHELL := /bin/bash

.SILENT: run 

all:
	mkdir -p bin files tests
	g++ -o bin/wzor src/wzor.cpp
	g++ -o bin/gen src/gen.cpp
	g++ -o bin/brut src/brut.cpp

run: 	 
	for i in `seq 1 1000000`;\
	do\
		echo $$i;\
		./bin/gen > files/_in;\
		./bin/brut < files/_in > files/_brout;\
		./bin/wzor < files/_in > files/_wzout;\
		out=$$(diff -EZ files/_wzout files/_brout);\
		cat files/_brout;\
		if test "$$out"; then\
			echo "Nie dziala :((";\
			echo "$$out";\
			cat files/_in;\
			break;\
		fi;\
	done;\

generate:
	mkdir -p files/big/in files/big/out
	for i in `seq 1 50`;\
	do\
		echo $$i;\
		./bin/gen > files/big/in/ele$$i.in;\
		./bin/wzor <files/big/in/ele$$i.in >files/big/out/ele$$i.out; \
	done;\

diff:
	mkdir -p files/myout
	for i in `seq 1 500`;\
	do\
		echo $$i;\
		./bin/wzor <files/ele_tests/in/ele$$i.in >files/myout/ele$$i.out; \
		out=$$(diff -EZ files/myout/ele$$i.out files/ele_tests/out/ele$$i.out);\
		if test "$$out"; then\
			echo "Nie dziala :((";\
			echo "$$out";\
			break;\
		fi;\
	done;\

clean:
	rm -rf bin/*
	rm -rf files/*