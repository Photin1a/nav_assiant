#ifndef TOOL_PAGE_H
#define TOOL_PAGE_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class ToolPage;
}

class ToolPage : public QWidget {
  Q_OBJECT

 public:
  explicit ToolPage(QWidget *parent = nullptr);
  ~ToolPage();
  void SetParent(QWidget *parent);

 private slots:
  void on_hide_btn_clicked();

 public:
QWidget *tool_stackedwidget_;
  Ui::ToolPage *ui;
};

#endif  // TOOLPAGE_H
