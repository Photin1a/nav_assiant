#ifndef MSGS_HPP
#define MSGS_HPP

#include <string>
#include <vector>
struct Header {
  double time;
  std::string frame_id;
};

namespace geometry_msgs {
struct Vector3d {
  double x;
  double y;
  double z;
};
struct Quaternion {
  double x;
  double y;
  double z;
  double w;
};

typedef struct Vector3d Point3d;

struct Twist {
  Vector3d linear;
  Vector3d angular;
};

struct Pose {
  Point3d position;
  Quaternion orientation;
};

struct PoseStamped {
  Header header;
  Pose pose;
};
} // namespace geometry_msgs

#endif