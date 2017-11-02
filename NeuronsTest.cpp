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

//===============AmplitudeValues============
TEST(NeuronsTEST, AmplitudeJIValue){
    NetworkNeurons net(1000,750,250,3,2);
    for (size_t i(0); i<net.GetAllNeurons_().size(); ++i){
        assert(i < net.GetAllNeurons_().size());
        if(i<net.GetNbrNE_()){
            EXPECT_EQ((net.GetAllNeurons_()[i].GetJ_())-JE,0.0);
        }else{
            EXPECT_EQ((net.GetAllNeurons_()[i].GetJ_())+3*JE,0.0);
        }
    }
}

//===============NU_THRESHValue============

TEST(NeuronsTEST, Nu_THRESHValues){
    EXPECT_EQ((MembranePotentialTHRESHOLD/(JE*TAU))-10.0,0.0);
}

//===============NEValue==================

TEST(NeuronsTEST, NEValue){
    EXPECT_EQ((NE*EPS)-1000.0,0.0);
}

//===============NumberOfConnections==================

TEST(NeuronsTEST, NumberOfConnections){
    NetworkNeurons net(100,75,25,3,2);
    for(size_t k(0); k <net.GetNbrNeurons_().size(); ++k){
        unsigned long NumberOfConnectionsCE(0);
        unsigned long NumberOfConnectionsCI(0);
        for(size_t i(0); i< net.GetNbrNeurons_().size(); ++i){
            assert(i < net.GetNbrNeurons_().size());
            for(size_t j(0); j< net.getNetworkConnections_()[i].size();++j){
                assert(j < net.getNetworkConnections_()[i].size());
                if(net.getNetworkConnections_()[i][j]==k){
                    if(i< net.GetNbrNE_()){
                        ++NumberOfConnectionsCE;
                    }else{
                        ++NumberOfConnectionsCI;
                    }
                }
            }
        }
    }
    EXPECT_EQ(NumberOfConnectionsCE-(net.GetNbrNE_()*EPS),0.0);
    EXPECT_EQ(NumberOfConnectionsCi-(net.GetNbrNI_()*EPS),0.0);
}
/*
//===============MembranePotentialValues============
TEST(NeuronTEST, PositiveInput){
    Neuron n;
    n.SetInputCurrent_(1.0);
    
    //First update test
    n.update(1, 1000);
    EXPECT_EQ(20.0*(1.0-exp(-0.1/20.0))- n.GetMembranePotential_(),0);
    
    //Test after several updates
    //*1*
    n.update(10000,1000);
    //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,n.GetNbrSpikes_());
    EXPECT_GT(1E-3, std::fabs(19.9999 - n.GetMembranePotential_()));
    //*2*
    //MembranePotential_ decay towards 0 without input current
    n.SetInputCurrent_(0.0);
    n.update(2000,1000);
    EXPECT_NEAR(0,n.GetMembranePotential_(), 1E-3);
}

TEST(NeuronTEST, NegativeInput){
    Neuron n;
    n.SetInputCurrent_(-1.0);
    
    //First update test
    n.update(1, 1000);
    EXPECT_EQ(-20.0*(1.0-exp(-0.1/20.0))- n.GetMembranePotential_(),0);
    
    //Test after several updates
    //*1*
    n.update(10000,1000);
    //MembranePotential_ should tend towards 20 but never spike
    EXPECT_EQ(0,n.GetNbrSpikes_());
    EXPECT_GT(1E-3, std::fabs(-19.9999 - n.GetMembranePotential_()));
    //*2*
    //MembranePotential_ decay towards 0 without input current
    n.SetInputCurrent_(0.0);
    n.update(2000,1000);
    EXPECT_NEAR(0,n.GetMembranePotential_(), 1E-3);
}

//=====================SpikeTime========================
TEST(NeuronTEST, TimeSpikes_){
    Neuron n;
    n.SetInputCurrent_(1.01);
    
    //Waiting for first spike
    n.update(924,1000);
    EXPECT_EQ(0,n.GetNbrSpikes_());
    n.update(1,1000);
    EXPECT_EQ(1, n.GetNbrSpikes_());
    EXPECT_EQ(0.0, n.GetMembranePotential_());
    
    //Waiting for second spike
    n.update(944,1000);
    EXPECT_EQ(1, n.GetNbrSpikes_());
    n.update(1,1000+945);
    EXPECT_EQ(2, n.GetNbrSpikes_());
}

//=====================Post-Synaptic========================
TEST(NeuronTEST, NoPSSpike){
    Neuron n1;
    Neuron n2;
    
    n1.SetInputCurrent_(1.01);
    for(int i=0; i<925+13; ++i){
        if(n1.update(1,1000+i)){
            EXPECT_EQ(0.0, n1.GetMembranePotential_());
            n2.SetBuffer_(1);
        }
        n2.update(1,1000+i);
    }
    EXPECT_EQ(0.1,n2.GetMembranePotential_());
}

TEST(NeuronTEST, WithPSSpike){
    Neuron n1;
    Neuron n2;
    n1.SetInputCurrent_(1.01);
    n2.SetInputCurrent_(1.0);
    for(int i=0; i<1869+13; ++i){
        if(n1.update(1,1000+i)){
            EXPECT_EQ(0.0, n1.GetMembranePotential_());
            n2.SetBuffer_(1);
        }
        n2.update(1,1000+i);
    }
    
    //Before n2 spikes
    EXPECT_EQ(0,n2.GetNbrSpikes_());
    n2.update(1,1869+13+1000);
    //After n2 spikes
    EXPECT_EQ(0,n2.GetMembranePotential_());
    EXPECT_EQ(1,n2.GetNbrSpikes_());
}
*/


int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
