#pragma once

#include "kommitqtcreatorplugin_global.h"

#include <extensionsystem/iplugin.h>

namespace KommitQtCreatorPlugin::Internal {

class KommitQtCreatorPluginPlugin : public ExtensionSystem::IPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "org.qt-project.Qt.QtCreatorPlugin" FILE "KommitQtCreatorPlugin.json")

public:
    KommitQtCreatorPluginPlugin();
    ~KommitQtCreatorPluginPlugin() override;

    void initialize() override;
    void extensionsInitialized() override;
    ShutdownFlag aboutToShutdown() override;

private:
    void triggerAction();
};

} // namespace KommitQtCreatorPlugin::Internal
