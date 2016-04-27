# Bell_CSCI2270_FInalProject

# QuantumSpins Overview

QuantumSpins uses small weighted graphs to make a simple model of an electrons spin. An electron orbiting an atom can have only be measured to have a spin of up or down but, until it's measured, it may have a spin of up and down at the same time. QuantumSpins captures the behaviour with a 2 verticy graph (2x2 matrix). The weights in the graph come from the probability that the electron will be found in spin up or spin down. It's basicialy how much spin up is in the electron or how much spin down is in the electron. The a lab the weights for the graph would be found by setting up a bunch of electrons in the same state and making measurements of spin on each of them. That would give some number of spin ups and spin downs and the probablilty of spin up would be ( number of spin up electrons ) / ( total number of electrons ).

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

TBD
