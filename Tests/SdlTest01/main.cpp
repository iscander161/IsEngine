/**
 * @file main.cpp
 * @author Alexander Tolstunov (iscander161@yandex.ru)
 * @brief 
 * @version 0.1
 * @date 08.04.2026
 * @copyright Copyright (c) 2026
 */

/* Includes ------------------------------------------------------------------*/
#include <iostream>
#include <IsEngine/Platform/IPlatform.h>

int main(int argc, char** argvs) {
    auto platform = IsEngine::IPlatform::create();
    
    if(!platform->isValid()) {
        std::cerr << "Platform is invalid!" << std::endl;
        return -1;
    }

    if (!platform->getWindow()->create(800, 600, "IsEngine Test")) {
        std::cerr << "Failed to create window!" << std::endl;
        return -1;
    }
    
    while (!platform->getWindow()->shouldClose()) {
        platform->getWindow()->pollEvents();
    }
    
    return 0;
}
