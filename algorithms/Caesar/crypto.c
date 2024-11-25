#include <crypto.h>

uint64_t encrypt(uint64_t input, int key) {

    uint8_t inp_byte[8],tmp[8];
    uint64_t output = 0;

    //splitting the 64 bit number into a string of 8 unsigned int
    for(int i = 0;i < 8;i++)
    {
        inp_byte[i] = (uint8_t)(input & 0xFF);
        input >>= 8;
    }

    //APPLYING THE KEY TO EACH OF THE CHARS
    for(int i = 0;i < 8;i++)
    {
        inp_byte[i] += key;
    }

    //creating temporary array to store the values
    for(int i = 0;i < 8;i++)
    {
        tmp[i] = inp_byte[i];
    }

    //TRANSPOSING PHASE WITH NUMBER OF COLUMNS = 4
    inp_byte[1] = tmp[4];
    inp_byte[2] = tmp[1];
    inp_byte[3] = tmp[5];
    inp_byte[4] = tmp[2];
    inp_byte[5] = tmp[6];
    inp_byte[6] = tmp[3];

    //reconverting back to UINT_64t format
    for (int i = 0; i < 8; i++) {
        output = (output << 8) | inp_byte[i];
    }

    return output;
}


uint64_t decrypt(uint64_t input, int key) {

    uint8_t inp_byte[8],tmp[8];
    uint64_t output = 0;

    //splitting the 64 bit number into a string of 8 unsigned int
    for(int i = 0;i < 8;i++)
    {
        inp_byte[i] = (uint8_t)(input & 0xFF);
        input >>= 8;
    }

    //creating a temporary array
    for(int i = 0;i < 8;i++)
    {
        tmp[i] = inp_byte[i];
    }


    //DETRANSPOSITION
    inp_byte[1] = tmp[2];
    inp_byte[2] = tmp[4];
    inp_byte[3] = tmp[6];
    inp_byte[4] = tmp[1];
    inp_byte[5] = tmp[3];
    inp_byte[6] = tmp[5];


    //INVERSE SUBSTITUTION
    for(int i = 0;i < 8;i++)
    {
        inp_byte[i] -= key;
    }

    //reconverting back to UINT_64t format
    for (int i = 0; i < 8; i++) {
        output = (output << 8) | inp_byte[i];
    }

    return output;
}


/*	EXAMPLE CODE

int main() {
    // Example 64-bit input number as 8 bytes (8 ASCII characters)
    uint64_t n_plain = 0x1122334455667788;
    uint64_t n_enc,n_inv;

    // Display the original input
    printf("Original Input: 0x%llx\n", n_plain);

    // Specify the rotation key for Caesar cipher
    int key = +10;

    n_enc = caesarCipher_dir(n_plain, key);
    // Encrypt the input using Caesar cipher
    printf("Encrypted Input: 0x%llx\n", n_enc);

    n_inv = caesarCipher_inv(n_enc, key);
    // Encrypt the input using Caesar cipher
    printf("Restored Input: 0x%llx\n", n_inv);

    return 0;
}
*/
