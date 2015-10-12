/*************************************************************************
	> File Name: download.cc
	> Author:Gangbiao.Liu 
	> Mail: lgb.nwpu@gmail.com
	> Created Time: 2015年10月12日 星期一 18时24分01秒
 ************************************************************************/

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>

#include"RamCloud.h"

using namespace std;
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
	Buffer value;
    	client.read(tableId, fileName, strlen(fileName), &value);
        
	/*open an create file to write*/	
	fp = fopen (fileName, "wb");
	if (fp==NULL) {
		fputs ("Open file error\n",stderr); 
		exit (1);
	}

	value.write(0, value.size(), fp);

	//client.createTable(tableName, 1);
	//tableId = client.getTableId(tableName);
}

