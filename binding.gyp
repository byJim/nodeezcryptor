{
  "targets": [
    {
      "target_name": "decryptor",
      "cflags!": [ "-fno-exceptions -static" ],
      "cflags_cc!": [ "-fno-exceptions -static" ],
      "sources": [ "native/decryptor.cc" ],
      "include_dirs": [
        "<!@(node -p \"require('node-addon-api').include\")"
      ],
      'defines': [ 'NAPI_DISABLE_CPP_EXCEPTIONS' ],
      'conditions': [
        ["OS=='linux'", {
          'libraries': [
            '-lcrypto',
            '-lssl'
          ]
        }],
        ["OS=='win'", {
          "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")",
            "C:\Program Files\OpenSSL-Win64\include"
          ],
          "link_settings": {
            "libraries": [
              "C:\Program Files\OpenSSL-Win64\lib\libssl.lib", 
              "C:\Program Files\OpenSSL-Win64\lib\libcrypto.lib"
            ]
          },
        }]
      ]
      
    }
  ]
}