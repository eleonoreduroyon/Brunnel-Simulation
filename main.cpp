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
    NetworkNeurons Network(ALLN,NE,NI);
    unsigned long tStop(10000);
    Network.update(tStop);
    return 0;
}






