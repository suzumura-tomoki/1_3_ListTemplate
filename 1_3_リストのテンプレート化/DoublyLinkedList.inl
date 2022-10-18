#pragma once
#include"DoublyLinkedList.h"
#include<assert.h>
#include<string>//abs()のため

template<typename Type>
DoublyLinkedList<Type>::DoublyLinkedList()
	:dummy({ nullptr,nullptr,Type() })
	, pTop(&dummy)
	, size(0)
{
	//初期化子リストで初期化
}


template<typename Type>
DoublyLinkedList<Type>::~DoublyLinkedList()
{
	DoublyLinkedList<Type>::Iterator it = GetBegin();

	while (size > 0)
	{
		Delete(it);
	}
}


template<typename Type>
unsigned int DoublyLinkedList<Type>::GetSize()const
{
	return size;
}


template<typename Type>
bool DoublyLinkedList<Type>::Insert(ConstIterator& iterator, const Type& data)
{
	if (this != iterator.pList)
	{
		return false;
	}

	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//新しい要素を生成
	Node* pNewNode = new Node;
	pNewNode->data = data;
	pNewNode->pNext = iterator.pNode;//追加する位置にあった要素を次の要素にする
	pNewNode->pPrevious = pNewNode->pNext->pPrevious;//追加位置の前の要素を前の要素にする

	//前後の要素が新しい要素を参照するようにする
	pNewNode->pNext->pPrevious = pNewNode;

	if (pNewNode->pPrevious != nullptr)
	{
		//前の要素がある場合
		pNewNode->pPrevious->pNext = pNewNode;
	}

	//先頭に追加した場合に先頭ポインタを更新
	if (iterator.pNode == pTop)
	{
		pTop = pNewNode;
	}

	iterator--;//追加した要素へ移動
	size++;

	return true;
}

template<typename Type>
bool DoublyLinkedList<Type>::Delete(ConstIterator& iterator)
{
	// イテレータが自分のリストのイテレータか判断する
	if (this != iterator.pList)
	{
		return false;
	}

	//不正なイテレータか判断する
	if (iterator.pNode == nullptr)
	{
		return false;
	}

	//ダミーノードか判断する
	if (iterator.pNode == &iterator.pList->dummy)
	{
		return false;
	}

	//前に要素があれば削除対象の次の要素を指すように変更
	if (iterator.pNode->pPrevious != nullptr)
	{
		iterator.pNode->pPrevious->pNext = iterator.pNode->pNext;
	}

	//次の要素が削除対象の前の要素を指すように変更
	iterator.pNode->pNext->pPrevious = iterator.pNode->pPrevious;

	Node* pDeleteNode = iterator.pNode;

	iterator++;//次のノードへ移動

	//削除対象が先頭だったら先頭ポインタを更新
	if (pDeleteNode == pTop)
	{
		pTop = iterator.pNode;
	}

	delete pDeleteNode;

	size--;

	return true;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::GetBegin()
{
	return Iterator(this, pTop);
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::GetConstBegin()const
{
	return ConstIterator(this, pTop);
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::GetEnd()
{
	return Iterator(this, &dummy);
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::GetConstEnd()const
{
	//コンストメンバ関数の中ではメンバ変数がコンストとして扱われますが、引数に渡せないためコンストを消します
	return ConstIterator(this, const_cast<Node*>(&dummy));
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator()
	:pList(nullptr)
	,pNode(nullptr)
{
	//初期化子リストで初期化
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator(const DoublyLinkedList<Type>* _pList, Node* _pNode)
	:pList(_pList)
	,pNode(_pNode)
{
	//初期化子リストで初期化
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::ConstIterator(const ConstIterator& obj)
{
	this->pList = obj.pList;
	this->pNode = obj.pNode;
}

template<typename Type>
DoublyLinkedList<Type>::ConstIterator::~ConstIterator()
{
	//何もしない
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator& DoublyLinkedList<Type>::ConstIterator::operator++()
{
	assert(this->pList != nullptr);//リストの参照がない場合
	assert(this->pNode != nullptr);//ノードの参照がない場合
	assert(this->pNode != &this->pList->dummy);//末尾ノードである場合

	pNode = pNode->pNext;
	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator++(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != nullptr);//ノードの参照がない場合
	assert(this->pNode != &this->pList->dummy);//末尾ノードである

	ConstIterator cit = *this;
	operator++();
	return cit;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator& DoublyLinkedList<Type>::ConstIterator::operator--()
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != nullptr);//ノードの参照がない場合
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	pNode = pNode->pPrevious;
	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator--(int)
{
	assert(this->pList != nullptr);//リストの参照がない
	assert(this->pNode != nullptr);//ノードの参照がない場合
	assert(this->pNode->pPrevious != nullptr);//先頭ノードである　またはリストが空の時の末尾ノード
	ConstIterator cit = *this;
	operator--();
	return cit;
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator+(int n)const
{
	//エラーチェック　他の項目は++演算子の呼び出し時に行われる
	//先にノードにアクセスするのでノードの参照のみチェックしておく
	assert(this->pNode != nullptr);//ノードの参照がない場合

	if (n >= 0)
	{//末尾に進む

		ConstIterator cit = *this;

		for (int i = 0; i < n; i++) {

			//末尾を越えるとアサーションがでるよう変更
			// 意図しない挙動で動いてしまうより、エラーになるほうが良いと判断
			// コード量も若干軽減
			//末尾を越えないように停止する
			//if (cit.pNode->pNext == nullptr)
			//{
			//	return cit;
			//}

			cit++;
		}

		return cit;
	}
	else
	{//先頭に進む

		//絶対値を取得
		n = static_cast<int>(labs(n));

		//先頭に進めたイテレータを返す
		return (*this) - n;
	}
}

template<typename Type>
typename DoublyLinkedList<Type>::ConstIterator DoublyLinkedList<Type>::ConstIterator::operator-(int n)const
{
	//エラーチェック　他の項目は++演算子の呼び出し時に行われる
	//先にノードにアクセスするのでノードの参照のみチェックしておく
	assert(this->pNode != nullptr);//ノードの参照がない場合

	if (n >= 0)
	{//先頭に進む

		ConstIterator cit = *this;

		for (int i = 0; i < n; i++) {

			//先頭を越えるとアサーションがでるよう変更
			// 意図しない挙動で動いてしまうより、エラーになるほうが良いと判断
			// コード量も若干軽減
			//先頭を越えないように停止する
			//if (cit.pNode->pPrevious == nullptr)
			//{
			//	return cit;
			//}

			cit--;
		}

		return cit;
	}
	else
	{//末尾に進む

		//絶対値を取得
		n = static_cast<int>(labs(n));

		//末尾に進めたイテレータを返す
		return (*this) + n;
	}
}

template<typename Type>
bool DoublyLinkedList<Type>::ConstIterator::operator==(const ConstIterator& it)const
{
	return this->pNode == it.pNode;
}

template<typename Type>
bool DoublyLinkedList<Type>::ConstIterator::operator!=(const ConstIterator& it)const
{
	return !(*this == it);
}

template<typename Type>
const Type& DoublyLinkedList<Type>::ConstIterator::operator*()const
{
	assert(pList != nullptr);//pListがnullptrでないこと
	assert(pNode != &pList->dummy);//pNodeがダミーでないこと

	return pNode->data;
}

template<typename Type>

const Type* DoublyLinkedList<Type>::ConstIterator::operator->()const
{
	assert(pList != nullptr);//pListがnullptrでないこと
	assert(pNode != &pList->dummy);//pNodeがダミーでないこと

	return &pNode->data;
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::Iterator()
{
	//何もしない　メンバがいない
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::Iterator(DoublyLinkedList<Type>* _pList, Node* _pNode) : ConstIterator(_pList, _pNode)
{
	//基底クラスConstIteratorのコンストラクタに引数を渡す
	//ここでは何もしない
}

template<typename Type>
DoublyLinkedList<Type>::Iterator::~Iterator()
{
	//何もしない
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator& DoublyLinkedList<Type>::Iterator::operator++()
{
	ConstIterator::operator++();

	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator++(int)
{
	Iterator it = *this;

	operator++();

	return it;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator& DoublyLinkedList<Type>::Iterator::operator--()
{
	ConstIterator::operator--();

	return *this;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator--(int)
{
	Iterator it = *this;

	operator--();

	return it;
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator+(int n)const
{
	ConstIterator cit = ConstIterator::operator+(n);

	//関数がconstのため、別のインスタンスの親クラスのメンバもconstとして扱われてしまうので、引数として渡すためにconstを外します
	return Iterator(const_cast<DoublyLinkedList<Type>*>(cit.pList), const_cast<Node*>(cit.pNode));
}

template<typename Type>
typename DoublyLinkedList<Type>::Iterator DoublyLinkedList<Type>::Iterator::operator-(int n)const
{
	ConstIterator cit = ConstIterator::operator-(n);

	//関数がconstのため、別のインスタンスの親クラスのメンバもconstとして扱われてしまうので、引数として渡すためにconstを外します
	return Iterator(const_cast<DoublyLinkedList<Type>*>(cit.pList), const_cast<Node*>(cit.pNode));
}

template<typename Type>
Type& DoublyLinkedList<Type>::Iterator::operator*()
{
	//コンストイテレータの機能を流用してコンストを解除
	return const_cast<Type&>(ConstIterator::operator*());
}

template<typename Type>
Type* DoublyLinkedList<Type>::Iterator::operator->()
{
	//コンストイテレータの機能を流用してコンストを解除
	return const_cast<Type*>(ConstIterator::operator->());//ここではポインタの->は呼ばれていない
}
