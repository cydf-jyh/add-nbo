#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <netinet/in.h>

union Value{
	uint8_t buffer[4];
	uint32_t num;
};
	
int main(int argc, char *argv[])
{
	FILE *fp1=fopen(argv[1],"r"),*fp2=fopen(argv[2],"r");	
	union Value a,b;
	fread(a.buffer,sizeof(int),1,fp1);
	a.num=ntohl(a.num);
	fread(b.buffer,sizeof(int),1,fp2);
	b.num=ntohl(b.num);	
	printf("%d(0x%x) + %d(0x%x) = %d(0x%x)",a.num,a.num,b.num,b.num,a.num+b.num,a.num+b.num);
	fclose(fp1);
	fclose(fp2);
	return 0;
}
