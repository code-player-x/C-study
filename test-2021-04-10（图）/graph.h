#pragma once
#include<vector>
template <class V,class W,bool Direction=false>//Direction���ڶ���������ͼ��������ͼ
class Graph
{
public:
	Graph(V* vertexs, int n)
	{
		_vertexs.reserve(n);
		for(int i = 0; i < n; ++i)
		{
			_vertexs.push_back(vertexs[i]);
			_vertexIndexMap[vertexs[i]] = i;
		}
		_matrix.resize(n);
		for (size_t i = 0; i < n; ++i)
		{
			_matrix[i].resize(n, W());
		}

	}

	int GetVertexIndex(const V&v)
	{
		auto it = _vertexIndexMap.find(v);
		if (it != _vertexIndexMap.end())
		{
			return it->second;
		}
		else
		{
			//return -1;
			throw invalid_argument("�Ƿ�����");
		}
	}
	void AddEdge(const V& src, const V&dst,const W& w)
	{
		int srcIndex = GetVertexIndex(src);
		int dstIndex = GetVertexIndex(dst);

		_matrix[srcIndex][dstIndex] = w;

		if (Direction == false)
			_matrix[dstIndex][srcIndex] = w;//����ͼ���ڽӾ����ǶԳƵ�


	}

private:
	vector<V> _vertexs; //���㼯��
	map<V, int> _vertexIndexMap;
	vector<vector<int>> _matrix;//��ʾ�ڽӾ���ı�
};

namespace table
{
	template<class W>
	struct EdgeNode
	{
		int srcIndex;
		int dstIndex;
		const

	};
	template <class V, class W, bool Direction = false>//Direction���ڶ���������ͼ��������ͼ
	class Graph
	{
	public:
		Graph(V* vertexs, int n)
		{
			_vertexs.reserve(n);
			for (int i = 0; i < n; ++i)
			{
				_vertexs.push_back(vertexs[i]);
				_vertexIndexMap[vertexs[i]] = i;
			}
			_matrix.resize(n);
			for (size_t i = 0; i < n; ++i)
			{
				_matrix[i].resize(n, W());
			}

		}

		int GetVertexIndex(const V&v)
		{
			auto it = _vertexIndexMap.find(v);
			if (it != _vertexIndexMap.end())
			{
				return it->second;
			}
			else
			{
				//return -1;
				throw invalid_argument("�Ƿ�����");
			}
		}
		void AddEdge(const V& src, const V&dst, const W& w)
		{
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);

			_matrix[srcIndex][dstIndex] = w;

			if (Direction == false)
				_matrix[dstIndex][srcIndex] = w;//����ͼ���ڽӾ����ǶԳƵ�


		}

	private:
		vector<V> _vertexs; //���㼯��
		map<V, int> _vertexIndexMap;
		vector<vector<int>> _matrix;//��ʾ�ڽӾ���ı�
	};



}

