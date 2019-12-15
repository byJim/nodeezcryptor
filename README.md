# nodeezcryptor

## package.json:
    "nodeezcryptor": "git+https://notabug.org/xefglm/nodeezcryptor.git#master"

## Example:

    const decryptor = require('decryptor');

    //Get Key:
    decryptor.getKey("trackID");

    //Decrypt File:
    decryptor.decryptFile("key", "inputFilename", "outputFilename");