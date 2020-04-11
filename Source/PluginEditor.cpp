#include "PluginProcessor.h"
#include "PluginEditor.h"


WaveSetWizardAudioProcessorEditor::WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (400, 300);

    distortionSlider_.setSliderStyle (Slider::LinearBarVertical);
    distortionSlider_.setRange(0.0, 127.0, 1.0);
    distortionSlider_.setTextBoxStyle (Slider::NoTextBox, false, 90, 0);
    distortionSlider_.setPopupDisplayEnabled (true, false, this);
    distortionSlider_.setTextValueSuffix (" Volume");
    distortionSlider_.setValue(1.0);

    addAndMakeVisible (&distortionSlider_);
}

WaveSetWizardAudioProcessorEditor::~WaveSetWizardAudioProcessorEditor()
{
}

void WaveSetWizardAudioProcessorEditor::paint (Graphics& g)
{
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
}

void WaveSetWizardAudioProcessorEditor::resized()
{
    distortionSlider_.setBounds (40, 30, 20, getHeight() - 60);



}
