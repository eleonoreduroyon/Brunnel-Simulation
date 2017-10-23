//
//  main.cpp
//  
//
//  Created by Ely on 10/2/17.
//
//

#include "Neuron.hpp"
#include "Constants.hpp"

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <cassert>
#include <random>

using namespace std;

int main(int argc, char* argv[]){
	/*//Open file
    ofstream sortie("MembranePotential", ios::out|ios::app);
    if(sortie.fail()){
        cerr<< "Erreur: impossible d'ecrire dans le fichier"<< endl;
    }
    
    int const NbreNeuron(12500);
    vector<Neuron> N1(NbreNeuron);
    
    default_random_engine generator;
    uniform_int_distribution<int> distributionCE(0,NE-1);
    uniform_int_distribution<int> distributionCI(NE,N1.size()-1);
    
    
    assert(N1.size()!= 0);
    vector<vector<int> > Connections(N1.size(), vector <int> (N1.size()));
   
    //initialisation of the vector Connections
    for (size_t i(0); i< N1.size(); ++i){
        if(i<NE){
            N[i] = JE;
        }else{
            N[i] = JI;
        }
        unsigned int CompteurCE(1);
        unsigned int CompteurCI(1);
        while(CompteurCE<= CE){
            Connections[i][distributionCE(generator)] += 1;
            ++CompteurCE;
        }
        while(CompteurCI<= CI){
            Connections[i][distributionCI(generator)] += 1;
            ++CompteurCI;
        }
    }
   */
    double Iext(1.01);  //Amplitude of Current
    NetworkNeurons Network(ALLN,NE,NI,Iext);
    unsigned long a(1000);   //Start of Step Current
    unsigned long b(4000);   //End of Step Current
    unsigned long tStop(5000); //Total Simulation Time
    Network.update(a,b,tStop);
    
 
        return 0;
}



