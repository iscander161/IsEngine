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
#include <iostream>

namespace IsEngine {

/*
 *
 */
SDLPlatform::SDLPlatform() {
    /* Инициализируем SDL */
    auto initFlag = SDL_Init(SDL_INIT_VIDEO);
    if (!initFlag) {
        std::cerr << "SDL_Init failed: " << SDL_GetError() << std::endl;
        m_valid = false;
        return;
    }
    
    // Создаём окно и input (пока input — заглушка)
    m_window = std::make_unique<SDLWindow>();
    m_input = std::make_unique<SDLInput>();
    m_valid = true;
}

/*
 *
 */
SDLPlatform::~SDLPlatform() {
    SDL_Quit();
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
    return SDL_GetTicks() / 1000.0f;
}

/**
 * Returns whether the platform is valid.
 */
bool SDLPlatform::isValid() const {
    return m_valid;
}

/*
 *
 */
std::unique_ptr<IPlatform> IPlatform::create() {
    return std::make_unique<SDLPlatform>();
}

} /* Namespace IsEngine. */
