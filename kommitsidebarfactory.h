#pragma once

#include <coreplugin/inavigationwidgetfactory.h>


class KommitSideBarFactory : public Core::INavigationWidgetFactory
{
public:
    KommitSideBarFactory();

    Core::NavigationView createWidget() override;
};
