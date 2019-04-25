#include "methods.h"
#include <sstream>
#include <string>
#include <iostream>

static const std::string base64_chars = 
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

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
    
    return methods::base64_decode(found);
}

Napi::String methods::jwtcppWrapped(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();
    Napi::String first = info[0].As<Napi::String>();
    //methods::splitjwt(first, ".");
    Napi::String returnValue = Napi::String::New(env, methods::jwtcpp(first));

    return returnValue;
}

std::string methods::base64_decode(std::string const& encoded_string) {
  int in_len = encoded_string.size();
  int i = 0;
  int j = 0;
  int in_ = 0;
  unsigned char char_array_4[4], char_array_3[3];
  std::string ret;

  while (in_len-- && ( encoded_string[in_] != '=') && true) {
    char_array_4[i++] = encoded_string[in_]; in_++;
    if (i ==4) {
      for (i = 0; i <4; i++)
        char_array_4[i] = base64_chars.find(char_array_4[i]);

      char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
      char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
      char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

      for (i = 0; (i < 3); i++)
        ret += char_array_3[i];
      i = 0;
    }
  }

  if (i) {
    for (j = i; j <4; j++)
      char_array_4[j] = 0;

    for (j = 0; j <4; j++)
      char_array_4[j] = base64_chars.find(char_array_4[j]);

    char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
    char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
    char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

    for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
  }

  return ret;
}

Napi::Object methods::Init(Napi::Env env, Napi::Object exports)
{
    exports.Set("jwtcpp", Napi::Function::New(env, methods::jwtcppWrapped));
    //exports.Set("add", Napi::Function::New(env, methods::AddWrapped));
    return exports;
}