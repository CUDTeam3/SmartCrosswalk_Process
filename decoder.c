#include <stdio.h>

#define DATASIZE 8

unsigned short decodedData[DATASIZE] = { 0, };

/*
DATE : 2016.11.08
PARM : int encodedInt - Data which encoded in unsigned integer but accpetable as integer to check the data is less than 0.
DESC : Translate the encoded data in intger to binary array. LSB(Least Significan Bit) starts from right. The size of decoded data can manipulate by predifined value.
*/
void decoding(int encodedInt) {
	unsigned int i, unsignedEncodedInt;
	if (encodedInt < 0) // Check the given encodedInt has less than 0 value. This will give a warning.
		printf("Given encodedInt is less than \'0\' vlaue, this causes unexpected error in deocding.\n");
	
	unsignedEncodedInt = (unsigned int)encodedInt;

	for (i = 0; i < DATASIZE; i++) // Flush the remaining previous data.
		decodedData[i] = 0;
	
	for (i = 0; i < DATASIZE; i++) { // Transfrom encoded data to binary expression.
		decodedData[DATASIZE-1-i] = unsignedEncodedInt % 2;
		unsignedEncodedInt >>= 1;
	}
}

/*
DATE : 2016.11.08
DESC : print out the decoded data 
*/
void printData() {
	unsigned int i;
	for (i = 0; i < DATASIZE; i++)
		printf("%u", decodedData[i]);
	printf("\n");
}


// Main procedures in this program
int main(int argc, char ** argv) {
	decoding(10);
	printData();


	return 0;
}
