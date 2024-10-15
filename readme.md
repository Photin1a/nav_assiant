# Nav Assiant
这是一个基于Qt5和开发的导航工具
* 不依赖于ROS，可移植，机器人原位端需要部署Sever。
* 支持终端操作
* 支持多机器人
![](./resources/4.gif)
## 使用方法 
### 编译
```bash
git clone https://github.com/Photin1a/nav_assiant.git
cd nav_assiant
#在CMakeLists.txt中修改Qt库位置
sudo chmod 777 ./re_config.sh
./re_config.sh
```
### 使用
```bash
cd build
./pid_assiant
```