/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
//#include "PluginEditor.h"
#include "GUI.h"


//==============================================================================
TdelayAudioProcessor::TdelayAudioProcessor()
{
    setParameterNotifyingHost(delayParam, 0);
    setParameterNotifyingHost(feedbackParam, 0);
    setParameterNotifyingHost(modParam, 0);
    setParameterNotifyingHost(mixParam, 0);
    setParameterNotifyingHost(filterTypeParam, 0);
    setParameterNotifyingHost(filterCutoffParam, 20);
    setParameterNotifyingHost(filterQParam, 0.1);
    setParameterNotifyingHost(qIsBandParam, 0);
    setParameterNotifyingHost(filterGainParam, 0);
    setParameterNotifyingHost(filterONOFFParam, 0);
    setParameterNotifyingHost(widthParam, 0);
    setParameterNotifyingHost(widthONOFFParam, 0);
    setParameterNotifyingHost(crossValueParam, 0.5);
    setParameterNotifyingHost(crossValueONOFF, 0);
    
    // Set default values:
    frequency = 2.0;
    depth = 1.0;
    waveform = 1;
    
    lfoPhase = 0.0;
    inverseSampleRate = 1.0/44100.0;
    
}

TdelayAudioProcessor::~TdelayAudioProcessor()
{
}

//==============================================================================
const String TdelayAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

int TdelayAudioProcessor::getNumParameters()
{
    return totalNumParams;
}

float TdelayAudioProcessor::getParameter(int index)
{
    switch (index) {
        case delayParam: return parameters[0];
        case feedbackParam: return parameters[1];
        case modParam: return parameters[2];
        case mixParam: return parameters[3];
        case filterTypeParam: return parameters[4];
        case filterCutoffParam: return parameters[5];
        case filterQParam: return parameters[6];
        case qIsBandParam: return parameters[7];
        case filterGainParam: return parameters[8];
        case filterONOFFParam: return parameters[9];
        case widthParam: return parameters[10];
        case widthONOFFParam: return parameters[11];
        case crossValueParam: return parameters[12];
        case crossValueONOFF: return parameters[13];
        case kFrequencyParam:     return frequency;
        case kDepthParam:         return depth;
        case kWaveformParam:      return (float)waveform;

        default:
            return 0.0f;
    }
}

void TdelayAudioProcessor::setParameter(int index, float newValue)
{
    switch (index) {
        case delayParam:  parameters[0] = newValue; break;
        case feedbackParam:  parameters[1] = newValue; break;
        case modParam:  parameters[2] = newValue; break;
        case mixParam:  parameters[3] = newValue; break;
        case filterTypeParam:  parameters[4] = newValue; break;
        case filterCutoffParam:  parameters[5] = newValue; break;
        case filterQParam:  parameters[6] = newValue; break;
        case qIsBandParam:  parameters[7] = newValue; break;
        case filterGainParam:  parameters[8] = newValue; break;
        case filterONOFFParam:  parameters[9] = newValue; break;
        case widthParam:  parameters[10] = newValue; break;
        case widthONOFFParam:  parameters[11] = newValue; break;
        case crossValueParam:  parameters[12] = newValue; break;
        case crossValueONOFF:  parameters[13] = newValue; break;
        case kFrequencyParam:  frequency = newValue; break;
        case kDepthParam: depth = newValue; break;
        case kWaveformParam: waveform = (int)newValue; break;
            
        default:
            break;
    }

}

const String TdelayAudioProcessor::getParameterName(int index)
{
    switch (index) {
        case delayParam: return "Delay";
        case feedbackParam: return "Feedback";
        case modParam: return "Modulation";
        case mixParam: return "Mix";
        case filterTypeParam: return "Filter Type";
        case filterCutoffParam: return "Cuttoff";
        case filterQParam: return "Q";
        case qIsBandParam: return "Q is Bandwidth";
        case filterGainParam: return "Gain";
        case filterONOFFParam: return "Filter On/Off";
        case widthParam: return "Width";
        case widthONOFFParam: return "Width On/Off";
        case crossValueParam: return "Cross Value";
        case crossValueONOFF: return "Cross Value On/Off";
        case kFrequencyParam:     return "frequency";
        case kDepthParam:         return "depth";
        case kWaveformParam:      return "waveform";
            
        default:
            return String::empty;
    }

}

const String TdelayAudioProcessor::getParameterText (int index)
{
    return String::empty;
}


bool TdelayAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TdelayAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TdelayAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double TdelayAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TdelayAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TdelayAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TdelayAudioProcessor::setCurrentProgram (int index)
{
}

const String TdelayAudioProcessor::getProgramName (int index)
{
    return String();
}

void TdelayAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void TdelayAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
 
    
    filter1.calculateCoefficients(getParameter(filterTypeParam), getParameter(filterCutoffParam), sampleRate, getParameter(filterQParam), getParameter(filterGainParam), getParameter(qIsBandParam));
    
    leftBuffer.setBufferSize((int)4410);
    rightBuffer.setBufferSize((int)4410);
    leftDelayTime = (((delayParam*0.004)+0.005) * sampleRate);
    rightDelayTime = (((delayParam*0.003)+0.005) * sampleRate);
    leftOsc.setFrequency(0.5);
    leftOsc.setSampleRate(sampleRate);
    rightOsc.setFrequency(0.6);
    rightOsc.setSampleRate(sampleRate);
    
    lfoPhase = 0.0;
    inverseSampleRate = 1.0/sampleRate;

}

void TdelayAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

void TdelayAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    
    float ph;
    
    // Mid-Side Stereo Widening before final buffer output.
    if (getParameter(widthONOFFParam)){
        MidSide(buffer, getParameter(widthParam));
    }
    
    // Stereo pan.
    if (getParameter(crossValueONOFF)){
        Panner(buffer, getParameter(crossValueParam));
    }
    
    // Helpful information about this block of samples:

    int sampleRate=getSampleRate();
    
    
    if (getTotalNumInputChannels() == 1) buffer.copyFrom(1, 0, buffer, 0, 0, buffer.getNumSamples());
    
    //float* channelData = buffer.getSampleData (0);
    for (int i = 0; i < buffer.getNumSamples(); i++) {
        
        
        float leftMod = (leftOsc.nextSample()+1.01) * getParameter(modParam) * 100;
        float rightMod = (leftOsc.nextSample()+1.01) * getParameter(modParam) * 100;
        
        leftDelayTime = (getParameter(delayParam) * 200) + leftMod + .002;
        rightDelayTime = (getParameter(delayParam) * 220) + rightMod + .0015;
        
        float l_xn = buffer.getReadPointer(0)[i];
        float r_xn = buffer.getReadPointer(1)[i];
        
        float l_combined;
        float r_combined;
        float l_yn;
        float r_yn;
        
        
        l_yn = leftBuffer.getSample(leftDelayTime);
        r_yn = rightBuffer.getSample(rightDelayTime);
        
        l_combined = l_xn + r_yn * getParameter(feedbackParam);
        r_combined = r_xn + l_yn * getParameter(feedbackParam);
        
        
        leftBuffer.addSample(l_combined);
        rightBuffer.addSample(r_combined);
        
        buffer.getWritePointer(0)[i] = (l_xn * (1-getParameter(mixParam)) + l_yn * getParameter(mixParam));
        buffer.getWritePointer(1)[i] = (r_xn * (1-getParameter(mixParam)) + r_yn * getParameter(mixParam));
        
    }
    
    
    
    if (getParameter(filterONOFFParam)){
        ph = lfoPhase;

    filter1.calculateCoefficients(getParameter(filterTypeParam), getParameter(filterCutoffParam)*(depth*lfo(ph, kWaveformParam)), sampleRate, getParameter(filterQParam), getParameter(filterGainParam), getParameter(qIsBandParam));
    filter1.processSamples(buffer);
        
        ph += frequency*inverseSampleRate;
        if(ph >= 1.0)
            ph -= 1.0;
    }
     lfoPhase = ph;
}


//==============================================================================

void TdelayAudioProcessor::MidSide (AudioSampleBuffer &buffer, double width)
{
    //    'width' is the stretch factor of the stereo field:
    //    width < 1: decrease in stereo width
    //    width = 1: no change
    //    width > 1: increase in stereo width
    //    width = 0: mono
    
    // calculate scale coefficient
    double coef_S = width*0.5;
    
    int numSamples=buffer.getNumSamples();
    
    for (int i = 0 ; i < numSamples ; i++)
    {
        lChannelData=buffer.getSample(0, i);
        rChannelData=buffer.getSample(1, i);
    
        midChannelData=(lChannelData+rChannelData)*0.5;
        sideChannelData=(rChannelData-lChannelData)*coef_S;
        
        
        lOutChannelData  = midChannelData - sideChannelData;           //Assign Left out to left channel of main buffer
        rOutChannelData = midChannelData + sideChannelData;            //Assign Right out to right channel of main buffer
        
        buffer.setSample(0, i, lOutChannelData);
        buffer.setSample(1, i, rOutChannelData);
    }
}

//==============================================================================

void TdelayAudioProcessor::Panner (AudioSampleBuffer &buffer, double crossValue)
{
    int numSamples=buffer.getNumSamples();
    
    for (int i = 0 ; i < numSamples ; i++)
    {
    lChannelPan=buffer.getSample(0, i);
    rChannelPan=buffer.getSample(1, i);
    
    lChannelData = lChannelPan*(sin((1 - crossValue)*(M_PI/2)));
    rChannelData = rChannelPan*(sin(crossValue*(M_PI/2)));
    
    buffer.setSample(0, i, lChannelData);
    buffer.setSample(1, i, rChannelData);
}
}

//==============================================================================
// Function for calculating LFO waveforms. Phase runs from 0-1, output is scaled
// from 0 to 1 (note: not -1 to 1 as would be typical of sine).
float TdelayAudioProcessor::lfo(float phase, int waveform)
{
    switch(waveform)
    {
        case 1:
            if(phase < 0.25f)
                return 0.5f + 2.0f*phase;
            else if(phase < 0.75f)
                return 1.0f - 2.0f*(phase - 0.25f);
            else
                return 2.0f*(phase-0.75f);
        case 2:
            if(phase < 0.5f)
                return 1.0f;
            else
                return 0.0f;
        case 3:
            if(phase < 0.48f)
                return 1.0f;
            else if(phase < 0.5f)
                return 1.0f - 50.0f*(phase - 0.48f);
            else if(phase < 0.98f)
                return 0.0f;
            else
                return 50.0f*(phase - 0.98f);
        case 4:
        default:
            return 0.5f + 0.5f*sinf(2.0 * M_PI * phase);
    }
}


//==============================================================================
bool TdelayAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* TdelayAudioProcessor::createEditor()
{
    //return new TdelayAudioProcessorEditor (*this);
    return new GUI(*this);
}

//==============================================================================
void TdelayAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void TdelayAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TdelayAudioProcessor();
    
}
