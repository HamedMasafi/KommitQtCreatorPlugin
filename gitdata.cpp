#include "gitdata.h"

#include <projectexplorer/project.h>
#include <projectexplorer/projectexplorer.h>
#include <projectexplorer/projectmanager.h>

#include <gitmanager.h>

GitData::GitData()
    : git{new Git::Manager}
{
    auto *sessionManager = ProjectExplorer::ProjectManager::instance();

    if (sessionManager)
        connect(sessionManager, &ProjectExplorer::ProjectManager::startupProjectChanged, this, &GitData::setProject);

}

void GitData::setProject(ProjectExplorer::Project *project)
{
    if (project)
        git->open(project->projectDirectory().path());
}

GitData *GitData::instance()
{
    static GitData *_instance{};
    if (!_instance)
        _instance = new GitData;
    return _instance;
}
