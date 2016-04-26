# Compiler using debug symbols.
CC = g++ -g
# Output filename!
out = QuantumSpins
# Define the files to compile.
Files = QuantumSpins.cpp Spins.cpp Spins.h

all:
	$(CC) -o $(out) $(Files) 

clean:
	rm -f $(out)

