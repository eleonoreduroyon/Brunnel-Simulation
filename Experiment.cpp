//
//  Experiment.cpp
//  
//
//  Created by Ely on 10/31/17.
//
//

#include "Experiment.hpp"
#include "NetworkNeurons.hpp"

//===============Constructeur================

/**
 * Constructeur for the class Experiment
 * */

Experiment ::Experiment(){}

//===============Destructeur================
/**
 * Destructeur for the class Experiment
 * */
Experiment::~Experiment(){}

//===============Methode================

/**
 *  @param Network of Neurons
 * */

void Experiment::runFig(double g, double eta, unsigned long stop, std::string title){
    NetworkNeurons net(ALLN,NE,NI,g,eta);
    Network_ = net;
    Network_.update(stop,title);
}
