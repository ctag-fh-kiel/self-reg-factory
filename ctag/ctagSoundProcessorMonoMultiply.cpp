#include "ctagSoundProcessorMonoMultiply.hpp"
#include <iostream>

using namespace CTAG::SP;

ctagSoundProcessorMonoMultiply::ctagSoundProcessorMonoMultiply()
{
    //std::cout << "Constructor" << std::endl;
    isStereo = false;
}

void ctagSoundProcessorMonoMultiply::Process(const ProcessData &data){
    for(uint32_t i=0;i<data.bufSize; i++){
        data.buf0[i] = (float)i;
        data.buf1[i] = (float)i;
    }
}

ctagSoundProcessorMonoMultiply::~ctagSoundProcessorMonoMultiply(){
    //std::cout << "Destructor" << std::endl;
}
