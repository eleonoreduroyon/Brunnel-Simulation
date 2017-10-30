#ifndef _CONSTANTS
#define _CONSTANTS

double const MembranePotentialTHRESHOLD(20.0); //Spike threshold
double const TAU(20.0);
double const C(1.0);
//double RESISTANCE(20.0); //TAU/C;0 a 400; Membrane Resistance
double const RefractoryTIME(2.0); //How long the break is
double const H(.1);
unsigned long const REFRACTORYSTEP = RefractoryTIME*10; //
unsigned long const DelaiSTEP(15);
double const VRESET(0.0);
//Amplitude
double const JE(.1);
double const JI(-.5);
//Number of Neurons
unsigned long const ALLN(12500);
unsigned long const NE(10000);
unsigned long const NI(2500);
//Frequence
double const NU_THR(0.01);
double const ETA(2);

//Connections
double const EPS(0.1); //10%
unsigned long const CE(NE*EPS); //1000
unsigned long const CI(NI*EPS); //250
unsigned long const Cext(CE);
double const g(JI/JE);
double const NU_EXT(ETA*NU_THR*CE); //=20

#endif
