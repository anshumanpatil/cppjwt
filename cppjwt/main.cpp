#include <napi.h>
#include "deps/functionexample.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports) {
  //return exports;
  return functionexample::Init(env, exports);
}

NODE_API_MODULE(jwtAddon, InitAll)
