/**
 * @file ICmdLine.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Parse command line arguments module.
 * @version 0.1
 * @date 11.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include <string>
#include "IsEngine/Common/System/ICmdLine.h"

namespace IsEngine::Common {

class CommandsLineArgs: public ICmdLineArg {
public:
    /**
     * @brief Construct a new CommandsLineArgs object
     * @param name 
     * @param value 
     * @param type 
     */
    CommandsLineArgs(const char* name, const char* value, CmdLineArgType type);

    /**
     * @brief 
     * @return const char* 
     */
    const char* GetName() const override;

    /**
     * @brief Get the Value object
     * @return const char* 
     */
    const char* GetValue() const override;

    /**
     * @brief Get the Type object
     * @return const CmdLineArgType 
     */
    IsEngine::Common::CmdLineArgType GetType() const override;

    /**
     * @brief 
     * @return const float 
     */
    float GetFValue() const override;

    /**
     * @brief 
     * @return const int 
     */
    int GetIValue() const override;

private:

    /**
     * @brief 
     */
    std::string m_name;

    /**
     * @brief 
     */
    std::string m_value;

    /**
     * @brief 
     */
    CmdLineArgType  m_type;
};

} /* Namespace IsEngine::Common. */
