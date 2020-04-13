#include "KnobComponent.h"

namespace nd
{
    KnobComponent::KnobComponent(Rectangle<int> bound)
    {
        setBounds(bound);
        auto localBounds = getLocalBounds();
        {
            auto coefficientBound = localBounds.removeFromLeft(95);
            coefficientBound.removeFromLeft(10);
            coefficientBound.removeFromRight(10);

            coefficientLabel_.setText("Coefficient", NotificationType::dontSendNotification);
            coefficientLabel_.setBounds(coefficientBound.removeFromTop(20));
            coefficientLabel_.setJustificationType(Justification::centred);
            addAndMakeVisible (&coefficientLabel_);

            coefficientSlider_.setSliderStyle(Slider::Rotary);
            coefficientSlider_.setRange(0.0, 1.0, 0.01);
            coefficientSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
            coefficientSlider_.setValue(1.0);
            coefficientSlider_.setBounds(coefficientBound);
            addAndMakeVisible (&coefficientSlider_);
        }

        {
            auto distortionBound = localBounds.removeFromLeft(95);
            distortionBound.removeFromLeft(10);
            distortionBound.removeFromRight(10);

            distortionLabel_.setText("Distortion", NotificationType::dontSendNotification);
            distortionLabel_.setBounds(distortionBound.removeFromTop(20));
            distortionLabel_.setJustificationType(Justification::centred);
            addAndMakeVisible (&distortionLabel_);

            distortionSlider_.setSliderStyle(Slider::Rotary);
            distortionSlider_.setRange(0.0, 1.0, 0.01);
            distortionSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
            distortionSlider_.setValue(1.0);
            distortionSlider_.setBounds(distortionBound);
            addAndMakeVisible (&distortionSlider_);
        }

        {
            auto attenuationBound = localBounds.removeFromLeft(95);
            attenuationBound.removeFromLeft(10);
            attenuationBound.removeFromRight(10);

            attenuationLabel_.setText("Attenuation", NotificationType::dontSendNotification);
            attenuationLabel_.setBounds(attenuationBound.removeFromTop(20));
            attenuationLabel_.setJustificationType(Justification::centred);
            addAndMakeVisible (&attenuationLabel_);

            attenuationSlider_.setSliderStyle(Slider::Rotary);
            attenuationSlider_.setRange(0.0, 1.0, 0.01);
            attenuationSlider_.setTextBoxStyle(Slider::TextBoxBelow, false, 60, 15);
            attenuationSlider_.setValue(1.0);
            attenuationSlider_.setBounds(attenuationBound);
            addAndMakeVisible (&attenuationSlider_);
        }
    }

    void KnobComponent::sliderValueChanged(Slider* /*slider*/)
    {

    }

    void KnobComponent::addListener(IKnobComponent::Listener* listener)
    {
        listeners_.insert(listener);
    }

    void KnobComponent::removeListener(IKnobComponent::Listener* listener)
    {
        listeners_.erase(listener);
    }
}