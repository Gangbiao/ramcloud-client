/*************************************************************************
	> File Name: upload.c
	> Author: Gangbiao Liu 
	> Mail: lgb.nwpu@gmail.com
	> Created Time: Sat 10 Oct 2015 01:20:30 PM EDT
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
int main(int argc, char **argv){
	if (argc < 3) {
		printf("usage: %s <file name>  <table name>\n", argv[0]);
		rturn 1;     
	}
	int retval, lSize; //lSize is the length of file in byte
	char *fileName = argv[1];
	char *tableName = argv[2];

	/*get table ID according the table name*/
	uint64_t tableId length;
	tableId = getTableId (tableName);

	/*open file */    
	FILE *fp;
	char *buffer;
	fp = fopen (fileName, "rb" );
	if (pFile==NULL) {
		fputs ("File error",stderr); 
		exit (1);
	}

	/*copy the file into the buffer*/
	retval = fread (buffer,1,lSize,fp);
	if (retval != lSize) {
		fputs ("Reading error",stderr); 
		exit (3);
	}
	/*the whole file is now loaded in the memory buffer. */
	fclose(fp);
    
}
