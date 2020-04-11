#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

class WaveSetWizardAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor&);
    ~WaveSetWizardAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    WaveSetWizardAudioProcessor& processor;

    Slider distortionSlider_;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveSetWizardAudioProcessorEditor)
};
