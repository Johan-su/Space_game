#pragma once

#if defined(_WIN32) || defined(__linux__)

#include "ecs/ecs.hpp"
#include "core/Application.hpp"
#include "scene/Camera.hpp"
#include "scene/component.hpp"
#include "core/Input.hpp"
#include "asset/asset.hpp"
#include "Renderer/Renderer.hpp"

#else

#error Compiles only on Windows or Linux

#endif