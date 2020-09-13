CXX = g++
STDVERSION = -std=c++17 -lstdc++fs
WARNINGS = -pedantic -Wall -Wfatal-errors -Wextra -Wno-unused-parameter -Wno-unused-variable


TARGET = VMTranslator
OBJECTS = code_gen.o file.o parser.o token.o utils.o

all:$(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(WARNINGS) -o $(TARGET) src/main.cpp $(OBJECTS) $(STDVERSION)

utils.o: src/utils.cpp src/utils.h 
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/utils.cpp -o utils.o

token.o: src/token.cpp src/token.h
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/token.cpp -o token.o

parser.o: src/parser.cpp src/parser.h
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/parser.cpp -o parser.o

file.o: src/file.cpp src/file.h
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/file.cpp -o file.o

code_gen.o: src/code_gen.cpp src/code_gen.h
	$(CXX) $(WARNINGS) $(STDVERSION) -c src/code_gen.cpp -o code_gen.o


clean:
	rm -rf *.o $(TARGET) *.asm 