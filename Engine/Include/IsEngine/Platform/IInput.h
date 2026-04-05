/**
 * @file IInput.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 06.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

namespace IsEngine {

/**
 * @brief Base key codes.
 */
enum class KeyCode {
    Unknown,
    Space,
    Apostrophe,
    Comma,
    Minus,
    Period,
    Slash,
    MaxKeyCode /*!< Max key code. */
};

/**
 * @brief Mouse key code.
 */
enum class MouseButton {
    Left,
    Right,
    Middle
};

/**
 * @brief 
 */
class IInput {
public:

    /**
     * @brief Destroy the IInput object
     */
    virtual ~IInput() = default;
    
    /**
     * @brief 
     * @param key 
     * @return true 
     * @return false 
     */
    virtual bool isKeyPressed(KeyCode key) const = 0;

    /**
     * @brief 
     * @param button 
     * @return true 
     * @return false 
     */
    virtual bool isMouseButtonPressed(MouseButton button) const = 0;

    /**
     * @brief Get the Mouse Position object
     * @param x 
     * @param y 
     */
    virtual void getMousePosition(float& x, float& y) const = 0;

    /**
     * @brief 
     */
    virtual void update() = 0;
};

} /* Namespace IsEngine. */
