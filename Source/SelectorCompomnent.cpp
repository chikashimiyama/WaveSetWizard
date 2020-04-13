#include "SelectorCompomnent.h"

namespace nd
{
    SelectorComponent::SelectorComponent(Rectangle<int> bound)
    {
        setBounds(bound);
        auto localBounds = getLocalBounds();
        auto selectionBound = localBounds.removeFromLeft(95);
        selectionBound.removeFromLeft(10);
        selectionBound.removeFromRight(10);
        {
            waveformSelectorLabel_.setText("Waveform", NotificationType::dontSendNotification);
            waveformSelectorLabel_.setJustificationType(Justification::centred);
            waveformSelectorLabel_.setBounds(selectionBound.removeFromTop(20));
            addAndMakeVisible(&waveformSelectorLabel_);

            waveformSelector_.setName("WaveformSelector");
            waveformSelector_.addItem("Sine", 1);
            waveformSelector_.addItem("Tri", 2);
            waveformSelector_.addItem("Saw", 3);
            waveformSelector_.addItem("Rect", 4);
            waveformSelector_.addItem("Pulse", 5);
            waveformSelector_.setBounds(selectionBound.removeFromTop(20));
            waveformSelector_.addListener(this);
            addAndMakeVisible(&waveformSelector_);
        }

        {
            maxLengthLabel_.setText("Max Length", NotificationType::dontSendNotification);
            maxLengthLabel_.setBounds(selectionBound.removeFromTop(20));
            maxLengthLabel_.setJustificationType(Justification::centred);
            addAndMakeVisible(&maxLengthLabel_);

            maxLengthSelector_.setName("WaveformSelector");
            maxLengthSelector_.setBounds(selectionBound.removeFromTop(20));
            maxLengthSelector_.addItem("1024", 1);
            maxLengthSelector_.addItem("2048", 2);
            maxLengthSelector_.addItem("4096", 3);
            maxLengthSelector_.addItem("8192", 4);
            addAndMakeVisible(&maxLengthSelector_);
        }
    }

    void SelectorComponent::comboBoxChanged(ComboBox* comboBoxThatHasChanged)
    {
        auto notify = [this](ParameterType type, float value){
            for(auto&& listener : listeners_)
                listener->onValueChanged(type, value);
        };

        if(comboBoxThatHasChanged == &waveformSelector_)
            notify(ParameterType::Waveform, comboBoxThatHasChanged->getSelectedItemIndex());
        else if(comboBoxThatHasChanged == &maxLengthSelector_)
            notify(ParameterType::MaxLength, comboBoxThatHasChanged->getSelectedItemIndex());
    }

    void SelectorComponent::addListener(ISelectorComponent::Listener* listener)
    {
        listeners_.insert(listener);
    }

    void SelectorComponent::removeListener(ISelectorComponent::Listener* listener)
    {
        listeners_.erase(listener);
    }
}
