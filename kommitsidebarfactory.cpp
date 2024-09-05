#include "kommitsidebarfactory.h"

#include "kommitqtcreatorplugintr.h"
#include "kommitsidebar.h"

KommitSideBarFactory::KommitSideBarFactory()
{
    setDisplayName(KommitQtCreatorPlugin::Tr::tr("Kommit"));
    setPriority(500);
    setId("kommit_sidebar");
}

Core::NavigationView KommitSideBarFactory::createWidget()
{
    return {new KommitSideBar, {}};
}
