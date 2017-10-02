#include <stdlib.h>
#include <stdio.h>
#include "tables.h"
#include "bool.h"

void bitsCopy(bool *dataOut,bool *dataIn,int num);
void bitToHex(char *dataOut,bool *dataIn,int num);
void keyInBit(bool *keyOut, char* keyIn, int num);
void BitToKey(char *keyOut, bool* keyIn, int num);
void tableP(bool* dataOut, bool* dataIn, const char* table, int num);
void circulate(bool* dataIn, int len, int num);
void Xor(bool* dataA, bool* dataB, int num);

void sBox(bool dataOut[32], bool dataIn[32]);
void textExpand(bool dataIn[32], bool dataI[48]);
void setKey(char key[8]);
void desEncrypt(char dataOut[8], char dataIn[8]); //加密
void desDecrypt(char dataOut[8], char dataIn[8]); //解密

int main() {
	char *key[8] = {0};
	int i = 0; 
	char temp[1];
	char publicText[8] = {0};
	char textInHex[16] = {'a', 'b', 'c', 'd', 'e', 'f', 'g'};
	char tempKey[8] = {0};
	// printf("%c ", textInHex[1]);
	// printf("Input your text\n");
	gets(publicText);
	//gets(temp);
	gets(key);
	// printf("Input your key\n");
	//gets(key);
	setKey(key);
	// printf("aaaaa\n");
	desEncrypt(textInHex, publicText);
	// printf("%c ", textInHex[0]);
	// printf("%c ", textInHex[1]);
	// printf("%c ", textInHex[2]);
	// printf("%c ", textInHex[3]);
	// printf("%c ", textInHex[4]);
	// printf("%c ", textInHex[5]);
	// printf("%c ", textInHex[6]);
	// printf("aaa:\n");
	 for(i = 0; i < 16; i++) {
	 	printf("%c", textInHex[i]);
	 }
	// desDecrypt(publicText, textInHex);
	// for( i = 0; i < 8; i++) {
	// 	printf("%c ", publicText[i]);
	// }
}

void bitsCopy(bool *dataOut,bool *dataIn,int num) {
	int i=0;
	for(i = 0; i < num;i++) {
		dataOut[i]= dataIn[i];
	}
}

void bitToHex(char *dataOut,bool *dataIn,int num) {
	int i = 0;
	for(i = 0; i < num / 4; i++) {
		dataOut[i]=0;
	}
	for(i=0;i<num/4;i++) {
		dataOut[i] = dataIn[i*4]+(dataIn[i*4+1]<<1)
					+(dataIn[i*4+2]<<2)+(dataIn[i*4+3]<<3);
		if((dataOut[i]%16)>9) {
			dataOut[i]=dataOut[i]%16+'7';
		}                                   
		else {
			dataOut[i]=dataOut[i]%16+'0'; 
		}
	}
	
}

void keyInBit(bool *keyOut, char* keyIn, int num) {
	int i = 0;
	for(i = 0; i < num; i++) {
		keyOut[i]=(keyIn[i/8]>>(i%8))&0x01;   
	}
}

void circulate(bool *dataIn, int len, int num) {
	static bool temp[256];
	bitsCopy(temp, dataIn, num);
	bitsCopy(dataIn, dataIn + num, len - num);
	bitsCopy(dataIn+len-num, temp, num);
}

void tableP(bool *dataOut, bool *dataIn, const char *table, int num) {
	int i = 0;
	static bool temp[256] = {0};
	for(i = 0; i < num; i++) {
		temp[i] = dataIn[table[i]-1];
	}
	bitsCopy(dataOut, temp, num);
}

void setKey(char key[8]) {
	int i = 0;
	static bool arrKIB[64] = {0};
	static bool *leftK = &arrKIB[0], *rightK = &arrKIB[28];
	keyInBit(arrKIB, key, 64);
	tableP(arrKIB, arrKIB, PC1_Table, 56);
	for(i = 0; i < 16; i++) {
		circulate(leftK, 28, compression_table[i]);
		circulate(rightK, 28, compression_table[i]);
		tableP(subkey[i], arrKIB, PC2_Table, 48);
	}
}

void Xor(bool* dataA, bool* dataB, int num) {
	int i = 0;
	for(i = 0;i < num; i++) {
		dataA[i]=dataA[i]^dataB[i];         
	}
} 

void sBox(bool dataOut[32], bool dataIn[32]) {
	int i,X,Y;                                     
	for(i = 0, Y = 0, X = 0; i < 8; i++, dataIn += 6, dataOut+=4) {    										  
		Y=(dataIn[0] << 1) + dataIn[5];
		X=(dataIn[1] << 3) + (dataIn[2] << 2) + (dataIn[3] << 1) + dataIn[4]; 
		keyInBit(dataOut, &S_Box[i][Y][X],4);	
	}
}

void textExpand(bool dataIn[32], bool dataI[48]) {
	static bool rightText[48]={0};
	tableP(rightText, dataIn, E_Table, 48);
	Xor(rightText, dataI,48);
	sBox(dataIn,rightText);
	tableP(dataIn,dataIn,P_Table,32);
}

void desEncrypt(char dataOut[8], char dataIn[8]) {
	int i=0;
	static bool textBit[64]={0};        
	static bool temp[32]={0};
	static bool *leftText = &textBit[0], *rightText = &textBit[32];
	keyInBit(textBit, dataIn,64);                 
	tableP(textBit, textBit, IP_Table, 64);    
	for(i = 0; i < 16; i++) {
		bitsCopy(temp, rightText, 32);            
		textExpand(rightText, subkey[i]);          
		Xor(rightText, leftText, 32);                 
		bitsCopy(leftText, temp, 32);       
	}					
	tableP(textBit,textBit,IPR_Table,64);
	bitToHex(dataOut, textBit, 64);
}