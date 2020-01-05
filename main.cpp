#include <iostream>
#include <memory>
#include "ctagSoundProcessor.hpp"
#include "ctagSoundProcessorStereoAM.hpp"

using namespace CTAG::SP;

int main()
{
    std::unique_ptr<ctagSoundProcessor> res( new ctagSoundProcessorStereoAM());
    
    ProcessData data;
    float b0[32], b1[32];
    data.buf0 = b0;
    data.buf1 = b1;
    data.bufSize = 32;
    res->Process(data);
    for(int i=0;i<32;i++){
        std::cout << "Value " << data.buf0[i] << " " << data.buf1[i] << std::endl;
    }
    
    return 0;
}