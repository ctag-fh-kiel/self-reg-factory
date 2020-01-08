#include <iostream>
#include <memory>
#include "ctagSoundProcessor.hpp"
#include "ctagSoundProcessorFactory.hpp"

using namespace CTAG::SP;

int main()
{
    std::unique_ptr<ctagSoundProcessor> processor = ctagSoundProcessorFactory::Create("abd");
    
    std::cout << "isStereo: " << processor->GetIsStereo() << std::endl;

    ProcessData data;
    float b0[32], b1[32];
    data.buf0 = b0;
    data.buf1 = b1;
    data.bufSize = 32;
    processor->Process(data);
    for(int i=0;i<32;i++){
        std::cout << "Value " << data.buf0[i] << " " << data.buf1[i] << std::endl;
    }

    printf("%s, %s\n", processor->GetCStrID(), processor->GetCStrJSONParamSpecs());
    
    return 0;
}