/*
*   Brandon Bell
*   Final Project 
*   Recitation: Th 1030am
*   Guogui Ding
*
*/
#ifndef SPINS_H
#define SPINS_H
#include<vector>
#include<iostream>

// Defines the basic graph structure used to store the probabilites (edges) of the
// differant spin states (the verticeses).
struct state
{
    std::string direction;
    float densityMatrix[2][2];// {{0.0,0.0},{0.0,0.0}};
    int time = 0;
};


/* Define the operators that can be applied to the z-spin state to determine
 * the values for spin up and down along the x and y axis.
*/
struct zSpinOperators
{
    // The Sx operator measures the spin component along the x-axis.
    float Sx[2][2] = {{0,1},
                      {1,0}};
    // The Sy operator measures the spin component along the y-axis.
    float Sy[2][2] = {{0,-1},
                      {1,0}};
    // The Sz operator measures the spin component along the z-axis.
    float Sz[2][2] = {{1,0},
                      {0,-1}};
};

class Spins
{
    public:
        Spins();
        ~Spins();
        void buildStateFromFile(char *);
        void buildStateFileArgument(char *);
        void buildStateByHand(float pUp, float pDown);
        void printZSpinGraph();
        void printXSpinGraph();
        void printYSpinGraph();
        void makeXSpinGraph();
        void makeYSpinGraph();
        void zExpectationValue();
        void xExpectationValue();
        state *zSpin = new state;
        state *xSpin = new state;
        state *ySpin = new state;
        zSpinOperators zOperators;

    protected:
    private:
};

#endif // SPINS_H
