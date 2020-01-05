#pragma once
#include <memory>
#include "ctagSoundProcessor.h"
#include "ctagSoundProcessors.h"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorFactory{
            public:
                static std::unique_ptr<ctagSoundProcessor> Create()
        };
    }
}