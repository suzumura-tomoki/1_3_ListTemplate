#include<fstream>
#include"main.h"

int main() {

	std::ifstream ifsScoreFile;
	ifsScoreFile.open("Scores.txt");

	if (!ifsScoreFile) {
		printf("�t�@�C�����J���܂���ł���");
		getchar();
		return 1;
	}

	DoublyLinkedList<ResultData> list;
	DoublyLinkedList<ResultData>::Iterator<ResultData> iterator = list.GetBegin();
	//�X�R�A�ǂݍ���
	while (ifsScoreFile.eof() == false)
	{
		list.AddNode(iterator);

		//�t�@�C���̓ǂݎ��
		char readCharacter;
		while (true)
		{
			ifsScoreFile.get(readCharacter);

			//�t�@�C���I�[�̉��s�𖳎�
			if (ifsScoreFile.eof())
				break;

			iterator->score += readCharacter;

			if (readCharacter == ' ')
				break;
			if (readCharacter == '�@')
				break;
		}

		while (true)
		{
			ifsScoreFile.get(readCharacter);

			//�t�@�C���I�[�̉��s�𖳎�
			if (ifsScoreFile.eof())
				break;

			iterator->name += readCharacter;

			if (readCharacter == '\n')
				break;
		}

		iterator++;
	}

	ifsScoreFile.close();

	//�ǂݍ��񂾒l���o��
	for (iterator = list.GetBegin(); iterator != list.GetEnd(); iterator++) {
		printf(iterator->score.c_str());
		printf(iterator->name.c_str());
		printf("\n");
	}

	printf("\nENTER�L�[�������ƏI�����܂�");
	getchar();
	return 0;
}