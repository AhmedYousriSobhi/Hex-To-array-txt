#include<stdio.h>
#define CODESIZE 128
int main(int argc, char *argv[])
{
	char tempc, datasize, recorddatasize, recordindex = 0, loopindex=0, flagfirsttime=1, eof=0, stored=0;
	int bytecount1, bytecount2, numofpage=1;
	int arraybytecounter = 0;
	FILE *cfptr_hex;
	FILE *cfptr_txt;
	printf("*Program STARTED*\n");
	if((cfptr_hex = fopen(argv[1],"r")) == NULL)
	{
		printf("*File could not be openned*\n");
	}
	else 
	{
		printf("*Hex File is Openned!!*\n");
		if((cfptr_txt = fopen("OutputArray.txt","w")) == NULL)
			{
				printf("*Could not Create Txt file*\n");
			}
		else
		{	
			printf("*OutputArray.txt is Created*\n");
			printf("*Starting Read Bytes from Hex File*\n");	
			printf("*Checking Hex File*\n");
			fprintf(cfptr_txt,"%s", "{"); /*Starting of the output array*/
			fputc('\n',cfptr_txt); /*new line*/
			/*read bytes from Hex file*/
			while( (fgetc(cfptr_hex) == ':') && (eof == 0) ) 
			{
				recordindex++;
				/*
				printf("*Hex record is Correct number = ");
				printf("%d *\n", recordindex);
				*/
				/*Check Byte Count in Intel Hex Format:
				  assumed only 32 or 16 data byte size is used.*/
				bytecount1 = (fgetc(cfptr_hex) - '0') * 16;
				bytecount2 = fgetc(cfptr_hex) - '0';
				recorddatasize = bytecount1 + bytecount2;
				if(stored == 0) {datasize = recorddatasize;stored =1;} 
				/*printf("DataSize of record = %d\n", recorddatasize);*/
				if(recorddatasize != 0)
				{	
					/*Igonre the coming 6 address and record type bytes*/
					for(loopindex =0; loopindex<6; loopindex++) tempc=fgetc(cfptr_hex);
					/*Reading the data bytes*/
					for(loopindex=0; loopindex<recorddatasize; loopindex++)
					{
						fprintf(cfptr_txt,"%s", " 0x");
						fputc(fgetc(cfptr_hex),cfptr_txt);
						fputc(fgetc(cfptr_hex),cfptr_txt);
						fputc(',', cfptr_txt);
					}
					/*ignore checksum*/
					do{
						tempc = fgetc(cfptr_hex);
					}while(tempc!='\n');
					fputc('\n',cfptr_txt); /*new line*/
					flagfirsttime = 1; /*reset flag*/
				}
				else eof = 1;	
			}
		}
		while(datasize*(recordindex-1) > CODESIZE*numofpage)
		{	
			numofpage++;
		}	
		for(loopindex = 1; loopindex<=(CODESIZE*numofpage - datasize*(recordindex-1)); loopindex++)
			{
				if(CODESIZE*numofpage - datasize*(recordindex-1) - loopindex == 0) fprintf(cfptr_txt,"%s", " 0xFF");
				else fprintf(cfptr_txt,"%s", " 0xFF,");
				//printf("%d\n", loopindex%datasize);
			    if(loopindex%datasize == 0) fputc('\n',cfptr_txt); /*new line*/
			}				
		fprintf(cfptr_txt,"%s","\n};\n\n");
		fprintf(cfptr_txt,"%s","#define CODE_SIZE ");
		fprintf(cfptr_txt,"%d\n",CODESIZE*numofpage);
		fprintf(cfptr_txt,"%s","#define NUM_OF_PAGES ");
		fprintf(cfptr_txt,"%d\n",numofpage);
		fclose(cfptr_txt);
	}
	fclose(cfptr_hex);
	printf("txt File Created SUCCESSFULY!!!\n");
	return 0;
}