//
//  main.cpp
//
//
//  Created by Ely on 10/2/17.
//
//

#include "NetworkNeurons.hpp"
#include "Constants.hpp"
#include <iostream>

using namespace std;

int main(){
    double Iext(0.0);  //Amplitude of Current
    NetworkNeurons Network(ALLN,NE,NI);
    unsigned long tStop(5000); //Total Simulation Time
    Network.update(tStop);
    return 0;
}






