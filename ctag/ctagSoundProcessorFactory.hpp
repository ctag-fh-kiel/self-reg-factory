#pragma once
#include <memory>
#include <iostream>
#include <string>
#include "ctagSoundProcessor.hpp"
#include "ctagSoundProcessors.h"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorFactory{
            public:
                static std::unique_ptr<ctagSoundProcessor> Create(const std::string type){
                        if(type.compare("abd") == 0) return std::make_unique<ctagSoundProcessorMonoMultiply>();
                        return nullptr;
                    }
        };
    }
}