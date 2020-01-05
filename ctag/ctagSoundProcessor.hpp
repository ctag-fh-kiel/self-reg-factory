// Base class for sound processors

#pragma once
#include <stdint.h>

namespace CTAG{
    namespace SP{
        struct ProcessData{
            float *buf0, *buf1;
            uint16_t *control;
            uint8_t *trig0, trig1;
            uint32_t bufSize;
        };
        class ctagSoundProcessor{
            public:
                virtual void Process(const ProcessData &) = 0;
                virtual ~ctagSoundProcessor(){};
                bool GetIsStereo(){return isStereo;}
            protected:
                bool isStereo = false;
        };
    }
}