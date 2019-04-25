#include "methods.h"
#include <sstream> // std::istringstream
#include <string>
#include <vector>
#include <iostream>

std::string methods::jwtcpp(std::string val)
{
    return val;
}

Napi::String methods::jwtcppWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String first = info[0].As<Napi::String>();
    //methods::splitjwt(first, ".");
    Napi::String returnValue = Napi::String::New(env, methods::jwtcpp(first));

    return returnValue;
}

std::vector<std::string> methods::splitjwt(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// int methods::add(int a, int b)
// {
//     return a + b;
// }

// Napi::Number methods::AddWrapped(const Napi::CallbackInfo& info) {
//     Napi::Env env = info.Env();
//     if (info.Length() < 2 || !info[0].IsNumber() || !info[1].IsNumber()) {
//         Napi::TypeError::New(env, "Number expected").ThrowAsJavaScriptException();
//     }

//     Napi::Number first = info[0].As<Napi::Number>();
//     Napi::Number second = info[1].As<Napi::Number>();

//     int returnValue = methods::add(first.Int32Value(), second.Int32Value());

//     return Napi::Number::New(env, returnValue);
// }

Napi::Object methods::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("jwtcpp", Napi::Function::New(env, methods::jwtcppWrapped));
    //exports.Set("add", Napi::Function::New(env, methods::AddWrapped));
    return exports;
}