#include "registerer.hpp"
#include "ctagAudioPlugin.hpp"
#include <iostream>

using factory::Registry;

int main(int, char**) {
    std::unique_ptr<ctagAudioPlugin> shape = Registry<ctagAudioPlugin>::New("ctagAudioPluginAM");
    assert(shape);
    shape->Process();  // will draw a rectangle!
}
