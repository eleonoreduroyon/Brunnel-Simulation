//
//  Neuron.hpp
//  
//
//  Created by Ely on 10/2/17.
//
//

#ifndef Neuron_hpp
#define Neuron_hpp

#include <string>
#include <vector>

class Neuron{
    private:
//=============Attributs==============
    double MembranePotential_;
    unsigned long NbrSpikes_; //Num of spikes
    unsigned long TimeSpikes_; //Time of last spike
    bool refractory_; // Is Refractory or not
    unsigned long RefractoryBreakStep_; //Time after spike during which MembranePotential_ =0
    double InputCurrent_; // External Current
    unsigned long tSimulation_; //Internal Clock
    std::vector< long> Buffer_; //To deal with Delay
    double c1_; //First Constant for the calculations of MembranePotential_
    double c2_; //Second Constant for the calculations of MembranePotential_
    double J_; //Amplitude
    
    public:
//=============Constructeurs=========
    Neuron();
//=============Destructeur===========
    ~Neuron();
//=============Methodes==============
    bool update(long StepsTaken);
    void recieve(unsigned long arrival, double j); //recieves stimulus from pre synaptic neuron
    std::string int2strg(double a) const; //converts int to string
//=============Getters===============
    double GetMembranePotential_() const;
    unsigned long GetTimeSpikes_() const;
    std::vector<unsigned long> GetBuffer_() const;
    unsigned long GetRefractoryBreakStep_() const;
    unsigned long GetNbrSpikes_() const;
    double GetJ_() const;
//=============Setters===============
    void SetMembranePotential_(double MembranePotential);
    void SetInputCurrent_(double InputCurrent);
    void SetBuffer_(int i);
    void SetJ_(double j);
};


#endif /* Neuron_hpp */
