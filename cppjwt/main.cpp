#include <napi.h>
#include "deps/methods.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  return methods::Init(env, exports);
}

NODE_API_MODULE(jwtAddon, InitAll)
