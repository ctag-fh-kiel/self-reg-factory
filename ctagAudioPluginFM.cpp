#include "ctagAudioPluginFM.hpp"

void ctagAudioPluginFM::Process () const { 
    std::cout << "ctag FM\n"; 
}

ctagAudioPluginFM::ctagAudioPluginFM(){
    std::cout << "Constructor called\n"; 
}

ctagAudioPluginFM::~ctagAudioPluginFM(){
    std::cout << "Destructor called\n"; 
}