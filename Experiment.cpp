//
//  Experiment.cpp
//  
//
//  Created by Ely on 10/31/17.
//
//

#include "Experiment.hpp"
#include "NetworkNeurons.hpp"
#include "Constants.hpp"

//===============Constructeur================

Experiment ::Experiment(){}

//===============Destructeur================

Experiment::~Experiment(){}

//===============Methode================

void Experiment::runFig(double g, double eta, unsigned long stop, std::string title){
    NetworkNeurons net(ALLN,NE,NI,g,eta);
    net.update(stop,title);
}
