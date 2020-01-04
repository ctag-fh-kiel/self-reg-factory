/* Could be also split in .h/.cpp, here kept in one file for simplicity */
#include <iostream>
#include "plugins.hpp"

class Plugin1: public PluginSystem::IPlugin {
    void DoSomething() {
        std::cout << "Plugin1" << std::endl;
    }
};

REGISTER_PLUGIN(Plugin1)