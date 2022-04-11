// Julian Espinoza
// Wesley Goo
// Hamza Patel
// Arturo Islas Mejia
// Date: 4/8/2022

#include <iostream>
#include <queue>
#include <map>
#include "input.h"
#include "Patient.h"
#include "simulationOfWar.h"
#include "SimulationOfER.h"
#include "SimulationOfCheckout.h"
using namespace std;

int mainMenuOption();
int main()
{
    do
    {
        switch (mainMenuOption())
        {
        case 0: exit(1); break;
        case 1: SimOfWar(); break;
        case 2: SimOfER(); break;
        case 3: SimOfCheckout(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");

    } while (true);
}

//Precondition:none
//PostCondition:displays the main menu
int mainMenuOption()
{
    cout << endl << "Chapter 7: Assignment by by Julian Espinoza, Wesley Goo, Hamza Patel, Arturo Islas Mejia";
    cout << endl << "==========================================";
    cout << endl << "1> Simulation of War (card game) using deque STL";
    cout << endl << "2> Simulation of an emergency room (ER) using priority queue STL";
    cout << endl << "3> Simulation of checkout lines at CostCo using multiple queues STL";
    cout << endl << "==========================================";
    cout << endl << "Exit 0";
    cout << endl << "==========================================" << endl;
    int options = inputInteger("Options: ", 0, 3);
    cout << endl << endl << endl;
    return options;
}