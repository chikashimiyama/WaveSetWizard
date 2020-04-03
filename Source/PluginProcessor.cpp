#include "PluginProcessor.h"
#include "PluginEditor.h"

WaveSetWizardAudioProcessor::WaveSetWizardAudioProcessor()
: AudioProcessor (BusesProperties()
                  .withInput  ("Input",  AudioChannelSet::stereo(), true)
                  .withOutput ("Output", AudioChannelSet::stereo(), true))
{}

WaveSetWizardAudioProcessor::~WaveSetWizardAudioProcessor()
{
}

const String WaveSetWizardAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WaveSetWizardAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WaveSetWizardAudioProcessor::producesMidi() const
{
    return false;
}

bool WaveSetWizardAudioProcessor::isMidiEffect() const
{
    return false;
}

double WaveSetWizardAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WaveSetWizardAudioProcessor::getNumPrograms()
{
    return 1;
}

int WaveSetWizardAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WaveSetWizardAudioProcessor::setCurrentProgram (int index)
{
}

const String WaveSetWizardAudioProcessor::getProgramName (int index)
{
    return {};
}

void WaveSetWizardAudioProcessor::changeProgramName (int index, const String& newName)
{
}

void WaveSetWizardAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{

}

void WaveSetWizardAudioProcessor::releaseResources()
{
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WaveSetWizardAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WaveSetWizardAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer&)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);
        
        for(auto i = 0; i < buffer.getNumSamples(); ++i)
        {
            channelData[i] = static_cast<float>(rand() % 20000) / 10000.0;
        }
    }
}

bool WaveSetWizardAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WaveSetWizardAudioProcessor::createEditor()
{
    return new WaveSetWizardAudioProcessorEditor (*this);
}

void WaveSetWizardAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WaveSetWizardAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WaveSetWizardAudioProcessor();
}
