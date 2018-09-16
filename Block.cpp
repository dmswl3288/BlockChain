#define _CRT_SECURE_NO_WARNINGS
#include"Block.h"
#include"sha256.h"
#include<ctime>
#include<sstream>

Block::Block(uint32_t nIndexIn, const string &sDataIn) : _nIndex(nIndexIn), _sData(sDataIn)
{
	_nNonce = -1;
	_tTime = time(nullptr);
}

string Block::GetHash()
{
	return _sHash;
}

void Block::MineBlock(uint32_t nDifficulty)
{
	char* ttime = ctime(&_tTime);               // ctime()의 char*형으로 변환
	char* cstr = new char[nDifficulty + 1];

	for (uint32_t i = 0; i < nDifficulty; ++i)
	{
		cstr[i] = '0';
	}
	cstr[nDifficulty] = '\0';

	string str(cstr);

	do
	{
		_nNonce++;
		_sHash = _CalculateHash();
	} while (_sHash.substr(0, nDifficulty) != str);

	cout << "Block mined: " << _sHash << endl;
	cout << "Mining Time: " << ttime << endl;     // 00:00:00 형식으로 마이닝된 시간 출력
}

inline string Block::_CalculateHash() const
{
	stringstream ss;
	ss << _nIndex << _tTime << _sData << _nNonce << sPrevHash;

	return sha256(ss.str());
}