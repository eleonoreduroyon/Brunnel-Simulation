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
    double MembranePotential_;//!<Value of Neuron's Membrane Potential
    unsigned long NbrSpikes_; //!<Num of spikes
    unsigned long TimeSpikes_; //!<Time of last spike
    bool refractory_; //!<Is Refractory or not
    unsigned long RefractoryBreakStep_; //!<Time after spike 
    double InputCurrent_; //!<External Current
    unsigned long tSimulation_; //!<Internal Clock
    std::vector< double> Buffer_; //!<To deal with Delay
    double c1_; //!<First Constant for the calculations of MembranePotential_
    double c2_; //!<Second Constant for the calculations of MembranePotential_
    double J_; //!<Amplitude of neuron
    bool BackgroundNoise_; //!<Presence of External Stimulation(For Testing Purposes)
    
public:
    //=============Constructeurs=========
    /**
     * Constructeur for the class Neuron
     * */

    Neuron();
    
    //=============Destructeur===========
    /**
     * Destructeur for the class Neuron
     * */
    ~Neuron();
    
    //=============Methodes==============
    
    /**
     * Updates state of the neuron for a fixed number of steps
     * @param StepsTaken: number of simulation steps taken
     * @return bool if neuron spikes or not
     * */ 

    bool update(long StepsTaken, double eta);
    
    /**
     * Converts type double to type string
     * @param value in type double
     * @return value in type string
     * */ 

    std::string int2strg(double a) const;
    
    /**
     * Store in buffer the amplitude of a firing neuron this neuron is connected to
     * @param time of arrival (in steps) and amplitude of firing neuron
     * */ 
    
    void receive(unsigned long arrival, double j); 

    //=============Getters===============
    
    /**
     * Getter for the current value of Membrane Potential
     * @return MembranePotential_
     * */ 
    
    double GetMembranePotential_() const;
    
    /**
     * Getter for the value of the last time in steps
     * @return TimeSpikes_
     * */ 
    
    unsigned long GetTimeSpikes_() const;
    
    /**
     * Getter for the value of the refractory break step
     * @return RefractoryBreakStep_
     * */ 
    
    unsigned long GetRefractoryBreakStep_() const;
    
    /**
     * Getter for the total number of spikes
     * @return NbrSpikes_
     * */

    
    unsigned long GetNbrSpikes_() const;
    
    /**
     * Getter for the value of the neuron's amplitude
     * @return J_
     * */

    
    double GetJ_() const;
    //=============Setters===============
    
    /**
     * Setter for the value of the membrane potential
     * @param membrane potential
     * */
    
    void SetMembranePotential_(double MembranePotential);
    
    /**
     * Setter for the value of the input current
     * @param input current
     * */
    
    void SetInputCurrent_(double InputCurrent);
    
    /**
     * Setter for the value of the amplitude
     * @param amplitude(j)
     * */
    
    void SetJ_(double j);
    
    /**
     * Setter for the value of the BackgroundNoise_
     * @param Presence of background noise or not
     * */
    
    void SetBackgroundNoise_(bool backgroundnoise);
    
    /**
     * Setter for the value of the buffer for a particular index
     * @param index i, j amplitude received
     * */
    
    void SetBuffer_(int i, double j);
};


#endif /* Neuron_hpp */

