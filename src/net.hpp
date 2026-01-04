#ifndef NET_H
#define NET_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_PORT 9876

typedef struct {
	short sin_family;
	unsigned short sin_port;
	struct in_addr sin_addr;
	char sin_zero[8];
} SocketAddress_In;

class Socket {
	private:
		int sock;
			
	public:
		bool connect();
		bool disconnect();
}

#endif
