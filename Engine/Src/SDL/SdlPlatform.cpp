/**
 * @file SdlPlatform.cpp
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright © 2026
 */

/* Includes ------------------------------------------------------------------*/
#include "IsEngine/Platform/SDL/SdlPlatform.h"
#include "IsEngine/Platform/SDL/SdlWindow.h"
#include "IsEngine/Platform/SDL/SdlInput.h"

namespace IsEngine {

/*
 *
 */
SDLPlatform::SDLPlatform() {
    // Empty plug
}

/*
 *
 */
SDLPlatform::~SDLPlatform() {
    // Empty plug
}

/*
 *
 */
IWindow* SDLPlatform::getWindow() {
    return m_window.get();
}

/*
 *
 */
IInput* SDLPlatform::getInput() {
    return m_input.get();
}

/*
 *
 */
float SDLPlatform::getTime() const {
    return 0.0F;  // Заглушка
}

/*
 *
 */
std::unique_ptr<IPlatform> IPlatform::create() {
    return std::make_unique<SDLPlatform>();
}

} /* Namespace IsEngine. */
