#include <napi.h>

namespace functionexample
{
  std::string jwtcpp(Napi::String);
  
  //int add(int a, int b);

  Napi::String jwtcppWrapped(const Napi::CallbackInfo& info);
  //Napi::Number AddWrapped(const Napi::CallbackInfo &info);

  Napi::Object Init(Napi::Env env, Napi::Object exports);

} 