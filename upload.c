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
    
    char *fileName = argv[1];
    char *tableName = argv[2];
    uint64_t tableId;
    tableId = getTableId (tableName);
    FILE *fp;
    char *buffer;
    size_t length, retval;
    fp = fopen();
    
}
