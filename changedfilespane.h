#pragma once

#include <QLabel>
#include <coreplugin/ioutputpane.h>

namespace ProjectExplorer
{
class Project;
}
namespace Git
{
class Manager;
}

class QTreeView;
class CommitsModel;
class ChangedFilesPane : public Core::IOutputPane
{
public:
    ChangedFilesPane();

    QWidget *outputWidget(QWidget *parent) override;
    void setProject(ProjectExplorer::Project *project);

    void clearContents() override;
    void setFocus() override;
    bool hasFocus() const override;
    bool canFocus() const override;
    bool canNavigate() const override;
    bool canNext() const override;
    bool canPrevious() const override;
    void goToNext() override;
    void goToPrev() override;

private:
    QTreeView *_treeView;
    Git::Manager *_git;
    CommitsModel *_model;
};
