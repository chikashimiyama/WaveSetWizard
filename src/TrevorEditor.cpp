#include "TrevorProcessor.h"
#include "TrevorEditor.h"

#include "KnobComponent.h"

#include <BinaryData.h>

namespace agsp
{
    using namespace juce;

    TrevorEditor::TrevorEditor(TrevorProcessor& p)
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

        knobComponent_ = std::make_unique<KnobComponent>(Rectangle<int>(105, 60, 285, 100));
        knobComponent_->addListener(this);
        addAndMakeVisible(*knobComponent_);
    }

    TrevorEditor::~TrevorEditor()
    {
    }

    void TrevorEditor::paint(Graphics& g)
    {
        Image background = ImageCache::getFromMemory(BinaryData::trevor_png, BinaryData::trevor_pngSize);
        g.drawImageAt(background, 0, 0);
        g.setColour(Colours::black);
    }

    void TrevorEditor::resized()
    {
    }

    void TrevorEditor::onValueChanged(ParameterType type, float value)
    {
        processor_.setValue(type, value);
    }
}
