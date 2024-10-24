/*
// Copyright (C) 2020-2023 Intel Corporation
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
*/

#pragma once
#include <stdint.h>

#include <map>
#include <set>
#include <string>

#include <openvino/openvino.hpp>

struct InferenceConfig {
    std::string deviceName = "AUTO";
    std::string cpuExtensionsPath;
    std::string clKernelsConfigPath;
    unsigned int maxAsyncRequests;
    ov::AnyMap compilationConfig;

    std::set<std::string> getDevices();
    std::map<std::string, std::string> getLegacyConfig();

protected:
    std::set<std::string> devices;
};

class ConfigFactory {
public:
    static InferenceConfig getUserConfig(const std::string& flags_d,
                                     uint32_t flags_nireq,
                                     const std::string& flags_nstreams,
                                     uint32_t flags_nthreads);
    static InferenceConfig getMinLatencyConfig(const std::string& flags_d, uint32_t flags_nireq);

protected:
    static InferenceConfig getCommonConfig(const std::string& flags_d, uint32_t flags_nireq);
};
