#pragma once

#include <atomic>

namespace agsp
{
    struct ParameterSet
    {
        ParameterSet()
        {
            coefficient = 0.f;
            distortion = 0.f;
            attenuation = 0.f;
        }

        std::atomic<float> coefficient;
        std::atomic<float> distortion;
        std::atomic<float> attenuation;
    };
}
