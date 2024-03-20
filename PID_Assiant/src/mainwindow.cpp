#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./ui_robot.h"
#include "./ui_terminalpage.h"
#include "./ui_toolpage.h"
#include <QDateTime>
#include <QJsonDocument>
#include <QJsonObject>
#include <QMessageBox>
using namespace photinia;

//定义系统
#define Linux

#ifdef Linux
#define OS "gnome-terminal"
#else
#define OS "cmd.exe"
#endif

const QString json_address(
    "./"); //文件结构：QString file_name = "robot_" + name_ + "Config.json";
const QString style_sheet(QString::fromUtf8(
    "/* "
    "\344\270\212\350\276\271\346\241\206\345\256\275\345\272\2460\345\203"
    "\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244"
    "\272\343\200\201\351\242\234\350\211\262\344\270\272\351\200\217\346\230"
    "\216 */\n"
    "QToolButton{   \n"
    "	border-top: 0px outset transparent;       \n"
    "	border-bottom: 0px outset transparent;\n"
    "	border-right: 0px outset transparent;\n"
    "	border-left: 0px outset transparent;\n"
    "}\n"
    "\n"
    "/* \351\274\240\346\240\207\346\202\254\345\201\234 */\n"
    "QToolButton:hover{\n"
    "	background-color: #151515;	\n"
    "}\n"
    "\n"
    "/* \347\202\271\345\207\273\345\222\214\346\214\211\344\270\213 */\n"
    "QToolButton:pressed,QToolButton:checked{\n"
    "	border-left: 3px outset rgb(93, 95, 97);  /* "
    "\345\267\246\350\276\271\346\241\206\345\256\275\345\272\2463\345\203"
    "\217\347\264\240\343\200\201\347\252\201\345\207\272\346\230\276\347\244"
    "\272\343\200\201\351\242\234\350\211\262\344\270\272\346\267\261\347\201"
    "\260 */\n"
    "	background-color:#151515;	\n"
    "}\n"
    "\n"
    "QPushButton:default {\n"
    "    bor"
    "der-color: navy; /* make the default button prominent */\n"
    "};\n"
    ""));

bool MainWindow::LoadRobotJson() {
  // to do
  QDir directory(json_address);
  QStringList dirs = directory.entryList(QDir::Dirs);
  int num = 0;
  foreach (const QString &dir, dirs) {
    if (!dir.contains("robot"))
      continue; //过滤文件夹
    auto config_path = dir + "/RobotConfig.json";
    QFile json_file(config_path);
    if (!json_file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      Error("false! " + config_path +
            ".open(QIODevice::ReadOnly | QIODevice::Text)");
      return false;
    }
    QByteArray data = json_file.readAll();
    QJsonParseError parseError;
    QJsonDocument json_doc = QJsonDocument::fromJson(data, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
      Warn("Error parsing JSON:" + parseError.errorString() + "," +
           config_path + "is not a json file!");
      continue;
    }
    if (!json_doc.isObject()) {
      Error("JSON document is not an object.");
      continue;
    }
    QJsonObject json_object = json_doc.object();
    AddRobot(Json2Robot(&json_object));
    num++;
  }
  Info("Loaded " + QString::number(num) + " robots.");
  return true;
}

// use to add a robot by json file or add_btn of Ui.
RobotMaster *MainWindow::AddRobot(RobotMaster *robot_master) {
  if (robot_master == nullptr) {
    Error("robot_master==nullptr");
    return nullptr;
  }
  robots_.push_back(robot_master);
  robot_btns_.push_back(new QToolButton());
  robot_btns_.back()->setMinimumSize(QSize(48, 48));
  robot_btns_.back()->setToolButtonStyle(
      Qt::ToolButtonTextUnderIcon); //文字显示在icon下边
  robot_btns_.back()->setText(robots_.back()->name_);
  QIcon icon2;
  icon2.addFile(QString::fromUtf8(":/imgs/robot.png"), QSize(), QIcon::Normal,
                QIcon::Off);
  robot_btns_.back()->setIcon(icon2);
  robot_btns_.back()->setIconSize(QSize(35, 35));
  robot_btns_.back()->setStyleSheet(style_sheet + "color: #bfbfbf;" +
                                    "font-size: 11px;");
  auto current_robot_index = robot_num_++; //添加的机器人id=当前的数量-1
  QObject::connect(robot_btns_.back(), &QToolButton::clicked,
                   [this, current_robot_index]() {
                     current_robot_index_ = current_robot_index;
                     if (robots_[current_robot_index]->online_)
                       tool_page_->ui->connect_btn->setText("已连接");
                     else
                       tool_page_->ui->connect_btn->setText("未连接");
                     SetupToolPage(current_robot_index);
                     SetupStateBar(robots_[current_robot_index]);
                   });

  QObject::connect(robots_[current_robot_index], &TcpClient::Connected,
                   [this, current_robot_index]() {
                     robots_[current_robot_index]->online_ = true;
                     tool_page_->ui->connect_btn->setText("已连接");
                     Info("connected to RobotMaster " +
                          robots_[current_robot_index]->name_ + "@" +
                          robots_[current_robot_index]->ip_ + ":" +
                          robots_[current_robot_index]->port_);
                   });
  QObject::connect(robots_[current_robot_index], &TcpClient::Disconnected,
                   [this, current_robot_index]() {
                     robots_[current_robot_index]->online_ = false;
                     tool_page_->ui->connect_btn->setText("未连接");
                     Info("disconnected to RobotMaster " +
                          robots_[current_robot_index]->name_ + "@" +
                          robots_[current_robot_index]->ip_ + ":" +
                          robots_[current_robot_index]->port_);
                   });
  QObject::connect(robots_[current_robot_index], &TcpClient::ReadyRead,
                   [this, current_robot_index](const QString &buf) {
                     //  auto this_robot_id = current_robot_index;
                     //  Info(robots_[this_robot_id]->name_ + "@" +
                     //       robots_[this_robot_id]->ip_ + "=> " + buf);
                     DoTask(buf); //分析任务
                   });
  if (list_open_) {
    Error(QString::number(robot_btns_.size() + 1));
    ui->toolbar_layout->insertWidget(
        robot_btns_.size() - 1 + 2,
        robot_btns_.back()); // 2:robot_btn start index
    robot_btns_.back()->show();
  }
  return robots_.back();
}

// note: new 了一个robot，需要手动释放。
RobotMaster *MainWindow::Json2Robot(QJsonObject *json_object) {
  QString name = json_object->value("name").toString();
  QString ip = json_object->value("ip").toString();
  QString port = json_object->value("port").toString();
  double max_v = json_object->value("max_v").toDouble();
  double max_w = json_object->value("max_w").toDouble();
  double test_distance = json_object->value("test_distance").toDouble();
  double brake_distance = json_object->value("brake_distance").toDouble();
  QString detail = json_object->value("detail").toString();
  return new RobotMaster(name, ip, port, max_v, max_w, test_distance,
                         brake_distance, detail);
}

bool MainWindow::RemoveRobot(QString name) {
  if (robots_.size() != robot_btns_.size()) {
    std::cout << "robots_.size()!=robot_btns_.size()" << std::endl;
    return false;
  }
  for (int i = 0; i < robots_.size(); i++) {
    if (robots_[i]->name_ != name)
      continue;
    if (robots_[i] != nullptr)
      delete robots_[i];
    if (robot_btns_[i] != nullptr)
      delete robot_btns_[i];
    robots_.erase(robots_.begin() + i);
    robot_btns_.erase(robot_btns_.begin() + i);
    return true;
  }
  std::cout << "No robot is named " + name.toStdString() + "!" << std::endl;
  return false;
}

void MainWindow::SetupToolPage(int current_robot_index) {
  // ip,portF
  tool_page_->ui->robot_name_label->setText(
      "Robot:" + robots_[current_robot_index]->name_);
  tool_page_->ui->ip_lineEdit->setText(robots_[current_robot_index]->ip_);
  tool_page_->ui->port_lineEdit->setText(robots_[current_robot_index]->port_);

  //插件是单例的
  // p,i,d参数
  auto pid_params_ptr =
      (PIDParams *)robots_[current_robot_index]->local_planner_->params_;
  tool_page_->ui->pos_p_box->setValue(pid_params_ptr->pos_p);
  tool_page_->ui->pos_i_box->setValue(pid_params_ptr->pos_i);
  tool_page_->ui->pos_d_box->setValue(pid_params_ptr->pos_d);
  tool_page_->ui->yaw_p_box->setValue(pid_params_ptr->yaw_p);
  tool_page_->ui->yaw_i_box->setValue(pid_params_ptr->yaw_i);
  tool_page_->ui->yaw_d_box->setValue(pid_params_ptr->yaw_d);

  // max_v,max_w,brake_dis,test_dis
  tool_page_->ui->max_v_box->setValue(robots_[current_robot_index]->max_v_);
  tool_page_->ui->max_w_box->setValue(robots_[current_robot_index]->max_w_);
  tool_page_->ui->brake_distance_lineEdit->setText(
      QString::number(robots_[current_robot_index]->brake_distance_));
  tool_page_->ui->test_distance_lineEdit->setText(
      QString::number(robots_[current_robot_index]->test_distance_));
  ui->tool_stackedwidget->setCurrentIndex(1);
  ui->tool_stackedwidget->show();
}

void MainWindow::SetupStateBar(RobotMaster *robot_master) {
  if (robot_master == nullptr) {
    std::cout << "SetupStateBar failed!  robot_master==nullptr." << std::endl;
    return;
  }
  signal_type_label_->setText(robot_master->name_ + "/TCP");
  ping_label_->setText(QString::number(robot_master->ping_) + "ms");
  auto pos = "pos(" + QString::number(robot_master->position_.x) + "," +
             QString::number(robot_master->position_.y) + "," +
             QString::number(robot_master->position_.z) + ")";
  position3D_label_->setText(pos);
  // auto euler = "ang(" + QString::number(robot_master->euler_.yaw) + "," +
  //              QString::number(robot_master->euler_.pitch) + "," +
  //              QString::number(robot_master->euler_.roll) + ")";
  // euler_angle_label_->setText(euler);
  //四元数
  auto quaternion = "ang(" + QString::number(robot_master->quaternion_.w) +
                    "," + QString::number(robot_master->quaternion_.x) + "," +
                    QString::number(robot_master->quaternion_.y) + "," +
                    QString::number(robot_master->quaternion_.z) + ")";
  euler_angle_label_->setText(quaternion);

  confidence_label_->setText(
      "confidence:" + QString::number(robot_master->confidence_) + "%");
  battery_progressbar_->setValue(robot_master->battery_);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
  // robot_ui
  new_robot_ui_ = new Robot();
  LoadRobotJson(); //加载保存的机器人

  // toolbar
  add_robot_btn_ = new QToolButton();
  QObject::connect(add_robot_btn_, SIGNAL(clicked()), this,
                   SLOT(AddRobotBtnClicked()));
  add_robot_btn_->setObjectName(QString::fromUtf8("add_robot_btn_"));
  add_robot_btn_->setMinimumSize(QSize(48, 48));
  add_robot_btn_->setStyleSheet(style_sheet);
  QIcon icon2;
  icon2.addFile(QString::fromUtf8(":/imgs/add.png"), QSize(), QIcon::Normal,
                QIcon::Off);
  add_robot_btn_->setIcon(icon2);
  add_robot_btn_->setIconSize(QSize(35, 35));

  // tool stackedwidget
  ui->tool_stackedwidget->setStyleSheet("background-color:gray;");
  tool_page_ = new ToolPage();
  tool_page_->SetParent(
      ui->tool_stackedwidget); //设置父界面，用于和子界面建立联系
  ui->tool_stackedwidget->addWidget(tool_page_); // tool_page 1
  ui->tool_stackedwidget->hide();
  QObject::connect(tool_page_->ui->connect_btn, SIGNAL(clicked()), this,
                   SLOT(ToolPage_ConnectBtnClicked()));
  QObject::connect(tool_page_->ui->save_btn, SIGNAL(clicked()), this,
                   SLOT(ToolPage_SaveBtnClicked()));
  QObject::connect(tool_page_->ui->send_params_btn, SIGNAL(clicked()), this,
                   SLOT(ToolPage_SendParamsClicked()));
  QObject::connect(tool_page_->ui->start_btn, SIGNAL(clicked()), this,
                   SLOT(ToolPage_StartBtnClicked()));
  QObject::connect(tool_page_->ui->reset_btn, SIGNAL(clicked()), this,
                   SLOT(ToolPage_ResetBtnClicked()));
  // request location thread
  QObject::connect(tool_page_->ui->location_check_box, &QCheckBox::stateChanged,
                   [&](int state) {
                     location_request_thread_.robot_ptr_ =
                         robots_[current_robot_index_];
                     location_request_thread_.state_ = state;
                   });
  location_request_thread_.start();

  // terminal stackedwidget
  QFont font = QApplication::font();
  font.setFamily(QStringLiteral("Monospace"));
  font.setPointSize(12);
  terminal_page_ = new TerminalPage();
  console_ = new QTermWidget();
  const QStringList arguments = {"Photinia", "linux"};
  console_->setColorScheme(arguments[0]);
  console_->setKeyBindings(arguments[1]);
  console_->setTerminalFont(font);
  qDebug() << "* INFO *************************";
  qDebug() << " availableKeyBindings:" << console_->availableKeyBindings();
  qDebug() << " keyBindings:" << console_->keyBindings();
  qDebug() << " availableColorSchemes:" << console_->availableColorSchemes();
  qDebug() << "* INFO END *********************";
  QObject::connect(console_, &QTermWidget::finished, this, &QMainWindow::close);
  terminal_page_->ui->gridLayout_2->addWidget(console_, 1, 0);
  ui->terminal_stackedwidget->addWidget(terminal_page_); // terminal_page 1
  QObject::connect(ui->new_terminal, SIGNAL(triggered()), this,
                   SLOT(on_new_terminal_triggered()));
  ui->terminal_stackedwidget->hide();

  // user stackedwidget
  display_page_ = new Display();
  ui->action_stackedwidget->addWidget(display_page_); // display_page 1
  ui->action_stackedwidget->setCurrentIndex(1);
  chart_1_ = new Chart("map");

  chart_1_layout_ = new QHBoxLayout();
  chart_1_layout_->setMargin(0);
  chart_1_layout_->addWidget(chart_1_);
  display_page_->ui->map->setLayout(chart_1_layout_);
  chart_2_ = new Chart("line speed");
  chart_2_->axis_x_->setRange(0, 5);
  chart_2_->axis_y_->setRange(0, 5);
  chart_2_->axis_x_->setTitleText("t(sec)");
  chart_2_->axis_y_->setTitleText("m/s");
  chart_3_ = new Chart("angle speed");
  chart_3_->axis_x_->setRange(0, 5);
  chart_3_->axis_y_->setRange(0, 5);
  chart_3_->axis_x_->setTitleText("t(sec)");
  chart_3_->axis_y_->setTitleText("m/s");
  display_page_->ui->line_speed->setWidget(chart_2_);
  display_page_->ui->angle_speed->setWidget(chart_3_);
  chart_1_->update(); //更新绘图，可以指定区域
  chart_2_->update();
  chart_3_->update();
  StatusBarLayout();
  SetupNewRobotUi();
}

void MainWindow::SetupNewRobotUi() {
  QObject::connect(new_robot_ui_->ui->save_btn, SIGNAL(clicked()), this,
                   SLOT(NewRobot_SaveBtnClicked()));
}

void MainWindow::NewRobot_SaveBtnClicked() {
  QString name_str = new_robot_ui_->ui->name_lineEdit->text();
  QString ip_str = new_robot_ui_->ui->ip_lineEdit->text();
  QString port_str = new_robot_ui_->ui->port_lineEdit->text();
  QString p_str = new_robot_ui_->ui->p_box->text();
  QString i_str = new_robot_ui_->ui->i_box->text();
  QString d_str = new_robot_ui_->ui->d_box->text();
  QString yaw_p_str = new_robot_ui_->ui->p_box->text();
  QString yaw_i_str = new_robot_ui_->ui->i_box->text();
  QString yaw_d_str = new_robot_ui_->ui->d_box->text();
  QString v_str = new_robot_ui_->ui->max_v_box->text();
  QString w_str = "0";

  if (name_str.isEmpty() || ip_str.isEmpty() || port_str.isEmpty()) {
    Error("name_str.isEmpty() || ip_str.isEmpty() || port_str.isEmpty()");
    return;
  }
  if (!IsLegal(name_str, ip_str, port_str, p_str, i_str, d_str, v_str) ||
      !IsLegal(name_str, ip_str, port_str, yaw_p_str, yaw_i_str, yaw_d_str,
               v_str))
    return;

  auto robot_master = AddRobot(new RobotMaster(
      name_str, ip_str, port_str, v_str.toDouble(), w_str.toDouble()));
  auto pid_params_ptr = (PIDParams *)robot_master->local_planner_->params_;
  pid_params_ptr->pos_p = p_str.toDouble(); // pos pid   default:yaw=0
  pid_params_ptr->pos_i = i_str.toDouble();
  pid_params_ptr->pos_d = d_str.toDouble();
  robot_master->local_planner_->SaveConfig();

  // save json
  if (robot_master == nullptr)
    Error("robot_master == nullptr\nauto robot_master"
          "=AddRobot(new_robot_ui_->ui->name_lineEdit->text(),new_robot_ui_->"
          "ui->ip_lineEdit->text(),new_robot_ui_->ui->port_lineEdit->text(), "
          "{p, i, d}, max_v)");
  else {
    if (robot_master->SaveRobotJson())
      Info(new_robot_ui_->ui->name_lineEdit->text() +
           " is added to robots-list successfully");
  }
}

void MainWindow::on_robot_menu_btn_clicked() {
  ui->tool_stackedwidget->setCurrentIndex(1);
  ui->tool_stackedwidget->show();
}

void MainWindow::on_new_terminal_triggered() {
  ui->terminal_stackedwidget->setCurrentIndex(1);
  ui->terminal_stackedwidget->show();
}

void MainWindow::on_list_robot_btn_clicked() {
  int i = 2;         // robot_btn start index
  if (!list_open_) { // open
    for (auto &robot_btn : robot_btns_) {
      ui->toolbar_layout->insertWidget(i++, robot_btn);
      robot_btn->show();
    }
    ui->toolbar_layout->insertWidget(i++, add_robot_btn_);
    add_robot_btn_->show();
    ui->list_robot_btn->setIcon(QIcon(QString::fromUtf8(":/imgs/up.png")));
    list_open_ = true;
  } else { // close
    for (auto &robot_btn : robot_btns_) {
      ui->toolbar_layout->removeWidget(robot_btn);
      robot_btn->hide();
    }
    ui->toolbar_layout->removeWidget(add_robot_btn_);
    add_robot_btn_->hide();
    ui->list_robot_btn->setIcon(QIcon(QString::fromUtf8(":/imgs/down.png")));
    list_open_ = false;
  }
}

void MainWindow::AddRobotBtnClicked() {
  if (new_robot_ui_ != nullptr)
    new_robot_ui_->show();
}

void MainWindow::StatusBarLayout() {
  ui->statusbar->setStyleSheet("QStatusBar::item{border: 0px};");
  ui->statusbar->setStyleSheet("background-color: #1b60d2;");

  message_btn_ = new QPushButton(ui->statusbar);
  message_btn_->setStyleSheet(
      "QPushButton{icon:url(:/imgs/message.png);border:0px outset "
      "transparent;width:20}QPushButton:hover{background-color: "
      "#151515;}QPushButton:pressed,QPushButton:checked{border-left: 1px "
      "outset rgb(93, 95, 97);background-color:#151515;}");
  ui->statusbar->addPermanentWidget(message_btn_);

  ping_btn_ = new QPushButton(ui->statusbar);
  ping_btn_->setStyleSheet(
      "QPushButton{icon:url(:/imgs/wifi_gray.png);border:0px outset "
      "transparent;width:20}QPushButton:hover{background-color: "
      "#151515;}QPushButton:pressed,QPushButton:checked{border-left: 1px "
      "outset rgb(93, 95, 97);background-color:#151515;}");
  ui->statusbar->insertPermanentWidget(0, ping_btn_);

  ping_label_ = new QLabel(ui->statusbar);
  ping_label_->setStyleSheet(
      "QLabel{qproperty-text:'None';border:0px outset "
      "transparent;font-size:12px;color:#FFFFFF;width:40;}");
  ui->statusbar->insertPermanentWidget(1, ping_label_);

  battery_progressbar_ = new QProgressBar(ui->statusbar);
  battery_progressbar_->setStyleSheet(
      "QProgressBar { font-size: 12px;color:white; "
      "}QProgressBar::chunk{background-color:green};");
  battery_progressbar_->setFixedSize(40, 15);
  battery_progressbar_->setValue(20);
  ui->statusbar->insertPermanentWidget(2, battery_progressbar_);

  // QLabel *empty = new QLabel(ui->statusbar);  // 占位符
  // empty->setFixedWidth(40);
  // ui->statusbar->insertWidget(0, empty);

  signal_type_label_ = new QLabel(ui->statusbar);
  signal_type_label_->setStyleSheet(
      "QLabel{qproperty-text:'[None]';border:0px outset "
      "transparent;font-size:12px;color:#FFFFFF;width:40;}");
  ui->statusbar->insertWidget(0, signal_type_label_);

  position3D_label_ = new QLabel(ui->statusbar);
  position3D_label_->setStyleSheet(
      "QLabel{qproperty-text:'pos:(0,0,0)';border:0px outset "
      "transparent;font-size:12px;color:#FFFFFF;width:40;}");
  ui->statusbar->insertWidget(1, position3D_label_);

  euler_angle_label_ = new QLabel(ui->statusbar);
  euler_angle_label_->setStyleSheet(
      "QLabel{qproperty-text:'ang:(0,0,0)';border:0px outset "
      "transparent;font-size:12px;color:#FFFFFF;width:40;}");
  ui->statusbar->insertWidget(2, euler_angle_label_);

  confidence_label_ = new QLabel(ui->statusbar);
  confidence_label_->setStyleSheet(
      "QLabel{qproperty-text:'confidence:0.0%';border:0px outset "
      "transparent;font-size:12px;color:#FFFFFF;width:40;}");
  ui->statusbar->insertWidget(3, confidence_label_);

  // statusbar_.emplace("message2", new QLabel("fault"));
  // statusbar_["message2"]->setStyleSheet("color:#FFFFFF");
}

MainWindow::~MainWindow() {
  delete ui;
  location_request_thread_.quit();
  for (auto &status : statusbar_)
    if (status.second != nullptr)
      delete status.second;
}

bool MainWindow::IsLegal(QString name, QString ip, QString port, QString p,
                         QString i, QString d, QString max_v) {
  if (IsLegalName(name, this->robots_) && IsLegalIP(ip, this->robots_) &&
      IsLegalPort(port) && IsLegalVelocity(max_v) && IsLegalPID(p, i, d))
    return true;
  else
    return false;
}

bool MainWindow::IsLegal(QString name, QString ip, QString port, QString p,
                         QString i, QString d, QString max_v,
                         QString test_distance, QString brake_distance,
                         QString detail) {
  if (IsLegalName(name, this->robots_) && IsLegalIP(ip, this->robots_) &&
      IsLegalPort(port) && IsLegalVelocity(max_v) && IsLegalPID(p, i, d))
    return true;
  else
    return false;
}
bool MainWindow::IsLegalName(const QString &name,
                             const std::vector<RobotMaster *> &robots) {
  //检查名字是否重复
  for (auto &robot : robots) {
    if (name == robot->name_) {
      Warn("Duplicate name, please change it!");
      return false;
    }
  }
  return true;
}
bool MainWindow::IsLegalIP(const QString &ip,
                           const std::vector<RobotMaster *> &robots) {

  //检查ip是否合法
  QRegExp ip_regex("^((25[0-5]|2[0-4][0-9]|[0-1]?[0-9][0-9]?)\\.){3}(25[0-5]|2["
                   "0-4][0-9]|[0-1]?[0-9][0-9]?)$");
  if (!ip_regex.exactMatch(ip)) {
    Warn("IP " + ip + " is illegal!!");
    return false;
  }
  return true;
}

bool MainWindow::IsLegalPort(const QString &port) {
  bool ok;
  unsigned int conv_port = port.toUInt(&ok);
  if (!ok || conv_port < 4000) {
    Warn("Port " + port + " is illegal, you need to enter a int > = 4000.");
    return false;
  }
  return true;
}
bool MainWindow::IsLegalVelocity(const QString &velocity) {
  bool ok;
  double conv_velocity = velocity.toDouble(&ok);
  if (!ok) {
    Warn("Velocity is illegal, you need to enter a int.");
    return false;
  }
  return true;
}
bool MainWindow::IsLegalPID(const QString p, const QString i, const QString d) {
  bool ok_p, ok_i, ok_d;
  double conv_p = p.toDouble(&ok_p);
  double conv_i = i.toDouble(&ok_i);
  double conv_d = d.toDouble(&ok_d);
  if (!ok_p || !ok_i || !ok_d) {
    Warn("PID is illegal, you need to enter a int.");
    return false;
  }
  return true;
}

void MainWindow::ToolPage_ConnectBtnClicked() {
  if (robots_[current_robot_index_]->online_) {
    robots_[current_robot_index_]->DisconnectToHostSlot();
  } else {
    tool_page_->ui->connect_btn->setText("正在连接");
    QString ip_str = tool_page_->ui->ip_lineEdit->text();
    QString port_str = tool_page_->ui->port_lineEdit->text();
    if (!IsLegalIP(ip_str, robots_) || !IsLegalPort(port_str))
      return;
    robots_[current_robot_index_]->ConnectToHostSlot(ip_str, port_str);
  }
}
void MainWindow::ToolPage_SaveBtnClicked() {
  QString name_str = tool_page_->ui->robot_name_label->text();
  QString ip_str = tool_page_->ui->ip_lineEdit->text();
  QString port_str = tool_page_->ui->port_lineEdit->text();
  QString pos_p_str = tool_page_->ui->pos_p_box->text();
  QString pos_i_str = tool_page_->ui->pos_i_box->text();
  QString pos_d_str = tool_page_->ui->pos_d_box->text();
  QString yaw_p_str = tool_page_->ui->yaw_p_box->text();
  QString yaw_i_str = tool_page_->ui->yaw_i_box->text();
  QString yaw_d_str = tool_page_->ui->yaw_d_box->text();
  QString v_str = tool_page_->ui->max_v_box->text();
  QString w_str = tool_page_->ui->max_w_box->text();
  QString brake_distance = tool_page_->ui->brake_distance_lineEdit->text();
  QString test_distance = tool_page_->ui->test_distance_lineEdit->text();

  if (!IsLegal(name_str, ip_str, port_str, pos_p_str, pos_i_str, pos_d_str,
               v_str) ||
      !IsLegal(name_str, ip_str, port_str, yaw_p_str, yaw_i_str, yaw_d_str,
               w_str))
    return;
  robots_[current_robot_index_]->ip_ = ip_str;
  robots_[current_robot_index_]->port_ = port_str;
  robots_[current_robot_index_]->max_v_ = v_str.toDouble();
  robots_[current_robot_index_]->max_w_ = w_str.toDouble();
  robots_[current_robot_index_]->brake_distance_ = brake_distance.toDouble();
  robots_[current_robot_index_]->test_distance_ = test_distance.toDouble();

  // pos_pid,yaw_pid
  auto pid_params_ptr =
      (PIDParams *)robots_[current_robot_index_]->local_planner_->params_;
  pid_params_ptr->pos_p = pos_p_str.toDouble(); // pos
  pid_params_ptr->pos_i = pos_i_str.toDouble();
  pid_params_ptr->pos_d = pos_d_str.toDouble();
  pid_params_ptr->max_v = v_str.toDouble();
  pid_params_ptr->yaw_p = yaw_p_str.toDouble(); // yaw  todo
  pid_params_ptr->yaw_i = yaw_i_str.toDouble();
  pid_params_ptr->yaw_d = yaw_d_str.toDouble();
  pid_params_ptr->max_w = w_str.toDouble();
  robots_[current_robot_index_]->SaveRobotJson(); //保存机器人config
  robots_[current_robot_index_]
      ->local_planner_->SaveConfig(); //保存LocalPlanner.config

  /*****************项目需求******************/
  QJsonObject pid_json;
  photinia::PID2JsonObject(pid_params_ptr->pos_p, pid_params_ptr->pos_i,
                 pid_params_ptr->pos_d, pid_params_ptr->yaw_p,
                 pid_params_ptr->yaw_i, pid_params_ptr->yaw_d,
                 pid_params_ptr->max_v, pid_params_ptr->max_w,
                 robots_[current_robot_index_]->brake_distance_, pid_json);
  auto file_path =
      "./robot_" + robots_[current_robot_index_]->name_ + "/RobotPID.json";
  if (QFile::exists(file_path)) { // todo
    QMessageBox msg(QMessageBox::Information, "保存参数",
                    "已存在历史参数，是否清除？", 0, this);
    msg.addButton("清除并新建", QMessageBox::RejectRole);
    msg.addButton("继续追加", QMessageBox::AcceptRole);
    auto state = msg.exec();
    if (state == QMessageBox::AcceptRole) {
      QFile::remove(file_path);
      photinia::Info("remove " + file_path);
    } else if (state == QMessageBox::RejectRole) {
    }
  }
  if (!SaveJsonObject(file_path, pid_json)) {
    photinia::Error(file_path + " save Faild!");
  }
}
/*******************************************/

/**********************项目需要***********************/
void MainWindow::ToolPage_SendParamsClicked() {
  // auto file_path =
  //     "./robot_" + robots_[current_robot_index_]->name_ + "/RobotPID.json";
  // robots_[current_robot_index_]->SendJsonFile();
  QJsonObject pid_json;
  QString pos_p_str = tool_page_->ui->pos_p_box->text();
  QString pos_i_str = tool_page_->ui->pos_i_box->text();
  QString pos_d_str = tool_page_->ui->pos_d_box->text();
  QString yaw_p_str = tool_page_->ui->yaw_p_box->text();
  QString yaw_i_str = tool_page_->ui->yaw_i_box->text();
  QString yaw_d_str = tool_page_->ui->yaw_d_box->text();
  QString v_str = tool_page_->ui->max_v_box->text();
  QString w_str = tool_page_->ui->max_w_box->text();
  QString brake_distance = tool_page_->ui->brake_distance_lineEdit->text();
  QString test_distance = tool_page_->ui->test_distance_lineEdit->text();
  if (!IsLegalPID(pos_p_str, pos_i_str, pos_d_str) ||
      !IsLegalPID(yaw_p_str, yaw_i_str, yaw_d_str))
    return;
  pid_json["require_type"] = "send_params";
  pid_json["time_stamped"] = QDateTime::currentDateTime().toString();
  pid_json["angular_pid"] = QJsonArray(
      {yaw_p_str.toDouble(), yaw_i_str.toDouble(), yaw_d_str.toDouble()});
  pid_json["linear_pid"] = QJsonArray(
      {pos_p_str.toDouble(), pos_i_str.toDouble(), pos_d_str.toDouble()});
  pid_json["max_v"] = v_str.toDouble();
  pid_json["max_w"] = w_str.toDouble();
  pid_json["brake_distance"] = brake_distance.toDouble();
  pid_json["test_distance"] = test_distance.toDouble();
  robots_[current_robot_index_]->SendJsonObject(pid_json);
}
void MainWindow::ToolPage_StartBtnClicked() {
  robots_[current_robot_index_]->SendCommandJson("require_type",
                                                 "start_to_test");
}
void MainWindow::ToolPage_ResetBtnClicked() {}

void MainWindow::DoTask(const QString &buf) {
  auto doc = QJsonDocument::fromJson(buf.toUtf8());
  QJsonObject obj = doc.object();
  auto response = obj.value("response_type").toString();
  // Task1
  if (response == "start_to_test") {
    //对方响应：开始测试
  }
  // Task2
  if (response == "finish_test") {
    //对方响应：完成测试
  }
  // Task3
  if (response == "realtime_location") {
    //处理定位数据
    auto time_stamped = obj.value("time_stamped").toString().toDouble(); //单位S
    struct photinia::Position pos = {
        obj.value("localization").toArray().at(0).toDouble(),
        obj.value("localization").toArray().at(1).toDouble(),
        obj.value("localization").toArray().at(2).toDouble()};
    struct photinia::Quaternion qua = {
        obj.value("Quaternion").toArray().at(0).toDouble(),
        obj.value("Quaternion").toArray().at(1).toDouble(),
        obj.value("Quaternion").toArray().at(2).toDouble(),
        obj.value("Quaternion").toArray().at(3).toDouble()};
    chart_1_->line_->append(pos.x, pos.y);
    chart_2_->line_->append(
        time_stamped,
        obj.value("linear_velocity").toArray().at(0).toDouble()); //线速度 todo
    chart_3_->line_->append(
        time_stamped,
        obj.value("angular_velocity").toArray().at(0).toDouble()); //角速度 todo
    auto num_v = chart_2_->line_->count();
    auto num_w = chart_3_->line_->count();
    // Warn(QString::number(num_v) + " " + QString::number(num_w) + " " +
    //      QString::number(num));
    if (chart_2_->line_->at(num_v - 1).x() > chart_2_->axis_x_->max()) {
      chart_2_->axis_x_->setMax(chart_2_->line_->at(num_v - 1).x());
      if (num_v > 300) {
        chart_2_->line_->remove(0);
        chart_2_->axis_x_->setMin(chart_2_->line_->at(0).x());
      }
    }q
    if (chart_3_->line_->at(num_w - 1).x() > chart_3_->axis_x_->max()) {
      chart_3_->axis_x_->setMax(chart_3_->line_->at(num_w - 1).x());
      if (num_w > 300) {
        chart_3_->line_->remove(0);
        chart_3_->axis_x_->setMin(chart_3_->line_->at(0).x());
      }
    }

    chart_1_->update();
    chart_2_->update();
    chart_3_->update();

    //处理状态数据
    auto robot_ptr = robots_[current_robot_index_];
    robot_ptr->position_ = pos;
    robot_ptr->quaternion_ = qua;
    robot_ptr->battery_ = obj.value("battery").toDouble();
    robot_ptr->confidence_ = obj.value("confidence").toDouble();
    robot_ptr->ping_ = obj.value("ping").toDouble();
    SetupStateBar(robot_ptr);
    // num++;
  }
  // Task4
  if (response == "received_params") {
    //对方收到参数
  }
}