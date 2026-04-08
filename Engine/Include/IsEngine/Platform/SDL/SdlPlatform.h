/**
 * @file SdlPlatform.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <IsEngine/Platform/IPlatform.h>
#include <memory>

namespace IsEngine {

class SDLWindow;
class SDLInput;

class SDLPlatform : public IPlatform {
public:
    /**
     * @brief Construct a new SDLPlatform object
     */
    SDLPlatform();

    /**
     * @brief Destroy the SDLPlatform object
     */
    ~SDLPlatform();
    
    /**
     * @brief Get the Window object
     * @return IWindow* 
     */
    IWindow* getWindow() override;

    /**
     * @brief Get the Input object
     * @return IInput* 
     */
    IInput* getInput() override;

    /**
     * @brief Get the Time object
     * @return float 
     */
    float getTime() const override;
    
private:
    /**
     * @brief 
     */
    std::unique_ptr<SDLWindow> m_window;

    /**
     * @brief 
     */
    std::unique_ptr<SDLInput> m_input;
};

} /* Namespace IsEngine. */
