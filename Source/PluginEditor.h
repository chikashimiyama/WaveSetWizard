#pragma once

#include <JuceHeader.h>

#include "ISelectorComponent.h"
#include "IKnobComponent.h"
#include "PluginProcessor.h"

namespace nd
{
    class WaveSetWizardAudioProcessorEditor: public AudioProcessorEditor,
                                             public ISelectorComponent::Listener,
                                             public IKnobComponent::Listener
    {
    public:
        WaveSetWizardAudioProcessorEditor(WaveSetWizardAudioProcessor&);

        ~WaveSetWizardAudioProcessorEditor();

        void paint(Graphics&) override;

        void resized() override;

        void onValueChanged(ParameterType type, float value) override;

    private:
        WaveSetWizardAudioProcessor& processor_;
        std::unique_ptr<nd::ISelectorComponent> selectorComponent_;
        std::unique_ptr<nd::IKnobComponent> knobComponent_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveSetWizardAudioProcessorEditor)
    };
}
