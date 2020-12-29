// Copyright (c) Microsoft Corporation.
// Licensed under the MIT license.

#include "pch.h"
#include "SettingContainer.h"
#include "SettingContainer.g.cpp"

using namespace winrt::Windows::UI::Xaml;

namespace winrt::Microsoft::Terminal::Settings::Editor::implementation
{
    void SettingContainer::ResetButton_Click(Windows::Foundation::IInspectable const& /*sender*/, RoutedEventArgs const& /*args*/)
    {
        _Setting.ClearVal();
    }
}
