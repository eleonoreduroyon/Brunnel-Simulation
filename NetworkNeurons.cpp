//
//  NetworkNeurons.cpp
//
//
//  Created by Ely on 10/23/17.
//
//

#include "NetworkNeurons.hpp"
#include "Constants.hpp"
#include <random>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
//#include <cstdlib>
//#include <cassert>

using namespace std;

NetworkNeurons::NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI){
    NbrNeurons_=NbrNeurons;
    NbrNE_ = NbrNE;
    NbrNI_ = NbrNI;
    
    //assert(NbrNeurons_ != 0);
    default_random_engine generator;
    uniform_int_distribution<int> distributionCE(0,NbrNE_-1);
    uniform_int_distribution<int> distributionCI(NbrNE_,NbrNeurons_-1);
    
    int compteur(0);
    while(compteur<NbrNeurons_){
        Neuron n;
        AllNeurons_.push_back(n);
        ++compteur;
    }
    
    for(int i=0; i<NbrNeurons_; i++)
    {
        vector<int> j(NbrNeurons_);
        std::fill(j.begin(),j.begin()+NbrNeurons_,0);
        NetworkConnections_.push_back(j);
    }
    
    //initialisation of the vector Connections
    for (size_t i(0); i< NbrNeurons_; ++i){
        AllNeurons_[i].SetInputCurrent_(0.0);
        if(i<NbrNE_){
            AllNeurons_[i].SetJ_(JE);
        }else{
            AllNeurons_[i].SetJ_(JI);
        }
        unsigned int CompteurCE(1);
        unsigned int CompteurCI(1);
        while(CompteurCE<= CE){
            NetworkConnections_[i][distributionCE(generator)] += 1;
            ++CompteurCE;
        }
        while(CompteurCI<= CI){
            NetworkConnections_[i][distributionCI(generator)] += 1;
            ++CompteurCI;
        }
    }
    
}

void NetworkNeurons::update(unsigned long a,unsigned long b,unsigned long tStop){
    //Open file
    ofstream sortie("MembranePotential", ios::out|ios::app);
    if(sortie.fail()){
        cerr<< "Erreur: impossible d'ecrire dans le fichier"<< endl;
    }
    
    bool HasSpikes(false);
    unsigned long clock(0);
    
    while(clock < tStop){
        for(size_t i(0); i< AllNeurons_.size(); ++i){
            if((clock<a) or (clock>b)){  //outside the interval
                AllNeurons_[i].SetInputCurrent_(0.0);
                AllNeurons_[i].SetMembranePotential_(0.0);
            }else{
                HasSpikes = AllNeurons_[i].update(1);
                if(HasSpikes){
                    //we add a-tStart because tSimulation  starts at a
                    cout<< "Spikes of "<< i+1 <<" at t = "<< (AllNeurons_[i].GetTimeSpikes_()+a)*H << " ms." <<endl;
                    //
                    for(size_t j(0); j < NetworkConnections_[i].size(); ++j){
                        if(NetworkConnections_[j][i] != 0){
                            AllNeurons_[j].recieve(clock+DelaiSTEP,NetworkConnections_[i][j]*AllNeurons_[i].GetJ_());
                        }
                    }
                    HasSpikes = false;
                }
            }
            //Write values of MembranePotential_ in file
            sortie << AllNeurons_[i].int2strg(AllNeurons_[i].GetMembranePotential_()) << endl;
        }
        ++clock;
    }
    //Close file
    sortie.close();
    
    
}    
}
