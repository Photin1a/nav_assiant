#include "toolpage.h"

#include "./ui_toolpage.h"

ToolPage::ToolPage(QWidget *parent) : QWidget(parent), ui(new Ui::ToolPage) {
  ui->setupUi(this);
}

void ToolPage::SetParent(QWidget *parent) {
  if (parent != nullptr)
    tool_stackedwidget_ = parent;
}

void ToolPage::on_hide_btn_clicked() { tool_stackedwidget_->hide(); }

ToolPage::~ToolPage() { delete ui; }
