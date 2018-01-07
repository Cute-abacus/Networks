#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
struct Edge
{
	int dest;//�ߵ���һ��
	double cost;
	Edge*link;//������һ��
	Edge() :link(NULL) {};
	Edge(int num, double weight) :dest(num), cost(weight), link(NULL) {};
	bool operator !=(Edge &a)const
	{
		return (dest != a.dest) ? true : false;
	}
};
struct Vertex
{
	int id;//���
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
	double getWeight(int v1, int v2);//��ñߵ�Ȩֵ
	int getFirstNeighbor(int v);//�õ���һ���ھ�
	int getNextNeighbor(int v, int w);//�õ���һ���ھ�
	bool insertVertex(const Vertex& vertex);//������
	int NumberOfVertices()//��ý��ĸ���
	{
		return numVertices;
	}
	bool insertEdge(int v1, int v2, double cost);
	int getvalue(int id);
protected:
	int maxVertices = 0x7fffffff;//��ඥ����Ŀ��������
public:
	int numEdges;//����
	int numVertices;//Ŀǰ������Ŀ
	int getVertexPos(int vertex)//�õ�������
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].id == vertex)
				return i;//�������ڵڼ���
		}
		return -1;

	}
	int getVertexPos(const Vertex vertex)
	{
		for (int i = 0; i < numVertices; i++)
		{
			if (NodeTable[i].id == vertex.id

				)
				return i;//�������ڵڼ���
		}
		return -1;
	}
	bool removeVertex(int v);
	bool removeEdge(int v1, int v2);
};