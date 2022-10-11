#pragma once

// @brief 双方向リストのクラス
// @brief 別名bi-directional list
template<typename Type>
class DoublyLinkedList
{
public:
	// @brief 双方向リストのノード
	// @brief 構造体ResultDataを格納している
	struct Node {
		DoublyLinkedList<Type>::Node* pPrevious = nullptr;
		DoublyLinkedList<Type>::Node* pNext = nullptr;
		Type resultData;
	};

	// @brief 双方向リストのイテレータ
	// @brief *演算子でイテレータが示すデータにアクセスできます
	template<typename TypeCI = Type>
	class ConstIterator {
		friend DoublyLinkedList<Type>;
	public:
		//コンストラクタ
		ConstIterator();
		ConstIterator(const DoublyLinkedList<Type>* _pList, const Node* _pNode);

		// @brief 次の要素に移動します
		//        次の要素に移動したイテレータを返します
		ConstIterator<TypeCI> operator++();
		// @brief 次の要素に移動します
		//        次の要素に移動していないイテレータを返します
		ConstIterator<TypeCI> operator++(int n);
		// @brief 前の要素に移動します
		//        前の要素に移動したイテレータを返します
		ConstIterator<TypeCI> operator--();
		// @brief 前の要素します
		//        前の要素に移動していないイテレータを返します
		ConstIterator<TypeCI> operator--(int n);

		// @brief 末尾方向に指定した数だけ移動したコンストイテレータを返します
		ConstIterator<TypeCI> operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したコンストイテレータを返します
		ConstIterator<TypeCI> operator-(int n);

		// @brief イテレータが示すコンスト要素の参照を取得します
		const Type& operator*();
		// @brief イテレータが示すコンスト要素の参照を取得します
		const Type* operator->();//何故かポインタを返さないといけない
		// @brief コピーコンストラクタ
		ConstIterator(const ConstIterator<TypeCI>& obj);

		// @brief イテレータを比較します
		bool operator==(ConstIterator<TypeCI> it);
		bool operator!=(ConstIterator<TypeCI> it);

		// @brief イテレータが参照するリストの参照を取得します
		const DoublyLinkedList<Type>& GetList();

	protected:
		Node* pNode = nullptr;
		DoublyLinkedList<TypeCI>* pList = nullptr;
	private:

	};

	// @brief 双方向リストのコンストイテレータ
	// @brief *演算子でイテレータが示すデータにアクセスできる
	template<typename TypeI = Type>
	class Iterator :public ConstIterator<TypeI> {
	public:
		Iterator();
		Iterator(DoublyLinkedList<TypeI>* _pList, Node* _pNode);

		// @brief 次の要素に移動します
		//        次の要素に移動したイテレータを返します
		Iterator<TypeI> operator++();
		// @brief 次の要素に移動します
		//        次の要素に移動していないイテレータを返します
		Iterator<TypeI> operator++(int n);
		// @brief 前の要素に移動します
		//        前の要素に移動したイテレータを返します
		Iterator<TypeI> operator--();
		// @brief 前の要素します
		//        前の要素に移動していないイテレータを返します
		Iterator<TypeI> operator--(int n);

		// @brief 末尾方向に指定した数だけ移動したイテレータを返します
		Iterator<TypeI> operator+(int n);
		// @brief 先頭方向に指定した数だけ移動したイテレータを返します
		Iterator<TypeI> operator-(int n);

		// @brief イテレータが示す要素を取得します
		Type& operator*();
		// @brief イテレータが示すコンスト要素を取得します
		Type* operator->();//何故かポインタを返さないといけない

	private:

	};

	// @brief コンストラクタ
	DoublyLinkedList();
	// @brief デストラクタ
	~DoublyLinkedList();

	// @brief 要素数を取得します
	unsigned int GetSize()const;

	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	bool AddNode(ConstIterator<Type>& iterator);
	// @brief イテレータが示す位置に要素を追加します
	// @param[in,out] 追加位置のイテレータ
	bool AddNode(Iterator<Type>& iterator);

	// @brief イテレータが示す位置の要素を削除します
	// @param[in,out] 削除位置のイテレータ
	bool DeleteNode(ConstIterator<Type>& iterator);

	// @brief 先頭のイテレータを取得
	Iterator<Type> GetBegin();

	// @brief 先頭のコンストイテレータを取得
	ConstIterator<Type> GetConstBegin()const;

	// @brief 末尾のイテレータを取得
	Iterator<Type> GetEnd();

	// @brief 末尾のコンストイテレータを取得
	ConstIterator<Type> GetConstEnd()const;

	// @brief 先頭要素へのポインタを取得
	//Node* GetNode();

private:

	// @brief 末尾を示すダミー要素　データは格納されない
	Node dummy;
	// @brief 先頭要素へのポインタ
	Node* pTop = &dummy;

	// @brief 要素の数
	unsigned int size = 0;
};