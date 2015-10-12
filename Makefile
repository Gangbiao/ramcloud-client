all:upload.o md5.o upload.o  download.o upload download  
upload.o: upload.cc
	g++ -g -fno-strict-aliasing -MD -msse4.2 -DTESTING=1 -fno-builtin -march=core2 -DENABLE_ZOOKEEPER -DINFINIBAND -std=c++0x  -I../install/include/ramcloud -I/usr/local/openonload-201405/src/include -Wall -Wformat=2 -Wextra -Wwrite-strings -Wno-unused-parameter -Wmissing-format-attribute -Wno-non-template-friend -Woverloaded-virtual -Wcast-qual -Wcast-align -Wconversion -Weffc++ -fPIC -c -o upload.o  upload.cc

download.o: download.cc
	g++ -g -fno-strict-aliasing -MD -msse4.2 -DTESTING=1 -fno-builtin -march=core2 -DENABLE_ZOOKEEPER -DINFINIBAND -std=c++0x   -I../install/include/ramcloud -I/usr/local/openonload-201405/src/include   -Wall -Wformat=2 -Wextra -Wwrite-strings -Wno-unused-parameter -Wmissing-format-attribute   -Wno-non-template-friend -Woverloaded-virtual -Wcast-qual -Wcast-align -Wconversion -Weffc++ -fPIC -c -o download.o download.cc

md5.o: md5.c md5.h
	gcc -I. -fPIC -g -O2 -fno-strict-aliasing -fasynchronous-unwind-tables -fno-omit-frame-pointer -fno-optimize-sibling-calls -fvisibility=hidden -Wall -MT md5.o -MD -MP -c -o md5.o md5.c

upload:
	g++ -o upload upload.o md5.o 	../install/lib/ramcloud/libramcloud.a  -L../install/lib/ramcloud   -lzookeeper_mt -lpcrecpp -lboost_program_options  -lprotobuf -lrt -lboost_filesystem -lboost_system -lpthread -lssl -lcrypto -rdynamic

download:
	g++ -o download download.o md5.o    ../install/lib/ramcloud/libramcloud.a  -L../install/lib/ramcloud   -lzookeeper_mt -lpcrecpp -lboost_program_options  -lprotobuf -lrt -lboost_filesystem -lboost_system -lpthread -lssl -lcrypto -rdynamic

clean:
	rm -rf *.o upload download
