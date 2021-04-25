#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;
//最近最少缓存算法（key,value）
class LRUCache
{
public:
	LRUCache(unsigned int capacity) :_capacity(capacity) {};
	~LRUCache();
	//获取
	int get(int key);
	//设置
	void set(int key, int value);

private:
	//1、list双向链表
	list<pair<int, int>>_list;

	//2、使用unordered_map
	//由于需要快速定位链表的结点，故在map中使用value字段来存储链表的结点
	//这里是使用了迭代器
	unordered_map<int, list<pair<int, int>>::iterator>_map;
	unsigned int _capacity;
};

void LRUCache::set(int key,int value)
{
	//1、查询是否在缓存中
	auto iteramap = _map.find(key);
	if (iteramap != _map.end()) {
		//2、在缓存中，需要在链表中删除
		_list.erase(iteramap->second);
		//3、把数据放到链表头
		_list.push_front(pair<int, int>(key, value));
		_map[key] = _list.begin();

	}
	else
	{
		if (_map.size() >= _capacity) {
			//4、缓存已经满了
			//4.1hash处要删除
			_map.erase(_list.back().first);
			//4.2链表也要删除尾巴部分
			_list.pop_back();
		}
		//5、双向链表首节点插入
		_list.push_front(pair<int, int >(key, value));
		//6、在哈希中增加
		_map[key] = _list.begin();
	}
}

//获取：根据key，获取缓存的value
int LRUCache::get(int key)
{
	//1、先从hash中查找
	auto iteramap= _map.find(key);
	if (iteramap == _map.end()) {
		//没找到，
		return -1;
	}

	//2、如果在缓存中，需要把数据放到链表头部
	_list.push_front(pair<int, int>(key, iteramap->second->second));
	_list.erase(iteramap->second);

	//3、hash原来存储的失效，需要重新设置
	_map[key] = _list.begin();

	//4、返回value值
	return iteramap->second->second;
}