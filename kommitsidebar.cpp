#include "kommitsidebar.h"

#include "gitdata.h"

#include <models/changedfilesmodel.h>

KommitSideBar::KommitSideBar(QWidget *parent)
    : QWidget(parent)
{
    setupUi(this);

    auto _model = new ChangedFilesModel{GitData::instance()->git};
    treeView->setModel(_model);
}
