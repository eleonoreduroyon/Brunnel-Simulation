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
#include <cassert>

using namespace std;

//=================Constructeur=================


NetworkNeurons::NetworkNeurons(unsigned long NbrNeurons,unsigned long NbrNE, unsigned long NbrNI, double g,double eta):NbrNeurons_(NbrNeurons),NbrNE_(NbrNE),NbrNI_(NbrNI),CE_(NbrNE_*EPS),CI_(NbrNI_*EPS),ETA_(eta){

    assert(NbrNeurons_ != 0);
    default_random_engine generator;
    uniform_int_distribution<unsigned int> distributionCE(0,NbrNE_-1);
    uniform_int_distribution<unsigned int> distributionCI(NbrNE_,NbrNeurons_-1);
    
    //initialisation of vector AllNeurons
    unsigned int compteur(0);
    while(compteur<NbrNeurons_){
        Neuron n;
        AllNeurons_.push_back(n);
        ++compteur;
    }
    
    //initialisation of the vector Connections   
    //a vector where each line contains the index of Neurons it sends spikes to
   unsigned int compteur1(0);
   while(compteur1<NbrNeurons_){
		vector<int> j;
		NetworkConnections_.push_back(j);
		++compteur1;
	}
    
    for (unsigned int i(0); i< NbrNeurons_; ++i){
		assert( i<AllNeurons_.size());
        AllNeurons_[i].SetInputCurrent_(0.0);
        if(i<NbrNE_){
            AllNeurons_[i].SetJ_(JE);
        }else{
            AllNeurons_[i].SetJ_(JE*-g);
        }
        unsigned int CompteurCE(1);
        unsigned int CompteurCI(1);
        while(CompteurCE<= CE){
			assert(distributionCE(generator) < NetworkConnections_.size());
            NetworkConnections_[distributionCE(generator)].push_back(i);
            ++CompteurCE;
        }
        while(CompteurCI<= CI){
			assert(distributionCI(generator) < NetworkConnections_.size());
            NetworkConnections_[distributionCI(generator)].push_back(i);
            ++CompteurCI;
        }
    }
    
}

//===================Destructeur==================

NetworkNeurons::~NetworkNeurons(){}

//===================Methodes==================


void NetworkNeurons::update(unsigned long tStop, string title){
    //Open file
    ofstream sortie( title, ios::out|ios::app);
    if(sortie.fail()){
        cerr<< "Erreur: impossible d'ecrire dans le fichier"<< endl;
    }
    
    bool HasSpikes(false);
    unsigned long clock(0);
    
    while(clock < tStop){
        for(size_t i(0); i< AllNeurons_.size(); ++i){
			assert(i<AllNeurons_.size());
            HasSpikes = AllNeurons_[i].update(1,ETA_);
            if(HasSpikes){
                //Write values of MembranePotential_ in file
				sortie << (AllNeurons_[i].GetTimeSpikes_())*H<<"   "<< i+1 << endl; //neurons from 1 to 12500
                for(size_t j(0); j < NetworkConnections_[i].size(); ++j){
                    AllNeurons_[NetworkConnections_[i][j]].recieve(clock+DelaiSTEP,AllNeurons_[i].GetJ_());
                }
            }
            HasSpikes = false;
        }
        ++clock;
    }
    //Close file
    sortie.close();
}

//=====================Getters=============
std::vector<Neuron> NetworkNeurons::GetAllNeurons_() const {
	return AllNeurons_;
}

unsigned long NetworkNeurons::GetNbrNE_() const {
    return NbrNE_;
}

std::vector<Neuron> NetworkNeurons::GetNetworkConnections_() const {
    return NetworkConnections_;
}

unsigned long NetworkNeurons::GetNbrNeurons_() const {
    return NbrNeurons_;
}

unsigned long NetworkNeurons::GetCE_() const {
    return CE_;
}

unsigned long NetworkNeurons::GetCI_() const{
    return CI_;
}

unsigned long NetworkNeurons::GetNbrNI_() const {
    return NbrNI_;
}
