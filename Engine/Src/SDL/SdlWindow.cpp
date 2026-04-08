/**
 * @file SdlWindow.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright © 2026
 */

/* Includes ------------------------------------------------------------------*/
#include <SDL3/SDL_properties.h>
#include <iostream>
#include "IsEngine/Platform/SDL/SdlWindow.h"

namespace IsEngine {

/*
 *
 */
SDLWindow::SDLWindow() 
    : m_window(nullptr), m_shouldClose(false) 
{
}

/*
 *
 */
SDLWindow::~SDLWindow() {
    destroy();
}

/*
 *
 */
bool SDLWindow::create(int width, int height, const char* title) {
    if (m_window) {
        std::cerr << "Window already created!" << std::endl;
        return false;
    }
    
    m_window = SDL_CreateWindow(title, width, height, 0);
    if (!m_window) {
        std::cerr << "Failed to create SDL window: " << SDL_GetError() << std::endl;
        return false;
    }
    
    m_shouldClose = false;
    return true;
}

/*
 *
 */
void SDLWindow::destroy() {
    if (m_window) {
        SDL_DestroyWindow(m_window);
        m_window = nullptr;
    }
}

/*
 *
 */
void SDLWindow::pollEvents() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_EVENT_QUIT) {
            m_shouldClose = true;
        }
    }
}

/*
 *
 */
bool SDLWindow::shouldClose() const {
    return m_shouldClose;
}

/*
 *
 */
void* SDLWindow::getNativeHandle() const {
    if (!m_window) {
        return nullptr;
    }
    
    // Получаем свойства окна
    SDL_PropertiesID props = SDL_GetWindowProperties(m_window);
    if (!props) {
        return nullptr;
    }
    
    // Получаем native handle в зависимости от ОС
    #ifdef __linux__
        return SDL_GetPointerProperty(props, SDL_PROP_WINDOW_X11_DISPLAY_POINTER, nullptr);
    #elif defined(_WIN32)
        return SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
    #else
        return nullptr;
    #endif
}

} // namespace IsEngine