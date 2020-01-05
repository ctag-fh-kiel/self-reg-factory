#include "ctagSoundProcessor.hpp"

namespace CTAG{
    namespace SP{
        class ctagSoundProcessorMonoMultiply : public ctagSoundProcessor{
            public: 
                virtual void Process(const ProcessData &) const;
                virtual ~ctagSoundProcessorMonoMultiply();
                ctagSoundProcessorMonoMultiply();
        };
    }
}