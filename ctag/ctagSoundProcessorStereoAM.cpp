#include "ctagSoundProcessorStereoAM.hpp"
#include "ctagSoundProcessorStereoAM_JSN.h"
#include <iostream>

using namespace CTAG::SP;

ctagSoundProcessorStereoAM::ctagSoundProcessorStereoAM()
{
    std::cout << "Constructor " << CTAGSOUNDPROCESSORSTEREOAM_ID << std::endl;
    isStereo = CTAGSOUNDPROCESSORSTEREOAM_ISSTEREO;
}

void ctagSoundProcessorStereoAM::Process(const ProcessData &data) const{
    for(uint32_t i=0;i<data.bufSize; i++){
        data.buf0[i] = (float)i;
        data.buf1[i] = (float)i;
    }
}

ctagSoundProcessorStereoAM::~ctagSoundProcessorStereoAM(){
    std::cout << "Destructor " << CTAGSOUNDPROCESSORSTEREOAM_ID << std::endl;
}

const unsigned char * ctagSoundProcessorStereoAM::GetCStrJSONParamSpecs() const{
    return CTAGSOUNDPROCESSORSTEREOAM_JSN;
}

const unsigned char * ctagSoundProcessorStereoAM::GetCStrID() const{
    return CTAGSOUNDPROCESSORSTEREOAM_ID;
}
