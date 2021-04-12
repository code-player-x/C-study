#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<queue>
namespace px{
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
		void _DFS(int srcIndex,vector<bool>&visited)
		{
			cout << _vertexs[srcIndex] << " : " << srcIndex << "->";
			visited[srcIndex] = true;
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (_matrix[srcIndex][i] != W() && visited[i] == false)
				{
					_DFS(i, visited);
				}
			}

		}
		void DFS(const V& src)
		{
			vector<bool> visited(_vertexs.size(), false);
			int srcIndex = GetVertexIndex(src);
			_DFS(srcIndex, visited);
			cout << endl;
		}

		void BFS(const V& src)
		{
			vector<bool>visited(_vertexs.size(), false);
			int srcIndex = GetVertexIndex(src);

			queue<int>q;
			q.push(srcIndex);
			while (!q.empty())
			{
				int front = q.front();
				q.pop();
				cout << _vertexs[front] << " : " << front << "->";
				visited[front] = true;
				//他的好友入队列
				for (int i = 0; i < _vertexs.size(); ++i)
				{
					if (_matrix[front][i] != W() && visited[i] == false)
					{

						q.push (i);
					}   
				}
			}
			cout << endl;
		}
	private:
		vector<V> _vertexs; //顶点集合
		map<V, int> _vertexIndexMap;
		vector<vector<int>> _matrix;//表示邻接矩阵的边
	};
	void TestGraph()
	{
		string strs[] = { "保罗", "詹姆斯", "韦德", "加内特", "科比", "库里" };
		Graph<string, int> g(strs, sizeof(strs) / sizeof(string));

 		g.AddEdge("保罗", "詹姆斯",95);
		g.AddEdge("韦德", "詹姆斯", 99);
		g.AddEdge("库里", "詹姆斯", 80);
		g.AddEdge("库里", "詹姆斯", 80);
		g.AddEdge("科比", "詹姆斯", 85);
		g.AddEdge("科比", "加内特",	80);
		g.AddEdge("科比", "韦德", 85);
		g.DFS("詹姆斯");
		g.BFS("詹姆斯");
	}
}
namespace table
{
	template<class W>
	struct EdgeNode
	{
		int _srcIndex;
		int _dstIndex;
		const W _w;
		EdgeNode<W>* _next;

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

			_linkTable / resize(n, nullptr);
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

			EdgeNode<W>* node = new AddEdge;
			node->_srcIndex = srcIndex;
			node->_dstIndex = dstIndex;
			node->_w = w;

			node->_next = _linkTable[srcIndex];
			_linkTable[srcIndex] = node;


			if (Direction == false)
			{
				int srcIndex = GetVertexIndex(src);
				int dstIndex = GetVertexIndex(dst);

				EdgeNode<W>* node = new AddEdge;
				node->_srcIndex = dstIndex;
				node->_dstIndex = srcIndex;
				node->_w = w;

				node->_next = _linkTable[dstIndex];
				_linkTable[dscIndex] = node;
			}
		}
	private:
		vector<V> _vertexs; //顶点集合
		map<V, int> _vertexIndexMap;
		vector<EdgeNode<W>*> _linkTable;//类似哈希桶结构的邻接表
	};
}

