/*Write a program in C++ to use map associative container. The keys will be the names of states and the values will be the populations of the states. When the program runs, the user is prompted to type the name of a state. The program then looks in the map, using the state name as an index and returns the population of the state.

 Map associativecon
 Map associative cont
 element has a keyva
 tainer:
 ainer are associative containers that store elements in a mapped fashion. Each
 lue and a mapped value. No two mapped values can have same key values.
 This operator is used
 to the at() function, th
 the position is notin
 map::operator[]
 to reference the element present at position given inside the operator. It is similar
 e only difference is that the at() function throws an out-of-range exception when
 the bounds of the size of map, while this operator causes undefined behaviour.
 Syntax :
 mapname[key]
 Parameters :
 Key value mapped to the element to be fetched.
 Returns :
 Direct reference to the element at the given key value*/


#include<iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // Create a map to store state names and their populations
    map<string, long> statePopulations;

    // Initialize the map with some state populations
    statePopulations["California"] = 39538223;
    statePopulations["Texas"] = 29145505;
    statePopulations["Florida"] = 21538187;
    statePopulations["New York"] = 20201249;
    statePopulations["Pennsylvania"] = 13002700;
    statePopulations["Illinois"] = 12812508;

    // Prompt the user to enter a state name
    string stateName;
    cout << "Enter the name of a state to get its population: ";
    getline(cin, stateName);

    // Search for the state in the map
    map<string, long>::iterator it = statePopulations.find(stateName);

    if (it != statePopulations.end()) {
        // If found, display the population
        cout << "The population of " << stateName << " is " << it->second << endl;
    } else {
        // If not found, display a message
        cout << "State not found." << endl;
    }

    return 0;
}

/*------------------------output----------------------
Enter the name of a state to get its population: California
The population of California is 39538223

--------------------------------
Process exited after 22.96 seconds with return value 0
Press any key to continue . . .*/