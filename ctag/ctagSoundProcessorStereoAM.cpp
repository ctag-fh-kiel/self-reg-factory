#include "ctagSoundProcessorStereoAM.hpp"
#include <iostream>

using namespace CTAG::SP;

ctagSoundProcessorStereoAM::ctagSoundProcessorStereoAM()
{
    std::cout << "Constructor" << std::endl;
}

void ctagSoundProcessorStereoAM::Process(const ProcessData &data){
    for(uint32_t i=0;i<data.bufSize; i++){
        data.buf0[i] = (float)i;
        data.buf1[i] = (float)i;
    }
}

ctagSoundProcessorStereoAM::~ctagSoundProcessorStereoAM(){
    std::cout << "Destructor" << std::endl;
}
