#include "ctagAudioPlugin.hpp"
#include <iostream>

class ctagAudioPluginFM : public ctagAudioPlugin{
    REGISTER("ctagAudioPluginFM", ctagAudioPlugin);
public: 
  void Process(const float *, float *) const override; 
  ctagAudioPluginFM();
  ~ctagAudioPluginFM();
};