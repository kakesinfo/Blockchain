#include <iostream>
#include <vector>

#include "blockchain.hpp"
#include "net.hpp"

using namespace std;

void debugBlockchain(Blockchain chain)
{
	vector<Block> blocks = chain.getBlocks();
	for(const auto &B : blocks)
	{
		cout << B.previousHash << endl;
		for(const auto &T : B.transactions)
		{
			cout << "\t" << T.sender << " : " << T.receiver << " : " << T.amount << endl;
		}
		cout << "<===>" << endl;
	}
}

int main()
{
	Socket socket;

	socket.connect();
	return 0;
}
