/**
 * @file IsPlatform.h
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 10.04.2026
 * @copyright Copyright (c) 2026
 */

#pragma once

#ifndef ISENGINE_UNIQUE_IFACE
	
/**
 * @brief UNIQUE_IFACE expands to nothing on _all_ platforms, but is recognized by 
 * the de-virtualization tool.  If placed in front of an interface 
 * struct/class, all methods are assumed to be unique-virtual.
 */
#define ISENGINE_UNIQUE_IFACE

#endif /* ISENGINE_UNIQUE_IFACE */
