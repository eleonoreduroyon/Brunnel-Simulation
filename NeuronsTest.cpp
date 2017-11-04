//
//  NeuronsTest.cpp
//  
//
//  Created by Ely on 10/31/17.
//
//

#include <stdio.h>

#include <iostream>
#include "Neuron.hpp"
#include "gtest/gtest.h"
#include "Constants.hpp"
#include "NetworkNeurons.cpp"
#include <cmath>
#include <vector>


//===============CheckAmplitudeValues==================

TEST(NeuronsTEST, AmplitudeValues){
    NetworkNeurons net(1000,750,250,5,2);
    for (size_t i(0); i<net.GetAllNeurons_().size(); ++i){
        assert(i < net.GetAllNeurons_().size());
        if(i<net.GetNbrNE_()){
            EXPECT_EQ(0.0,(net.GetAllNeurons_()[i].GetJ_())-JE);
        }else{
            EXPECT_EQ(0.0,(net.GetAllNeurons_()[i].GetJ_())+5*JE);
        }
    }
}

//===============NU_THRESHValue============

TEST(NeuronsTEST, Nu_THRESHValues){
    EXPECT_EQ(0.0,(MembranePotentialTHRESHOLD/(JE*TAU))-10.0);
}

//===============NumberOfConnections==================

TEST(NeuronsTEST, NumberOfConnections){
    NetworkNeurons net(100,75,25,5,2);
    for(size_t k(0); k <net.GetNbrNeurons_(); ++k){
		assert(k < net.GetNbrNeurons_());
        unsigned long NumberOfConnectionsCE(0);
        unsigned long NumberOfConnectionsCI(0);
        for(size_t i(0); i< net.GetNbrNeurons_(); ++i){
            assert(i < net.GetNbrNeurons_());
            for(size_t j(0); j< net.GetNetworkConnections_()[i].size();++j){
                assert(j < net.GetNetworkConnections_()[i].size());
                if(net.GetNetworkConnections_()[i][j] == k){
                    if(i< net.GetNbrNE_()){
                        ++NumberOfConnectionsCE;
                    }else{
                        ++NumberOfConnectionsCI;
                    }
                }
            }
        }
    
    EXPECT_EQ(NumberOfConnectionsCE,net.GetCE_());
    EXPECT_EQ(NumberOfConnectionsCI,net.GetCI_());
}
}

//===============MembranePotentialValues============
TEST(NeuronTEST, PositiveInput){
    Neuron n;
    n.SetInputCurrent_(1.0);
    n.SetBackgroundNoise_(false);
    double eta(2.0);
    
    //First update test
    n.update(1, eta);
    EXPECT_EQ(0,20.0*(1.0-exp(-0.1/20.0))- n.GetMembranePotential_());
    
    //Test after several updates
    //*1*
    n.update(10000,eta);
    //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,n.GetNbrSpikes_());
    EXPECT_GT(1E-3, std::fabs(19.9999 - n.GetMembranePotential_()));
    //*2*
    //MembranePotential_ decay towards 0 without input current
    n.SetInputCurrent_(0.0);
    n.update(2000,eta);
    EXPECT_NEAR(0,n.GetMembranePotential_(), 1E-3);
}

TEST(NeuronTEST, NegativeInput){
    Neuron n;
    n.SetInputCurrent_(-1.0);
    n.SetBackgroundNoise_(false);
    double eta(2.0);
    
    //First update test
    n.update(1, eta);
    EXPECT_EQ(-20.0*(1.0-exp(-0.1/20.0))- n.GetMembranePotential_(),0);
    
    //Test after several updates
    //*1*
    n.update(10000,eta);
    //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,n.GetNbrSpikes_());
    EXPECT_GT(1E-3, std::fabs(-19.9999 - n.GetMembranePotential_()));
    //*2*
    //MembranePotential_ decay towards 0 without input current
    n.SetInputCurrent_(0.0);
    n.update(2000,eta);
    EXPECT_NEAR(0,n.GetMembranePotential_(), 1E-3);
}

//=====================SpikeTime========================
TEST(NeuronTEST, TimeSpikes_){
    Neuron n;
    n.SetInputCurrent_(1.01);
    n.SetBackgroundNoise_(false);
    double eta(2.0);
    
    //Waiting for first spike
    n.update(924,eta);
    EXPECT_EQ(0,n.GetNbrSpikes_());
    n.update(1,eta);
    EXPECT_EQ(1, n.GetNbrSpikes_());
    EXPECT_EQ(0.0, n.GetMembranePotential_());
    
    //Waiting for second spike
    n.update(944,eta);
    EXPECT_EQ(1, n.GetNbrSpikes_());
    n.update(1,eta);
    EXPECT_EQ(2, n.GetNbrSpikes_());
}


//=====================Post-Synaptic========================
TEST(NeuronTEST, NoPSSpike){
    Neuron n1;
    Neuron n2;
    
    n1.SetInputCurrent_(1.01);
    
    n1.SetBackgroundNoise_(false);
    n2.SetBackgroundNoise_(false);
    double eta(2.0);
    
    for(size_t i(0); i<925+DelaiSTEP+1; ++i){
        if(n1.update(1,eta)){
            EXPECT_EQ(0.0, n1.GetMembranePotential_());
            n2.update(1,eta);
            n2.receive(i,n1.GetJ_());
        }else{
            n2.update(1,eta);
        }
        
    }
    EXPECT_EQ(0.1,n2.GetMembranePotential_());
}

TEST(NeuronTEST, WithPSSpike){
    Neuron n1;
    Neuron n2;
    n1.SetInputCurrent_(1.01);
    n2.SetInputCurrent_(1.0);
    
    n1.SetBackgroundNoise_(false);
    n2.SetBackgroundNoise_(false);
    double eta(2.0);
  
    for(size_t i(0); i<1870+DelaiSTEP+1; ++i){
        if(n1.update(1,eta)){
            EXPECT_EQ(0.0, n1.GetMembranePotential_());
            n2.update(1,eta);
            n2.receive(i,n1.GetJ_());
        }else{
            n2.update(1,eta);
        }
    }
    
    //Before n2 spikes
    EXPECT_EQ(0,n2.GetNbrSpikes_());
    n2.update(1,eta);
    //After n2 spikes
    EXPECT_EQ(0,n2.GetMembranePotential_());
    EXPECT_EQ(1,n2.GetNbrSpikes_());
}



int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
