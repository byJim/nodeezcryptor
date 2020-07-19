# nodeezcryptor

## Instalation

### Linux:

Install your OS openssl libraries. (`apt install libssl-dev` on Ubuntu)

### Windows:

You have to install OpenSSL to `C:\Program Files\OpenSSL-Win64`
It is recomended to use installer from: https://slproweb.com/products/Win32OpenSSL.html and keep the default path.

## package.json:
    "nodeezcryptor": "git+https://notabug.org/xefglm/nodeezcryptor.git#master"

## Example:

    const decryptor = require('decryptor');

    //Get Key:
    decryptor.getKey("trackID");

    //Decrypt File:
    decryptor.decryptFile("key", "inputFilename", "outputFilename");