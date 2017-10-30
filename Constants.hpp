#ifndef _CONSTANTS
#define _CONSTANTS

double const MembranePotentialTHRESHOLD(20.0); //Spike threshold
double const TAU(20.0);
double const C(1.0);
//double RESISTANCE(20.0); //TAU/C;0 a 400; Membrane Resistance
double const RefractoryTIME(2.0); //How long the break is
double const H(.1);
unsigned long const REFRACTORYSTEP = RefractoryTIME*10; //
double const g(2.0);
unsigned long const DelaiSTEP(15);
double const VRESET(0.0);
//Amplitude
double const JE(.1);
double const JI(-.5);
//Number of Neurons
unsigned long const ALLN(500);
unsigned long const NE(300);
unsigned long const NI(200);
//Frequence
double const NU_THR(0.01);
double const ETA(2);
double const NU_EXT(ETA*NU_THR*CE);
//Connections
unisgned double EPS(.01); //10%
unsigned long const CE(NE*EPS);
unsigned long const CI(NI*EPS);
unsigned long const Cext(CE);
double const g(JI/JE);


#endif
