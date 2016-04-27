/*
*   Brandon Bell
*   Final Project
*   Recitation: Th 1030am
*   Guogui Ding
*/

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <climits>

#include "Spins.h"
using namespace std;

Spins::Spins(){
    //zSpin = NULL;
    //xSpin = NULL;
    //ySpin = NULL;
}


Spins::~Spins(){
}


/* Takes a file name in the current directory as an argument. Reads a file
 * contating a series 'u' for up and 'd' for down separated by spaces. Based on
 * the number of up and down states in the file buildStatFromFile returns a
 * state with probabiles for up and down determined by the probabilty of
 * getting 'u' or 'd' in the file.
*/
void Spins::buildStateFromFile(char *file)
{
    string line;
    string st;
    int up = 0;      // Tallys the number of up states in file.
    int down = 0;    // Tallys the number of down states in the file.
    float pUp = 0.0;   // the probability of an up state in file. up/(up+down).
    float pDown = 0.0; // the probability of an down state in file. down/(up+down).
    int total = 0;   // The totaly number of states in the file.
    // set the z-spin graph values to zero.
    //zSpin->densityMatrix = {{0.0,0.0},{0.0,0.0}};

    // Read in the file and tally the number of up and down states.
    ifstream inFile(file);
    while( getline( inFile, line) )
    {
        stringstream stat(line);
        //stat >> st;
        //cout<<st<<endl;        
        while( stat.good() )
        {
            stat >> st;
            //cout<<st.compare("u")<<endl;
            if( st.compare("u") == 0 )
                {
                    up++;
                }
            else if( st.compare("d") == 0 )
            {
                down++;
            }
        }
    }

    // determine pUp and pDown.
    total = up + down;
    pUp = float(up) / total;
    pDown = float(down) / total;

    cout<<"Total number of state measured :"<<total<<endl;
    cout<<"Probability of z-spin up :"<<pUp<<endl;
    cout<<"Probability of z-spin down :"<<pDown<<endl;

    // Make a state from the propbabilities.
    // We need the off-diagonal elements to be zero.
    state *fileState = new state;
    //fileState.densityMatrix = {{0.0,0.0},{0.0,0.0}};
    fileState->direction = 'z';
    fileState->densityMatrix[0][0] = pUp;
    fileState->densityMatrix[0][1] = 0.0;
    fileState->densityMatrix[1][1] = pDown;
    fileState->densityMatrix[1][0] = 0.0;

    // Print the "state density matrix" it's just a 2-node graph whose edges
    // are the probability of measuring either spin up or spin down. It's
    // simply a weighted adjacency matrix.
    cout<<"The new z-spin state graph is, "<<endl;
    cout<<'|'<<fileState->densityMatrix[0][0]
        <<' '<<fileState->densityMatrix[0][1]<<'|'<<endl;
    cout<<'|'<<fileState->densityMatrix[1][0]
        <<' '<<fileState->densityMatrix[1][1]<<'|'<<endl;
    zSpin = fileState;
    delete fileState;
}



// Take argv[0] as argument and pass it to buildStateFromFile.
void Spins::buildStateFileArgument(char *arg)
{
    buildStateFromFile(arg);
}

/* Take some user defined probabilities and use them to build and set the
 * z-sping state graph or "density matrix".
*/
void Spins::buildStateByHand(float pUp, float pDown)
{
    // set the z-spin graph values to zero.
    //zSpin->densityMatrix = {{0.0,0.0},{0.0,0.0}};

    cout<<"Probability of z-spin up :"<<pUp<<endl;
    cout<<"Probability of z-spin down :"<<pDown<<endl;

    // Make a state from the propbabilities.
    // We need the off-diagonal elements to be zero.
    state *fileState = new state;
    //fileState.densityMatrix = {{0.0,0.0},{0.0,0.0}};
    fileState->direction = 'z';
    fileState->densityMatrix[0][0] = pUp;
    fileState->densityMatrix[0][1] = 0.0;
    fileState->densityMatrix[1][1] = pDown;
    fileState->densityMatrix[1][0] = 0.0;

    // Print the "state density matrix" it's just a 2-node graph whose edges
    // are the probability of measuring either spin up or spin down. It's
    // simply a weighted adjacency matrix.
    cout<<"The new z-spin state graph is, "<<endl;
    cout<<'|'<<fileState->densityMatrix[0][0]
        <<' '<<fileState->densityMatrix[0][1]<<'|'<<endl;
    cout<<'|'<<fileState->densityMatrix[1][0]
        <<' '<<fileState->densityMatrix[1][1]<<'|'<<endl;
    zSpin = fileState;
    delete fileState;
}


void Spins::printZSpinGraph()
{
    if( zSpin != NULL )
    {
        cout<<"The z-spin state graph is, "<<endl;
        cout<<'|'<<zSpin->densityMatrix[0][0]
            <<' '<<zSpin->densityMatrix[0][1]<<'|'<<endl;
        cout<<'|'<<zSpin->densityMatrix[1][0]
            <<' '<<zSpin->densityMatrix[1][1]<<'|'<<endl;
        cout<<"The current time step is :"<<zSpin->time<<endl;
    }
    else
    {
        cout<<"No z-spin state defined yet"<<endl;
    }
}


void Spins::printXSpinGraph()
{
    if( zSpin != NULL )
    {
        cout<<"The x-spin state graph is, "<<endl;
        cout<<'|'<<xSpin->densityMatrix[0][0]
            <<' '<<xSpin->densityMatrix[0][1]<<'|'<<endl;
        cout<<'|'<<xSpin->densityMatrix[1][0]
            <<' '<<xSpin->densityMatrix[1][1]<<'|'<<endl;
        cout<<"The current time step is :"<<xSpin->time<<endl;
    }
    else
    {
        cout<<"No x-spin state defined yet"<<endl;
    }
}


void Spins::printYSpinGraph()
{
    if( zSpin != NULL )
    {
        cout<<"The y-spin state graph is, "<<endl;
        cout<<'|'<<ySpin->densityMatrix[0][0]
            <<' '<<ySpin->densityMatrix[0][1]<<'|'<<endl;
        cout<<'|'<<ySpin->densityMatrix[1][0]
            <<' '<<ySpin->densityMatrix[1][1]<<'|'<<endl;
        cout<<"The current time step is :"<<ySpin->time<<endl;
    }
    else
    {
        cout<<"No y-spin state defined yet"<<endl;
    }
}

// Make the y-spin graph by operating on the z-spin graph with the y-spin
// operator. This is just basic multiplication of 2x2 matricies.
void Spins::makeYSpinGraph()
{
    state *y= new state;
    // Multiply the z-sping graph by the Sy operator matrix.
    y->densityMatrix[0][0] = 
           (zSpin->densityMatrix[0][0] * zOperators.Sy[0][0])
           + (zSpin->densityMatrix[0][1] * zOperators.Sy[1][0]);

    y->densityMatrix[1][0] = 
           (zSpin->densityMatrix[1][0] * zOperators.Sy[0][0])
           + (zSpin->densityMatrix[1][1] * zOperators.Sy[1][0]);

    y->densityMatrix[0][1] = 
           (zSpin->densityMatrix[0][0] * zOperators.Sy[0][1])
           + (zSpin->densityMatrix[0][1] * zOperators.Sy[1][1]);

    y->densityMatrix[1][1] = 
           (zSpin->densityMatrix[1][0] * zOperators.Sy[0][1])
           + (zSpin->densityMatrix[1][1] * zOperators.Sy[1][1]);
    ySpin = y;
    delete y;

    // Print the new y-spin Graph.
    cout<<"The new y-spin state graph is, "<<endl;
    cout<<'|'<<ySpin->densityMatrix[0][0]
        <<' '<<ySpin->densityMatrix[0][1]<<'|'<<endl;
    cout<<'|'<<ySpin->densityMatrix[1][0]
        <<' '<<ySpin->densityMatrix[1][1]<<'|'<<endl;
    cout<<"The current time step is :"<<ySpin->time<<endl;
}



void Spins::makeXSpinGraph()
{
    state *x = new state;
    // Multiply the z-sping graph by the Sy operator matrix.
    x->densityMatrix[0][0] = 
           (zSpin->densityMatrix[0][0] * zOperators.Sx[0][0])
           + (zSpin->densityMatrix[0][1] * zOperators.Sx[1][0]);

    x->densityMatrix[1][0] = 
           (zSpin->densityMatrix[1][0] * zOperators.Sx[0][0])
           + (zSpin->densityMatrix[1][1] * zOperators.Sx[1][0]);

    x->densityMatrix[0][1] = 
           (zSpin->densityMatrix[0][0] * zOperators.Sx[0][1])
           + (zSpin->densityMatrix[0][1] * zOperators.Sx[1][1]);

    x->densityMatrix[1][1] = 
           (zSpin->densityMatrix[1][0] * zOperators.Sx[0][1])
           + (zSpin->densityMatrix[1][1] * zOperators.Sx[1][1]);
    xSpin = x;
    delete x;

    // Print the new y-spin Graph.
    cout<<"The new x-spin state graph is, "<<endl;
    cout<<'|'<<xSpin->densityMatrix[0][0]
        <<' '<<xSpin->densityMatrix[0][1]<<'|'<<endl;
    cout<<'|'<<xSpin->densityMatrix[1][0]
        <<' '<<xSpin->densityMatrix[1][1]<<'|'<<endl;
    cout<<"The current time step is :"<<xSpin->time<<endl;
}


void Spins::zExpectationValue()
{
    float expec;
    expec = ( 1*zSpin->densityMatrix[0][0] ) + ( -1*zSpin->densityMatrix[1][1] );
    cout<<"The expactation value of z-spin is: "<<expec<<endl;
}


void Spins::xExpectationValue()
{
    if( xSpin != NULL )
    {
        float expec;
        expec = ( 1*xSpin->densityMatrix[0][0] ) + ( -1*xSpin->densityMatrix[1][1] );
        cout<<"The expactation value of z-spin is: "<<expec<<endl;
    }
}
