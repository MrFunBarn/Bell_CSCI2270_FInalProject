# Bell_CSCI2270_FInalProject

# QuantumSpins Overview

QuantumSpins uses small weighted graphs to make a simple model of an electrons spin. An electron orbiting an atom can have only be measured to have a spin of up or down but, until it's measured, it may have a spin of up and down at the same time. QuantumSpins captures the behaviour with a 2 verticy graph (2x2 matrix). The weights in the graph come from the probability that the electron will be found in spin up or spin down. It's basicialy how much spin up is in the electron or how much spin down is in the electron. In a lab, the weights for the graph would be found by setting up a bunch of electrons in the same state and making measurements of the spin on each of them. That would give some number of spin ups and spin downs and the probablilty of spin up would be ( number of spin up electrons ) / ( total number of electrons ). Quantum spins lets you make a graph of the electrons spin state by reading "lab spin data" from a text file or by manually specifing the weights for the graph. Once you have a graph, you can calculate the expection value of that electrons spin state. The expectaion value can be used to compute various cool stuff that I did not get around to codeing.

## Installation/Compilation

To get the code run 
```bash 
git clone https://github.com/MrFunBarn/Bell_CSCI2270_FInalProject.git
```
in a directory where you want to save the code. Git clone will make a new subdirectory named after the repository.

For conveiance I've made up a simple make file to handle
compiling all the files needed. You can just run  the command 

```bash
make
```

in the directory with all the files. Or, you can copy and paste the command

```bash
g++ -g -std=c++11 -o QuantumSpins QuantumSpins.cpp Spins.cpp Spins.h 
```
into the terminal and run it (in the directory where the file are located)

## Usage

To Start Quantum Spins run,

```bash
./QuantumSpins testStateFile.txt
```
and you'll get the main menu.

```bash
======Main Menu======
1. Build a Superposition State From a File
2. Build a Superposition State From a FileSupplied as Command Line Argument
3. Build a Superposition State by Hand
4. Make y-spin state graph
5. Make x-spin state graph
6. Print z-spin state graph
7. Print x-spin state graph
8. Print y-spin state graph
9. Calculate the expectation vlaue of z-spin
10. Calculate the expectation vlaue of x-spin
11. Quit
```
### options:
1. lets you type in a filename for "lab data".
2. If you started with a filename as a command line argument, reads in that file.
3. Lets you specify the probability of spin up or spin down manualy. (the two must sum to 1)
4. The default spin graph finds the spin component along the z-axis, 4 lets you find the spin graph for the spin component along the y axis.
5. The default spin graph finds the spin component along the z-axis, 4 lets you find the spin graph for the spin component along the x axis.
6. through 8 simply print the current graph( make sure to "make x and y before printing")
9.  and 10 calculate the expactation value of z or x graphs.

## Making "lab data":
lab data files are just plan text files with space separated u and d charachters for up and down. 
