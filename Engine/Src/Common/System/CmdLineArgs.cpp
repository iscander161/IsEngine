/**
 * @file CmdLineArgs.cpp
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief Parse command line arguments module.
 * @version 0.1
 * @date 11.04.2026
 * @copyright Copyright © 2026
 */

/* Includes ------------------------------------------------------------------*/
#include "IsEngine/Common/System/CmdLineArgs.h"

using namespace IsEngine::Common;

namespace IsEngine::Common {

/*
 *
 */
CommandsLineArgs::CommandsLineArgs(const char* name, const char* value, CmdLineArgType type)
	: m_name(name)
	, m_value(value)
	, m_type(type)
{
}

/*
 *
 */
const char* CommandsLineArgs::GetName() const {
	return m_name.c_str();
}

/*
 *
 */
const char* CommandsLineArgs::GetValue() const {
	return m_value.c_str();
}

/*
 *
 */
CmdLineArgType CommandsLineArgs::GetType() const {
	return m_type;
}

/*
 *
 */
float CommandsLineArgs::GetFValue() const {
	return (float)atof(m_value.c_str());
}

/*
 *
 */
int CommandsLineArgs::GetIValue() const {
	return atoi(m_value.c_str());
}

} /* Namespace IsEngine::Common. */
