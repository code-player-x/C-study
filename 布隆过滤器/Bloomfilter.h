#pragma once
#include "bitset.h"
#include<iostream>
#include <string>
using namespace std;
namespace px1
{

	struct HashStr1
	{
		// BKDR
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= 131;
				hash += str[i];
			}

			return hash;
		}
	};

	struct HashStr2
	{
		// RSHash
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			size_t magic = 63689; // ħ��
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= magic;
				hash += str[i];
				magic *= 378551;
			}

			return hash;
		}
	};

	struct HashStr3
	{
		// SDBMHash
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0; i < str.size(); ++i)
			{
				hash *= 65599;
				hash += str[i];
			}

			return hash;
		}
	};

	template <class K = string,  
	class Hash1 = HashStr1,
	class Hash2 = HashStr2,
	class Hash3 = HashStr3>

	//��¡������
	class bloomfilter
	{
	public:
		bloomfilter(size_t num)
			:_bs(5 * num)//λͼ
			, _N(5 * num)//5�ǿ���ͨ����ʽ��������ģ��ٶ�������¡������ԭ���ɵõ�
		{}

		void set(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;//Hash1�Ƿº��������ͣ�Hash3()�Ƿº����Ķ���һ����������
			size_t index2 = Hash2()(key) % _N;
			size_t index3 = Hash3()(key) % _N;

			cout << index1 << endl;
			cout << index2 << endl;
			cout << index3 << endl << endl;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			if (_bs.test(index1) == false)
				return false;

			size_t index2 = Hash2()(key) % _N;
			if (_bs.test(index2) == false)
				return false;

			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
				return false;

			return true; // ��������Ҳ��һ��������ڣ����ǿ��ܴ�������

			// �ж��ڣ��ǲ�׼ȷ�ģ����ܴ�������
			// �жϲ��ڣ���׼ȷ
		}

		void reset(const K& key)
		{
			// ��ӳ���λ�ø���0�Ϳ��ԣ�
			// ��֧��ɾ�������ܻ������ɾ��һ�㲼¡��������֧��ɾ��
		}

	private:
		px::bitset _bs; // λͼ
		size_t _N;
	};

	void test_bloomfilter()
	{
		bloomfilter<std::string> bf(100);
		bf.set("abcd");
		bf.set("aadd");
		bf.set("bcad");

		cout << bf.test("abcd") << endl;
		cout << bf.test("aadd") << endl;
		cout << bf.test("bcad") << endl;
		cout << bf.test("cbad") << endl;
	}
}