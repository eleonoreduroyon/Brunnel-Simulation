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
#include <cmath>
#include <vector>

//===============AmplitudeJIValues============
TEST(NeuronsTEST, AmplitudeJIValue){
    NetworkNeurons net(100,75,25,4);
    EXPECT_EQ((g*JE)-0.4,0.0);
}

//===============NU_THRESHValue============

TEST(NeuronsTEST, Nu_THRESHValues){
    EXPECT_EQ((MembranePotentialTHRESHOLD/(JE*TAU))-10.0,0.0);
}

//===============NEValue==================

TEST(NeuronsTEST, NEValue){
    EXPECT_EQ((NE*EPS)-1000.0,0.0);
}

int main(int argc, char **argv){
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}
