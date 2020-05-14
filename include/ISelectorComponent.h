#pragma once

#include <juce_gui_basics/juce_gui_basics.h>

#include "ParameterType.h"

namespace agsp
{
    class ISelectorComponent : public juce::Component,
                               public juce::ComboBox::Listener
    {
    public:
        class Listener
        {
        public:
            virtual ~Listener() = default;

            virtual void onValueChanged(ParameterType type, float value) = 0;
        };

    public:
        virtual ~ISelectorComponent() = default;

        virtual void addListener(Listener* listener) = 0;

        virtual void removeListener(Listener* listener) = 0;
    };
}
