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

#include "buffer.h"

int main(int argc, char *argv[]){

struct timeval t;
  
  gettimeofday(&t, NULL);

  long time;

  time = (t.tv_sec *1000000) + t.tv_usec;




	int svrfd = -1, clifd = -1, nrecv, quit = 0, portnum;
	socklen_t cliaddrlen = sizeof(struct sockaddr_in);
	struct sockaddr_in svraddr, cliaddr;
	char msgbuf[128000];
	std::stringstream ss(std::stringstream::in | std::stringstream::out);

	if (argc < 3) {
		std::cout << "Usage: " << argv[0] 
			<< " server_ip_address port_number" << std::endl;
		return 0;
	}

	ss << argv[2];
	ss >> portnum;

	svrfd = socket(AF_INET, SOCK_STREAM, 0);
	if (svrfd < 0) {
		std::cerr << argv[0] << ": socket(SOCK_STREAM): " 
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

	if (bind(svrfd, (struct sockaddr*)&svraddr, sizeof(struct sockaddr_in))
		!= 0) {
		std::cerr << argv[0] 
			<< ": bind(): " << strerror(errno) << std::endl;
		goto cleanup;
	}

	if (listen(svrfd, 1) != 0) {
		std::cerr << argv[0]
			<< ": listen(): " << strerror(errno) << std::endl;
		goto cleanup;
	}

	do {
		clifd = accept(svrfd, (struct sockaddr*)&cliaddr, &cliaddrlen);
		if (clifd < 0) {
			std::cerr << argv[0] << ": accept(): " 
				<<  strerror(errno) << std::endl;
			goto cleanup;
		}

		do {
			nrecv = recv(clifd, msgbuf, sizeof(msgbuf), 0);
			if (nrecv < 0) {
				std::cerr << argv[0] << ": recv(): "
					<< strerror(errno) << std::endl;
				goto cleanup;
			}
			if (nrecv > 0){
			  int c_time;
			  /*call get time of day*/
			  gettimeofday(&t, NULL);
			  sscanf(msgbuf,"%d", &c_time);
			  time = (t.tv_sec *1000000) + t.tv_usec;
			  std::cout << c_time << std::endl;
			  std::cout << (time-c_time) << std::endl;
			    }
			if (msgbuf[0] == 0 && nrecv == 1)
				quit = 1;
		} while (nrecv > 0);

		if (clifd >=0)
			close(clifd);
	} while(!quit);

cleanup:
	if (svrfd >= 0)
		close(svrfd);

	return 0;
}

