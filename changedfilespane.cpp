#include "changedfilespane.h"
#include "3rdparty/kommit/src/libkommit/gitmanager.h"
#include "3rdparty/kommit/src/libkommitwidgets/models/commitsmodel.h"
#include <projectexplorer/project.h>
#include <widgets/graphpainter.h>

#include <QTreeView>

ChangedFilesPane::ChangedFilesPane()
{
    setId("kommit");
    setDisplayName("kommit");
    setPriorityInStatusBar(10);

    _git = new Git::Manager;
    _treeView = new QTreeView;
    _model = new CommitsModel{_git, this};
    _treeView->setModel(_model);
    auto mGraphPainter = new GraphPainter(_model, this);
    _treeView->setItemDelegateForColumn(0, mGraphPainter);

}

QWidget *ChangedFilesPane::outputWidget(QWidget *parent)
{
    return _treeView;
}

void ChangedFilesPane::setProject(ProjectExplorer::Project *project) {
    if (project)
        _git->open(project->projectDirectory().path());
}

void ChangedFilesPane::clearContents() {}

void ChangedFilesPane::setFocus() {}

bool ChangedFilesPane::hasFocus() const
{
    return true;
}

bool ChangedFilesPane::canFocus() const
{
    return true;
}

bool ChangedFilesPane::canNavigate() const
{
    return true;
}

bool ChangedFilesPane::canNext() const
{
    return true;
}

bool ChangedFilesPane::canPrevious() const
{
    return true;
}

void ChangedFilesPane::goToNext() {}

void ChangedFilesPane::goToPrev() {}
