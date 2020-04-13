#include "PluginProcessor.h"
#include "PluginEditor.h"

#include "SelectorComponent.h"
#include "KnobComponent.h"

namespace nd
{
    WaveSetWizardAudioProcessorEditor::WaveSetWizardAudioProcessorEditor(WaveSetWizardAudioProcessor& p)
        : AudioProcessorEditor(&p)
          , processor_(p)
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
        setSize(400, 220);

        selectorComponent_ = std::make_unique<SelectorComponent>(Rectangle<int>(10, 60, 95, 100));
        selectorComponent_->addListener(this);
        addAndMakeVisible(*selectorComponent_);

        knobComponent_ = std::make_unique<KnobComponent>(Rectangle<int>(105, 60, 285, 100));
        knobComponent_->addListener(this);
        addAndMakeVisible(*knobComponent_);
    }

    WaveSetWizardAudioProcessorEditor::~WaveSetWizardAudioProcessorEditor()
    {
    }

    void WaveSetWizardAudioProcessorEditor::paint(Graphics& g)
    {
        Image background = ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
        g.drawImageAt(background, 0, 0);
        g.setColour(Colours::black);
    }

    void WaveSetWizardAudioProcessorEditor::resized()
    {
    }

    void WaveSetWizardAudioProcessorEditor::onValueChanged(ParameterType type, float value)
    {
        processor_.setValue(type, value);
    }
}
