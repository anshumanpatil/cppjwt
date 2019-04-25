#include <napi.h>


namespace methods
{
  std::string jwtcpp(std::string);
  std::string base64_decode(std::string const& encoded_string);
  //int add(int a, int b);

  Napi::String jwtcppWrapped(const Napi::CallbackInfo& info);
  //Napi::String base64_decodeWrapped(const Napi::CallbackInfo &info);

  Napi::Object Init(Napi::Env env, Napi::Object exports);

} 