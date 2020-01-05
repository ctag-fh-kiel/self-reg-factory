#pragma once
#include <memory>
#include <string>
#include "ctagSoundProcessor.hpp"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorFactory{
            public:
                enum SoundProcessorIDs{
                    none,
                    am
                };
                static std::unique_ptr<ctagSoundProcessor> Create(const SoundProcessorIDs &id){
                    switch(id){
                        case none: return nullptr;
                        default: return nullptr;
                    }
                }
        };
    }
}