#pragma once

// @brief �o�������X�g�̃N���X
// @brief �ʖ�bi-directional list
template<typename Type>
class DoublyLinkedList
{
public:
	// @brief �o�������X�g�̃m�[�h
	// @brief �\����ResultData���i�[���Ă���
	struct Node {
		DoublyLinkedList<Type>::Node* pPrevious = nullptr;
		DoublyLinkedList<Type>::Node* pNext = nullptr;
		Type resultData;
	};

	// @brief �o�������X�g�̃C�e���[�^
	// @brief *���Z�q�ŃC�e���[�^�������f�[�^�ɃA�N�Z�X�ł��܂�
	template<typename TypeCI = Type>
	class ConstIterator {
		friend DoublyLinkedList<Type>;
	public:
		//�R���X�g���N�^
		ConstIterator();
		ConstIterator(const DoublyLinkedList<Type>* _pList, const Node* _pNode);

		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator++();
		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator++(int n);
		// @brief �O�̗v�f�Ɉړ����܂�
		//        �O�̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator--();
		// @brief �O�̗v�f���܂�
		//        �O�̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator--(int n);

		// @brief ���������Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator+(int n);
		// @brief �擪�����Ɏw�肵���������ړ������R���X�g�C�e���[�^��Ԃ��܂�
		ConstIterator<TypeCI> operator-(int n);

		// @brief �C�e���[�^�������R���X�g�v�f�̎Q�Ƃ��擾���܂�
		const Type& operator*();
		// @brief �C�e���[�^�������R���X�g�v�f�̎Q�Ƃ��擾���܂�
		const Type* operator->();//���̂��|�C���^��Ԃ��Ȃ��Ƃ����Ȃ�
		// @brief �R�s�[�R���X�g���N�^
		ConstIterator(const ConstIterator<TypeCI>& obj);

		// @brief �C�e���[�^���r���܂�
		bool operator==(ConstIterator<TypeCI> it);
		bool operator!=(ConstIterator<TypeCI> it);

		// @brief �C�e���[�^���Q�Ƃ��郊�X�g�̎Q�Ƃ��擾���܂�
		const DoublyLinkedList<Type>& GetList();

	protected:
		Node* pNode = nullptr;
		DoublyLinkedList<TypeCI>* pList = nullptr;
	private:

	};

	// @brief �o�������X�g�̃R���X�g�C�e���[�^
	// @brief *���Z�q�ŃC�e���[�^�������f�[�^�ɃA�N�Z�X�ł���
	template<typename TypeI = Type>
	class Iterator :public ConstIterator<TypeI> {
	public:
		Iterator();
		Iterator(DoublyLinkedList<TypeI>* _pList, Node* _pNode);

		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator++();
		// @brief ���̗v�f�Ɉړ����܂�
		//        ���̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator++(int n);
		// @brief �O�̗v�f�Ɉړ����܂�
		//        �O�̗v�f�Ɉړ������C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator--();
		// @brief �O�̗v�f���܂�
		//        �O�̗v�f�Ɉړ����Ă��Ȃ��C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator--(int n);

		// @brief ���������Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator+(int n);
		// @brief �擪�����Ɏw�肵���������ړ������C�e���[�^��Ԃ��܂�
		Iterator<TypeI> operator-(int n);

		// @brief �C�e���[�^�������v�f���擾���܂�
		Type& operator*();
		// @brief �C�e���[�^�������R���X�g�v�f���擾���܂�
		Type* operator->();//���̂��|�C���^��Ԃ��Ȃ��Ƃ����Ȃ�

	private:

	};

	// @brief �R���X�g���N�^
	DoublyLinkedList();
	// @brief �f�X�g���N�^
	~DoublyLinkedList();

	// @brief �v�f�����擾���܂�
	unsigned int GetSize()const;

	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in,out] �ǉ��ʒu�̃C�e���[�^
	bool AddNode(ConstIterator<Type>& iterator);
	// @brief �C�e���[�^�������ʒu�ɗv�f��ǉ����܂�
	// @param[in,out] �ǉ��ʒu�̃C�e���[�^
	bool AddNode(Iterator<Type>& iterator);

	// @brief �C�e���[�^�������ʒu�̗v�f���폜���܂�
	// @param[in,out] �폜�ʒu�̃C�e���[�^
	bool DeleteNode(ConstIterator<Type>& iterator);

	// @brief �擪�̃C�e���[�^���擾
	Iterator<Type> GetBegin();

	// @brief �擪�̃R���X�g�C�e���[�^���擾
	ConstIterator<Type> GetConstBegin()const;

	// @brief �����̃C�e���[�^���擾
	Iterator<Type> GetEnd();

	// @brief �����̃R���X�g�C�e���[�^���擾
	ConstIterator<Type> GetConstEnd()const;

	// @brief �擪�v�f�ւ̃|�C���^���擾
	//Node* GetNode();

private:

	// @brief �����������_�~�[�v�f�@�f�[�^�͊i�[����Ȃ�
	Node dummy;
	// @brief �擪�v�f�ւ̃|�C���^
	Node* pTop = &dummy;

	// @brief �v�f�̐�
	unsigned int size = 0;
};