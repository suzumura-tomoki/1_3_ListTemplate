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

	while (ifsScoreFile.eof() == false)
	{
		//ファイルの読み取り

		ResultData data{};
		std::string readString{};

		//スコアの読み込み
		std::getline(ifsScoreFile, readString, '\t');

		//ファイル終端の改行を無視
		if (ifsScoreFile.eof())
		{
			break;
		}

		//数字の文字列を整数値に変換
		data.score = std::stoi(readString);


		//名前の読み込み
		//ResultDataに直接読み込む
		std::getline(ifsScoreFile, data.name, '\n');

		//ファイル終端の改行を無視
		if (ifsScoreFile.eof())
		{
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
		printf(std::to_string(it->score).c_str());
		printf("\t");
		printf(it->name.c_str());
		printf("\n");
	}

	printf("\nENTERキーを押すと終了します");
	getchar();
	return 0;
}