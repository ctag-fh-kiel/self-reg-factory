#include <list>
#include <string>
#include <map>
#include <memory>

namespace PluginSystem {

    /* Base class for plugins */
    class IPlugin {
    public:
        virtual void DoSomething() = 0;
    };
    
    /* 
     * Base class for PluginRegistrar
     * See PluginRegistrar below for explanations
     */
    class IPluginRegistrar {
    public:
        virtual std::unique_ptr<IPlugin> GetPlugin() = 0;
    };

    /* 
     * This is the factory, the common interface to "plugins".
     * Plugins registers themselves here and the factory can serve them on
     * demand.
     * It is a Singleton
     */
    class PluginFactory {
    public:
        /* Get Singleton instance */
        static PluginFactory& Instance();
        /* Register a new plugin */
        void Register(IPluginRegistrar* registrar, std::string name);
        /* Get an instance of a plugin based on its name */
        /* throws out_of_range if plugin not found */
        std::unique_ptr<IPlugin> GetPlugin(std::string name);

    private:
        /* Holds pointers to plugin registrars */
        std::map<std::string, IPluginRegistrar*> registry_;
        /* Make constructors private and forbid cloning */
        PluginFactory(): registry_() {};
        PluginFactory(PluginFactory const&) = delete;
        void operator=(PluginFactory const&) = delete;
    };
    
    /* 
     * Helper class that registers a plugin upon construction.
     * Actually, the registrar registers itself, and the proxied plugin is only
     * created on-demand. This mechanism can be shortened by directly 
     * registering and instance of the plugin, but the assumption here is that
     * instanciating the plugin can be heavy and not necessary.
     */
    template<class TPlugin>
    class PluginRegistrar: public IPluginRegistrar {
    public:
        PluginRegistrar(std::string classname);
        std::unique_ptr<IPlugin> GetPlugin();
    private:
        /* That is not really used there, but could be useful */
        std::string classname_;
    };

    /* template functions in header */
    
    template<class TPlugin>
    PluginRegistrar<TPlugin>::PluginRegistrar(std::string classname): classname_(classname) {
        PluginFactory &factory = PluginFactory::Instance();
        factory.Register(this, classname);
    }
    
    template<class TPlugin>
    std::unique_ptr<IPlugin>
    PluginRegistrar<TPlugin>::GetPlugin() {
        std::unique_ptr<IPlugin> plugin(new TPlugin());
        return plugin;
    }
}

/*
 * Here is the trick: upon creation of the global variable, the class created
 * out of the template will get instanciated once, and will register itself.
 * The template contains the information to create a plugin instance.
 * An unnamed namespace is used to enclose this later unused variable in the
 * compilation unit.
 */
#define REGISTER_PLUGIN(CLASSNAME) \
    namespace { \
        static PluginSystem::PluginRegistrar<CLASSNAME> \
        _registrar( #CLASSNAME ); \
    };