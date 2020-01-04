#include <iostream>
#include "registerer.hpp"

class ctagAudioPlugin {
public:
  virtual ~ctagAudioPlugin() {}
  virtual void Process(const float *, float *) const = 0;
};
