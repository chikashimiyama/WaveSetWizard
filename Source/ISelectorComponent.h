#pragma once

#include <JuceHeader.h>
#include "ParameterType.h"

namespace nd
{
    class ISelectorComponent : public Component,
                               public ComboBox::Listener
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
