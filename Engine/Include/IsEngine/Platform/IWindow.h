/**
 * @file IWindow.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 06.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/

namespace IsEngine {

class IWindow {
public:
    /**
     * @brief Destroy the IWindow object
     */
    virtual ~IWindow() = default;
    
    /**
     * @brief 
     * @param width 
     * @param height 
     * @param title 
     * @return true 
     * @return false 
     */
    virtual bool create(int width, int height, const char* title) = 0;

    /**
     * @brief 
     */
    virtual void destroy() = 0;

    /**
     * @brief 
     */
    virtual void pollEvents() = 0;

    /**
     * @brief 
     * @return true 
     * @return false 
     */
    virtual bool shouldClose() const = 0;

    /**
     * @brief Get the Native Handle object
     * @return void* 
     */
    virtual void* getNativeHandle() const = 0;
};

} /* Namespace IsEngine. */
