#pragma once
#include<vector>
template <class V,class W,bool Direction=false>//Direction用于定义是有向图还是无向图
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
			throw invalid_argument("非法顶点");
		}
	}
	void AddEdge(const V& src, const V&dst,const W& w)
	{
		int srcIndex = GetVertexIndex(src);
		int dstIndex = GetVertexIndex(dst);

		_matrix[srcIndex][dstIndex] = w;

		if (Direction == false)
			_matrix[dstIndex][srcIndex] = w;//无向图的邻接矩阵是对称的


	}

private:
	vector<V> _vertexs; //顶点集合
	map<V, int> _vertexIndexMap;
	vector<vector<int>> _matrix;//表示邻接矩阵的边
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
	template <class V, class W, bool Direction = false>//Direction用于定义是有向图还是无向图
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
				throw invalid_argument("非法顶点");
			}
		}
		void AddEdge(const V& src, const V&dst, const W& w)
		{
			int srcIndex = GetVertexIndex(src);
			int dstIndex = GetVertexIndex(dst);

			_matrix[srcIndex][dstIndex] = w;

			if (Direction == false)
				_matrix[dstIndex][srcIndex] = w;//无向图的邻接矩阵是对称的


		}

	private:
		vector<V> _vertexs; //顶点集合
		map<V, int> _vertexIndexMap;
		vector<vector<int>> _matrix;//表示邻接矩阵的边
	};



}

