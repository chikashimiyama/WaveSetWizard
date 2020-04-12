#include "PluginProcessor.h"
#include "PluginEditor.h"


WaveSetWizardAudioProcessorEditor::WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    auto& lookAndFeel = getLookAndFeel();
    lookAndFeel.setColour(Label::textColourId, Colours::black);
    lookAndFeel.setColour(Slider::backgroundColourId, Colours::black);
    lookAndFeel.setColour(Slider::rotarySliderFillColourId, Colours::black);
    lookAndFeel.setColour(Slider::rotarySliderOutlineColourId, Colours::black);
    lookAndFeel.setColour(Slider::thumbColourId, Colours::orange);
    lookAndFeel.setColour(Slider::textBoxOutlineColourId, Colours::transparentBlack);
    lookAndFeel.setColour(Slider::textBoxTextColourId, Colours::black);
    lookAndFeel.setColour(ComboBox::backgroundColourId, Colours::black);
    lookAndFeel.setColour(ComboBox::textColourId, Colours::white);
    lookAndFeel.setColour(ComboBox::arrowColourId, Colours::orange);

    lookAndFeel.setDefaultSansSerifTypefaceName("Copperplate");
    setSize (400, 220);
    auto localBounds = getLocalBounds();
    localBounds.removeFromTop(60);
    localBounds.removeFromLeft(10);
    localBounds.removeFromRight(10);
    localBounds.removeFromBottom(60);

    {
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

WaveSetWizardAudioProcessorEditor::~WaveSetWizardAudioProcessorEditor()
{
}

void WaveSetWizardAudioProcessorEditor::paint (Graphics& g)
{
    Image background = ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
    g.drawImageAt (background, 0, 0);
    g.setColour(Colours::black);
}

void WaveSetWizardAudioProcessorEditor::resized()
{}
