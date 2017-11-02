//
//  Experiment.hpp
//  
//
//  Created by Ely on 10/31/17.
//
//

#ifndef Experiment_hpp
#define Experiment_hpp

#include <stdio.h>
#include <string>

class Experiment{
    public:
    //=============Constructeurs=========
    /**
     * Constructeur for the class Experiment
     * */

    Experiment();
    
    //=============Destructeurs=========
    /**
     * Destructeur for the class Experiment
     * */
    
    ~Experiment();
    
    //=============Methodes=========
    
    /**
     * Runs whole simulation and creates my file with my spike time associated to the 
     * number of the neuron which spikes
     * @param g and eta parameters we choose, stop: the numer of steps the simulation 
     * lasts, title the name of the file the values are saved in
     * */

    void runFig(double g, double eta, unsigned long stop, std::string title);
};
#endif /* Experiment_hpp */
