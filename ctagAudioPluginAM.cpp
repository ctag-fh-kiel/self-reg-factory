#include "ctagAudioPluginAM.hpp"

void ctagAudioPluginAM::Process (const float *in, float *out) const { 
    std::cout << "ctag AM\n"; 
}

ctagAudioPluginAM::ctagAudioPluginAM(){
    std::cout << "Constructor called\n"; 
}

ctagAudioPluginAM::~ctagAudioPluginAM(){
    std::cout << "Destructor called\n"; 
}