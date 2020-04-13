#pragma once

#include <set>
#include <JuceHeader.h>

#include "ISelectorComponent.h"

namespace nd
{
    class SelectorComponent : public ISelectorComponent,
                              public Component,
                              public ComboBox::Listener
    {
    public:
        SelectorComponent(Rectangle<int> bound);

        ~SelectorComponent() override = default;

        void addListener(ISelectorComponent::Listener* listener) override;

        void removeListener(ISelectorComponent::Listener* listener) override;

    private:
        void comboBoxChanged(ComboBox* comboBoxThatHasChanged) override;

        Label waveformSelectorLabel_;
        ComboBox waveformSelector_;

        Label maxLengthLabel_;
        ComboBox maxLengthSelector_;

        std::set<ISelectorComponent::Listener*> listeners_;
    };
}
