#pragma once

#include <JuceHeader.h>

#include "SelectorCompomnent.h"
#include "KnobComponent.h"
#include "PluginProcessor.h"

class WaveSetWizardAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor&);
    ~WaveSetWizardAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    WaveSetWizardAudioProcessor& processor_;
    std::unique_ptr<nd::SelectorComponent> selectorComponent_;
    std::unique_ptr<nd::KnobComponent> knobComponent_;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveSetWizardAudioProcessorEditor)
};
