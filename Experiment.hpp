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

class Experiment{
    public:
    Experiment();
    ~Experiment();
    void runFig(double g, double eta, unsigned long stop, std::string title);
};
#endif /* Experiment_hpp */
