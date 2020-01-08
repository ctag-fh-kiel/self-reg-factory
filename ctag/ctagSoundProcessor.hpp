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
                virtual void Process(const ProcessData &) const = 0; // pure virtual --> must be implemented by derived
                virtual ~ctagSoundProcessor(){};
                bool GetIsStereo(){return isStereo;}
                virtual const unsigned char * GetCStrJSONParamSpecs() const = 0;
                virtual const unsigned char * GetCStrID() const = 0;
            protected:
                bool isStereo = false;
        };
    }
}