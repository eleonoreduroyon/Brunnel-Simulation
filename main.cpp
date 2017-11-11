//
//  main.cpp
//
//
//  Created by Ely on 10/2/17.
//
//

#include "NetworkNeurons.hpp"
#include "Experiment.hpp"
#include "Constants.hpp"
#include <iostream>

using namespace std;

int main(){
    Experiment exp;
    unsigned long tStop(10000);
    /**
     * Almost fully synchronized network, neurons firing 
     * regularly
     * at high rates
     **/
    exp.runFig(3,2,tStop,"ValuesFigA.txt");
    /**
     * Fast oscillation of the global activity, neurons firing
     * irregularly at a rate that is lower than the global
     * frequency
     **/
    exp.runFig(6,4,tStop,"ValuesFigB.txt");
    /**
     * Stationary global activity, irregularly firing
     * neurons
     **/
    exp.runFig(5,2,tStop,"ValuesFigC.txt");
    /**
     * Slow oscillation of the global activity, neurons firing 
     * irregularly at very low rates
     **/
    exp.runFig(4.5,0.9,tStop,"ValuesFigD.txt");
    return 0;
}






