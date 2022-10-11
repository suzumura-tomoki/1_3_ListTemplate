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

	//新しい要素を生成
	Node* pNewNode = new Node;
	pNewNode->pNext = iterator.pNode;//追加する位置にあった要素を次の要素にする
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//追加位置の前の要素を前の要素にする

	//前後の要素が新しい要素を参照するようにする
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//先頭に追加した場合に先頭ポインタを更新
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//追加した要素へ移動
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

	//新しい要素を生成
	Node* pNewNode = new Node;
	pNewNode->pNext = iterator.pNode;//追加する位置にあった要素を次の要素にする
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//追加位置の前の要素を前の要素にする

	//前後の要素が新しい要素を参照するようにする
	pNewNode->pNext->pPrevious = pNewNode;
	if (pNewNode->pPrevious != nullptr)
		pNewNode->pPrevious->pNext = pNewNode;

	//先頭に追加した場合に先頭ポインタを更新
	if (iterator.pNode == pTop)
		pTop = pNewNode;

	iterator--;//追加した要素へ移動
	size++;

	return true;
}


template<typename Type>
bool DoublyLinkedList<Type>::DeleteNode(ConstIterator<Type>& iterator)
{
	// イテレータが自分のリストのイテレータか判断する
	if (this != iterator.pList)
		return false;

	//不正なイテレータか判断する
	if (iterator.pNode == nullptr)
		return false;

	//ダミーノードか判断する
	if (iterator.pNode == &iterator.pList->dummy)
		return false;

	//前の要素が削除対象の次の要素を指すように変更
	if (iterator.pNode->pPrevious != nullptr)
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;

	//次の要素が削除対象の前の要素を指すように変更
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator.pNode = iterator.pNode->pNext;//次のノードへ移動

	//削除対象が先頭だったら先頭ポインタを更新
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
	//何もしない
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
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	pNode = pNode->pNext;
	return *this;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator++(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	ConstIterator<TypeCI> cit = *this;
	pNode = pNode->pNext;
	return cit;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator--()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	pNode = pNode->pPrevious;
	return *this;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator--(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	ConstIterator<TypeCI> cit = *this;
	pNode = pNode->pPrevious;
	return cit;
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator+(int n)
{
	assert(this->pList != nullptr);//リストの参照がない場合

	Node* pMoved = pNode;

	if (n >= 0) {

		//末尾に進む
		for (int i = 0; i < n; i++) {

			//末尾を越えないように停止する
			if (pMoved->pNext == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++よりオーバーヘッドが少ない？
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
	else {

		//先頭に進む
		for (int i = 0; i > n; i--) {

			//先頭を越えないように停止する
			if (pMoved->pPrevious == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--よりオーバーヘッドが少ない？
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
}

template<typename Type>
template<typename TypeCI>
DoublyLinkedList<Type>::ConstIterator<TypeCI> DoublyLinkedList<Type>::ConstIterator<TypeCI>::operator-(int n)
{
	assert(this->pList != nullptr);//リストの参照がない場合

	Node* pMoved = pNode;

	if (n >= 0) {

		//先頭に進む
		for (int i = 0; i < n; i++) {

			//先頭を越えないように停止する
			if (pMoved->pPrevious == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--よりオーバーヘッドが少ない？
		}

		return ConstIterator<TypeCI>(pList, pMoved);
	}
	else {

		//末尾に進む
		for (int i = 0; i > n; i--) {

			//末尾を越えないように停止する
			if (pMoved->pNext == nullptr)
				return ConstIterator<TypeCI>(pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++よりオーバーヘッドが少ない？
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
	assert(pList != nullptr);//pListがnullptrでないこと
	assert(pNode != &pList->dummy);//pNodeがダミーでないこと

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
	return *pList;//const_castしなくていい？
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI>::Iterator()
{
	//何もしない
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI>::Iterator(DoublyLinkedList<TypeI>* _pList, Node* _pNode) : ConstIterator<TypeI>(_pList, _pNode)
{
	//基底クラスIterator<TypeI>のコンストラクタを呼び出す
	//ここでは何もしない
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator++()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	this->pNode = this->pNode->pNext;
	return *this;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator++(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	Iterator<TypeI> it = *this;
	this->pNode = this->pNode->pNext;
	return it;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator--()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード

	this->pNode = this->pNode->pPrevious;
	return *this;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator--(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード

	Iterator<TypeI> it = *this;
	this->pNode = this->pNode->pPrevious;
	return it;
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator+(int n)
{
	assert(this->pList != nullptr);//リストの参照がない場合

	Node* pMoved = this->pNode;

	if (n >= 0) {

		//末尾に進む
		for (int i = 0; i < n; i++) {

			//末尾を越えないように停止する
			if (pMoved->pNext == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++よりオーバーヘッドが少ない？
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
	else {

		//先頭に進む
		for (int i = 0; i > n; i--) {

			//先頭を越えないように停止する
			if (pMoved->pPrevious == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--よりオーバーヘッドが少ない？
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
}

template<typename Type>
template<typename TypeI>
DoublyLinkedList<Type>::Iterator<TypeI> DoublyLinkedList<Type>::Iterator<TypeI>::operator-(int n)
{
	assert(this->pList != nullptr);//リストの参照がない場合

	Node* pMoved = this->pNode;

	if (n >= 0) {

		//先頭に進む
		for (int i = 0; i < n; i++) {

			//先頭を越えないように停止する
			if (pMoved->pPrevious == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pPrevious;//(*this)--よりオーバーヘッドが少ない？
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}
	else {

		//末尾に進む
		for (int i = 0; i > n; i--) {

			//末尾を越えないように停止する
			if (pMoved->pNext == nullptr)
				return Iterator<TypeI>(this->pList, pMoved);

			pMoved = pMoved->pNext;//(*this)++よりオーバーヘッドが少ない？
		}

		return Iterator<TypeI>(this->pList, pMoved);
	}

}

template<typename Type>
template<typename TypeI>
Type& DoublyLinkedList<Type>::Iterator<TypeI>::operator*()
{
	assert(this->pList != nullptr);//pListがnullptrでないこと
	assert(this->pNode != &this->pList->dummy);//pNodeがダミーでないこと

	return this->pNode->resultData;
}

template<typename Type>
template<typename TypeI>
Type* DoublyLinkedList<Type>::Iterator<TypeI>::operator->()
{
	assert(this->pList != nullptr);//pListがnullptrでないこと
	assert(this->pNode != &this->pList->dummy);//pNodeがダミーでないこと

	return &this->pNode->resultData;
}
