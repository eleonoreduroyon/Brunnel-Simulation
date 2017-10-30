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
    unsigned long NbrNeurons_;//!<Total number of neurons in Network
    unsigned long NbrNE_;//!<Total number of excitatory neurons in Network
    unsigned long NbrNI_;//!<Total number of inhibitory neurons in Network
    std::vector<Neuron> AllNeurons_;//!<Vector of all Neurons
    std::vector<std::vector<int> > NetworkConnections_; //!<Vector of all Network connections within the network
    
public:
    NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI);
    void update(unsigned long tStop);
    ~NetworkNeurons();
    
};
#endif /* NetworkNeurons_hpp */
