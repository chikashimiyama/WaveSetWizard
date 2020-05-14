cmake_minimum_required(VERSION 3.15)

project(trevor VERSION 1.0.0)

add_subdirectory(JUCE)

juce_add_plugin(trevor
    PLUGIN_MANUFACTURER_CODE Agsp
    PLUGIN_CODE Trev
    FORMATS VST3
    PRODUCT_NAME "Trevor")

target_sources(trevor
    PRIVATE
    src/SelectorComponent.cpp
    src/KnobComponent.cpp
    src/PluginEditor.cpp
    src/PluginProcessor.cpp)

target_compile_definitions(trevor
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_include_directories(trevor
    PRIVATE
    include)

target_link_libraries(trevor
    PRIVATE
    juce::juce_audio_utils)
