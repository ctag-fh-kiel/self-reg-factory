#include "ctagSoundProcessor.hpp"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorStereoAM : public ctagSoundProcessor{
            public: 
                virtual void Process(const ProcessData &) const;
                virtual ~ctagSoundProcessorStereoAM();
                ctagSoundProcessorStereoAM();
                virtual const unsigned char * GetCStrJSONParamSpecs() const;
                virtual const unsigned char * GetCStrID() const;
        };
    }
}