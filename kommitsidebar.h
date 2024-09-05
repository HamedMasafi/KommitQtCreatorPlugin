#pragma once

#include "ui_kommitsidebar.h"

class KommitSideBar : public QWidget, private Ui::KommitSideBar
{
    Q_OBJECT

public:
    explicit KommitSideBar(QWidget *parent = nullptr);
};
