/**
 * @file SdlWindow.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <IsEngine/Platform/IWindow.h>

namespace IsEngine {

/**
 * @brief 
 */
class SDLWindow : public IWindow {
public:
    /**
     * @brief 
     * @param width 
     * @param height 
     * @param title 
     * @return true 
     * @return false 
     */
    bool create(int width, int height, const char* title) override { return false; }

    /**
     * @brief 
     */
    void destroy() override {}

    /**
     * @brief 
     */
    void pollEvents() override {}

    /**
     * @brief 
     * @return true 
     * @return false 
     */
    bool shouldClose() const override { return false; }

    /**
     * @brief Get the Native Handle object
     * @return void* 
     */
    void* getNativeHandle() const override { return nullptr; }
};

} /* Namespace IsEngine. */
