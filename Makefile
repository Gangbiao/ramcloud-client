all:
	rm -rf file fread fopen test2.txt
	gcc -o file file.c
	gcc -o fread fread.c
	gcc -o fopen fopen.c
