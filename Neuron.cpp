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

Neuron::Neuron():MembranePotential_(0.0),NbrSpikes_(0),TimeSpikes_(0), refractory_(false),RefractoryBreakStep_(0),InputCurrent_(0),tSimulation_(0), J_(JE),BackgroundNoise_(true){
    for(size_t n(0); n < DelaiSTEP+1;++n){
        Buffer_.push_back(0.0);
    }
    assert(TAU != 0);
    c1_ = exp(-H/TAU);
    c2_ = RESISTANCE*(1-c1_);
}

//========================Destructeurs=======================

Neuron::~Neuron(){}

//========================Methodes=============================

bool Neuron :: update(long StepsTaken,double eta){
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
           static poisson_distribution<> poisson(NU_THR*eta*H);
           assert(tSimulation_%(DelaiSTEP+1) < Buffer_.size());
           MembranePotential_= (c1_*MembranePotential_)+(InputCurrent_*c2_) + Buffer_[tSimulation_%(DelaiSTEP+1)];
            if(BackgroundNoise_){
                MembranePotential_+=(poisson(gen)*JE);
            }
           Buffer_[tSimulation_%(DelaiSTEP+1)]=0;
        }
        ++tSimulation_;
    }
    return HasSpike;
}


string Neuron::int2strg(double a) const{
    ostringstream s;
    s << a;
    string str = s.str();
    return str;
}



void Neuron::receive(unsigned long arrival, double j){
    assert(arrival%(DelaiSTEP+1) < Buffer_.size());
    Buffer_[arrival%(DelaiSTEP+1)] += j;
}

//====================Getters==================

double Neuron::GetMembranePotential_() const{
    return MembranePotential_;
}

unsigned long Neuron::GetTimeSpikes_() const{
    return TimeSpikes_;
}

unsigned long Neuron::GetRefractoryBreakStep_() const{
    return RefractoryBreakStep_;
}

unsigned long Neuron::GetNbrSpikes_() const{
    return NbrSpikes_;
}

double Neuron::GetJ_() const{
    return J_;
}

//====================Setters====================

void Neuron::SetMembranePotential_(double MembranePotential){
    MembranePotential_=MembranePotential;
}

void Neuron::SetInputCurrent_(double InputCurrent){
    InputCurrent_=InputCurrent;
}

void Neuron::SetJ_(double j){
    J_=j;
}

void Neuron::SetBackgroundNoise_(bool backgroundNoise){
    BackgroundNoise_=backgroundNoise;
}

void Neuron::SetBuffer_(int i, double j){
    Buffer_[i] += j;
}
