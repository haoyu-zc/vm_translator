VMTranslator: code_gen.o file.o main.o parser.o token.o utils.o
	g++ -std=c++17 code_gen.o file.o main.o parser.o token.o utils.o -o VMTranslator

code_gen.o: code_gen.cpp code_gen.h
	g++ -std=c++17 code_gen.cpp

file.o: file.cpp file.h
	g++ -std=c++17 file.cpp

main.o: main.cpp
	g++ -std=c++17 main.cpp

parser.o: parser.cpp parser.h
	g++ -std=c++17 parser.cpp

token.o: token.cpp token.h
	g++ -std=c++17 token.cpp

utils.o: utils.cpp utils.h
	g++ -std=c++17 utils.cpp