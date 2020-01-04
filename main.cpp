#include <iostream>
#include "plugins.hpp"

int main()
{
    auto &factory = PluginSystem::PluginFactory::Instance();
    
    auto plugin = factory.GetPlugin("Plugin1");
    
    plugin->DoSomething();
    
    return 0;
}