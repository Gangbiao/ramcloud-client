/*************************************************************************
	> File Name: upload.cc
	> Author: Gangbiao Liu 
	> Mail: lgb.nwpu@gmail.com
	> Created Time: Sat 10 Oct 2015 01:20:30 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include"RamCloud.h"

using namespace RAMCloud;

int main(int argc, char **argv){
	if (argc < 3) {
		printf("usage: %s <file name>  <table name>\n", argv[0]);
		return 1;     
	}
	long retval, lSize; //lSize is the length of file in byte
	char *fileName = argv[1];
	char *tableName = argv[2];

	FILE *fp;
	char *buffer;

	/*client here connect to the default service locator*/
	char *serviceLocator = "tcp:host=10.22.91.246,port=11100";
	char *clusterName = "main";
	RamCloud client(serviceLocator, clusterName);

	/*get table ID according the table name*/
	uint64_t tableId, length;
	client.createTable(tableName, 1);
	//tableId = client.getTableId(tableName);
	//printf("%s\n%s\n", fileName, tableName);
	/*open file */    
	fp = fopen (fileName, "rb" );
	if (fp==NULL) {
		fputs ("Open file error\n",stderr); 
		exit (1);
	}

	/*obtain file size:*/
	fseek (fp , 0 , SEEK_END);
	lSize = ftell (fp);
	rewind (fp);
	// allocate memory to contain the whole file:
	buffer = (char*) malloc (sizeof(char)*lSize);
	if (buffer == NULL) {
		fputs ("Allocate memory error\n",stderr); 
		exit (2);
	}

	/*copy the file into the buffer*/
	retval = fread (buffer,1,lSize,fp);
	//printf("%ld\n%ld\n", retval, lSize);
	if (retval != lSize) {
		fputs ("Reading file error\n",stderr); 
		exit (3);
	}
	/*the whole file is now loaded in the memory buffer. */
	fclose(fp);

	/*upload the file to ramcloud*/
	tableId = client.getTableId(tableName);
	client.write(tableId, fileName, strlen(fileName), buffer, lSize);
	free(buffer);

	return 0;
}
