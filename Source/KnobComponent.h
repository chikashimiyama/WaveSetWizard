#pragma once

#include <set>
#include <JuceHeader.h>
#include "IKnobComponent.h"

namespace nd
{
    class KnobComponent : public IKnobComponent,
                          public Component,
                          public Slider::Listener
    {
    public:
        KnobComponent(Rectangle<int> bound);

        void addListener(IKnobComponent::Listener* listener) override;

        void removeListener(IKnobComponent::Listener* listener) override;

    private:
        void sliderValueChanged(Slider* slider) override;

        Label coefficientLabel_;
        Slider coefficientSlider_;

        Label distortionLabel_;
        Slider distortionSlider_;

        Label attenuationLabel_;
        Slider attenuationSlider_;

        std::set<IKnobComponent::Listener*> listeners_;
    };
}
