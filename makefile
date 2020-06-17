# makefile
# 
# @author Ryan Morehouse
# @license MIT

OBJ = TerminalPrompt.o MortgageCalculator.o test_calculator.o
DEPS = TerminalPrompt.o MortgageCalculator.o
FLAGS = -Wall -lm
CC = g++
.SUFFIXES: .cpp .o

.cpp.o:
	g++ -o $@ $^ $(FLAGS)

all: $(OBJ)

TerminalPrompt.o: TerminalPrompt.cpp
	$(CC) -c -o $@ $< $(FLAGS)

MortgageCalculator.o: MortgageCalculator.cpp
	$(CC) -c -o $@ $< $(FLAGS)

test_calculator.o: test_calculator.cpp $(DEPS)

clean:
	\rm -f *.o
