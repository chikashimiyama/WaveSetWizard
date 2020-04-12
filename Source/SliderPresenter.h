#pragma once

#include <JuceHeader.h>
#include "ISliderPresenter.h"
#include "ISlider.h"

namespace nd
{
    class SliderPresenter : public ISliderPresenter,
                            public ISlider::Listener,
                            public juce::Slider::Listener
    {
    public:
        SliderPresenter(ISlider& slider, juce::Slider& sliderComponent);

        ~SliderPresenter() override;

    private:
        void onSliderChanged() override;

        void sliderValueChanged(juce::Slider* slider) override;

        ISlider& slider_;
        juce::Slider& sliderComponent_;
    };
} // namespace dearvr
