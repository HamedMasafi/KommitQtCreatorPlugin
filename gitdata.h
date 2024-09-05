#pragma once

#include <QObject>

namespace Git {
    class Manager;
}
namespace ProjectExplorer
{
class Project;
}

class GitData : public QObject
{
    Q_OBJECT

public:
    GitData();

    void setProject(ProjectExplorer::Project *project);

    static GitData *instance();
    Git::Manager *git{nullptr};
};
