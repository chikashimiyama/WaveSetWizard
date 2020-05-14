#pragma once

#include <juce_graphics/juce_graphics.h>
#include <juce_audio_utils/juce_audio_utils.h>

#include "IKnobComponent.h"
#include "TrevorProcessor.h"

namespace agsp
{
    class TrevorEditor: public juce::AudioProcessorEditor,
                        public IKnobComponent::Listener
    {
    public:
        TrevorEditor(TrevorProcessor&);

        ~TrevorEditor();

        void paint(juce::Graphics&) override;

        void resized() override;

        void onValueChanged(ParameterType type, float value) override;

    private:
        TrevorProcessor& processor_;
        std::unique_ptr<IKnobComponent> knobComponent_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrevorEditor)
    };
}
