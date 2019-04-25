#include "methods.h"
#include "base64_decode/decode.h"
#include <sstream>
#include <string>
#include <iostream>

std::string methods::jwtcpp(std::string val)
{
    std::istringstream f(val);
    std::string s;
    std::string found;
    int ii = 0;
    while (std::getline(f, s, '.')) {
        ii++;
        if(ii==2){
            found = s;
        }
    }
    
    return base64_decode(found);
}

Napi::String methods::jwtcppWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String first = info[0].As<Napi::String>();
    Napi::String returnValue = Napi::String::New(env, methods::jwtcpp(first));
    return returnValue;
}

Napi::String methods::base64_decodeWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String first = info[0].As<Napi::String>();
    Napi::String returnValue = Napi::String::New(env, base64_decode(first));
    return returnValue;
}

Napi::Object methods::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("jwtcpp", Napi::Function::New(env, methods::jwtcppWrapped));
    exports.Set("base64_decode", Napi::Function::New(env, methods::base64_decodeWrapped));
    return exports;
}