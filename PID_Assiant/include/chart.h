#ifndef CHART_H
#define CHART_H

#include <QChart>
#include <QChartView>
#include <QHBoxLayout>
#include <QLineSeries>
#include <QString>
#include <QVBoxLayout>
#include <QValueAxis>
#include <QLegend>


class Chart : public QT_CHARTS_NAMESPACE::QChartView {
  Q_OBJECT
public:
  Chart(QString name = "", QWidget *parent = nullptr);
  ~Chart();

public:
  QT_CHARTS_NAMESPACE::QChart *chart_;
  QT_CHARTS_NAMESPACE::QLineSeries *line_;
  QT_CHARTS_NAMESPACE::QLegend *legend_;
  QT_CHARTS_NAMESPACE::QValueAxis *axis_x_;
  QT_CHARTS_NAMESPACE::QValueAxis *axis_y_;
};

#endif