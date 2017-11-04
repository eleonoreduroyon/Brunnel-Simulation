# Brunnel-Simulation

This program is the implementation of a recurrent spiking neuron network simulation based on Nicolas Brunel's paper on the dynamics of Sparsely Connected Networks of Excitatory and Inhibitory Spiking Neurons(Model A).

My program is composed of 3 classes and a main: Neuron.cpp, NetworkNeuron.cpp and Experiment.cpp.
-Experiment is a class which contains the method to get the file with the values needed for the histogram following specific parameters: g, eta, the number of total neurons, the number of excitatory neurons and inhibitory neurons. 
-NetworkNeuron is a class where the entire network is created; mainly composed of vector with all the neurons as well as a vector of all the connections between each neuron. In this Connection vector, each line contains the indexes of the neurons it sends spikes to. There are as many lines as there are neurons.The important method in this class is the update which updates all the neurons at each time step t (on the global clock) until the end of the simulation(tStop).
-Neuron is the class simulating the evolution of a neuron's different parameters over time (local clock) taking into account background noise as well as the spikes of the neurons it is connected to.

To simulate different situations, one may change specific values such as the number of total neurons, the number of excitatory neurons, the number of inhibitory neurons, g(controls the amplitude of inhibitory neurons(the amplitude of excitatory neurons is set at 0.1 in the Constants file)) or eta(controls background noise) when calling the function Experiment::runFig.

In addition, I wrote 8 tests in order to test my program's accuracy:

Several Neurons
1)Checks that all neurons have the right amplitude value whether they are excitatory or inhibitory
2)Checks that the value of NU_THRESH is correct(because it is essential for the calculation of NU_EXT used for the Poisson distribution)
3)Checks that my vector of connections contains the right amount of excitatory and inhibitory connections per neuron

One Neuron:
4)Checks that my membrane potential values are correct without background noise after one and several updates having a positive input current
5)Checks that my membrane potential values are correct without background noise after one and several updates having a negative input current
6)Checks that a neuron spikes at the right time following specific parameters and updates its number of spikes accordingly(no background noise)

Two Neurons:
7)Checks that my buffer works currently and a connected neuron receives the spiking neuron's amplitude DelaiSTEPs later(no background noise)
8)Checks that a connected neuron can spike after receiving the spiking neuron's amplitude DelaiSTEPs later(no background noise)

