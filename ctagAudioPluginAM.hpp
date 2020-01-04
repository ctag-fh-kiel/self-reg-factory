#include "ctagAudioPlugin.hpp"
#include <iostream>

class ctagAudioPluginAM : public ctagAudioPlugin{
    REGISTER("ctagAudioPluginAM", ctagAudioPlugin);
public: 
  void Process(const float *, float *) const override; 
  ctagAudioPluginAM();
  ~ctagAudioPluginAM();
};