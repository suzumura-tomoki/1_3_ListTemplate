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
	DoublyLinkedList<ResultData>::Iterator it;

	//スコア読み込み
	while (ifsScoreFile.eof() == false)
	{
		ResultData data{};

		//ファイルの読み取り
		char readCharacter;
		while (true)
		{
			ifsScoreFile.get(readCharacter);

			//ファイル終端の改行を無視
			if (ifsScoreFile.eof())
				break;

			data.score += readCharacter;

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

			data.name += readCharacter;

			if (readCharacter == '\n')
				break;
		}

		//読み取ったデータの挿入
		it = list.GetEnd();
		list.Insert(it, data);
	}

	ifsScoreFile.close();

	//読み込んだ値を出力
	const DoublyLinkedList<ResultData>::Iterator end = list.GetEnd();
	for (it = list.GetBegin(); it != end; it++) {
		printf(it->score.c_str());
		printf(it->name.c_str());
		printf("\n");
	}

	printf("\nENTERキーを押すと終了します");
	getchar();
	return 0;
}