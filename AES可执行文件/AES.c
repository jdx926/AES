#include<stdio.h>
#include"AES.h"

//一下为测试AES-128算法的测试

void expand_key(unsigned char *key, unsigned char *kid_key);
void cipher(unsigned char *input, unsigned char *output, unsigned char *kid_key);
void decrypt(unsigned char *input, unsigned char *output, unsigned char *kid_key);

 
int main()
{
	int i = 0;
	unsigned char temp;
	//用字符串定义一个密钥,输入的明文，输出的密文
	 
//	unsigned char key[] = 
//	{
//		0x00, 0x01, 0x02, 0x03, 
//		0x04, 0x05, 0x06, 0x07, 
//		0x08, 0x09, 0x0a, 0x0b, 
//		0x0c, 0x0d, 0x0e, 0x0f
//	};
//	unsigned char input[] = 
//	{
//		0x00, 0x01, 0x02, 0x03,
//		0x04, 0x05, 0x06, 0x07,
//		0x08, 0x09, 0x0a, 0x0b,
//		0x0c, 0x0d, 0x0e, 0x0f
//	};
	unsigned char input[16];
	unsigned char key[16];
	unsigned char output[16]; 	
	unsigned char *kid_key;
	
	printf("请输入明文信息：\n");
	for(i=0;i<16;i++)
	{
		scanf("%x",&temp);
		input[i] = temp;
	}
		
	printf("请输入密钥信息：\n");
	for(i=0;i<16;i++)
	{
		scanf("%x",&temp);
		key[i] = temp;
	}
		
		
	kid_key = malloc(glen*(rd+1)*4); 
	expand_key(key,kid_key);	//将密钥扩展成子密钥 
	
	printf("明文：\n");
	for(i=0;i<16;i++)
		printf("%x ",input[i]);
	printf("\n"); 

	//扩展子密钥 
	printf("\n扩展子密钥：\n");
	for(i=0;i<176;i++)
	{
		printf("%x ",kid_key[i]);
		if((i+1)%16 == 0)
			printf("\n");
	}
	printf("\n"); 
	
	printf("密文：\n");
	cipher(input,output,kid_key);	//代码加密函数 
	for(i=0;i<16;i++)
		printf("%x ",output[i]);
	printf("\n"); 
	
	
	printf("\n解密后的密文：\n");
	decrypt(output,input,kid_key);	//代码解密函数 
	for(i=0;i<16;i++)
		printf("%x ",input[i]);
	printf("\n");
	
	free(kid_key);
	return 0;
} 
