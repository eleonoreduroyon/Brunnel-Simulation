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
    double Iext(1.01);  //Amplitude of Current
    NetworkNeurons Network(ALLN,NE,NI);
    unsigned long a(1000);   //Start of Step Current
    unsigned long b(4000);   //End of Step Current
    unsigned long tStop(5000); //Total Simulation Time
    Network.update(a,b,tStop);
    
    
    return 0;
}






