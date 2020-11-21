#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <alloca.h>
#define TAMANHO 128
#define TAMANHOTOTAL 256
#define SIZE 128
#define ADRESS 0xFFFF
#define OFFSET 0xFF

int pageTableNumbers[SIZE];
int pageTableFrames[SIZE];
int phisica[TAMANHOTOTAL][TAMANHO];

int Faults = 0;
int primeiroframe = 0;
int primeiroframenumber = 0;
#define BUFFER_SIZE 10
#define CHUNK 128
FILE *addresses;
FILE *BACKING_STORE;
FILE *output;
char address[BUFFER_SIZE];
int logical_address;
signed char buffer[CHUNK];
signed char value;
void getPage(int address);
void Ler(int pageNumber);
void getPage(int logical_address){
    int pageNumber = ((logical_address & ADRESS)>>8);
    int offset = (logical_address & OFFSET);
        int i;  
        for(i = 0; i < primeiroframenumber; i++){
        }
        Ler(pageNumber);             
        Faults++;                          
printf("offset: %d\n", offset); 
}
void Ler(int pageNumber){
    int i;
    for(i = 0; i < CHUNK; i++){
        phisica[primeiroframe][i] = buffer[i];
    }
    pageTableNumbers[primeiroframenumber] = pageNumber;
    pageTableFrames[primeiroframenumber] = primeiroframe;
    primeiroframe++;
    primeiroframenumber++;
}
int main(int argc, char *argv[])
{
    double pfRate;
    if (argc != 2) {
        return -1;
    }
    BACKING_STORE = fopen("BACKING_STORE.bin", "rb");
    if (BACKING_STORE == NULL) {
        return -1;
    }
    addresses = fopen(argv[1], "r");
    if (addresses == NULL) {
        return -1;
    }
    int numberOfTranslatedAddresses = 0;
    while ( fgets(address, BUFFER_SIZE, addresses) != NULL) {
        logical_address = atoi(address);
        getPage(logical_address);
        numberOfTranslatedAddresses++;       
    }
    printf("Page Faults = %d\n", Faults);
    printf("Number of translated addresses = %d\n", numberOfTranslatedAddresses);
    output = fopen(numberOfTranslatedAddresses, "w");
    fclose(addresses);
    fclose(output);
    fclose(BACKING_STORE);
    return 0;
}