#include"Blockchain.h"
#include<string>

int main()
{
	int blockNum = 1;
	string mining_block, ing, str;
	Blockchain bChain = Blockchain();

	while (1)
	{
		mining_block = "Mining block ";
		ing = "...";
		str = "Block ";                             // Loop 돌때마다 문자열 초기화

		mining_block.append(to_string(blockNum));   // blockNum을 문자열로 변경후 문자열에 붙이기
		mining_block.append(ing);
		cout << mining_block << endl;               // Mining block 1...

		str.append(to_string(blockNum));
		str.append(" Data");                        // str = Block 1 Data
		bChain.AddBlock(Block(blockNum, str));

		blockNum++;
	}

	system("pause");

	return 0;
}