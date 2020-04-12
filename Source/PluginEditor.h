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

    Label waveformSelectorLabel_;
    ComboBox waveformSelector_;

    Label maxLengthLabel_;
    ComboBox maxLengthSelector_;

    Label coefficientLabel_;
    Slider coefficientSlider_;

    Label distortionLabel_;
    Slider distortionSlider_;

    Label attenuationLabel_;
    Slider attenuationSlider_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveSetWizardAudioProcessorEditor)
};
