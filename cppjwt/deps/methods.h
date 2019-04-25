#include <napi.h>


namespace methods
{
  std::string jwtcpp(std::string);
  std::vector<std::string> splitjwt(const std::string &s, char delimiter);
  //int add(int a, int b);

  Napi::String jwtcppWrapped(const Napi::CallbackInfo& info);
  //Napi::Number AddWrapped(const Napi::CallbackInfo &info);

  Napi::Object Init(Napi::Env env, Napi::Object exports);

} 