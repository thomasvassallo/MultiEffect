/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 4.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "GUI.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
GUI::GUI (TdelayAudioProcessor& p)
    : TdelayAudioProcessorEditor(p)
{
    //[Constructor_pre] You can add your own custom stuff here..
    ourprocessor = &p;

    //[/Constructor_pre]

    addAndMakeVisible (groupComponent5 = new GroupComponent ("Filter",
                                                             TRANS("Stereo")));
    groupComponent5->setTextLabelPosition (Justification::centred);
    groupComponent5->setColour (GroupComponent::outlineColourId, Colours::white);
    groupComponent5->setColour (GroupComponent::textColourId, Colour (0x00ffffff));

    addAndMakeVisible (groupComponent4 = new GroupComponent ("Filter",
                                                             TRANS("Stereo Wid")));
    groupComponent4->setTextLabelPosition (Justification::centred);
    groupComponent4->setColour (GroupComponent::outlineColourId, Colours::white);
    groupComponent4->setColour (GroupComponent::textColourId, Colour (0x00ffffff));

    addAndMakeVisible (groupComponent = new GroupComponent ("Chorus",
                                                            TRANS("Chorus")));
    groupComponent->setTextLabelPosition (Justification::centred);
    groupComponent->setColour (GroupComponent::outlineColourId, Colours::white);
    groupComponent->setColour (GroupComponent::textColourId, Colour (0x00ffffff));

    addAndMakeVisible (groupComponent3 = new GroupComponent ("Filter",
                                                             TRANS("Stereo Widenerere")));
    groupComponent3->setTextLabelPosition (Justification::centred);
    groupComponent3->setColour (GroupComponent::outlineColourId, Colours::white);
    groupComponent3->setColour (GroupComponent::textColourId, Colour (0x00ffffff));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("Filter",
                                                             TRANS("Filterrrr")));
    groupComponent2->setTextLabelPosition (Justification::centred);
    groupComponent2->setColour (GroupComponent::outlineColourId, Colours::white);
    groupComponent2->setColour (GroupComponent::textColourId, Colour (0x00ffffff));

    addAndMakeVisible (fCutoff = new Slider ("fCutoff"));
    fCutoff->setRange (20, 20000, 1);
    fCutoff->setSliderStyle (Slider::Rotary);
    fCutoff->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    fCutoff->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    fCutoff->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    fCutoff->addListener (this);

    addAndMakeVisible (qFactor = new Slider ("qFactor"));
    qFactor->setRange (0.1, 1, 0);
    qFactor->setSliderStyle (Slider::Rotary);
    qFactor->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    qFactor->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    qFactor->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    qFactor->setColour (Slider::textBoxTextColourId, Colours::black);
    qFactor->addListener (this);

    addAndMakeVisible (fGain = new Slider ("fGain"));
    fGain->setRange (0, 9, 0.1);
    fGain->setSliderStyle (Slider::Rotary);
    fGain->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    fGain->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    fGain->setColour (Slider::thumbColourId, Colours::white);
    fGain->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    fGain->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    fGain->setColour (Slider::textBoxTextColourId, Colours::black);
    fGain->addListener (this);

    addAndMakeVisible (filterType = new Slider ("fGain"));
    filterType->setRange (0, 8, 1);
    filterType->setSliderStyle (Slider::Rotary);
    filterType->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    filterType->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    filterType->setColour (Slider::thumbColourId, Colours::white);
    filterType->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    filterType->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    filterType->setColour (Slider::textBoxTextColourId, Colours::black);
    filterType->addListener (this);

    addAndMakeVisible (filterONOFF = new Slider ("new slider"));
    filterONOFF->setRange (0, 1, 1);
    filterONOFF->setSliderStyle (Slider::LinearVertical);
    filterONOFF->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    filterONOFF->setColour (Slider::thumbColourId, Colours::white);
    filterONOFF->setColour (Slider::trackColourId, Colours::white);
    filterONOFF->addListener (this);

    addAndMakeVisible (qIsBand = new Slider ("new slider"));
    qIsBand->setRange (0, 1, 1);
    qIsBand->setSliderStyle (Slider::LinearVertical);
    qIsBand->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    qIsBand->setColour (Slider::thumbColourId, Colours::white);
    qIsBand->setColour (Slider::trackColourId, Colours::white);
    qIsBand->addListener (this);

    addAndMakeVisible (stereoWidth = new Slider ("stereo width"));
    stereoWidth->setRange (0, 3, 0.1);
    stereoWidth->setSliderStyle (Slider::Rotary);
    stereoWidth->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    stereoWidth->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    stereoWidth->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    stereoWidth->setColour (Slider::textBoxTextColourId, Colours::black);
    stereoWidth->addListener (this);

    addAndMakeVisible (stereoONOFF = new Slider ("new slider"));
    stereoONOFF->setRange (0, 1, 1);
    stereoONOFF->setSliderStyle (Slider::LinearVertical);
    stereoONOFF->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    stereoONOFF->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    stereoONOFF->setColour (Slider::thumbColourId, Colours::white);
    stereoONOFF->setColour (Slider::trackColourId, Colours::white);
    stereoONOFF->addListener (this);

    addAndMakeVisible (cFeedback = new Slider ("cFeedback"));
    cFeedback->setRange (0, 0.9, 0.01);
    cFeedback->setSliderStyle (Slider::Rotary);
    cFeedback->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    cFeedback->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    cFeedback->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    cFeedback->addListener (this);

    addAndMakeVisible (cMod = new Slider ("cMod"));
    cMod->setRange (0, 1, 0.1);
    cMod->setSliderStyle (Slider::Rotary);
    cMod->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    cMod->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    cMod->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    cMod->addListener (this);

    addAndMakeVisible (cMix = new Slider ("cMix"));
    cMix->setRange (0, 1, 0.1);
    cMix->setSliderStyle (Slider::Rotary);
    cMix->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    cMix->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    cMix->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    cMix->addListener (this);

    addAndMakeVisible (cDelay = new Slider ("cDelay"));
    cDelay->setRange (0, 1, 0.1);
    cDelay->setSliderStyle (Slider::Rotary);
    cDelay->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    cDelay->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    cDelay->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    cDelay->addListener (this);

    addAndMakeVisible (crossValue = new Slider ("crossValue"));
    crossValue->setRange (0, 1, 0.01);
    crossValue->setSliderStyle (Slider::Rotary);
    crossValue->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    crossValue->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    crossValue->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    crossValue->addListener (this);

    addAndMakeVisible (crossValueONOFF = new Slider ("crossValueONOFF"));
    crossValueONOFF->setRange (0, 1, 1);
    crossValueONOFF->setSliderStyle (Slider::LinearVertical);
    crossValueONOFF->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    crossValueONOFF->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    crossValueONOFF->setColour (Slider::thumbColourId, Colours::white);
    crossValueONOFF->setColour (Slider::trackColourId, Colours::white);
    crossValueONOFF->addListener (this);

    addAndMakeVisible (lfoWidth = new Slider ("lfoWidth"));
    lfoWidth->setRange (0, 1, 0.01);
    lfoWidth->setSliderStyle (Slider::Rotary);
    lfoWidth->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    lfoWidth->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    lfoWidth->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    lfoWidth->addListener (this);

    addAndMakeVisible (lfoFreq = new Slider ("lfoFreq"));
    lfoFreq->setRange (1, 1000, 0.01);
    lfoFreq->setSliderStyle (Slider::Rotary);
    lfoFreq->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    lfoFreq->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    lfoFreq->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    lfoFreq->addListener (this);

    addAndMakeVisible (lfoWaveform = new Slider ("lfoWaveform"));
    lfoWaveform->setRange (0, 4, 1);
    lfoWaveform->setSliderStyle (Slider::Rotary);
    lfoWaveform->setTextBoxStyle (Slider::TextBoxAbove, false, 80, 20);
    lfoWaveform->setColour (Slider::backgroundColourId, Colour (0x00ffffff));
    lfoWaveform->setColour (Slider::thumbColourId, Colours::white);
    lfoWaveform->setColour (Slider::rotarySliderFillColourId, Colour (0x7fffffff));
    lfoWaveform->setColour (Slider::rotarySliderOutlineColourId, Colour (0x66ffffff));
    lfoWaveform->setColour (Slider::textBoxTextColourId, Colours::black);
    lfoWaveform->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (430, 336);


    //[Constructor] You can add your own custom stuff here..
    crossValue->setValue(ourprocessor->getParameter(TdelayAudioProcessor::crossValueParam));
    //[/Constructor]
}

GUI::~GUI()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    groupComponent5 = nullptr;
    groupComponent4 = nullptr;
    groupComponent = nullptr;
    groupComponent3 = nullptr;
    groupComponent2 = nullptr;
    fCutoff = nullptr;
    qFactor = nullptr;
    fGain = nullptr;
    filterType = nullptr;
    filterONOFF = nullptr;
    qIsBand = nullptr;
    stereoWidth = nullptr;
    stereoONOFF = nullptr;
    cFeedback = nullptr;
    cMod = nullptr;
    cMix = nullptr;
    cDelay = nullptr;
    crossValue = nullptr;
    crossValueONOFF = nullptr;
    lfoWidth = nullptr;
    lfoFreq = nullptr;
    lfoWaveform = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void GUI::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    g.setColour (Colours::black);
    g.fillRect (-22, -17, 497, 353);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Frequency"),
                14, 125, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("Yuppy TC", 15.00f, Font::plain));
    g.drawText (TRANS("Width"),
                351, 15, 50, 28,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Q"),
                95, 125, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Gain"),
                174, 125, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Filter Type"),
                255, 125, 73, 27,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Q is Band"),
                343, 125, 73, 27,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Delay"),
                14, 13, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Feedback"),
                95, 13, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Modulation"),
                174, 13, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("Mix"),
                255, 13, 65, 27,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("Chorus"),
                135, -5, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("Filter"),
                183, 107, 65, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("Widener"),
                319, -5, 121, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("Yuppy TC", 15.00f, Font::plain));
    g.drawText (TRANS("Pan"),
                23, 240, 50, 28,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("Panner"),
                -6, 215, 113, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("Yuppy TC", 15.00f, Font::plain));
    g.drawText (TRANS("Width"),
                135, 239, 50, 28,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("Yuppy TC", 15.00f, Font::plain));
    g.drawText (TRANS("Freq"),
                215, 239, 50, 28,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 12.00f, Font::plain));
    g.drawText (TRANS("LFO Shape"),
                287, 239, 73, 27,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("LFO"),
                183, 215, 113, 29,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("DAFx"),
                362, 255, 70, 33,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("2016"),
                362, 279, 70, 33,
                Justification::centred, true);

    g.setColour (Colours::white);
    g.setFont (Font ("PT Mono", 15.00f, Font::plain));
    g.drawText (TRANS("TV"),
                362, 231, 70, 33,
                Justification::centred, true);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void GUI::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    groupComponent5->setBounds (112, 224, 256, 104);
    groupComponent4->setBounds (8, 224, 88, 104);
    groupComponent->setBounds (8, 0, 320, 104);
    groupComponent3->setBounds (336, 0, 88, 104);
    groupComponent2->setBounds (8, 112, 416, 104);
    fCutoff->setBounds (24, 150, 50, 50);
    qFactor->setBounds (104, 150, 50, 50);
    fGain->setBounds (184, 150, 50, 50);
    filterType->setBounds (264, 150, 50, 50);
    filterONOFF->setBounds (392, 176, 40, 32);
    qIsBand->setBounds (352, 152, 48, 40);
    stereoWidth->setBounds (352, 40, 50, 50);
    stereoONOFF->setBounds (392, 64, 40, 32);
    cFeedback->setBounds (104, 40, 50, 50);
    cMod->setBounds (184, 40, 50, 50);
    cMix->setBounds (264, 40, 50, 50);
    cDelay->setBounds (24, 40, 50, 50);
    crossValue->setBounds (24, 264, 50, 50);
    crossValueONOFF->setBounds (64, 288, 40, 32);
    lfoWidth->setBounds (136, 264, 50, 50);
    lfoFreq->setBounds (216, 264, 50, 50);
    lfoWaveform->setBounds (296, 264, 50, 50);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void GUI::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == fCutoff)
    {
        //[UserSliderCode_fCutoff] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::filterCutoffParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_fCutoff]
    }
    else if (sliderThatWasMoved == qFactor)
    {
        //[UserSliderCode_qFactor] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::filterQParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_qFactor]
    }
    else if (sliderThatWasMoved == fGain)
    {
        //[UserSliderCode_fGain] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::filterGainParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_fGain]
    }
    else if (sliderThatWasMoved == filterType)
    {
        //[UserSliderCode_filterType] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::filterTypeParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterType]
    }
    else if (sliderThatWasMoved == filterONOFF)
    {
        //[UserSliderCode_filterONOFF] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::filterONOFFParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_filterONOFF]
    }
    else if (sliderThatWasMoved == qIsBand)
    {
        //[UserSliderCode_qIsBand] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::qIsBandParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_qIsBand]
    }
    else if (sliderThatWasMoved == stereoWidth)
    {
        //[UserSliderCode_stereoWidth] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::widthParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_stereoWidth]
    }
    else if (sliderThatWasMoved == stereoONOFF)
    {
        //[UserSliderCode_stereoONOFF] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::widthONOFFParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_stereoONOFF]
    }
    else if (sliderThatWasMoved == cFeedback)
    {
        //[UserSliderCode_cFeedback] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::feedbackParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_cFeedback]
    }
    else if (sliderThatWasMoved == cMod)
    {
        //[UserSliderCode_cMod] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::modParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_cMod]
    }
    else if (sliderThatWasMoved == cMix)
    {
        //[UserSliderCode_cMix] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::mixParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_cMix]
    }
    else if (sliderThatWasMoved == cDelay)
    {
        //[UserSliderCode_cDelay] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::delayParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_cDelay]
    }
    else if (sliderThatWasMoved == crossValue)
    {
        //[UserSliderCode_crossValue] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::crossValueParam, sliderThatWasMoved->getValue());
        //[/UserSliderCode_crossValue]
    }
    else if (sliderThatWasMoved == crossValueONOFF)
    {
        //[UserSliderCode_crossValueONOFF] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::crossValueONOFF, sliderThatWasMoved->getValue());
        //[/UserSliderCode_crossValueONOFF]
    }
    else if (sliderThatWasMoved == lfoWidth)
    {
        //[UserSliderCode_lfoWidth] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::kDepthParam, lfoWidth->getValue());
        //[/UserSliderCode_lfoWidth]
    }
    else if (sliderThatWasMoved == lfoFreq)
    {
        //[UserSliderCode_lfoFreq] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::kFrequencyParam, lfoFreq->getValue());
        //[/UserSliderCode_lfoFreq]
    }
    else if (sliderThatWasMoved == lfoWaveform)
    {
        //[UserSliderCode_lfoWaveform] -- add your slider handling code here..
        getProcessor()->setParameterNotifyingHost(TdelayAudioProcessor::kWaveformParam, lfoWaveform->getValue());
        //[/UserSliderCode_lfoWaveform]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void GUI::timerCallback()
{
    fCutoff->setValue(getProcessor()->getParameter(TdelayAudioProcessor::filterCutoffParam),dontSendNotification);
    qFactor->setValue(getProcessor()->getParameter(TdelayAudioProcessor::filterQParam),dontSendNotification);
    fGain->setValue(getProcessor()->getParameter(TdelayAudioProcessor::filterGainParam),dontSendNotification);
    filterType->setValue(getProcessor()->getParameter(TdelayAudioProcessor::filterTypeParam),dontSendNotification);
    filterONOFF->setValue(getProcessor()->getParameter(TdelayAudioProcessor::filterONOFFParam),dontSendNotification);
    qIsBand->setValue(getProcessor()->getParameter(TdelayAudioProcessor::qIsBandParam),dontSendNotification);
    stereoWidth->setValue(getProcessor()->getParameter(TdelayAudioProcessor::widthParam),dontSendNotification);
    stereoONOFF->setValue(getProcessor()->getParameter(TdelayAudioProcessor::widthONOFFParam),dontSendNotification);
    cDelay->setValue(getProcessor()->getParameter(TdelayAudioProcessor::delayParam),dontSendNotification);
    cFeedback->setValue(getProcessor()->getParameter(TdelayAudioProcessor::feedbackParam),dontSendNotification);
    cMod->setValue(getProcessor()->getParameter(TdelayAudioProcessor::modParam),dontSendNotification);
    cMix->setValue(getProcessor()->getParameter(TdelayAudioProcessor::mixParam),dontSendNotification);

}

//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="GUI" componentName="" parentClasses="public TdelayAudioProcessorEditor"
                 constructorParams="TdelayAudioProcessor&amp; p" variableInitialisers="TdelayAudioProcessorEditor(p)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="1" initialWidth="430" initialHeight="336">
  <BACKGROUND backgroundColour="ffffffff">
    <RECT pos="-22 -17 497 353" fill="solid: ff000000" hasStroke="0"/>
    <TEXT pos="14 125 65 29" fill="solid: ffffffff" hasStroke="0" text="Frequency"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="351 15 50 28" fill="solid: ffffffff" hasStroke="0" text="Width"
          fontname="Yuppy TC" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="95 125 65 29" fill="solid: ffffffff" hasStroke="0" text="Q"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="174 125 65 29" fill="solid: ffffffff" hasStroke="0" text="Gain"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="255 125 73 27" fill="solid: ffffffff" hasStroke="0" text="Filter Type"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="343 125 73 27" fill="solid: ffffffff" hasStroke="0" text="Q is Band"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="14 13 65 29" fill="solid: ffffffff" hasStroke="0" text="Delay"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="95 13 65 29" fill="solid: ffffffff" hasStroke="0" text="Feedback"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="174 13 65 29" fill="solid: ffffffff" hasStroke="0" text="Modulation"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="255 13 65 27" fill="solid: ffffffff" hasStroke="0" text="Mix"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="135 -5 65 29" fill="solid: ffffffff" hasStroke="0" text="Chorus"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="183 107 65 29" fill="solid: ffffffff" hasStroke="0" text="Filter"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="319 -5 121 29" fill="solid: ffffffff" hasStroke="0" text="Widener"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="23 240 50 28" fill="solid: ffffffff" hasStroke="0" text="Pan"
          fontname="Yuppy TC" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="-6 215 113 29" fill="solid: ffffffff" hasStroke="0" text="Panner"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="135 239 50 28" fill="solid: ffffffff" hasStroke="0" text="Width"
          fontname="Yuppy TC" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="215 239 50 28" fill="solid: ffffffff" hasStroke="0" text="Freq"
          fontname="Yuppy TC" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="287 239 73 27" fill="solid: ffffffff" hasStroke="0" text="LFO Shape"
          fontname="PT Mono" fontsize="12" bold="0" italic="0" justification="36"/>
    <TEXT pos="183 215 113 29" fill="solid: ffffffff" hasStroke="0" text="LFO"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="362 255 70 33" fill="solid: ffffffff" hasStroke="0" text="DAFx"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="362 279 70 33" fill="solid: ffffffff" hasStroke="0" text="2016"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
    <TEXT pos="362 231 70 33" fill="solid: ffffffff" hasStroke="0" text="TV"
          fontname="PT Mono" fontsize="15" bold="0" italic="0" justification="36"/>
  </BACKGROUND>
  <GROUPCOMPONENT name="Filter" id="a7bc89bcc8f8526a" memberName="groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="112 224 256 104" outlinecol="ffffffff"
                  textcol="ffffff" title="Stereo" textpos="36"/>
  <GROUPCOMPONENT name="Filter" id="75c274134da740d5" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="8 224 88 104" outlinecol="ffffffff"
                  textcol="ffffff" title="Stereo Wid" textpos="36"/>
  <GROUPCOMPONENT name="Chorus" id="1a811eb8a88a2e3b" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 0 320 104" outlinecol="ffffffff"
                  textcol="ffffff" title="Chorus" textpos="36"/>
  <GROUPCOMPONENT name="Filter" id="4312a931fef663f6" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="336 0 88 104" outlinecol="ffffffff"
                  textcol="ffffff" title="Stereo Widenerere" textpos="36"/>
  <GROUPCOMPONENT name="Filter" id="66a24d4e8e95cfc0" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 112 416 104" outlinecol="ffffffff"
                  textcol="ffffff" title="Filterrrr" textpos="36"/>
  <SLIDER name="fCutoff" id="88f58dce0419c7b8" memberName="fCutoff" virtualName=""
          explicitFocusOrder="0" pos="24 150 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="20" max="20000" int="1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="qFactor" id="4457d1faa7181a4e" memberName="qFactor" virtualName=""
          explicitFocusOrder="0" pos="104 150 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" textboxtext="ff000000" min="0.10000000000000000555"
          max="1" int="0" style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fGain" id="24118af2da20b6fc" memberName="fGain" virtualName=""
          explicitFocusOrder="0" pos="184 150 50 50" bkgcol="ffffff" thumbcol="ffffffff"
          rotarysliderfill="7fffffff" rotaryslideroutline="66ffffff" textboxtext="ff000000"
          min="0" max="9" int="0.10000000000000000555" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="fGain" id="4764d39ff46f49a" memberName="filterType" virtualName=""
          explicitFocusOrder="0" pos="264 150 50 50" bkgcol="ffffff" thumbcol="ffffffff"
          rotarysliderfill="7fffffff" rotaryslideroutline="66ffffff" textboxtext="ff000000"
          min="0" max="8" int="1" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="d792f09915665ed4" memberName="filterONOFF"
          virtualName="" explicitFocusOrder="0" pos="392 176 40 32" thumbcol="ffffffff"
          trackcol="ffffffff" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="c486542b99328880" memberName="qIsBand"
          virtualName="" explicitFocusOrder="0" pos="352 152 48 40" thumbcol="ffffffff"
          trackcol="ffffffff" min="0" max="1" int="1" style="LinearVertical"
          textBoxPos="NoTextBox" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="stereo width" id="339875e5225ea920" memberName="stereoWidth"
          virtualName="" explicitFocusOrder="0" pos="352 40 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" textboxtext="ff000000" min="0"
          max="3" int="0.10000000000000000555" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="new slider" id="a22a9414e1a2f749" memberName="stereoONOFF"
          virtualName="" explicitFocusOrder="0" pos="392 64 40 32" bkgcol="ffffff"
          thumbcol="ffffffff" trackcol="ffffffff" min="0" max="1" int="1"
          style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cFeedback" id="bc4f698c65468ce7" memberName="cFeedback"
          virtualName="" explicitFocusOrder="0" pos="104 40 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="0.9000000000000000222"
          int="0.010000000000000000208" style="Rotary" textBoxPos="TextBoxAbove"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cMod" id="82a2d6a365f3c7cd" memberName="cMod" virtualName=""
          explicitFocusOrder="0" pos="184 40 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="1" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cMix" id="bcde9f1e950cb0cc" memberName="cMix" virtualName=""
          explicitFocusOrder="0" pos="264 40 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="1" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="cDelay" id="7083f9c5d0e13df8" memberName="cDelay" virtualName=""
          explicitFocusOrder="0" pos="24 40 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="1" int="0.10000000000000000555"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="crossValue" id="1ba2dd0d42018235" memberName="crossValue"
          virtualName="" explicitFocusOrder="0" pos="24 264 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="1" int="0.010000000000000000208"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="crossValueONOFF" id="6c84abc1720b9b9f" memberName="crossValueONOFF"
          virtualName="" explicitFocusOrder="0" pos="64 288 40 32" bkgcol="ffffff"
          thumbcol="ffffffff" trackcol="ffffffff" min="0" max="1" int="1"
          style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoWidth" id="8aeae67acea51b82" memberName="lfoWidth" virtualName=""
          explicitFocusOrder="0" pos="136 264 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="0" max="1" int="0.010000000000000000208"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoFreq" id="c97167bd9d19736e" memberName="lfoFreq" virtualName=""
          explicitFocusOrder="0" pos="216 264 50 50" rotarysliderfill="7fffffff"
          rotaryslideroutline="66ffffff" min="1" max="1000" int="0.010000000000000000208"
          style="Rotary" textBoxPos="TextBoxAbove" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <SLIDER name="lfoWaveform" id="6dd138e716ced705" memberName="lfoWaveform"
          virtualName="" explicitFocusOrder="0" pos="296 264 50 50" bkgcol="ffffff"
          thumbcol="ffffffff" rotarysliderfill="7fffffff" rotaryslideroutline="66ffffff"
          textboxtext="ff000000" min="0" max="4" int="1" style="Rotary"
          textBoxPos="TextBoxAbove" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
