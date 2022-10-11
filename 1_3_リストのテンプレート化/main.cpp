#include<fstream>
#include"main.h"

int main() {

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("ファイルを開けませんでした");
		getchar();
		return 1;
	}

	DoublyLinkedList<ResultData> list;
	DoublyLinkedList<ResultData>::Iterator<ResultData> iterator = list.GetBegin();
	//スコア読み込み
	while (ifsScoreFile.eof() == false)
	{
		list.AddNode(iterator);

		//ファイルの読み取り
		char readCharacter;
		while (true)
		{
			ifsScoreFile.get(readCharacter);

			//ファイル終端の改行を無視
			if (ifsScoreFile.eof())
				break;

			iterator->score += readCharacter;

			if (readCharacter == ' ')
				break;
			if (readCharacter == '　')
				break;
		}

		while (true)
		{
			ifsScoreFile.get(readCharacter);

			//ファイル終端の改行を無視
			if (ifsScoreFile.eof())
				break;

			iterator->name += readCharacter;

			if (readCharacter == '\n')
				break;
		}

		iterator++;
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	for (iterator = list.GetBegin(); iterator != list.GetEnd(); iterator++) {
		printf(iterator->score.c_str());
		printf(iterator->name.c_str());
		printf("\n");
	}

	printf("\nENTERキーを押すと終了します");
	getchar();
	return 0;
}