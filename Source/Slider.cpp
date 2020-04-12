#include "Slider.h"

namespace nd
{
    Slider::Slider(float defaultValue)
        : value_(defaultValue)
    {}

    void Slider::addListener(Listener* listener)
    {
        listeners_.insert(listener);
    }

    void Slider::removeListener(Listener* listener)
    {
        listeners_.erase(listener);
    }

    float Slider::get() const
    {
        return value_;
    }

    void Slider::set(float value)
    {
        if (value_ == value)
            return;

        value_ = value;
        for (auto&& listener : listeners_)
            listener->onSliderChanged();
    }

} // namespace dearvr
