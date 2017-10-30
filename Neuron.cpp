//
//  Neuron.cpp
//
//
//  Created by Ely on 10/2/17.
//
//

#include "Neuron.hpp"
#include "Constants.hpp"

#include <cmath>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <random>

using namespace std;

//========================Constructeurs=======================
/**
* Constructeur for the class Neuron
* */
Neuron::Neuron():MembranePotential_(0.0),NbrSpikes_(0),TimeSpikes_(0), refractory_(false),RefractoryBreakStep_(0),InputCurrent_(0),tSimulation_(0){
    for(size_t n(0); n < DelaiSTEP+1;++n){
        Buffer_.push_back(0);
    }
    assert(TAU != 0);
    c1_ = exp(-H/TAU);
    c2_ = RESISTANCE*(1-c1_);
}

//========================Destructeurs=======================

/**
* Destructeur for the class Neuron
* */
Neuron::~Neuron(){}


//========================Methodes=============================

/**
* Updates state of the neuron for a fixed number of steps
* @param StepsTaken: number of simulation steps taken
* @return bool if neuron spikes or not
* */ 

bool Neuron :: update(long StepsTaken){
    if(StepsTaken<=0){
        return false;
    }
    bool HasSpike(false);
   
    unsigned long tStop = tSimulation_+StepsTaken;
    while(tSimulation_ < tStop){
        if(MembranePotential_ > MembranePotentialTHRESHOLD){
            //Membrane potential is above threshold.
            refractory_ = true;
            HasSpike = true;
            //We store the spike and move on.
            TimeSpikes_ = tSimulation_;
            ++NbrSpikes_;
        }
        
        if(refractory_){
            //Neuron is refractory => reset memebrane potential to 0
            MembranePotential_ = 0.0;
            ++RefractoryBreakStep_;
            //Reset BreakTime when over
            if(RefractoryBreakStep_ > REFRACTORYSTEP){
                MembranePotential_ = VRESET;
                RefractoryBreakStep_= 0.0;
                refractory_= false;
            }
        }else{
           //static declare inside the function you actually use it(convention)
           static random_device rd;
           static mt19937 gen(rd());
           static poisson_distribution<> poisson(NU_EXT*H);
           assert(tSimulation_%(DelaiSTEP+1) < Buffer_.size());
           MembranePotential_= (c1_*MembranePotential_)+(InputCurrent_*c2_)+(poisson(gen)*JE) + Buffer_[tSimulation_%(DelaiSTEP+1)];
           Buffer_[tSimulation_%(DelaiSTEP+1)]=0;
        }
        ++tSimulation_;
    }
    return HasSpike;
}

/**
* Converts type double to type string
* @param value in type double
* @return value in type string
* */ 

string Neuron::int2strg(double a) const{
    ostringstream s;
    s << a;
    string str = s.str();
    return str;
}

/**
* Store in buffer the amplitude of a firing neuron this neuron is connected to
* @param time of arrival (in steps) and amplitude of firing neuron 
* */ 

void Neuron::recieve(unsigned long arrival, double j){
    assert(arrival%(DelaiSTEP+1) < Buffer_.size());
    Buffer_[arrival%(DelaiSTEP+1)] += j;
}

//====================Getters==================

/**
* Getter for the current value of Membrane Potential
* @return MembranePotential_
* */ 
    
double Neuron::GetMembranePotential_() const{
    return MembranePotential_;
}

/**
* Getter for the value of the last time in steps
* @return TimeSpikes_
* */ 

unsigned long Neuron::GetTimeSpikes_() const{
    return TimeSpikes_;
}

/**
* Getter for the value of the refractory break step
* @return RefractoryBreakStep_
* */ 

unsigned long Neuron::GetRefractoryBreakStep_() const{
    return RefractoryBreakStep_;
}

/**
* Getter for the total number of spikes
* @return NbrSpikes_
* */

unsigned long Neuron::GetNbrSpikes_() const{
    return NbrSpikes_;
}

/**
* Getter for the value of the neuron's amplitude
* @return J_
* */

double Neuron::GetJ_() const{
    return J_;
}

//====================Setters====================
/**
* Setter for the value of the membrane potential
* @param membrane potential
* */

void Neuron::SetMembranePotential_(double MembranePotential){
    MembranePotential_=MembranePotential;
}

/**
* Setter for the value of the input current
* @param input current
* */

void Neuron::SetInputCurrent_(double InputCurrent){
    InputCurrent_=InputCurrent;
}

/**
* Setter for the value of the amplitude
* @param amplitude(j)
* */

void Neuron::SetJ_(double j){
    J_=j;
}   
