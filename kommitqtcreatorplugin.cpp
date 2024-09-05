#include "kommitqtcreatorplugin.h"
#include "changedfilespane.h"
#include "kommitqtcreatorpluginconstants.h"
#include "kommitqtcreatorplugintr.h"
#include "kommitsidebarfactory.h"

#include <coreplugin/actionmanager/actioncontainer.h>
#include <coreplugin/actionmanager/actionmanager.h>
#include <coreplugin/actionmanager/command.h>
#include <coreplugin/coreconstants.h>
#include <coreplugin/icontext.h>
#include <coreplugin/icore.h>


#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectmanager.h>

#include <QAction>
#include <QMainWindow>
#include <QMenu>
#include <QMessageBox>

namespace KommitQtCreatorPlugin::Internal {

KommitQtCreatorPluginPlugin::KommitQtCreatorPluginPlugin()
{
    // Create your members
}

KommitQtCreatorPluginPlugin::~KommitQtCreatorPluginPlugin()
{
    // Unregister objects from the plugin manager's object pool
    // Delete members
}

void KommitQtCreatorPluginPlugin::initialize()
{
    // Register objects in the plugin manager's object pool
    // Load settings
    // Add actions to menus
    // Connect to other plugins' signals
    // In the initialize function, a plugin can be sure that the plugins it
    // depends on have initialized their members.

    // If you need access to command line arguments or to report errors, use the
    //    bool IPlugin::initialize(const QStringList &arguments, QString *errorString)
    // overload.

    auto action = new QAction(Tr::tr("KommitQtCreatorPlugin Action"), this);
    Core::Command *cmd = Core::ActionManager::registerAction(action,
                                                             Constants::ACTION_ID,
                                                             Core::Context(
                                                                 Core::Constants::C_GLOBAL));
    cmd->setDefaultKeySequence(QKeySequence(Tr::tr("Ctrl+Alt+Meta+A")));
    connect(action, &QAction::triggered, this, &KommitQtCreatorPluginPlugin::triggerAction);

    Core::ActionContainer *menu = Core::ActionManager::createMenu(Constants::MENU_ID);
    menu->menu()->setTitle(Tr::tr("KommitQtCreatorPlugin"));
    menu->addAction(cmd);
    Core::ActionManager::actionContainer(Core::Constants::M_TOOLS)->addMenu(menu);

    auto pane = new ChangedFilesPane;
    pane->setParent(this);

    auto *sessionManager = ProjectExplorer::ProjectManager::instance();

    if (sessionManager)
        connect(sessionManager, &ProjectExplorer::ProjectManager::startupProjectChanged, pane, &ChangedFilesPane::setProject);

    pane->setProject(sessionManager->startupProject());

    auto sideBar =new KommitSideBarFactory;

}

void KommitQtCreatorPluginPlugin::extensionsInitialized()
{
    // Retrieve objects from the plugin manager's object pool
    // In the extensionsInitialized function, a plugin can be sure that all
    // plugins that depend on it are completely initialized.
}

ExtensionSystem::IPlugin::ShutdownFlag KommitQtCreatorPluginPlugin::aboutToShutdown()
{
    // Save settings
    // Disconnect from signals that are not needed during shutdown
    // Hide UI (if you add UI that is not in the main window directly)
    return SynchronousShutdown;
}

void KommitQtCreatorPluginPlugin::triggerAction()
{
    QMessageBox::information(Core::ICore::mainWindow(),
                             Tr::tr("Action Triggered"),
                             Tr::tr("This is an action from KommitQtCreatorPlugin."));
}

} // namespace KommitQtCreatorPlugin::Internal
