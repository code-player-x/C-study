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
			size_t index = x / 32;//算出映射的位置在第几个整型
			size_t pos = x % 32;//算出x在整型的第几位

			_bits[index] |= (1 << pos);//第pos个位置成1
		}

		void reset(size_t x)
		{
			size_t index = x / 32;//算出映射的位置在第几个整型
			size_t pos = x % 32;//算出x在整型的第几位
			_bits[index] &= ~(1 << pos); //第pos个位置成0
		}
		// 判断x在不在(也就是说x映射的位是否为1)
		bool test(size_t x)
		{
			size_t index = x / 32;//算出映射的位置在第几个整型
			size_t pos = x % 32;//算出x在整型的第几位
			return _bits[index] & (1 << pos);
		}
	private:
		std::vector<int> _bits;
		size_t _num;//映射存储多少个数据
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

		//如何开无符号整型范围的位图
		//法1：bitset bs(-1); //-1在内存中是补码
		//法2：bitset bs(pow(2,32));//2的32次
		//法3：biset bs(0xffffffff);//16进制最大值
		bitset bs(-1);
	}
}
