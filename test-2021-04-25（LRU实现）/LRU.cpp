#include<iostream>
#include<string>
#include<unordered_map>
#include<list>
using namespace std;
//������ٻ����㷨��key,value��
class LRUCache
{
public:
	LRUCache(unsigned int capacity) :_capacity(capacity) {};
	~LRUCache();
	//��ȡ
	int get(int key);
	//����
	void set(int key, int value);

private:
	//1��list˫������
	list<pair<int, int>>_list;

	//2��ʹ��unordered_map
	//������Ҫ���ٶ�λ����Ľ�㣬����map��ʹ��value�ֶ����洢����Ľ��
	//������ʹ���˵�����
	unordered_map<int, list<pair<int, int>>::iterator>_map;
	unsigned int _capacity;
};

void LRUCache::set(int key,int value)
{
	//1����ѯ�Ƿ��ڻ�����
	auto iteramap = _map.find(key);
	if (iteramap != _map.end()) {
		//2���ڻ����У���Ҫ��������ɾ��
		_list.erase(iteramap->second);
		//3�������ݷŵ�����ͷ
		_list.push_front(pair<int, int>(key, value));
		_map[key] = _list.begin();

	}
	else
	{
		if (_map.size() >= _capacity) {
			//4�������Ѿ�����
			//4.1hash��Ҫɾ��
			_map.erase(_list.back().first);
			//4.2����ҲҪɾ��β�Ͳ���
			_list.pop_back();
		}
		//5��˫�������׽ڵ����
		_list.push_front(pair<int, int >(key, value));
		//6���ڹ�ϣ������
		_map[key] = _list.begin();
	}
}

//��ȡ������key����ȡ�����value
int LRUCache::get(int key)
{
	//1���ȴ�hash�в���
	auto iteramap= _map.find(key);
	if (iteramap == _map.end()) {
		//û�ҵ���
		return -1;
	}

	//2������ڻ����У���Ҫ�����ݷŵ�����ͷ��
	_list.push_front(pair<int, int>(key, iteramap->second->second));
	_list.erase(iteramap->second);

	//3��hashԭ���洢��ʧЧ����Ҫ��������
	_map[key] = _list.begin();

	//4������valueֵ
	return iteramap->second->second;
}