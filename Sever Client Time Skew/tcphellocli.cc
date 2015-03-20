/*
 *	tcphellocli.cc
 */
/* Description */
/* 
 * A TCP'ed "hello, world" client program 
 */


#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <sstream>
#include <cstring>
#include <stdio.h>
#include <sys/time.h>
#include <sys/stat.h>

using namespace std;

int main(int argc, char *argv[])
{

struct timeval t;
  
  gettimeofday(&t, NULL);

  int time;
  int i;

  time = (t.tv_sec *1000000) + t.tv_usec;

  
	int clifd = -1, msglen, portnum;
	struct sockaddr_in svraddr;
	char msgbuf[2048];
	std::stringstream ss(std::stringstream::in | std::stringstream::out);

	if (argc < 3) {
		std::cout << "Usage: " << argv[0] 
			<< " server_ip_address port_number" << std::endl;
		return 0;
	}

	ss << argv[2];
	ss >> portnum;

	clifd = socket(AF_INET, SOCK_STREAM, 0);
	if (clifd < 0) {
		std::cerr << argv[0] << ": socket(SOCKET_STREAM): "
			<< strerror(errno) << std::endl; 
		goto cleanup;
	}

	svraddr.sin_family = AF_INET;
	svraddr.sin_port = htons(portnum);
	if (!inet_aton(argv[1], &svraddr.sin_addr)) {
		std::cerr << argv[0] << ": inet_aton(): " << argv[1]
			<< " is not a valid IP address."  << std::endl;
		goto cleanup;
	}

	if (connect(clifd, (struct sockaddr*)&svraddr,
				sizeof(struct sockaddr_in)) < 0) {
		std::cerr << argv[0] 
			<< ": connect(): " << strerror(errno) << std::endl;
		goto cleanup;
	}

	for(i=0; i < 10000; i++){
	  /*call get time of day*/
	  gettimeofday(&t, NULL);
	  time = (t.tv_sec *1000000) + t.tv_usec;
	  sprintf(msgbuf,"%d",time);
	  msglen = strlen(msgbuf) + 1;

	  if (send(clifd, msgbuf, msglen, 0) < 0) {
		std::cerr << argv[0] 
			<< ": send(): " << strerror(errno) << std::endl;
		goto cleanup;
	  }
	  sleep(10);
	}

cleanup:
	if (clifd >=0)
		close(clifd);
	return 0;
}

