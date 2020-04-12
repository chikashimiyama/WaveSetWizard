#pragma once

#include <memory>

namespace nd
{
    class ISlider
    {
    public:
        class Listener
        {
        public:
            virtual ~Listener() = default;
            virtual void onSliderChanged() = 0;
        };

        virtual ~ISlider() = default;

        virtual void addListener(Listener* listener) = 0;

        virtual void removeListener(Listener* listener) = 0;

        virtual float get() const = 0;

        virtual void set(float value) = 0;
    };

    using SliderPtr = std::unique_ptr<ISlider>;

} // namespace dearvr
