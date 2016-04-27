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

#include "Spins.h"
using namespace std;

// The basic structure of this main function was taken from my assignments 5.
int main(int argc, char *argv[]){
    // instantiate Graph instance, and menu selection variables.
    Spins spinHalf;
    int option = 0;

    // The main loop. runs until quit is selected.
    while( option != 11 ){
        // Print the main menu.
        cout<<"======Main Menu======"<< endl
            <<"1. Build a Superposition State From a File"<< endl
            <<"2. Build a Superposition State From a File"
                     <<"Supplied as Command Line Argument"<< endl
            <<"3. Build a Superposition State by Hand"<< endl
            <<"4. Make y-spin state graph"<<endl
            <<"5. Make x-spin state graph"<<endl
            <<"6. Print z-spin state graph"<<endl
            <<"7. Print x-spin state graph"<<endl
            <<"8. Print y-spin state graph"<<endl
            <<"9. Calculate the expectation vlaue of z-spin"<<endl
            <<"10. Calculate the expectation vlaue of x-spin"<<endl
            <<"11. Quit"<< endl;

        // Grab the option and convert to int with stringstream.
        string s;
        // this get line prevents a stray \n from hanging around messing up
        // latter getline calls.
        getline( cin, s );
        stringstream ss(s);
        ss >> option;

        // Processes option and apply the relevent method.
        if( option == 1 ){
            char file[20];
            string name;
            cout<<"Name of file containg state information:"<<endl;
            getline( cin, name );
            stringstream s(name);
            s >> file;
            spinHalf.buildStateFromFile(file);
        }
        else if( option == 2 ){
            spinHalf.buildStateFileArgument(argv[1]);
        }

        else if( option == 3 ){
            float pUp;
            string p;
            float pDown;
            cout<<"Enter the probability of measureing z-spin up:"<<endl;
            getline( cin, p);
            stringstream probup(p);
            probup >> pUp;
            cout<<"Enter the probability of measureing z-spin down:"<<endl;
            getline( cin, p);
            stringstream probdown(p);
            probdown >> pDown;
            spinHalf.buildStateByHand( pUp, pDown );
            
        }
        else if( option == 4 ){
            spinHalf.makeYSpinGraph();
        }
        else if( option == 5 ){
            spinHalf.makeXSpinGraph();
        }
        else if( option == 6 ){
            spinHalf.printZSpinGraph();
        }
        else if( option == 7 ){
            spinHalf.printXSpinGraph();
        }
        else if( option == 8 ){
            spinHalf.printYSpinGraph();
        }
        else if( option == 9 ){
            spinHalf.zExpectationValue();
        }
        else if( option == 10 ){
            spinHalf.xExpectationValue();
        }
        else if( option == 11 ){
            cout << "Goodbye!" << endl;
        }
    }
return 0;
}
