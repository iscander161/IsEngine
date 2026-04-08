/**
 * @file IPlatform.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 06.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <memory>
#include "IWindow.h"
#include "IInput.h"

namespace IsEngine {

class IPlatform {

public:
    /**
     * @brief Destroy the IPlatform object
     */
    virtual ~IPlatform() = default;
    
    /**
     * @brief Get the Window object
     * @return IWindow* 
     */
    virtual IWindow* getWindow() = 0;

    /**
     * @brief Get the Input object
     * @return IInput* 
     */
    virtual IInput* getInput() = 0;

    /**
     * @brief Get the Time object
     * @return float 
     */
    virtual float getTime() const = 0;
    
    /**
     * @brief 
     * @return std::unique_ptr<IPlatform> 
     */
    static std::unique_ptr<IPlatform> create();

    /**
     * @brief Returns whether the platform is valid.
     * @return true - Platform is valid.
     * @return false - Platform is invalid.
     */
    virtual bool isValid() const = 0;

};

} /* Namespace IsEngine. */
