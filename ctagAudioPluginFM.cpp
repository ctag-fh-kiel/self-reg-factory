#include "ctagAudioPluginFM.hpp"

void ctagAudioPluginFM::Process (const float *in, float *out) const { 
    std::cout << "ctag FM\n"; 
}

ctagAudioPluginFM::ctagAudioPluginFM(){
    std::cout << "Constructor called\n"; 
}

ctagAudioPluginFM::~ctagAudioPluginFM(){
    std::cout << "Destructor called\n"; 
}