#include <napi.h>
#include <iostream>
#include "decryptor.h"

Napi::Value napiGetKey(const Napi::CallbackInfo& info) {
    Napi::Env env = info.Env();

    std::string trackIdArg = info[0].As<Napi::String>().Utf8Value();
    char* trackId = new char[trackIdArg.length() + 1];
    strcpy(trackId, trackIdArg.c_str());

    char key[16];
    getKey(trackId, key);
    return Napi::String::New(env, key, 16);
}

void napiDecryptFile(const Napi::CallbackInfo& info) {
    std::string decKeyArg = info[0].As<Napi::String>().Utf8Value();
    char* decKey = new char[17];
    strcpy(decKey, decKeyArg.c_str());

    std::string inputFn = info[1].As<Napi::String>().Utf8Value();
    std::string outputFn = info[2].As<Napi::String>().Utf8Value();
    std::cout << inputFn;
    decryptFile(decKey, inputFn.c_str(), outputFn.c_str());
    
    return;
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set(Napi::String::New(env, "getKey"), Napi::Function::New(env, napiGetKey));
    exports.Set(Napi::String::New(env, "decryptFile"), Napi::Function::New(env, napiDecryptFile));
    return exports;
}

NODE_API_MODULE(decryptor, Init)