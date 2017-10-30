//
//  NetworkNeurons.hpp
//
//
//  Created by Ely on 10/23/17.
//
//

#ifndef NetworkNeurons_hpp
#define NetworkNeurons_hpp

#include "Neuron.hpp"
#include <stdio.h>
#include <vector>

class NetworkNeurons{
private:
    unsigned long NbrNeurons_;
    unsigned long NbrNE_;
    unsigned long NbrNI_;
    std::vector<Neuron> AllNeurons_;
    std::vector<std::vector<int> > NetworkConnections_;
    
public:
    NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI);
    void update(unsigned long a,unsigned long b,unsigned long tStop);
    
};
#endif /* NetworkNeurons_hpp */
