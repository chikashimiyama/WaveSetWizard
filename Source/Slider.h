#pragma once

#include "ISlider.h"

#include <set>

namespace nd
{
    class Slider : public ISlider
    {
    public:
        Slider(float defaultValue);

        ~Slider() override = default;

        void addListener(Listener* listener) override;

        void removeListener(Listener* listener) override;

        float get() const override;

        void set(float value) override;

    private:
        float value_{ 0.f };

        std::set<Listener*> listeners_;
    };
} // namespace dearvr
