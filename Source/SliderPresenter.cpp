#include "SliderPresenter.h"

namespace nd
{
    SliderPresenter::SliderPresenter(ISlider& slider, juce::Slider& sliderComponent)
        : slider_(slider)
          , sliderComponent_(sliderComponent)
    {
        sliderComponent_.setValue(slider.get(), juce::dontSendNotification);
        sliderComponent_.addListener(this);
        slider_.addListener(this);
    }

    SliderPresenter::~SliderPresenter()
    {
        sliderComponent_.removeListener(this);
        slider_.removeListener(this);
    }

    void SliderPresenter::onSliderChanged()
    {
        sliderComponent_.setValue(slider_.get(), juce::dontSendNotification);
    }

    void SliderPresenter::sliderValueChanged(juce::Slider* slider)
    {
        slider_.set(static_cast<float>(slider->getValue()));
    }

} // namespace dearvr
