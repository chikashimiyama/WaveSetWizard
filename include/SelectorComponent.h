#pragma once

#include <set>
#include <juce_gui_basics/juce_gui_basics.h>

#include "ISelectorComponent.h"

namespace agsp
{
    class SelectorComponent : public ISelectorComponent
    {
    public:
        SelectorComponent(juce::Rectangle<int> bound);

        ~SelectorComponent() override = default;

        void addListener(ISelectorComponent::Listener* listener) override;

        void removeListener(ISelectorComponent::Listener* listener) override;

    private:
        void comboBoxChanged(juce::ComboBox* comboBoxThatHasChanged) override;

        juce::Label waveformSelectorLabel_;
        juce::ComboBox waveformSelector_;

        juce::Label maxLengthLabel_;
        juce::ComboBox maxLengthSelector_;

        std::set<ISelectorComponent::Listener*> listeners_;
    };
}
