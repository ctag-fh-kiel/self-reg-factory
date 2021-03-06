#include "ctagSoundProcessorMonoMultiply.hpp"
#include "ctagSoundProcessorMonoMultiply_JSN.h"
#include <iostream>


using namespace CTAG::SP;

ctagSoundProcessorMonoMultiply::ctagSoundProcessorMonoMultiply()
{
    std::cout << "Constructor " << CTAGSOUNDPROCESSORMONOMULTIPLY_ID << std::endl;
    isStereo = CTAGSOUNDPROCESSORMONOMULTIPLY_ISSTEREO;
}

void ctagSoundProcessorMonoMultiply::Process(const ProcessData &data) const {
    for(uint32_t i=0;i<data.bufSize; i++){
        data.buf0[i] = (float)i;
        data.buf1[i] = (float)i;
    }
}

ctagSoundProcessorMonoMultiply::~ctagSoundProcessorMonoMultiply(){
    std::cout << "Destructor " << CTAGSOUNDPROCESSORMONOMULTIPLY_ID << std::endl;
}

const unsigned char * ctagSoundProcessorMonoMultiply::GetCStrJSONParamSpecs() const{
    return CTAGSOUNDPROCESSORMONOMULTIPLY_JSN;
}

const unsigned char * ctagSoundProcessorMonoMultiply::GetCStrID() const{
    return CTAGSOUNDPROCESSORMONOMULTIPLY_ID;
}
