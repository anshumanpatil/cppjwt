#include <napi.h>

namespace methods
{
  Napi::String jwtcppWrapped(const Napi::CallbackInfo& info);
  Napi::String base64_decodeWrapped(const Napi::CallbackInfo &info);
  Napi::Object Init(Napi::Env env, Napi::Object exports);
} 