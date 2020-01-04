#include "ctagAudioPlugin.hpp"
#include <iostream>

class ctagAudioPluginFM : public ctagAudioPlugin{
    REGISTER("ctagAudioPluginFM", ctagAudioPlugin);
public: 
  void Process() const override; 
  ctagAudioPluginFM();
  ~ctagAudioPluginFM();
};