#pragma once

#include <memory>

namespace nd
{
    class ISliderPresenter
    {
    public:
        virtual ~ISliderPresenter() = default;
    };

    using SliderPresenterPtr = std::unique_ptr<ISliderPresenter>;

} // namespace dearvr
