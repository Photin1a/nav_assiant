#ifndef BASE_LOCAL_PLANNER_H
#define BASE_LOCAL_PLANNER_H

#include "msgs.hpp"
#include <QString>
#include <QVariant>
#include <QtPlugin>

#define PLUGIN_IID                                                             \
  "com.photinia.navigation.BaseLocalPlanner" //版本号必须有，或者json文件指定
#define PLUGIN_JSON "pid_controller_plugin/base_local_planner.json"
/**
 * @class BaseLocalPlanner
 * @brief Provides an interface for local planners used in navigation. All local
 * planners written as plugins for the navigation stack must adhere to this
 * interface.
 */
class BaseLocalPlanner {
public:
  /**
   * @brief  Given the current position, orientation, and velocity of the robot,
   * compute velocity commands to send to the base
   * @param cmd_vel Will be filled with the velocity command to be passed to the
   * robot base
   * @return True if a valid velocity command was found, false otherwise
   */
  virtual bool ComputeVelocityCommands(geometry_msgs::Twist &cmd_vel) = 0;

  /**
   * @brief  Check if the goal pose has been achieved by the local planner
   * @return True if achieved, false otherwise
   */
  virtual bool IsGoalReached() = 0;

  /**
   * @brief  Set the plan that the local planner is following
   * @param plan The plan to pass to the local planner
   * @return True if the plan was updated successfully, false otherwise
   */
  virtual bool SetPlan(const std::vector<geometry_msgs::PoseStamped> &plan) = 0;

  /**
   * @brief  Constructs the local planner
   * @param name The name to give this instance of the local planner
   * @param tf A pointer to a transform listener
   * @param costmap_ros The cost map to use for assigning costs to local plans
   */
  virtual void Initialize(const QString &name, const QString &config_file) = 0;
  virtual bool LoadConfig() = 0;
  virtual bool SaveConfig() = 0;
  virtual void SetParameter() = 0;

  /**
   * @brief  Virtual destructor for the interface
   */
  virtual ~BaseLocalPlanner() {}

  const void *params_;  //用于指向子类参数
};
Q_DECLARE_INTERFACE(BaseLocalPlanner, PLUGIN_IID)

#endif
