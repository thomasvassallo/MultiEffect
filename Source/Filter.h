/*
  ==============================================================================

    Filter.h
    Created: 23 Mar 2016 12:23:25pm
    Author:  Thomas Vassallo

  ==============================================================================
*/

#ifndef FILTER_H_INCLUDED
#define FILTER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"


class Filter
{
public:
    Filter();
    
    void calculateCoefficients(int const type,double const frequency,double const sample_rate,double const q,double const db_gain,bool q_is_bandwidth);
    void processSamples(AudioSampleBuffer &buffer);
    
    
private:
    
    // filter coeffs
    float b0a0,b1a0,b2a0,a1a0,a2a0;
    
    // in/out history
    float ou1,ou2,in1,in2;
    
    // temp coef vars
    double alpha,a0,a1,a2,b0,b1,b2;
    
    //Buffer Input
    double in0;
    //Buffer Output
    float  yn;
    
    
};



#endif  // FILTER_H_INCLUDED
