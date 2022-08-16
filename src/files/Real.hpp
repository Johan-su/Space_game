#pragma once

#if defined(_WIN64) || defined(__linux__)

#include "ecs/ecs.hpp"
#include "core/Application.hpp"
#include "scene/Camera.hpp"
#include "scene/component.hpp"
#include "core/Input.hpp"
#include "asset/asset.hpp"
#include "Renderer.hpp"

#else

#error Compiles only on 64 bit Windows or Linux

#endif