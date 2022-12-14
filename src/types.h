/*
* Brian R Taylor
* brian.taylor@bolderflight.com
* 
* Copyright (c) 2022 Bolder Flight Systems Inc
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the “Software”), to
* deal in the Software without restriction, including without limitation the
* rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
* sell copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
* FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
* IN THE SOFTWARE.
*/

#ifndef TYPES_SRC_TYPES_H_  // NOLINT
#define TYPES_SRC_TYPES_H_

#include <cstddef>
#include <cstdint>
#include <array>

namespace bfs {

enum GnssFix : int8_t {
  GNSS_FIX_NONE = 1,
  GNSS_FIX_2D = 2,
  GNSS_FIX_3D = 3,
  GNSS_FIX_DGNSS = 4,
  GNSS_FIX_RTK_FLOAT = 5,
  GNSS_FIX_RTK_FIXED = 6
};

class ImuData {
 public:
  bool installed;
  bool new_data;
  float die_temp_c;
  float accel_mps2[3];
  float gyro_radps[3];
};

class MagData {
 public:
  bool installed;
  bool new_data;
  float die_temp_c;
  float mag_ut[3];
};

class GnssRelPosData {
 public:
  bool avail;
  bool moving_baseline;
  bool baseline_normalized;
  float rel_pos_acc_ned_m[3];
  double rel_pos_ned_m[3];
};

class GnssData {
 public:
  bool installed;
  bool new_data;
  int8_t fix;
  int8_t num_sats;
  int16_t gps_week;
  float alt_wgs84_m;
  float horz_acc_m;
  float vert_acc_m;
  float vel_acc_m;
  float ned_vel_mps[3];
  float ecef_vel_mps[3];
  float ecef_pos_acc_m[3];
  double gps_tow_s;
  double lat_rad;
  double lon_rad;
  double ecef_pos_m[3];
};

class StaticPressData {
 public:
  bool installed;
  bool new_data;
  float die_temp_c;
  float pres_pa;
};

class DiffPressData {
 public:
  bool installed;
  bool new_data;
  float die_temp_c;
  float pres_pa;
};

class InceptorData {
 public:
  static constexpr int8_t max_ch = 16;
  bool installed;
  bool lost_frame;
  bool failsafe;
  int8_t num_ch;
  std::array<float, max_ch> inputs;
};

class AdcData {
 public:
  float static_pres_pa;
  float diff_pres_pa;
  float pres_alt_m;
  float ias_mps;
};

class InsData {
 public:
  bool ins_initialized;
  float pitch_rad;
  float roll_rad;
  float heading_rad;
  float alt_wgs84_m;
  float home_alt_wgs84_m;
  float accel_bias_mps2[3];
  float gyro_bias_radps[3];
  float mag_bias_ut[3];
  float accel_mps2[3];
  float gyro_radps[3];
  float mag_ut[3];
  float ned_vel_mps[3];
  double lat_rad;
  double lon_rad;
  double home_lat_rad;
  double home_lon_rad;
  double ned_pos_m[3];
};

}  // namespace bfs

#endif  // TYPES_SRC_TYPES_H_ NOLINT
