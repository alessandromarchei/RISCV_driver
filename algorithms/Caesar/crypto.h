#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


/*THE ENCRYPTION ALGORITHM IS THE COMBINATION OF:
    - CAESER CHIPER algorithm with key
    - TRANSPOSITION : the 8 bytes are permuted in the following order : 0->0, 1->2 , 2->4, 3->6, 4->1, 5->3, 6->5, 7->7
*/

uint64_t encrypt(uint64_t input, int key);		//used to ENCRYPT THE INPUT VALUE
uint64_t decrypt(uint64_t input, int key);		//used to DECRYPT THE INPUT VALUE
