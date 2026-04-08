/**
 * @file SdlInput.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <IsEngine/Platform/IInput.h>

namespace IsEngine {

/**
 * @brief 
 */
class SDLInput : public IInput {
public:
    /**
     * @brief 
     * @param key 
     * @return true 
     * @return false 
     */
    bool isKeyPressed(KeyCode key) const override { (void)key; return false; }

    /**
     * @brief 
     * @param button 
     * @return true 
     * @return false 
     */
    bool isMouseButtonPressed(MouseButton button) const override { (void)button; return false; }

    /**
     * @brief Get the Mouse Position object
     * @param x 
     * @param y 
     */
    void getMousePosition(float& x, float& y) const override { x = y = 0; }

    /**
     * @brief 
     */
    void update() override {}
};

} /* Namespace IsEngine. */
