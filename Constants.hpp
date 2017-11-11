#ifndef _CONSTANTS
#define _CONSTANTS

double const MembranePotentialTHRESHOLD(20.0); //!<Spike threshold
double const TAU(20.0); //!<Membrane time constant
double const RESISTANCE(20.0); //!<Membrane Resistance
double const RefractoryTIME(2.0); //!<RefractoryTime in ms
double const H(.1); //!<Step size
unsigned long const REFRACTORYSTEP(RefractoryTIME/H); //!<RefractoryTime in steps
unsigned long const DelaiSTEP(15); //!<Synaptic delay in steps
unsigned long const DelaiTIME(DelaiSTEP*0.1); //!<Synaptic delay in steps
double const VRESET(0.0); //!<Reset MembranePotential_ after spike
//Amplitude
double const JE(.1); //!<Amplitude of excitatory neurons
//Number of Neurons
unsigned long const ALLN(12500); //!<Number of neurons
unsigned long const NE(10000); //!<Number of excitatory neurons
unsigned long const NI(2500); //!<Number of inhibitory neurons
//Frequence
double const NU_THR(MembranePotentialTHRESHOLD/(JE*TAU)); //!<Frequency needed for a neuron to reach threshold
//Connections
double const EPS(0.1); //!<10%

#endif
