#pragma once

#include <pcl/point_types.h>

namespace pcl {

using Matrix4fMap = Eigen::Map<Eigen::Matrix4f, Eigen::Aligned>;
using Matrix4fMapConst = const Eigen::Map<const Eigen::Matrix4f, Eigen::Aligned>;

struct EIGEN_ALIGN16 PointCovariance {
  PCL_ADD_POINT4D;
  Eigen::Matrix4f cov;

  Matrix4fMap getCovariance4fMap() { return Matrix4fMap(cov.data()); }
  Matrix4fMapConst getCovariance4fMap() const { return Matrix4fMapConst(cov.data()); }

  PCL_MAKE_ALIGNED_OPERATOR_NEW
};

struct EIGEN_ALIGN16 PointNormalCovariance {
  PCL_ADD_POINT4D;
  PCL_ADD_NORMAL4D
  Eigen::Matrix4f cov;

  Matrix4fMap getCovariance4fMap() { return Matrix4fMap(cov.data()); }
  Matrix4fMapConst getCovariance4fMap() const { return Matrix4fMapConst(cov.data()); }

  PCL_MAKE_ALIGNED_OPERATOR_NEW
};

}  // namespace pcl
