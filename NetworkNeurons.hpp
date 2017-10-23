//
//  NetworkNeurons.hpp
//  
//
//  Created by Ely on 10/23/17.
//
//

#ifndef NetworkNeurons_hpp
#define NetworkNeurons_hpp

#include <stdio.h>

class NetworkNeurons(){
    private:
    unsigned long NbrNeurons_;
    unsigned long NbrNE_;
    unsigned long NbrNI_;
    std::vector<Neuron> AllNeurons_(NbrNeurons_);
    std::vector<std::vector<int> > NetworkConnections_(NbrNeurons_, std::vector <int> (NbrNeurons_));
    
    public:
    NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI,double Iext);
    ~NetworkNeurons();
    void update(unsigned long a,unsigned long b,unsigned long tStop);
    
}
#endif /* NetworkNeurons_hpp */
