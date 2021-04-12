#pragma once
#include<vector>
#include<iostream>
#include<string>
#include<map>
#include<queue>
namespace px{
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
				//���ĺ��������
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
		vector<V> _vertexs; //���㼯��
		map<V, int> _vertexIndexMap;
		vector<vector<int>> _matrix;//��ʾ�ڽӾ���ı�
	};
	void TestGraph()
	{
		string strs[] = { "����", "ղķ˹", "Τ��", "������", "�Ʊ�", "����" };
		Graph<string, int> g(strs, sizeof(strs) / sizeof(string));

 		g.AddEdge("����", "ղķ˹",95);
		g.AddEdge("Τ��", "ղķ˹", 99);
		g.AddEdge("����", "ղķ˹", 80);
		g.AddEdge("����", "ղķ˹", 80);
		g.AddEdge("�Ʊ�", "ղķ˹", 85);
		g.AddEdge("�Ʊ�", "������",	80);
		g.AddEdge("�Ʊ�", "Τ��", 85);
		g.DFS("ղķ˹");
		g.BFS("ղķ˹");
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
				throw invalid_argument("�Ƿ�����");
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
		vector<V> _vertexs; //���㼯��
		map<V, int> _vertexIndexMap;
		vector<EdgeNode<W>*> _linkTable;//���ƹ�ϣͰ�ṹ���ڽӱ�
	};
}

