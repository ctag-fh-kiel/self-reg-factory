#include "ctagSoundProcessor.hpp"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorMonoMultiply : public ctagSoundProcessor{
            public: 
                void Process(const ProcessData &) ;
                ~ctagSoundProcessorMonoMultiply();
                ctagSoundProcessorMonoMultiply();
        };
    }
}