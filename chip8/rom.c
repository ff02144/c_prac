#include "rom.h"
#include<stdio.h>
int load_rom(const char *filename, uint8_t *memory,uint16_t load_address){
FILE *fp=fopen(filename,"rb");
if(fp==NULL){return 1;}
fseek(fp,0,SEEK_END);
long filesize=ftell(fp);
if(filesize>3584){return 1;}
rewind(fp);
fread(memory+load_address,1,filesize,fp);
fclose(fp);
	return 0;
}
