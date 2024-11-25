#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int prime(uint64_t n);
void compute_e(uint64_t p,uint64_t q,uint64_t t,uint64_t* e,uint64_t* d);
uint64_t compute_d(uint64_t t, uint64_t x);
uint64_t* enc(uint64_t* msg, uint32_t len, uint64_t key_e,uint64_t n);
uint64_t* dec(uint64_t* msg, uint32_t len, uint64_t key_d, uint64_t n);
uint64_t* encrypt(uint64_t* msg, uint32_t len, uint64_t p, uint64_t q);
uint64_t* decrypt(uint64_t* msg, uint32_t len, uint64_t p, uint64_t q);
uint64_t mod_exp(uint64_t b, uint64_t exp, uint64_t mod);


//PUBLIC KEY = (n,e)    => NEEDED FOR ENCRIPTION
//PRIVATE KEY = (n,d)   => NEEDED FOR DECRYPTION
int main()
{
    uint64_t msg[4] = {99, 105, 97, 111};
    uint64_t p = 829, q = 4003;
    uint64_t* ret = encrypt(msg, 4, p, q);
    printf("encoded message : ");
    for(int i = 0;i < 4;i++)
    {
        printf("%llu ", ret[i]);
    }
    printf("\n");



    ret = decrypt(ret, 4, p, q);
    printf("decoded message : ");
    for(int i = 0;i < 4;i++)
    {
        printf("%llu ", ret[i]);
    }
    printf("\n");
}


uint64_t* encrypt(uint64_t* msg, uint32_t len, uint64_t p, uint64_t q) {

    uint64_t n,t,flag,e[20] = {0} ,d[20] = {0};
    //CHECK IF P AND Q ARE PRIME NUMBERS

	flag=prime(p);
	if(flag==0) {
		exit(1);
	}

	flag=prime(q);
	if(flag==0||p==q) {
		exit(1);
	}

	n=p*q;
	t=(p-1)*(q-1);
    printf("n = %lu\n", n);
	compute_e(p,q,t,e,d);
	printf("e = %lu\n", e[5]);
	return enc(msg,len,e[5],n);
}

uint64_t* decrypt(uint64_t* msg, uint32_t len, uint64_t p, uint64_t q) {

    //CHECK IF P AND Q ARE PRIME NUMBERS
    uint64_t n,t,flag,e[20] = {0} ,d[20] = {0};
	flag=prime(p);
	if(flag==0) {
		exit(1);
	}
	flag=prime(q);
	if(flag==0||p==q) {
		exit(1);
	}

	n=p*q;
	t=(p-1)*(q-1);
	compute_e(p,q,t,e,d);
	printf("d = %d\n", d[5]);
	return dec(msg,len,d[5],n);
}


int prime(uint64_t n) {
	uint64_t i,j;
	j=sqrt(n);
	for (i=2;i<=j;i++) {
		if(n%i==0)
		    return 0;
	}
	return 1;
}
void compute_e(uint64_t p,uint64_t q,uint64_t t,uint64_t* e,uint64_t* d) {

	uint64_t k,flag,i;
	k=0;
	for (i=2;i<t;i++) {
		if(t%i==0)
		    continue;
		flag=prime(i);
		if(flag==1&&i!=p&&i!=q) {
			e[k]=i;
			flag=compute_d(t, e[k]);
			if(flag>0) {
				d[k]=flag;
				k++;
			}
			if(k==20)
			        break;
		}
	}

}
uint64_t compute_d(uint64_t t, uint64_t x) {
	uint64_t k=1;
	while(1) {
		k=k+t;
		if(k%x==0)
		    return(k/x);
	}
}
uint64_t* enc(uint64_t* msg, uint32_t len, uint64_t key_e,uint64_t n) {

    uint64_t* en = malloc(len * sizeof(uint64_t));
	uint64_t i=0;

	for (i = 0; i < len; ++i) {
        en[i] = mod_exp(msg[i], key_e, n);
    }
    return en;

}
uint64_t* dec(uint64_t* msg, uint32_t len, uint64_t key_d, uint64_t n) {
	uint64_t* out_dec = malloc(len * sizeof(uint64_t));
	uint64_t i;
	for (i = 0; i < len; ++i) {
        out_dec[i] = mod_exp(msg[i], key_d, n);
    }
    return out_dec;
}

uint64_t mod_exp(uint64_t b, uint64_t exp, uint64_t mod) {
    uint64_t result = 1;
    b = b % mod;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * b) % mod;
        }

        exp = exp >> 1;
        b = (b * b) % mod;
    }

    return result;
}
