#include"Graph.h"
bool Graph::removeEdge(int v1, int v2)
{
	v1 = getVertexPos(v1);
	v2 = getVertexPos(v2);
	if (v1 != -1 && v2 != -1)
	{
		Edge *p = NodeTable[v1].adj, *q = NULL, *s = p;
		while (p != NULL&&p->dest != v2)
		{//q是p的上一个
			q = p;
			p = p->link;
		}
		//找到v2
		if (p != NULL)
		{//第一个结点就是v2
			if (p == s)
				NodeTable[v1].adj = p->link;
			else
				q->link = p->link;
			delete p;
		}//未找到
		else return false;
		//对称删除
		p = NodeTable[v2].adj;
		q = NULL, s = p;
		while (p->dest != v1)
		{
			q = p;
			p = p->link;
		}
		if (p == s)
			NodeTable[v2].adj = p->link;
		else
			q->link = p->link;
		delete p;
		return true;
	}
	return false;
}
bool Graph::removeVertex(int v)
{
	if (numVertices == 1 || v < 0 || v >= numVertices) return false;
	Edge *p, *s, *t;
	int i, k;
	while (NodeTable[v].adj != NULL)
	{
		p = NodeTable[v].adj;
		k = p->dest;
		s = NodeTable[k].adj;
		t = NULL;
		//依次删除边的过程
		while (s != NULL&&s->dest != v)
		{
			t = s;
			s = s->link;
		}
		if (s != NULL)
		{
			if (t == NULL)
				NodeTable[k].adj = s->link;
			else
				t->link = s->link;
			delete s;
		}
		NodeTable[v].adj = p->link;
		delete p;
		numEdges--;
	}
	numVertices--;
	//置换，用最后一个结点覆盖当前结点
	NodeTable[v].id = NodeTable[numVertices - 1].id;
	NodeTable[v].name = NodeTable[numVertices - 1].name;
	p = NodeTable[v].adj = NodeTable[numVertices - 1].adj;
	while (p != NULL)
	{
		s = NodeTable[p->dest].adj;
		while (s != NULL)
		{
			if (s->dest == numVertices)
			{
				s->dest = v;//更改边的链接点
				break;
			}
			else
				s = s->link;
		}
		p = p->link;
	}
	return true;
}
Graph::Graph()
{
	maxVertices = 1000000;
	numVertices = 0;
	numEdges = 0;
	NodeTable = new Vertex[1000000];
	if (NodeTable == NULL)
	{
		cerr << "存储分配错误" << endl; exit(1);
	}
	for (int i = 0; i < maxVertices; i++)
	{
		NodeTable[i].adj = NULL;
	}
}
Graph::~Graph()
{
	for (int i = 0; i < numVertices; i++)
	{
		for (int i = 0; i < numVertices; i++)
		{
			Edge *p = NodeTable[i].adj;
			while (p != NULL)
			{
				NodeTable[i].adj = p->link;
				delete p;
				p = NodeTable[i].adj;
			}
		}
	}
}
int Graph::getFirstNeighbor(int v)//这个v表示该结点在图中第几排
{
	if (v != -1)
	{
		Edge *p = NodeTable[v].adj;
		if (p != NULL)
			return p->dest;
		else return -1;
	}
	else return -1;
}
int Graph::getNextNeighbor(int v, int w)
{
	if (v != -1)
	{
		Edge*p = NodeTable[v].adj;
		while (p != NULL&&p->dest != w)
			p = p->link;
		if (p != NULL&&p->link != NULL)
			return p->link->dest;//返回的是结点的真实编号而非序号
		else return -1;
	}
	else
		return -1;
}
double Graph::getWeight(int v1, int v2)//先在函数外面找到了两个结点所对应的序号
{
	if (v1 != -1 && v2 != -1)
	{
		Edge*p = NodeTable[v1].adj;
		while (p != NULL&&p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)return p->cost;
	}
	return maxWeight;
}
bool Graph::insertVertex(const Vertex& vertex)
{
	for (int i = 0; i < numVertices; i++)
	{
		if (NodeTable[i].id == vertex.id)
		{
			cout << "该结点已存在！\n";
			return false;//该结点已然存在
		}

	}
	if (numVertices == maxVertices)return false;
	else
	{
		NodeTable[numVertices].id = vertex.id;
		NodeTable[numVertices].name = vertex.name;
		NodeTable[numVertices].adj = NULL;
		numVertices++;
		return true;
	}
}
bool Graph::insertEdge(int v1, int v2, double weight)//这里的v1 v2是实际的编号
{
	v1 = getVertexPos(v1);
	v2 = getVertexPos(v2);
	if (v1 >= 0 && v1 < numVertices&&v2 >= 0 && v2 < numVertices)
	{
		Edge*q, *p = NodeTable[v1].adj;
		while (p != NULL&&p->dest != v2)
		{
			p = p->link;
		}
		if (p != NULL)
		{
			return false;
		}
		p = new Edge;
		q = new Edge;
		p->dest = v2;
		p->cost = weight;
		p->link = NodeTable[v1].adj;
		NodeTable[v1].adj = p;
		q->dest = v1;
		q->cost = weight;
		q->link = NodeTable[v2].adj;
		NodeTable[v2].adj = q;
		numEdges++;
		return true;
	}
}
int Graph::getvalue(int num)
{//获取真实的id
	if (num >= 0 && num < NumberOfVertices())
		return NodeTable[num].id;
	else
		return -1;
}