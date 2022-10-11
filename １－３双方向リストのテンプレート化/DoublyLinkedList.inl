#include "DoublyLinkedList.h"
#include<assert.h>

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
{
	dummy.pPrevious = nullptr;
	dummy.pNext = nullptr;
	dummy.resultData.name = "dummy";
	dummy.resultData.score = "dummy";
	//Node* pTop = &dummy;
}

template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	DoublyLinkedList<Type>::Node* pCurrent = pTop;
	DoublyLinkedList<Type>::Node* pDeleteNode;

	while (true)
	{
		if (pCurrent == &dummy)
			break;

		pDeleteNode = pCurrent;
		pCurrent = pCurrent->pNext;

		delete pDeleteNode;

	}
}


template<typename Type>
unsigned int DoublyLinkedList<Type>::GetSize()const
{
	return size;
}


template<typename Type>
bool DoublyLinkedList<Type>::AddNode(ConstIterator<Type>& iterator)
{
	if (this != iterator.pList)
		return false;

	if (iterator.pNode == nullptr)
		return false;

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//�ǉ������v�f�ֈړ�
	size++;

	return true;
}

template<typename Type>
bool DoublyLinkedList<Type>::AddNode(Iterator<Type>& iterator)
{
	if (this != iterator.pList)
		return false;

	if (iterator.pNode == nullptr)
		return false;

	//�V�����v�f�𐶐�
	Node* pNewNode = new Node;
	pNewNode->pNext = iterator.pNode;//�ǉ�����ʒu�ɂ������v�f�����̗v�f�ɂ���
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//�ǉ��ʒu�̑O�̗v�f��O�̗v�f�ɂ���

	//�O��̗v�f���V�����v�f���Q�Ƃ���悤�ɂ���
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//�擪�ɒǉ������ꍇ�ɐ擪�|�C���^���X�V
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//�ǉ������v�f�ֈړ�
	size++;

	return true;
}


template<typename Type>
bool DoublyLinkedList<Type>::DeleteNode(ConstIterator<Type>& iterator)
{
	// �C�e���[�^�������̃��X�g�̃C�e���[�^�����f����
	if (this != iterator.pList)
		return false;

	//�s���ȃC�e���[�^�����f����
	if (iterator.pNode == nullptr)
		return false;

	//�_�~�[�m�[�h�����f����
	if (iterator.pNode == &iterator.pList->dummy)
		return false;

	//�O�̗v�f���폜�Ώۂ̎��̗v�f���w���悤�ɕύX
	if (iterator.pNode->pPrevious != nullptr)
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;

	//���̗v�f���폜�Ώۂ̑O�̗v�f���w���悤�ɕύX
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator.pNode = iterator.pNode->pNext;//���̃m�[�h�ֈړ�

	//�폜�Ώۂ��擪��������擪�|�C���^���X�V
	if (pDeleteNode == pTop)
		pTop = iterator.pNode;

	delete pDeleteNode;

	size--;

	return true;
}

template<typename Type>
DoublyLinkedList<Type>::Iterator<Type> DoublyLinkedList<Type>::GetBegin()
{
	return Iterator<Type>(this, pTop);
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator<Type> DoublyLinkedList<Type>::GetConstBegin()const
{
	return ConstIterator<Type>(this, pTop);
}

template<typename Type>
DoublyLinkedList<Type>::Iterator<Type> DoublyLinkedList<Type>::GetEnd()
{
	return Iterator<Type>(this, &dummy);
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator<Type> DoublyLinkedList<Type>::GetConstEnd()const
{
	return ConstIterator<Type>(this, &dummy);
}

//DoublyLinkedList<Type>::Node* DoublyLinkedList<Type>::GetNode()
//{
//  if(size==0)
//		return nullptr;
// 
//	return pTop;
//}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI>::ConstIterator()
{
	//�������Ȃ�
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI>::ConstIterator(const DoublyLinkedList<Type>* _pList, const Node* _pNode)
{
	pList = const_cast<DoublyLinkedList<Type>*>(_pList);
	pNode = const_cast<Node*>(_pNode);
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator++()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	pNode = pNode->pNext;
	return *this;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator++(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	ConstIterator<TypeCI> cit = *this;
	pNode = pNode->pNext;
	return cit;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator--()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	pNode = pNode->pPrevious;
	return *this;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator--(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h
	ConstIterator<TypeCI> cit = *this;
	pNode = pNode->pPrevious;
	return cit;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator+(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�����ɐi��
		for (int i = 0; i < n; i++) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
	else {

		//�擪�ɐi��
		for (int i = 0; i > n; i--) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator-(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = pNode;

	if (n >= 0) {

		//�擪�ɐi��
		for (int i = 0; i < n; i++) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
	else {

		//�����ɐi��
		for (int i = 0; i > n; i--) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
}

template<typename Type>
template<typename TypeCI>
const Type& DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator*()
{
	return pNode->resultData;
}

template<typename Type>
template<typename TypeCI>
const Type* DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator->()
{
	assert(pList != nullptr);//pList��nullptr�łȂ�����
	assert(pNode != &pList->dummy);//pNode���_�~�[�łȂ�����

	return &pNode->resultData;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI>::ConstIterator(const ConstIterator<TypeCI>& obj)
{
	this->pNode = obj.pNode;
	this->pList = obj.pList;
}

template<typename Type>
template<typename TypeCI>
bool DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator==(ConstIterator<TypeCI> it)
{
	return this->pNode == it.pNode;
}

template<typename Type>
template<typename TypeCI>
bool DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator!=(ConstIterator<TypeCI> it)
{

	return !(this->pNode == it.pNode);
}

template<typename Type>
template<typename TypeCI>
const DoublyLinkedList<Type>& DoublyLinkedList<Type>::ConstIterator<TypeCI>::GetList()
{
	return *pList;//const_cast���Ȃ��Ă����H
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI>::Iterator()
{
	//�������Ȃ�
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI>::Iterator(DoublyLinkedList<TypeI>* _pList, Node* _pNode) : ConstIterator<TypeI>(_pList, _pNode)
{
	//���N���XIterator<TypeI>�̃R���X�g���N�^���Ăяo��
	//�����ł͉������Ȃ�
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator++()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	this->pNode = this->pNode->pNext;
	return *this;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator++(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode != &this->pList->dummy);//�����m�[�h�ł���

	Iterator<TypeI> it = *this;
	this->pNode = this->pNode->pNext;
	return it;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator--()
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h

	this->pNode = this->pNode->pPrevious;
	return *this;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator--(int)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ�
	assert(this->pNode->pPrevious != nullptr);//�擪�m�[�h�ł���@�܂��̓��X�g����̎��̖����m�[�h

	Iterator<TypeI> it = *this;
	this->pNode = this->pNode->pPrevious;
	return it;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator+(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = this->pNode;

	if (n >= 0) {

		//�����ɐi��
		for (int i = 0; i < n; i++) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
	else {

		//�擪�ɐi��
		for (int i = 0; i > n; i--) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator-(int n)
{
	assert(this->pList != nullptr);//���X�g�̎Q�Ƃ��Ȃ��ꍇ

	Node* pMoved = this->pNode;

	if (n >= 0) {

		//�擪�ɐi��
		for (int i = 0; i < n; i++) {

			//�擪���z���Ȃ��悤�ɒ�~����
			if (pMoved->pPrevious == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
	else {

		//�����ɐi��
		for (int i = 0; i > n; i--) {

			//�������z���Ȃ��悤�ɒ�~����
			if (pMoved->pNext == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++���I�[�o�[�w�b�h�����Ȃ��H
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}

}

template<typename Type>
template<typename TypeI>
Type& DoublyLinkedList<Type>::Iterator<TypeI>::operator*()
{
	assert(this->pList != nullptr);//pList��nullptr�łȂ�����
	assert(this->pNode != &this->pList->dummy);//pNode���_�~�[�łȂ�����

	return this->pNode->resultData;
}

template<typename Type>
template<typename TypeI>
Type* DoublyLinkedList<Type>::Iterator<TypeI>::operator->()
{
	assert(this->pList != nullptr);//pList��nullptr�łȂ�����
	assert(this->pNode != &this->pList->dummy);//pNode���_�~�[�łȂ�����

	return &this->pNode->resultData;
}
