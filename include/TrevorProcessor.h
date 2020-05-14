#pragma once

#include <juce_audio_processors/juce_audio_processors.h>
#include <TrevorCore.h>
#include <stitch/queue_spsc_waitfree.h>

#include "ParameterType.h"

namespace agsp
{
    class TrevorProcessor : public juce::AudioProcessor
    {
    public:
        TrevorProcessor();

        ~TrevorProcessor();

        void prepareToPlay(double sampleRate, int samplesPerBlock) override;

        void releaseResources() override;

#ifndef JucePlugin_PreferredChannelConfigurations

        bool isBusesLayoutSupported(const BusesLayout& layouts) const override;

#endif

        void processBlock(juce::AudioBuffer<float>&, juce::MidiBuffer&) override;

        juce::AudioProcessorEditor* createEditor() override;

        bool hasEditor() const override;

        const juce::String getName() const override;

        bool acceptsMidi() const override;

        bool producesMidi() const override;

        bool isMidiEffect() const override;

        double getTailLengthSeconds() const override;

        int getNumPrograms() override;

        int getCurrentProgram() override;

        void setCurrentProgram(int index) override;

        const juce::String getProgramName(int index) override;

        void changeProgramName(int index, const juce::String& newName) override;

        void getStateInformation(juce::MemoryBlock& destData) override;

        void setStateInformation(const void* data, int sizeInBytes) override;

        void setValue(ParameterType type, float value);
    private:
        Engine* engine_;

        struct Command
        {
            ParameterType type;
            float value;
        };

        Stitch::Waitfree_SPSC_Queue<Command> queue_;

        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TrevorProcessor)
    };

}