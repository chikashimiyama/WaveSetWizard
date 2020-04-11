#include "PluginProcessor.h"
#include "PluginEditor.h"


WaveSetWizardAudioProcessorEditor::WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 200);
    auto localBounds = getLocalBounds();
    localBounds.removeFromTop(30);
    localBounds.removeFromLeft(30);
    localBounds.removeFromRight(30);

    auto knobArrayBounds = localBounds.removeFromTop(120);
    {
        auto distortionBound = knobArrayBounds.removeFromLeft(100);
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

}

WaveSetWizardAudioProcessorEditor::~WaveSetWizardAudioProcessorEditor()
{
}

void WaveSetWizardAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("WaveSetWizard", 0,0, getWidth(),
                     30, Justification::centred, 1);
}

void WaveSetWizardAudioProcessorEditor::resized()
{



}
