#include "plugins.hpp"

namespace PluginSystem {

PluginFactory&
PluginFactory::Instance() {
    static PluginFactory instance;
    return instance;
}

void
PluginFactory::Register(IPluginRegistrar* registrar, std::string name) {
    registry_[name] = registrar;
}

std::unique_ptr<IPlugin>
PluginFactory::GetPlugin(std::string name) {
    /* throws out_of_range if plugin unknown */
    IPluginRegistrar* registrar = registry_.at(name);
    return registrar->GetPlugin();
}

}