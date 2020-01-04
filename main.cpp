#include "registerer.hpp"
#include "ctagAudioPlugin.hpp"
#include <iostream>

using factory::Registry;

int main(int argc, char** argv) {
    std::unique_ptr<ctagAudioPlugin> plugin = Registry<ctagAudioPlugin>::New(argv[1]);
    assert(plugin);
    float in[32], out[32];
    plugin->Process(in, out);  // will draw a rectangle!
    plugin = Registry<ctagAudioPlugin>::New(argv[2]);
    plugin->Process(in, out); 
    plugin = nullptr;
}