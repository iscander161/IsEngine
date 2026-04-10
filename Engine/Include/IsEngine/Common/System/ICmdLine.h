/**
 * @file ICmdLine.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Command line interface.
 * @version 0.1
 * @date 10.04.2026
 * @copyright Copyright © 2026
 */

#pragma once // Define to prevent recursive inclusion

/* Includes ------------------------------------------------------------------*/
#include "Common/IsPlatform.h"

namespace IsEngine::Common {

/**
 * @brief The type of command line argument.
 */
enum class CmdLineArgType {
    /**
     * @brief Argument was not preceeded by anything.
     */
    Normal = 0,

    /**
     * @brief Argument was preceeded by a minus sign '-'
     */
    Pre,

    /**
     * @brief Argument was preceeded by a plus signe '+'
     */
    Post,

    /**
     * @brief Argument is the executable filename.
     */
    Executable,
};

/**
 * @brief Container for a command line Argument.
 */
ISENGINE_UNIQUE_IFACE class ICmdLineArg {
public:
    /**
     * @brief Destroy the ICmdLineArg object
     */
	virtual ~ICmdLineArg() = default;

    /**
     * @brief Retrieve the name of the argument.
     * @return const char* - The name of the argument.
     */
	virtual const char *GetName() const = 0;

    /**
     * @brief Get the Value object.
     * @return const char* - The value of the argument as a null-terminated string.
     */
	virtual const char *GetValue() const = 0;
	
    /**
     * @brief Retrieve the type of argument.
     * @return const CmdLineArgType - The type of command line argument. @ref CmdLineArgType
     */
	virtual const CmdLineArgType GetType() const = 0;
	
    /**
     * @brief Retrieve the value of the argument.
     * @return const float - The value of the argument as float number.
     */
	virtual const float GetFValue() const = 0;

    /**
     * @brief Retrieve the value of the argument.
     * @return const int - The value of the argument as integer number.
     */
	virtual const int GetIValue() const = 0;
};

/** 
 * @brief Command line interface.
 */
class ICmdLine {
public:
    /**
     * @brief Destroy the ICmdLine object
     */
	virtual ~ICmdLine() = default;

    /**
     * @brief Returns the n'th command line argument.
     * @param n - 0 returns executable name, otherwise returns n'th argument.
     * @return const ICmdLineArg* - Pointer to the command line argument 
     * at index specified by idx.
     */
	virtual const ICmdLineArg* GetArg(int n) const = 0;

	/**
	 * @brief Returns the number of command line arguments.
	 * @return int - The number of command line arguments.
	 */
	virtual int GetArgCount() const = 0;

    /**
     * @brief Finds an argument in the command line.
     * @param argType - The type of command line argument.
     * @param name - Name of the argument to find, excluding any '+' or '-'.
     * @param caseSensitive - Flag indicating whether the name comparison should be case-sensitive.
     * @return const ICmdLineArg* 
     */
	virtual const ICmdLineArg* FindArg(const CmdLineArgType argType,
        const char* name, 
        bool caseSensitive = false) const = 0;
};

} /* Namespace IsEngine::Common */
