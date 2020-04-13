#include "PluginProcessor.h"
#include "PluginEditor.h"


WaveSetWizardAudioProcessorEditor::WaveSetWizardAudioProcessorEditor (WaveSetWizardAudioProcessor& p)
    : AudioProcessorEditor (&p), processor_ (p)
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

    selectorComponent_ = std::make_unique<nd::SelectorComponent>(Rectangle<int>(10, 60, 95, 100));
    addAndMakeVisible(*selectorComponent_);


    knobComponent_ = std::make_unique<nd::KnobComponent>(Rectangle<int>(105, 60, 285, 100));
    addAndMakeVisible(*knobComponent_);


}

WaveSetWizardAudioProcessorEditor::~WaveSetWizardAudioProcessorEditor()
{}

void WaveSetWizardAudioProcessorEditor::paint (Graphics& g)
{
    Image background = ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
    g.drawImageAt (background, 0, 0);
    g.setColour(Colours::black);
}

void WaveSetWizardAudioProcessorEditor::resized()
{}
