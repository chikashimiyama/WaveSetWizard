cmake_minimum_required(VERSION 3.15)

project(trevor VERSION 1.0.0)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

add_subdirectory(JUCE)

find_package(Trevor)

execute_process(
    COMMAND cbindgen --output include/TrevorCore.h
    COMMAND cargo clean
    COMMAND cargo build --release
    COMMAND cargo build
    WORKING_DIRECTORY "${CMAKE_CURRENT_LIST_DIR}/core")

juce_add_plugin(trevor
    PLUGIN_MANUFACTURER_CODE Agsp
    PLUGIN_CODE Trev
    FORMATS VST3
    COMPANY_NAME "Angry Sparrow GmbH"
    PRODUCT_NAME "Trevor")

target_sources(trevor
    PRIVATE
    src/KnobComponent.cpp
    src/TrevorEditor.cpp
    src/TrevorProcessor.cpp)

target_compile_definitions(trevor
    PUBLIC
    JUCE_WEB_BROWSER=0
    JUCE_USE_CURL=0
    JUCE_VST3_CAN_REPLACE_VST2=0)

target_include_directories(trevor
    PRIVATE
    include)

juce_add_binary_data(trevorData
    SOURCES resource/trevor.png)

target_link_libraries(trevor
    PRIVATE
    trevorData
    juce::juce_audio_utils
    Trevor::Core)

target_compile_features(trevor INTERFACE cxx_std_17)


