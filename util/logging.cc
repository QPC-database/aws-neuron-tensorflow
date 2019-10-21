/* Copyright 2018 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/
#include "tensorflow/python/neuron/util/logging.h"
#include <sstream>

namespace tensorflow {
namespace kaena {
namespace logging {

int LogLevelStrToInt(const char* tf_env_var_val) {
  if (tf_env_var_val == nullptr) {
    return -1;
  }

  // Ideally we would use env_var / safe_strto64, but it is
  // hard to use here without pulling in a lot of dependencies,
  // so we use std:istringstream instead
  std::string min_log_level(tf_env_var_val);
  std::istringstream ss(min_log_level);
  int level;
  if (!(ss >> level)) {
    // Invalid vlog level setting, set level to default (0)
    level = 0;
  }
  return level;
}


}  // namespace logging
}  // namespace kaena
}  // namespace tensorflow
