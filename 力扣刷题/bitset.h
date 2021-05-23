#pragma once
#include<vector>
namespace px
{
	class bitset
	{
	public:
		bitset(size_t N)
		{
			_bits.resize(N / 32 + 1, 0);
			_num = 0;
		}

		void set(size_t x)
		{
			size_t index = x / 32;//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;//���x�����͵ĵڼ�λ

			_bits[index] |= (1 << pos);//��pos��λ�ó�1
		}

		void reset(size_t x)
		{
			size_t index = x / 32;//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;//���x�����͵ĵڼ�λ
			_bits[index] &= ~(1 << pos); //��pos��λ�ó�0
		}
		// �ж�x�ڲ���(Ҳ����˵xӳ���λ�Ƿ�Ϊ1)
		bool test(size_t x)
		{
			size_t index = x / 32;//���ӳ���λ���ڵڼ�������
			size_t pos = x % 32;//���x�����͵ĵڼ�λ
			return _bits[index] & (1 << pos);
		}
	private:
		std::vector<int> _bits;
		size_t _num;//ӳ��洢���ٸ�����
	};

	void test_bitset()
	{
		//bitset bs(100);
		//bs.set(99);
		//bs.set(98);
		//bs.set(97);
		//bs.set(5);
		//bs.reset(98);
		//for (size_t i= 0; i < 100; ++i)
		//{
		//	printf("[%d]:%d\n", i, bs.test(i));
		//}

		//��ο��޷������ͷ�Χ��λͼ
		//��1��bitset bs(-1); //-1���ڴ����ǲ���
		//��2��bitset bs(pow(2,32));//2��32��
		//��3��biset bs(0xffffffff);//16�������ֵ
		bitset bs(-1);
	}
}
