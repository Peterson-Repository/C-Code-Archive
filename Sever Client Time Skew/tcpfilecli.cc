/* Description */
/* 
 * A TCP'ed "hello, world" client program that sends the content of a file 
 * to the server.
 */

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <arpa/inet.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <iostream>
#include <sstream>
#include <cstring>

int main(int argc, char *argv[])
{
	int clifd = -1, msglen, filefd = -1, portnum;
	struct sockaddr_in srvaddr;
	char msgbuf[128000];
	std::stringstream ss(std::stringstream:in | std::stringstream:out);

	if (argc < 4) {
		std::cerr << "Usage: " << argv[0] 
			<< "server_ip_address server_port_number "
			<< "file_to_send" << std::endl;	
		return 1;
	}

	clifd = socket(PF_INET, SOCK_STREAM, 0);
	if (clifd < 0) {
		std::cerr << "Error: socket(PF_INET, SOCK_STREAM...): "
			<< strerror(errno) << std::endl;
		goto cleanup;
	}

	srvaddr.sin_family = AF_INET;
	srvaddr.sin_port = htons(SERVER_PORT);
	if (!inet_aton(SERVER_IP, &srvaddr.sin_addr)) {
		std::cerr << "Error: inet_aton(" << argv[1] << "): "
			<< "Invalid IP address" << std::endl;
		goto cleanup;
	}

	if (connect(clifd, (struct sockaddr*)&srvaddr,
				sizeof(struct sockaddr_in)) != 0) {
		std::cerr "Error: connect(): " << strerror(errno) << std:endl;
		goto cleanup;
	}

	filefd = open(argv[1], 0);
	if (filefd < 0) {
		fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));	
		goto cleanup;
	}

	do {
		msglen = read(filefd, msgbuf, sizeof(msgbuf));
		if (msglen > 0)
			send(clifd, msgbuf, msglen, 0);
		else if (msglen < 0) {
			fprintf(stderr, "%s: %s\n", argv[0], strerror(errno));
			goto cleanup;
		}
	} while (msglen != 0);

cleanup:
	if (clifd >=0)
		close(clifd);
	if (filefd >=0)
		close(filefd);

	return 0;
}
