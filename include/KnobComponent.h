#pragma once

#include <set>
#include "IKnobComponent.h"

namespace agsp
{
    class KnobComponent : public IKnobComponent
    {
    public:
        KnobComponent(juce::Rectangle<int> bound);

        void addListener(IKnobComponent::Listener* listener) override;

        void removeListener(IKnobComponent::Listener* listener) override;

    private:
        void sliderValueChanged(juce::Slider* slider) override;

        juce::Label coefficientLabel_;
        juce::Slider coefficientSlider_;

        juce::Label distortionLabel_;
        juce::Slider distortionSlider_;

        juce::Label attenuationLabel_;
        juce::Slider attenuationSlider_;

        std::set<IKnobComponent::Listener*> listeners_;
    };
}
