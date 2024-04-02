#include "chart.h"

using namespace QT_CHARTS_NAMESPACE;
Chart::Chart(QString name, QWidget *parent) : QChartView(parent) {
  chart_ = new QChart();
  line_ = new QLineSeries();
  legend_ = chart_->legend();
  //坐标轴
  axis_x_ = new QValueAxis();
  axis_y_ = new QValueAxis();
  axis_x_->setTitleText("X/m");
  axis_y_->setTitleText("Y/m");
  axis_x_->setRange(-50, 50);
  axis_y_->setRange(-50, 50);
  axis_x_->setGridLineVisible(true); //网格
  axis_y_->setGridLineVisible(true);

  chart_->setTitle(name);
  chart_->addSeries(line_);
  chart_->addAxis(axis_x_, Qt::AlignmentFlag::AlignBottom);
  chart_->addAxis(axis_y_, Qt::AlignmentFlag::AlignLeft);
  line_->attachAxis(axis_x_);
  line_->attachAxis(axis_y_);

  this->setChart(chart_);
  this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  legend_->setVisible(false);

  //   chart_view_->setContentsMargins(0,0,0,0);
  // chart_->addAxis(axis_x_)
}

Chart::~Chart(){};