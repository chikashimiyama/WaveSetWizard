#include "TrevorProcessor.h"
#include "TrevorEditor.h"

namespace agsp
{
    using namespace juce;

    TrevorProcessor::TrevorProcessor()
        : AudioProcessor(BusesProperties()
                             .withInput("Input", AudioChannelSet::stereo(), true)
                             .withOutput("Output", AudioChannelSet::stereo(), true))
    {
        engine_ = create(2);
    }

    TrevorProcessor::~TrevorProcessor()
    {
        destroy(engine_);
    }

    const String TrevorProcessor::getName() const
    {
        return JucePlugin_Name;
    }

    bool TrevorProcessor::acceptsMidi() const
    {
#if JucePlugin_WantsMidiInput
        return true;
#else
        return false;
#endif
    }

    bool TrevorProcessor::producesMidi() const
    {
        return false;
    }

    bool TrevorProcessor::isMidiEffect() const
    {
        return false;
    }

    double TrevorProcessor::getTailLengthSeconds() const
    {
        return 0.0;
    }

    int TrevorProcessor::getNumPrograms()
    {
        return 1;
    }

    int TrevorProcessor::getCurrentProgram()
    {
        return 0;
    }

    void TrevorProcessor::setCurrentProgram(int)
    {
    }

    const String TrevorProcessor::getProgramName(int)
    {
        return {};
    }

    void TrevorProcessor::changeProgramName(int, const String&)
    {
    }

    void TrevorProcessor::prepareToPlay(double, int)
    {
    }

    void TrevorProcessor::releaseResources()
    {

    }

#ifndef JucePlugin_PreferredChannelConfigurations

    bool TrevorProcessor::isBusesLayoutSupported(const BusesLayout& layouts) const
    {
#if JucePlugin_IsMidiEffect
        ignoreUnused (layouts);
        return true;
#else
        // This is the place where you check if the layout is supported.
        // In this template code we only support mono or stereo.
        if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
            && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
            return false;

        // This checks if the input layout matches the output layout
#if !JucePlugin_IsSynth
        if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
            return false;
#endif

        return true;
#endif
    }

#endif

    void TrevorProcessor::processBlock(AudioBuffer<float>& buffer, MidiBuffer&)
    {
        ScopedNoDenormals noDenormals;
        auto totalNumInputChannels = getTotalNumInputChannels();
        auto totalNumOutputChannels = getTotalNumOutputChannels();

        for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
            buffer.clear(i, 0, buffer.getNumSamples());

        set_coefficient(engine_, parameterSet_.coefficient);
        set_distortion(engine_, parameterSet_.distortion);
        set_attenuation(engine_, parameterSet_.attenuation);

        process(engine_, buffer.getWritePointer(0), 2, buffer.getNumSamples());
    }

    bool TrevorProcessor::hasEditor() const
    {
        return true; // (change this to false if you choose to not supply an editor)
    }

    AudioProcessorEditor* TrevorProcessor::createEditor()
    {
        return new TrevorEditor(*this);
    }

    void TrevorProcessor::getStateInformation(MemoryBlock&)
    {

    }

    void TrevorProcessor::setStateInformation(const void*, int)
    {

    }

    void TrevorProcessor::setValue(ParameterType type, float value)
    {
        switch(type)
        {
            case ParameterType::Coefficient:
                parameterSet_.coefficient = value; return;
            case ParameterType::Distortion:
                parameterSet_.distortion = value; return;
            case ParameterType::Attenuation:
                parameterSet_.attenuation = value; return;
        }
    }
}

juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new agsp::TrevorProcessor();
}
