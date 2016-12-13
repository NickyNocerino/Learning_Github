#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[])
{
	int i; 
	int *encrypt = (int*)malloc(sizeof(int)*4); 
	int *key =  (int*)malloc(sizeof(int)*4); 
	char convert_hex[3]; 
	int temp, temp2;
if (argc != 3 && strlen(argv[1]) != 8 && strlen(argv[2]) != 8) 
{ 
	printf("usage: program.exe message_as_hex_8digitskey_as_hex_8digits\n"); 
	exit(-1);
}
convert_hex[2] = '\0'; 
for (i = 0; i < 4; i ++) 
{
	convert_hex[0] = argv[1][i*2]; 
	convert_hex[1] = argv[1][i*2+1]; 
	encrypt[i] = (int)strtol(convert_hex, NULL, 16); 
	convert_hex[0] = argv[2][i*2]; 
	convert_hex[1] = argv[2][i*2+1]; 
	key[i] = (int)strtol(convert_hex, NULL, 16);
}
for (i = 0; i < 4; i++) 
{
	encrypt[i] = encrypt[i] ^ key[i];
} 
printf("xor1 %02x%02x%02x%02x\n",encrypt[0],encrypt[1],encrypt[2],encrypt[3]); // means print with 2 digits
temp = encrypt[0]; 
temp2 = encrypt[1]; 
encrypt[0] = encrypt[2]; 
encrypt[2] = temp; 
encrypt[1] = encrypt[3]; 
encrypt[3] = temp2; 
printf("swap %02x%02x%02x%02x\n",encrypt[0],encrypt[1],encrypt[2],encrypt[3]); // means print with 2 digits
for (i = 0; i < 4; i++) 
{
	encrypt[i] = encrypt[i] ^ key[i];
} 
printf("xor2 %02x%02x%02x%02x\n",encrypt[0],encrypt[1],encrypt[2],encrypt[3]); // means print with 2 digits
printf("encrypted as int %02x%02x%02x%02x\n",encrypt[0],encrypt[1],encrypt[2],encrypt[3]); // means print with 2 digits
return 0;
}