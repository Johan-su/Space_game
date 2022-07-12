#pragma once

#if defined(_WIN64) || defined(__linux__)

#include "ecs/ecs.hpp"
#include "Application/Application.hpp"
#include "scene/Camera.hpp"
#include "scene/component.hpp"
#include "scene/iter.hpp"
#include "input/Input.hpp"

#else
#error Compiles only on 64 bit Windows or Linux

#endif