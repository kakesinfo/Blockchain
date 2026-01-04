#include <net.h>


bool Socket::connect() 
{
	this->sock = socket(AF_INET, SOCK_STREAM, 0);
	
}

bool Socket::disconnect()
{

}
