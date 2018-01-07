#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Edge
{
	int dest;//边的另一点
	double cost;
	Edge*link;//连向下一个
	Edge() :link(NULL) {};
	Edge(int num, double weight) :dest(num), cost(weight), link(NULL) {};
	bool operator !=(Edge &a)const
	{
		return (dest != a.dest) ? true : false;
	}
};
struct Vertex
{
	int id;//编号
	string name;
	Edge*adj;
};
class Graph
{
public:
	const int maxWeight = 0x7fffffff;
	Vertex *NodeTable;
	Graph();
	~Graph();
	bool GraphEmpty()const
	{
		if (numEdges == 0)return true;
		else return false;
	}
	int NumberOfEdges()
	{
		return numEdges;
	}
	double getWeight(int v1, int v2);//获得边的权值
	int getFirstNeighbor(int v);//得到第一个邻居
	int getNextNeighbor(int v, int w);//得到下一个邻居
	bool insertVertex(const Vertex& vertex);//插入结点
	int NumberOfVertices()//获得结点的个数
	{
		return numVertices;
	}
	bool insertEdge(int v1, int v2, double cost);
	int getvalue(int id);
protected:
	int maxVertices = 0x7fffffff;//最多顶点数目，无意义
public:
	int numEdges;//边数
	int numVertices;//目前顶点数目
	int getVertexPos(int vertex)//得到点的序号
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].id == vertex)
				return i;//这个结点在第几排
		}
		return -1;

	}
	int getVertexPos(const Vertex vertex)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].id == vertex.id

				)
				return i;//这个结点在第几排
		}
		return -1;
	}
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
};