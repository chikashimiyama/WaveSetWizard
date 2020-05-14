#pragma once

#include <juce_graphics/juce_graphics.h>
#include <juce_audio_utils/juce_audio_utils.h>

#include "ISelectorComponent.h"
#include "IKnobComponent.h"
#include "PluginProcessor.h"

namespace agsp
{
    class WaveSetWizardAudioProcessorEditor: public juce::AudioProcessorEditor,
                                             public ISelectorComponent::Listener,
                                             public IKnobComponent::Listener
    {
    public:
        WaveSetWizardAudioProcessorEditor(WaveSetWizardAudioProcessor&);

        ~WaveSetWizardAudioProcessorEditor();

        void paint(juce::Graphics&) override;

        void resized() override;

        void onValueChanged(ParameterType type, float value) override;

    private:
        WaveSetWizardAudioProcessor& processor_;
        std::unique_ptr<nd::ISelectorComponent> selectorComponent_;
        std::unique_ptr<nd::IKnobComponent> knobComponent_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveSetWizardAudioProcessorEditor)
    };
}
