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
#include <string>

class NetworkNeurons{
private:
    //=============Attributs==============
    unsigned long NbrNeurons_;//!<Total number of neurons in Network
    unsigned long NbrNE_;//!<Total number of excitatory neurons in Network
    unsigned long NbrNI_;//!<Total number of inhibitory neurons in Network
    unsigned long CE_; //!<Number of excitatory connections
    unsigned long CI_; //!<Number of inhibitory connections
    double ETA_; //!<Nu_EXT/NU_THR
    std::vector<Neuron> AllNeurons_;//!<Vector of all Neurons
    std::vector<std::vector<size_t> > NetworkConnections_; //!<Vector of all Network connections within the network
    
public:
    //=============Constructeurs=========
    /**
     * Constructeur for the class NetworkNeurons
     * @param total Number of neurons, Number of excitatory neurons, Number in inhibitory neurons
     * */

    NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI, double g,double eta);
    
    //=============Destructeurs=========

    /**
     * Destructeur for the class NetworkNeurons
     * */
    
    ~NetworkNeurons();
    
    //=============Methodes==============
    
    /**
     * Updates the Network until all steps are completed
     * @param tStop: the number of steps after which the simulation stops and title: name file
     * */

    void update(unsigned long tStop, std::string title);
    
    //=============Getters==============
    
    /**
     * Getter for the vector regrouping all Neurons
     * @return AllNeurons_
     * */
    std::vector<Neuron> GetAllNeurons_() const ;
    
    /**
     * Getter for the vector regrouping all the network connections
     * @return NetworkConnections_
     * */
    std::vector<std::vector<size_t> > GetNetworkConnections_() const ;
    
    /**
     * Getter for the number of neurons
     * @return NbrNeurons_
     * */
    unsigned long GetNbrNeurons_() const ;
    
    /**
     * Getter for the number of inhibitory neurons
     * @return NbrNI_
     * */
    unsigned long GetNbrNI_() const ;
    
    /**
     * Getter for the number of excitatory neurons
     * @return NbrNE_
     * */
    unsigned long GetNbrNE_() const ;
    
    /**
     * Getter for the number of excitatory connections
     * @return CE_
     * */
    unsigned long GetCE_() const ;
    
    /**
     * Getter for the number of inhibitory connections
     * @return CI_
     * */
    unsigned long GetCI_() const ;

};
#endif /* NetworkNeurons_hpp */
