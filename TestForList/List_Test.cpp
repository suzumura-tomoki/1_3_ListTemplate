/**********************************************************************************//**
	@file           List_Test.cpp
	@brief          GoogleTest自動テストコード
*//***********************************************************************************/

#include "pch.h"

// テスト対象のヘッダファイル
#include "../課題１_双方向リスト/DoublyLinkedList.h"

namespace ex01_DataStructure
{
	namespace chapter2
	{

		//=================================== 要素数の取得 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合の要素数の取得テスト
			@details	ID:リスト-0\n
						要素数の取得機能のテストです。\n
						リストが空である場合の戻り値を確認しています。\n
						要素数が0であれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumWhenEmpty) {
			DoublyLinkedList list;
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入を行った際の要素数の取得テスト
			@details	ID:リスト-1\n
						要素数の取得機能のテストです。\n
						リスト末尾への挿入を行った際の戻り値を確認しています。\n
						要素数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushBack)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();
			ASSERT_TRUE(list.AddNode(it));
			EXPECT_EQ(1, list.GetSize());//intとunsigned int だが通る
		}

		/**********************************************************************************//**
			@brief		リスト末尾への挿入が失敗した際の要素数の取得テスト
			@details	ID:リスト-2　自動テストを行いません\n　
						要素数の取得機能のテストです。\n
						リスト末尾への挿入が失敗した際の戻り値を確認しています。\n
						要素数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushBackFailed)
		{
			// "末尾への"挿入失敗はメモリ確保失敗時のためここではスキップ
// 			DoublyLinkedList list;
// 			DoublyLinkedList::Iterator it = list.GetEnd();
// 			ASSERT_FALSE(list.Insert(it, 1));
// 			EXPECT_EQ(0, list.GetCount());

		}

		/**********************************************************************************//**
			@brief		要素の挿入を行った際の要素数の取得テスト
			@details	ID:リスト-3\n
						要素数の取得機能のテストです。\n
						要素の挿入を行った際の戻り値を確認しています。\n
						要素数が1増えていれば成功です。\n
		 *//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPush)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_TRUE(list.AddNode(it));
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		要素の挿入が失敗した際の要素数の取得テスト
			@details	ID:リスト-4\n
						要素数の取得機能のテストです。\n
						要素の挿入が失敗した際の戻り値を確認しています。\n
						要素数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterPushFailed)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			ASSERT_FALSE(list.AddNode(it));
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		要素を削除した際の要素数の取得テスト
			@details	ID:リスト-5\n
						要素数の取得機能のテストです。\n
						要素を削除した際の戻り値を確認しています。\n
						要素数が１減っていれば成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);
			ASSERT_TRUE(list.DeleteNode(it));
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		要素の削除に失敗した際の要素数の取得テスト
			@details	ID:リスト-6\n
						要素数の取得機能のテストです。\n
						要素の削除に失敗した際の戻り値を確認しています。\n
						要素数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDeleteFailed)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);
			it++;//末尾ダミーのイテレータ
			ASSERT_FALSE(list.DeleteNode(it));
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストが空である場合に削除を行った際の要素数の取得テスト
			@details	ID:リスト-7\n
						要素数の取得機能のテストです。\n
						リストが空である場合に削除を行った際の戻り値を確認しています。\n
						要素数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumAfterDeleteWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			ASSERT_FALSE(list.DeleteNode(it));
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		要素数の取得をする関数がconst関数であるかテスト
			@details	ID:リスト-8　自動テストを行いません\n
						要素数の取得機能のテストです。\n
						constのリストから呼び出して、コンパイルエラーとならなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetDataNumTest, TestGetDataNumIsConstMethod)
		{
			//スキップ
		}

		//=================================== 要素の挿入 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、要素を追加した際の挙動テスト
			@details	ID:リスト-9\n
						要素追加テストです。\n
						リストが空である場合に追加した際の挙動を確認しています。\n
						要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushBackWhenEmpty)
		{
			//先頭に追加
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			EXPECT_TRUE(list.AddNode(it));
			EXPECT_EQ(1, list.GetSize());

			//末尾に追加
			DoublyLinkedList list2;
			it = list2.GetEnd();
			EXPECT_TRUE(list2.AddNode(it));
			EXPECT_EQ(1, list2.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して要素を追加した際の挙動テスト
			@details	ID:リスト-10\n
						リスト先頭の要素追加テストです。\n
						リストに複数の要素がある場合に、先頭に追加した際の挙動を確認しています。\n
						先頭に要素が挿入され、元々先頭だった要素が２番目になっていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushFront)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it);
			std::string str = "元々先頭の要素";
			it->name = str;

			//先頭に要素を追加
			EXPECT_TRUE(list.AddNode(it));

			//要素を確認
			it++;//2番目の要素へ
			EXPECT_EQ(str, it->name);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して要素を追加した際の挙動テスト
			@details	ID:リスト-11\n
						リスト末尾の要素追加テストです。\n
						リストに複数の要素がある場合に、末尾に追加した際の挙動を確認しています。\n
						末尾に要素が追加されていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushBack)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it);
			std::string str = "元々先頭の要素";
			it->name = str;

			//末尾に要素を追加
			it = list.GetEnd();
			EXPECT_TRUE(list.AddNode(it));

			//要素を確認
			it--;//1番目の要素へ
			EXPECT_EQ(str, it->name);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して要素を追加した際の挙動テスト
			@details	ID:リスト-12\n
						リストの要素追加テストです。\n
						リストに複数の要素がある場合に、中間位置に追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入され、その位置にあった要素が後ろにずれていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushToMiddle)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を2つ用意する
			list.AddNode(it);
			list.AddNode(it);

			EXPECT_EQ(2, list.GetSize());

			std::string str = "元々先頭の要素";
			it->name = str;

			EXPECT_TRUE(it == list.GetBegin());

			it++;//2つ目の要素へ
			std::string str2 = "元々２番目の要素";
			it->name = str2;

			//2番目に要素を追加
			EXPECT_TRUE(list.AddNode(it));

			//要素を確認
			it--;//1番目の要素へ
			EXPECT_EQ(str, it->name);
			EXPECT_EQ(str2, (it + 2)->name);

		}

		/**********************************************************************************//**
			@brief		ConstIteratorを渡して要素を追加した際の挙動テスト
			@details	ID:リスト-13\n
						リストの要素追加テストです。\n
						ConstIteratorを渡して要素列の先頭、中央、末尾に要素を追加した際の挙動を確認しています。\n
						イテレータの指す位置に要素が挿入され、その位置にあった要素が後ろにずれていれば成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushByConstIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			//要素を1つ用意
			list.AddNode(cit);

			const ResultData* pData = &*cit;
			int listSize = list.GetSize();

			//先頭に要素を追加
			EXPECT_TRUE(list.AddNode(cit));
			EXPECT_EQ(++listSize, list.GetSize());//要素が増えていることを確認
			EXPECT_EQ(pData, &*(cit + 1));//後ろにずれていることを確認


			//中央に要素を追加
			cit++;
			pData = &*cit;
			EXPECT_TRUE(list.AddNode(cit));
			EXPECT_EQ(++listSize, list.GetSize());//要素が増えていることを確認
			EXPECT_EQ(pData, &*(cit + 1));//後ろにずれていることを確認

			//末尾に要素を追加
			cit = list.GetConstEnd();
			pData = &*cit;
			EXPECT_TRUE(list.AddNode(cit));
			EXPECT_EQ(++listSize, list.GetSize());//要素が増えていることを確認
			EXPECT_EQ(pData, &*(cit + 1));//後ろにずれていることを確認

		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して要素を追加した際の挙動テスト
			@details	ID:リスト-14\n
						リストの要素追加テストです。\n
						不正なイテレータを渡して要素を追加した際の挙動を確認しています。\n
						要素数が増えていなければ成功です。\n
		*//***********************************************************************************/
		TEST(PushTest, PushByIrregularityIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			//リストの参照がないイテレータを渡す
			EXPECT_FALSE(list.AddNode(it));

			//別リストのイテレータを渡す
			DoublyLinkedList otherList;
			EXPECT_FALSE(list.AddNode(otherList.GetBegin()));

			//要素が追加されていないことを確認
			EXPECT_EQ(0, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		非constのメソッドであるか
			@details	ID:リスト-15 自動テストを行いません\n
						リストの要素追加テストです。\n
						constのリストから呼び出して、コンパイルエラーとなるかを確認しています。\n
		*//***********************************************************************************/
		TEST(PushTest, PushIsNotConstMethod)
		{
			//スキップ
		}


		//=================================== 要素の削除 ===================================

		/**********************************************************************************//**
			@brief		リストが空である場合に削除を行った際の挙動テスト
			@details	ID:リスト-16\n
						要素削除テストです。\n
						リストが空である場合に要素を削除した際の挙動を確認しています。\n
						リストが空のままであれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteWhenEmpty)
		{
			//先頭イテレータを渡す
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			EXPECT_FALSE(list.DeleteNode(it));
			EXPECT_EQ(0, list.GetSize());

			//末尾イテレータを渡す
			DoublyLinkedList list2;
			it = list2.GetEnd();
			EXPECT_FALSE(list2.DeleteNode(it));
			EXPECT_EQ(0, list2.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-17\n
						リスト先頭の要素削除テストです。\n
						リストに複数の要素がある場合に、先頭の要素を削除した際の挙動を確認しています。\n
						先頭要素が削除されていれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteBegin)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を２つ用意する
			list.AddNode(it);
			list.AddNode(it);
			std::string str = "元々先頭の要素";
			std::string str2 = "元々２番目の要素";
			it->name = str;
			(it + 1)->name = str2;

			//先頭の要素を削除
			EXPECT_TRUE(list.DeleteNode(it));

			//要素を確認 ２番目だった要素が先頭要素になっているか
			EXPECT_EQ(str2, it->name);
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、末尾イテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-18\n
						リスト末尾の要素削除テストです。\n
						リストに複数の要素がある場合に、末尾の要素を削除した際の挙動を確認しています。\n
						要素が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を追加しておく
			list.AddNode(it);

			//末尾の要素を削除
			it = list.GetEnd();
			EXPECT_FALSE(list.DeleteNode(it));

			//要素数を確認
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して削除した際の挙動テスト
			@details	ID:リスト-19\n
						リストの要素削除テストです。\n
						リストに複数の要素がある場合に、先頭でも末尾でもないイテレータを渡して要素を削除した際の挙動を確認しています。\n
						イテレータの指す位置の要素が削除されていれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteMiddle)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			//要素を2つ用意する
			list.AddNode(it);
			list.AddNode(it);
			std::string str = "元々先頭の要素";
			it->name = str;
			it++;//2番目の要素へ
			std::string str2 = "元々２番目の要素";
			it->name = str2;

			//2番目の要素を削除
			EXPECT_TRUE(list.DeleteNode(it));

			//要素を確認
			EXPECT_EQ(str, list.GetBegin()->name);
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		ConstIteratorを渡して要素を削除した際の挙動テスト
			@details	ID:リスト-20\n
						リストの要素削除テストです。\n
						ConstIteratorを渡して要素列の先頭、中央、末尾の要素を削除した際の挙動を確認しています。\n
						ConstIteratorの指す要素が削除されていれば成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteByConstIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			//要素を４つ用意 0123
			list.AddNode(cit);
			list.AddNode(cit);
			list.AddNode(cit);
			list.AddNode(cit);

			//先頭の要素を削除 _123
			const ResultData* pData = &*(cit + 1);//後ろの要素を格納
			EXPECT_TRUE(list.DeleteNode(cit));
			EXPECT_EQ(pData, &*cit);//後ろにあった要素が前にずれていることを確認

			//中央の要素を削除 1_3
			cit++;
			pData = &*(cit + 1);//後ろの要素を格納
			EXPECT_TRUE(list.DeleteNode(cit));
			EXPECT_EQ(pData, &*cit);//後ろにあった要素が前にずれていることを確認

			//末尾の要素を削除 13
			cit = list.GetConstEnd();
			EXPECT_FALSE(list.DeleteNode(cit));
			EXPECT_EQ(2, list.GetSize());//要素が減っていなければ成功
		}

		/**********************************************************************************//**
			@brief		不正なイテレータを渡して要素を削除した際の挙動テスト
			@details	ID:リスト-21\n
						リストの要素削除テストです。\n
						不正なイテレータを渡して要素を削除した際の挙動を確認しています。\n
						要素数が減っていなければ成功です。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteByIrregularityIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it;

			//要素を1つ用意する
			list.AddNode(list.GetBegin());

			//リストの参照がないイテレータを渡す
			EXPECT_FALSE(list.DeleteNode(it));

			//範囲外のイテレータを渡す
			EXPECT_FALSE(list.DeleteNode(list.GetBegin() + 1));

			//別リストの要素を指すイテレータを渡す
			DoublyLinkedList otherList;
			EXPECT_FALSE(list.DeleteNode(otherList.GetBegin()));

			//要素が削除されていないことを確認
			EXPECT_EQ(1, list.GetSize());
		}

		/**********************************************************************************//**
			@brief		非constのメソッドであるか
			@details	ID:リスト-22 自動テストを行いません\n
						リストの要素削除テストです。\n
						constのリストから呼び出して、コンパイルエラーとなるかを確認しています。\n
		*//***********************************************************************************/
		TEST(DeleteTest, DeleteIsNotConstMethod)
		{
			//スキップ
		}

		//================================= 先頭イテレータの取得 =================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-23\n
						先頭イテレータの取得機能のテストです。\n
						リストが空である場合に先頭イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallGetBeginWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_DEATH(list.GetBegin()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-24\n
						先頭イテレータの取得機能のテストです。\n
						リストに要素が一つある場合に先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallGetBeginWhenOneData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);

			std::string name = "先頭要素";
			it->name = name;

			EXPECT_EQ(name, list.GetBegin()->name);
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-25\n
						先頭イテレータの取得機能のテストです。\n
						リストに二つ以上の要素がある場合に先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallGetBeginWhenMultipledData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);
			list.AddNode(it);

			std::string name = "先頭要素";
			it->name = name;

			EXPECT_EQ(name, list.GetBegin()->name);
		}

		/**********************************************************************************//**
			@brief		要素の追加を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-26\n
						先頭イテレータの取得機能のテストです。\n
						先頭、中央、末尾に要素の追加を行った後に先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallGetBeginAffterAdd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator itBegin = list.GetBegin();

			//先頭に要素を追加
			list.AddNode(itBegin);
			EXPECT_TRUE(itBegin == list.GetBegin());
			//末尾に要素を追加
			list.AddNode(list.GetEnd());
			EXPECT_TRUE(itBegin == list.GetBegin());
			//中央に要素を追加
			list.AddNode(list.GetBegin() + 1);
			EXPECT_TRUE(itBegin == list.GetBegin());
		}

		/**********************************************************************************//**
			@brief		要素の削除を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-27\n
						先頭イテレータの取得機能のテストです。\n
						先頭、中央、末尾に要素の削除を行った後に先頭イテレータを取得した際の挙動を確認しています。\n
						先頭要素を指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallGetBeginAffterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator itBegin = list.GetBegin();

			//要素を3つ用意する
			list.AddNode(itBegin);
			list.AddNode(itBegin);
			list.AddNode(itBegin);

			//中央の要素を削除
			list.DeleteNode(itBegin + 1);
			EXPECT_TRUE(itBegin == list.GetBegin());
			//先頭の要素を削除
			list.DeleteNode(itBegin);
			EXPECT_TRUE(itBegin == list.GetBegin());
			//末尾の要素を削除
			EXPECT_FALSE(list.DeleteNode(list.GetEnd()));
			EXPECT_TRUE(itBegin == list.GetBegin());

		}

		/**********************************************************************************//**
			@brief		constのリストから呼び出した際の挙動テスト
			@details	ID:リスト-28 自動テストを行いません\n
						先頭イテレータの取得機能のテストです。\n
						constのリストから呼び出した際の挙動を確認しています。\n
						コンパイルエラーになれば成功です。\n
		*//***********************************************************************************/
		TEST(GetBeginTest, CallByConstList)
		{
			//スキップ
		}


		//=============================== 先頭コンストイテレータの取得 ===============================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-29\n
						先頭コンストイテレータの取得機能のテストです。\n
						リストが空である場合に取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallGetConstBeginWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_DEATH(list.GetConstBegin()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-30\n
						先頭コンストイテレータの取得機能のテストです。\n
						リストに要素が一つある場合に取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallGetConstBeginWhenOneData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			list.AddNode(cit);

			EXPECT_TRUE(cit == list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-31\n
						先頭コンストイテレータの取得機能のテストです。\n
						リストに二つ以上の要素がある場合に取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallGetConstBeginWhenMultipledData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			list.AddNode(cit);
			list.AddNode(cit);

			EXPECT_TRUE(cit == list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		要素の追加を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-32\n
						先頭コンストイテレータの取得機能のテストです。\n
						先頭、中央、末尾に要素の追加を行った後に取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallGetConstBeginAffterAdd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator citBegin = list.GetConstBegin();

			//先頭に要素を追加
			list.AddNode(citBegin);//自動的に先頭要素に移動する
			EXPECT_TRUE(citBegin == list.GetConstBegin());
			//末尾に要素を追加
			list.AddNode(list.GetEnd());
			EXPECT_TRUE(citBegin == list.GetConstBegin());
			//中央に要素を追加
			list.AddNode(list.GetBegin() + 1);
			EXPECT_TRUE(citBegin == list.GetConstBegin());
		}

		/**********************************************************************************//**
			@brief		要素の削除を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-33\n
						先頭コンストイテレータの取得機能のテストです。\n
						先頭、中央、末尾の要素を削除した後に取得した際の挙動を確認しています。\n
						先頭要素を指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallGetConstBeginAffterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::ConstIterator citBegin = list.GetConstBegin();

			//要素を3つ用意する
			list.AddNode(citBegin);
			list.AddNode(citBegin);
			list.AddNode(citBegin);

			//中央の要素を削除
			list.DeleteNode(citBegin + 1);
			EXPECT_TRUE(citBegin == list.GetConstBegin());
			//先頭の要素を削除
			list.DeleteNode(citBegin);
			EXPECT_TRUE(citBegin == list.GetConstBegin());
			//末尾の要素を削除
			EXPECT_FALSE(list.DeleteNode(list.GetEnd()));
			EXPECT_TRUE(citBegin == list.GetConstBegin());

		}

		/**********************************************************************************//**
			@brief		constのリストから呼び出した際の挙動テスト
			@details	ID:リスト-34 自動テストを行いません\n
						先頭コンストイテレータの取得機能のテストです。\n
						constのリストから呼び出した際の挙動を確認しています。\n
						コンパイルエラーにならなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetConstBeginTest, CallByConstList)
		{
			//スキップ
		}


		//================================= 末尾イテレータの取得 =================================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-35\n
						末尾イテレータの取得機能のテストです。\n
						リストが空である場合に末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallGetEndWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-36\n
						末尾イテレータの取得機能のテストです。\n
						リストに要素が一つある場合に末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallGetEndWhenOneData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-37\n
						末尾イテレータの取得機能のテストです。\n
						リストに二つ以上の要素がある場合に末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallGetEndWhenMultipledData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);
			list.AddNode(it);

			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		要素の追加を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-38\n
						末尾イテレータの取得機能のテストです。\n
						先頭、中央、末尾に要素の追加を行った後に末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallGetEndAffterAdd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			//先頭に要素を追加
			list.AddNode(it);
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
			//末尾に要素を追加
			list.AddNode(list.GetEnd());
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
			//中央に要素を追加
			list.AddNode(list.GetBegin() + 1);
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		要素の削除を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-39\n
						末尾イテレータの取得機能のテストです。\n
						先頭、中央、末尾の要素を削除した後に末尾イテレータを取得した際の挙動を確認しています。\n
						ダミーノードを指すイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallGetEndAffterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator itBegin = list.GetBegin();

			//要素を3つ用意する
			list.AddNode(itBegin);
			list.AddNode(itBegin);
			list.AddNode(itBegin);

			//中央の要素を削除
			list.DeleteNode(itBegin + 1);
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
			//先頭の要素を削除
			list.DeleteNode(itBegin);
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
			//末尾の要素を削除
			EXPECT_FALSE(list.DeleteNode(list.GetEnd()));//失敗することを確認
			EXPECT_DEATH(list.GetEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		constのリストから呼び出した際の挙動テスト
			@details	ID:リスト-40 自動テストを行いません\n
						末尾イテレータの取得機能のテストです。\n
						constのリストから呼び出した際の挙動を確認しています。\n
						コンパイルエラーになれば成功です。\n
		*//***********************************************************************************/
		TEST(GetEndTest, CallByConstList)
		{
			//スキップ
		}

		//============================== 末尾コンストイテレータの取得 ==============================

		/**********************************************************************************//**
			@brief		リストが空である場合に、呼び出した際の挙動テスト
			@details	ID:リスト-41\n
						末尾コンストイテレータの取得機能のテストです。\n
						リストが空である場合に取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallGetConstEndWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに要素が一つある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-42\n
						末尾コンストイテレータの取得機能のテストです。\n
						リストに要素が一つある場合に取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallGetConstEndWhenOneData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に、呼び出した際の挙動テスト
			@details	ID:リスト-43\n
						末尾コンストイテレータの取得機能のテストです。\n
						リストに二つ以上の要素がある場合に取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallGetConstEndWhenMultipledData)
		{
			DoublyLinkedList list;

			DoublyLinkedList::Iterator it = list.GetBegin();
			list.AddNode(it);
			list.AddNode(it);

			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		要素の追加を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-44\n
						末尾コンストイテレータの取得機能のテストです。\n
						先頭、中央、末尾に要素の追加を行った後に取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallGetConstEndAffterAdd)
		{
			DoublyLinkedList list;

			//先頭に要素を追加
			list.AddNode(list.GetBegin());
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
			//末尾に要素を追加
			list.AddNode(list.GetEnd());
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
			//中央に要素を追加
			list.AddNode(list.GetBegin() + 1);
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		要素の削除を行った後に、呼び出した際の挙動テスト
			@details	ID:リスト-45\n
						末尾コンストイテレータの取得機能のテストです。\n
						先頭、中央、末尾の要素を削除した後に取得した際の挙動を確認しています。\n
						ダミーノードを指すコンストイテレータを取得できれば成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallGetConstEndAffterDelete)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator itBegin = list.GetBegin();

			//要素を3つ用意する
			list.AddNode(itBegin);
			list.AddNode(itBegin);
			list.AddNode(itBegin);

			//中央の要素を削除
			list.DeleteNode(itBegin + 1);
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
			//先頭の要素を削除
			list.DeleteNode(itBegin);
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");
			//末尾の要素を削除
			EXPECT_FALSE(list.DeleteNode(list.GetEnd()));
			EXPECT_DEATH(list.GetConstEnd()++, "Assertion failed");

		}

		/**********************************************************************************//**
			@brief		constのリストから呼び出した際の挙動テスト
			@details	ID:リスト-46 自動テストを行いません\n
						末尾コンストイテレータの取得機能のテストです。\n
						constのリストから呼び出した際の挙動を確認しています。\n
						コンパイルエラーにならなければ成功です。\n
		*//***********************************************************************************/
		TEST(GetConstEndTest, CallByConstList)
		{
			//スキップ
		}

		//=============================== イテレータの指す要素の取得 ===============================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で要素を取得した際の挙動テスト
			@details	ID:イテレータ-0\n
						イテレータの要素取得機能のテストです。\n
						リストの参照がない状態で要素を取得した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetNodeTest, GetNodeWhenNoReference)
		{
			DoublyLinkedList::Iterator it;
			EXPECT_DEATH(it->name, "Assertion failed");//エラーになれば成功

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit;
			EXPECT_DEATH(cit->name, "Assertion failed");//エラーになれば成功
		}

		/**********************************************************************************//**
			@brief		イテレータから取得した要素に対して、値を代入した際の挙動テスト
			@details	ID:イテレータ-1\n
						イテレータの要素取得機能のテストです。\n
						イテレータから取得した要素に対して、値を代入した際の挙動を確認しています。\n
						値が変わっていれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetNodeTest, GetNodeAndAssignment)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			std::string testString = "テスト";
			list.AddNode(it);
			it->name = testString;

			EXPECT_EQ(testString, it->name);
		}

		/**********************************************************************************//**
			@brief		コンストイテレータから取得した要素に対して、値を代入した際の挙動テスト
			@details	ID:イテレータ-2 自動テストを行いません\n
						コンストイテレータの要素取得機能のテストです。\n
						コンストイテレータから取得した要素に対して、値を代入した際の挙動を確認しています。\n
						コンパイルエラーになれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetNodeTest, ConstIteratorGetDataAndAssignment)
		{
			//スキップ
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータから要素を取得した際の挙動テスト
			@details	ID:イテレータ-3\n
						イテレータの要素取得機能のテストです。\n
						リストが空の際に先頭イテレータから要素を取得した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetNodeTest, GetTopNodeWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_DEATH(it->name, "Assertion failed");//エラーになれば成功

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			EXPECT_DEATH(cit->name, "Assertion failed");//エラーになれば成功
		}


		/**********************************************************************************//**
			@brief		末尾イテレータから要素を取得した際の挙動テスト
			@details	ID:イテレータ-4\n
						イテレータの要素取得機能のテストです。\n
						末尾イテレータから要素を取得した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorGetNodeTest, GetNodeByEnd)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(it->name, "Assertion failed");//エラーになれば成功

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();
			EXPECT_DEATH(cit->name, "Assertion failed");//エラーになれば成功
		}

		//======================== イテレータをリストの末尾に向かって一つ進める ===========================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:イテレータ-5\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						リストの参照がない状態で呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, IncrementWhenNoReference)
		{
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(it++, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit;
			EXPECT_DEATH(cit++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:イテレータ-6\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						リストが空の際の、先頭イテレータに対して呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, IncrementWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_DEATH(it++, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			EXPECT_DEATH(cit++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:イテレータ-7\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						末尾イテレータに対して呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, IncrementToEndIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(it++, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();
			EXPECT_DEATH(cit++, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動テスト
			@details	ID:イテレータ-8\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
						次の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, IncrementWhenMultipleData)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			list.AddNode(it);
			list.AddNode(it);

			std::string test1 = "1";
			std::string test2 = "2";

			it->name = test1;
			(it + 1)->name = test2;

			//先頭要素　2番目の要素　末尾ダミーの順に確認
			EXPECT_EQ(test1, it->name);
			it++;
			EXPECT_EQ(test2, it->name);
			it++;
			EXPECT_TRUE(list.GetEnd() == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			//先頭要素　2番目の要素　末尾ダミーの順に確認
			EXPECT_EQ(test1, cit->name);
			cit++;
			EXPECT_EQ(test2, cit->name);
			cit++;
			EXPECT_TRUE(list.GetEnd() == cit);
		}

		/**********************************************************************************//**
			@brief		前置インクリメントを行った際の挙動テスト
			@details	ID:イテレータ-9\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						前置インクリメントを行った際の挙動を確認しています。\n
						次の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, ForwardIncrement)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//前置インクリメント時と実行後に確認
			EXPECT_TRUE(list.GetEnd() == ++it);
			EXPECT_TRUE(list.GetEnd() == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			//後置インクリメント時と実行後に確認
			EXPECT_TRUE(list.GetEnd() == ++cit);
			EXPECT_TRUE(list.GetEnd() == cit);
		}

		/**********************************************************************************//**
			@brief		後置インクリメントを行った際の挙動テスト
			@details	ID:イテレータ-10\n
						イテレータの末尾に向かって一つ進める機能のテストです。\n
						後置インクリメントを行った際の挙動を確認しています。\n
						次の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorIncrement, BackwardIncrement)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//後置インクリメント時と実行後に確認
			EXPECT_TRUE(list.GetBegin() == it++);
			EXPECT_TRUE(list.GetEnd() == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			//後置インクリメント時と実行後に確認
			EXPECT_TRUE(list.GetBegin() == cit++);
			EXPECT_TRUE(list.GetEnd() == cit);
		}

		//======================== イテレータをリストの先頭に向かって一つ進める ===========================

		/**********************************************************************************//**
			@brief		リストの参照がない状態で呼び出した際の挙動テスト
			@details	ID:イテレータ-11\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						リストの参照がない状態で呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, DecrementWhenNoReference)
		{
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(it--, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit;
			EXPECT_DEATH(cit--, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストが空の際の、末尾イテレータに対して呼び出した際の挙動テスト
			@details	ID:イテレータ-12\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						リストが空の際の、末尾イテレータに対して呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, DecrementWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			EXPECT_DEATH(it--, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();
			EXPECT_DEATH(cit--, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		先頭イテレータに対して呼び出した際の挙動テスト
			@details	ID:イテレータ-13\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						先頭イテレータに対して呼び出した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, DecrementToEndIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_DEATH(it--, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			EXPECT_DEATH(cit--, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		リストに二つ以上の要素がある場合に呼び出した際の挙動テスト
			@details	ID:イテレータ-14\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
						前の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, DecrementWhenMultipleData)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetEnd();

			list.AddNode(it);
			list.AddNode(it);

			std::string test1 = "1";
			std::string test2 = "2";

			it->name = test1;
			(it + 1)->name = test2;

			//末尾ダミー　2番目の要素　先頭要素の順に確認
			it = list.GetEnd();
			EXPECT_TRUE(list.GetEnd() == it);
			it--;
			EXPECT_EQ(test2, it->name);
			it--;
			EXPECT_EQ(test1, it->name);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();

			//末尾ダミー　2番目の要素　先頭要素の順に確認
			EXPECT_TRUE(list.GetEnd() == cit);
			cit--;
			EXPECT_EQ(test2, cit->name);
			cit--;
			EXPECT_EQ(test1, cit->name);
		}

		/**********************************************************************************//**
			@brief		前置デクリメントを行った際の挙動テスト
			@details	ID:イテレータ-15\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						前置デクリメントを行った際の挙動を確認しています。\n
						次の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, ForwardDecrement)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//前置デクリメント実行時と実行後に確認
			it = list.GetEnd();
			EXPECT_TRUE(list.GetBegin() == --it);
			EXPECT_TRUE(list.GetBegin() == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();

			//前置デクリメント実行時と実行後に確認
			EXPECT_TRUE(list.GetBegin() == --cit);
			EXPECT_TRUE(list.GetBegin() == cit);
		}

		/**********************************************************************************//**
			@brief		後置デクリメントを行った際の挙動テスト
			@details	ID:イテレータ-16\n
						イテレータの先頭に向かって一つ進める機能のテストです。\n
						後置デクリメントを行った際の挙動を確認しています。\n
						次の要素を指すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorDecrement, BackwardDecrement)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//後置デクリメント実行時と実行後に確認
			it = list.GetEnd();
			EXPECT_TRUE(list.GetEnd() == it--);
			EXPECT_TRUE(list.GetBegin() == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();

			//後置デクリメント実行時と実行後に確認
			EXPECT_TRUE(list.GetEnd() == cit--);
			EXPECT_TRUE(list.GetBegin() == cit);
		}

		//============================== イテレータのコピー =================================

		/**********************************************************************************//**
			@brief		ConstIteratorから、Iteratorのコピーを行った際の挙動テスト
			@details	ID:イテレータ-17 自動テストを行いません\n
						イテレータのコピー機能のテストです。\n
						ConstIteratorから、Iteratorのコピーを行った際の挙動を確認しています。\n
						コンパイルエラーになると成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCopy, ConstIteratorToIterator)
		{
			//スキップ
		}

		/**********************************************************************************//**
			@brief		コピーコンストラクトを行った際の挙動テスト
			@details	ID:イテレータ-18\n
						イテレータのコピー機能のテストです。\n
						コピーコンストラクトを行った際の挙動を確認しています。\n
						コピーコンストラクト後の値がコピー元と等しいければ成功です。\n
		*//***********************************************************************************/
		TEST(IteratorCopy, CopyConstruct)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2 = it;

			EXPECT_TRUE(it == it2);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			DoublyLinkedList::ConstIterator cit2 = cit;
			EXPECT_TRUE(cit == cit2);
		}

		//=============================== イテレータの代入 ==================================

		/**********************************************************************************//**
			@brief		IteratorにConstIteratorを代入した際の挙動テスト
			@details	ID:イテレータ-19 自動テストを行いません\n
						イテレータの代入のテストです。\n
						IteratorにConstIteratorを代入した際の挙動を確認しています。\n
						コンパイルエラーとなれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorAssignment, ConstIteratorToIterator)
		{
			//スキップ
		}

		/**********************************************************************************//**
			@brief		イテレータを代入した際の挙動テスト
			@details	ID:イテレータ-20\n
						イテレータの代入のテストです。\n
						イテレータを代入した際の挙動を確認しています。\n
						代入後の値がコピー元と等しければ成功です。\n
		*//***********************************************************************************/
		TEST(IteratorAssignment, IteratorAssignment)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator it2;

			it2 = it;

			EXPECT_TRUE(it == it2);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			DoublyLinkedList::ConstIterator cit2;
			cit2 = cit;
			EXPECT_TRUE(cit == cit2);
		}

		//============================= 二つのイテレータが同一のものか比較する ================================

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータが同一か比較した際の挙動テスト
			@details	ID:イテレータ-21\n
						イテレータの比較テストです。\n
						リストが空の状態での先頭イテレータと末尾イテレータが同一かどうか比較した際の挙動を確認しています。\n
						戻り値が真であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonEqualBeginAndEndWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_TRUE(list.GetBegin() == list.GetEnd());
			EXPECT_TRUE(list.GetConstBegin() == list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		同一のイテレータが同一か比較した際の挙動テスト
			@details	ID:イテレータ-22\n
						イテレータの比較テストです。\n
						同一のイテレータが同一かどうか比較した際の挙動を確認しています。\n
						戻り値が真であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonEqualSameOne)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_TRUE(it == it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			EXPECT_TRUE(cit == cit);

			//コンストイテレータとイテレータ
			EXPECT_TRUE(cit == it);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータが同一か比較した際の挙動テスト
			@details	ID:イテレータ-23\n
						イテレータの比較テストです。\n
						異なるイテレータが同一かどうか比較した際の挙動を確認しています。\n
						戻り値が偽であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonEqualDifferentOne)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//示す要素が異なる
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_FALSE(it == it2);

			//参照するリストが異なる
			DoublyLinkedList list2;

			it2 = list2.GetBegin();

			EXPECT_FALSE(it == it2);

			//コンストイテレータ
			//示す要素が異なる
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();
			EXPECT_FALSE(it == cit);

			//参照するリストが異なる
			cit = list2.GetBegin();
			EXPECT_FALSE(it == cit);
		}

		//============================ 二つのイテレータが異なるのものか比較する ==============================

		/**********************************************************************************//**
			@brief		リストが空の状態での先頭イテレータと末尾イテレータが異なるか比較した際の挙動テスト
			@details	ID:イテレータ-24\n
						イテレータの比較テストです。\n
						リストが空の状態での先頭イテレータと末尾イテレータが異なるものか比較した際の挙動を確認しています。\n
						戻り値が偽であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonNotEqualBeginAndEndWhenEmpty)
		{
			DoublyLinkedList list;
			EXPECT_FALSE(list.GetBegin() != list.GetEnd());

			//コンストイテレータ
			EXPECT_FALSE(list.GetConstBegin() != list.GetConstEnd());
		}

		/**********************************************************************************//**
			@brief		同一のイテレータが異なるものか比較した際の挙動テスト
			@details	ID:イテレータ-25\n
						イテレータの比較テストです。\n
						同一のイテレータが異なるものか比較した際の挙動を確認しています。\n
						戻り値が偽であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonNotEqualSameOne)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			EXPECT_FALSE(it != it);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();
			EXPECT_FALSE(cit != cit);
		}

		/**********************************************************************************//**
			@brief		異なるイテレータが異なるものか比較した際の挙動テスト
			@details	ID:イテレータ-26\n
						イテレータの比較テストです。\n
						異なるイテレータが異なるものか比較した際の挙動を確認しています。\n
						戻り値が真であれば成功です。\n
		*//***********************************************************************************/
		TEST(IteratorComparison, ComparisonNotEqualDifferentOne)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			//示す要素が異なる
			DoublyLinkedList::Iterator it2 = list.GetEnd();

			EXPECT_TRUE(it != it2);

			//参照するリストが異なる
			DoublyLinkedList list2;

			it2 = list2.GetBegin();

			EXPECT_TRUE(it != it2);

			//コンストイテレータ
			//示す要素が異なる
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();
			EXPECT_TRUE(it != cit);

			//参照するリストが異なる
			cit = list2.GetConstBegin();
			EXPECT_TRUE(it != cit);
		}

		//====================== 末尾に指定した数進めたイテレータを返す ==========================

		/**********************************************************************************//**
			@brief		イテレータの末尾に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-0\n
						イテレータの末尾に進めたイテレータを返す機能のテストです。\n
						リストの参照がない場合に実行した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorPlus, PlusWhenNoReference)
		{
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(it + 1, "Assertion failed");
			EXPECT_DEATH(it + 0, "Assertion failed");
			EXPECT_DEATH(it + -1, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit;

			EXPECT_DEATH(cit + 1, "Assertion failed");
			EXPECT_DEATH(cit + 0, "Assertion failed");
			EXPECT_DEATH(cit + -1, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		イテレータの末尾に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-1\n
						イテレータの末尾に進めたイテレータを返す機能のテストです。\n
						リストが空の場合に先頭イテレータに対して呼び出した際の挙動を確認しています。\n
						末尾のイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorPlus, PlusWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator itEnd = list.GetEnd();

			EXPECT_TRUE(it + 1 == itEnd);
			EXPECT_TRUE(it + 0 == itEnd);
			EXPECT_TRUE(it + -1 == itEnd);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			EXPECT_TRUE(cit + 1 == itEnd);
			EXPECT_TRUE(cit + 0 == itEnd);
			EXPECT_TRUE(cit + -1 == itEnd);
		}

		/**********************************************************************************//**
			@brief		イテレータの末尾に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-2\n
						イテレータの末尾に進めたイテレータを返す機能のテストです。\n
						末尾イテレータに対して呼び出した際の挙動を確認しています。\n
						０、正の数では末尾のイテレータを返し、負の数では先頭に移動したイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorPlus, CallByEndIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			it = list.GetEnd();
			EXPECT_TRUE((it + 1) == list.GetEnd());
			EXPECT_TRUE((it + 0) == list.GetEnd());
			EXPECT_TRUE((it + -1) == list.GetBegin());

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstEnd();

			EXPECT_TRUE((cit + 1) == list.GetEnd());
			EXPECT_TRUE((cit + 0) == list.GetEnd());
			EXPECT_TRUE((cit + -1) == list.GetBegin());

		}

		/**********************************************************************************//**
			@brief		イテレータの末尾に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-3\n
						イテレータの末尾に進めたイテレータを返す機能のテストです。\n
						リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
						指定数移動したイテレータを返し、範囲外の数では末尾または先頭のイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorPlus, PlusWhenMultipleData)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);
			list.AddNode(it);

			it++;//二番目の要素へ

			EXPECT_TRUE((it + 2) == list.GetEnd());//末尾範囲外
			EXPECT_TRUE((it + 1) == list.GetEnd());//末尾
			EXPECT_TRUE((it + 0) == ++list.GetBegin());//２番目の要素
			EXPECT_TRUE((it + -1) == list.GetBegin());//先頭
			EXPECT_TRUE((it + -2) == list.GetBegin());//先頭範囲外

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			cit++;//２番目の要素へ

			EXPECT_TRUE((cit + 2) == list.GetEnd());
			EXPECT_TRUE((cit + 1) == list.GetEnd());
			EXPECT_TRUE((cit + 0) == ++list.GetBegin());
			EXPECT_TRUE((cit + -1) == list.GetBegin());
			EXPECT_TRUE((cit + -2) == list.GetBegin());
		}

		//====================== 先頭に指定した数進めたイテレータを返す ==========================

		/**********************************************************************************//**
			@brief		イテレータの先頭に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-4\n
						イテレータの先頭に進めたイテレータを返す機能のテストです。\n
						リストの参照がない場合に実行した際の挙動を確認しています。\n
						Assert発生で成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorMinus, MinusWhenNoReference)
		{
			DoublyLinkedList::Iterator it;

			EXPECT_DEATH(it - 1, "Assertion failed");
			EXPECT_DEATH(it - 0, "Assertion failed");
			EXPECT_DEATH(it - -1, "Assertion failed");

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit;

			EXPECT_DEATH(cit - 1, "Assertion failed");
			EXPECT_DEATH(cit - 0, "Assertion failed");
			EXPECT_DEATH(cit - -1, "Assertion failed");
		}

		/**********************************************************************************//**
			@brief		イテレータの先頭に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-5\n
						イテレータの先頭に進めたイテレータを返す機能のテストです。\n
						リストが空の場合に先頭イテレータに対して呼び出した際の挙動を確認しています。\n
						先頭のイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorMinus, MinusWhenEmpty)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();
			DoublyLinkedList::Iterator itBegin = list.GetBegin();

			EXPECT_TRUE(it - 1 == itBegin);
			EXPECT_TRUE(it - 0 == itBegin);
			EXPECT_TRUE(it - -1 == itBegin);

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			EXPECT_TRUE(cit - 1 == itBegin);
			EXPECT_TRUE(cit - 0 == itBegin);
			EXPECT_TRUE(cit - -1 == itBegin);
		}

		/**********************************************************************************//**
			@brief		イテレータの先頭に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-6\n
						イテレータの先頭に進めたイテレータを返す機能のテストです。\n
						先頭イテレータに対して呼び出した際の挙動を確認しています。\n
						０、正の数では先頭のイテレータを返し、負の数では末尾に移動したイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorMinus, CallByTopIterator)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			list.AddNode(it);

			EXPECT_TRUE((it - 1) == list.GetBegin());
			EXPECT_TRUE((it - 0) == list.GetBegin());
			EXPECT_TRUE((it - -1) == list.GetEnd());

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			EXPECT_TRUE((cit - 1) == list.GetBegin());
			EXPECT_TRUE((cit - 0) == list.GetBegin());
			EXPECT_TRUE((cit - -1) == list.GetEnd());

		}

		/**********************************************************************************//**
			@brief		イテレータの先頭に指定した数進めたイテレータを返す機能の挙動テスト
			@details	ID:イテレータ追加機能-7\n
						イテレータの先頭に進めたイテレータを返す機能のテストです。\n
						リストに二つ以上の要素がある場合に呼び出した際の挙動を確認しています。\n
						指定数移動したイテレータを返し、範囲外の数では末尾または先頭のイテレータを返すと成功です。\n
		*//***********************************************************************************/
		TEST(IteratorOperatorMinus, MinusWhenMultipleData)
		{
			DoublyLinkedList list;
			DoublyLinkedList::Iterator it = list.GetBegin();

			//要素を2つ用意
			list.AddNode(it);
			list.AddNode(it);

			it++;//二番目の要素へ

			EXPECT_TRUE((it - 2) == list.GetBegin());//先頭範囲外
			EXPECT_TRUE((it - 1) == list.GetBegin());//先頭
			EXPECT_TRUE((it - 0) == ++list.GetBegin());//２番目の要素
			EXPECT_TRUE((it - -1) == list.GetEnd());//末尾
			EXPECT_TRUE((it - -2) == list.GetEnd());//末尾範囲外

			//コンストイテレータ
			DoublyLinkedList::ConstIterator cit = list.GetConstBegin();

			cit++;//２番目の要素へ

			EXPECT_TRUE((cit - 2) == list.GetBegin());//先頭範囲外
			EXPECT_TRUE((cit - 1) == list.GetBegin());//先頭
			EXPECT_TRUE((cit - 0) == ++list.GetBegin());//２番目の要素
			EXPECT_TRUE((cit - -1) == list.GetEnd());//末尾
			EXPECT_TRUE((cit - -2) == list.GetEnd());//末尾範囲外
		}

		//TODO コンストのイテレータについて同じテストをする
	}//namespace chapter2
}//namespace ex01_DataStructure