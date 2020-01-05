#include "ctagSoundProcessor.hpp"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorStereoAM : public ctagSoundProcessor{
            public: 
                void Process(const ProcessData &) ;
                ~ctagSoundProcessorStereoAM();
                ctagSoundProcessorStereoAM();
        };
    }
}