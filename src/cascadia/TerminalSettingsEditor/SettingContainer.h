// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#pragma once

#include "SettingWrapper.g.h"
#include "SettingContainer.g.h"
#include "Utils.h"

namespace winrt::Microsoft::Terminal::Settings::Editor::implementation
{
    struct SettingWrapper : SettingWrapperT<SettingWrapper>
    {
    public:
        SettingWrapper(std::function<bool()> pfnHasVal, std::function<void()> pfnClearVal) :
            _pfnHasVal{ pfnHasVal },
            _pfnClearVal{ pfnClearVal }
        {
        }

        bool HasVal() const
        {
            if (!_pfnHasVal)
            {
                throw winrt::hresult_illegal_method_call();
            }
            return _pfnHasVal();
        }

        void ClearVal()
        {
            if(!_pfnClearVal)
            {
                throw winrt::hresult_illegal_method_call();
            }
            return _pfnClearVal();
        }

    private:
        std::function<bool()> _pfnHasVal;
        std::function<void()> _pfnClearVal;
    };

    struct SettingContainer : SettingContainerT<SettingContainer>
    {
    public:
        SettingContainer() = delete;

        SettingContainer(SettingWrapper setting) :
            _Setting{ setting } {}

        void ResetButton_Click(Windows::Foundation::IInspectable const& sender, Windows::UI::Xaml::RoutedEventArgs const& args);

        SettingWrapper Setting() { return _Setting; }

    private:
        SettingWrapper _Setting;
    };
}

namespace winrt::Microsoft::Terminal::Settings::Editor::factory_implementation
{
    BASIC_FACTORY(SettingContainer);
}
