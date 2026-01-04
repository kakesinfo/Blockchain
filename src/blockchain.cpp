#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <ctime>

#include "blockchain.hpp"
#include "sha256.hpp"

using namespace std;

Blockchain::Blockchain()
{
	// Nombre de zeros à trouver pour la preuve de travail.
	this->difficulty = 5;

	// Ajout du premier block à la blockchain.
	this->newBlock(100, "GENESIS_BLOCK");
}

Block Blockchain::newBlock(int proof, string previousHash)
{
	Block block;

	block.index = this->chain.size();
	block.timestamp = time(0);
	block.transactions = this->pending;
	block.proof = proof;
	block.previousHash = previousHash;

	this->pending.clear();
	this->chain.push_back(block);

	return block;
}

int Blockchain::newTransaction(string sender, string receiver, int amount)
{
	Transaction transaction;

	transaction.timestamp = time(0);
	transaction.sender = sender;
	transaction.receiver = receiver;
	transaction.amount = amount;

	this->pending.push_back(transaction);

	return this->chain.back().index + 1;
}

string Blockchain::normalize(Block block)
{
	string buffer;

	buffer = to_string(block.index);
	buffer += ":";
	buffer += to_string(block.timestamp);
	buffer += ":";

	for (const auto &transaction : block.transactions)
	{
		buffer += this->normalize(transaction);
		buffer += ":";
	}

	buffer += block.previousHash;
	buffer += ":";
	buffer += to_string(block.proof);

	return buffer;
}

string Blockchain::normalize(Transaction transaction)
{
	string buffer;

	buffer = to_string(transaction.timestamp);
	buffer += ":";
	buffer += transaction.sender;
	buffer += ":";
	buffer += transaction.receiver;
	buffer += ":";
	buffer += to_string(transaction.amount);

	return buffer;
}

string Blockchain::hash(Block block)
{
	const char *buffer;
	SHA256 sha256;
	string hash;

	buffer = this->normalize(block).c_str();
	hash = sha256(buffer, sizeof(buffer));

	return hash;
}

int Blockchain::pow(int previousProof)
{
	int proof;

	proof = 0;
	while (!valid_pow(previousProof * proof))
		proof++;
	return proof;
}

bool Blockchain::valid_pow(int proof)
{
	const char *buffer;
	SHA256 sha256;
	string hash;

	// Converti la preuve en chaine de caractère
	buffer = to_string(proof).c_str();

	// Hash la preuve
	hash = sha256(buffer, sizeof(buffer));

	// Chercher un hash qui fini par <difficulty> zeros.
	int i = 0;
	while (i < (int)hash.length())
	{
		if (hash.at(i) != '0')
			break;
		i++;
	}

	return i == this->difficulty;
}

bool Blockchain::mine(string receiver)
{
	// Récupère le dernier block et sa preuve de travail
	Block previousBlock = this->chain.back();
	int previousProof = previousBlock.proof;

	// Calcule une nouvelle preuve de travail
	int proof = this->pow(previousProof);

	// Rémunère le mineur
	this->newTransaction("", receiver, 1);

	// Hash du block précédent
	string previousHash = this->hash(previousBlock);

	// Ajoute le block à la blockchain
	this->newBlock(proof, previousHash);

	return true;
}

vector<Block> Blockchain::getBlocks()
{
	return this->chain;
}
