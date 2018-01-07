#include"Manage.h"
void Manage::print(Graph& G, int v, double dist[], int path[])
{
	cout << endl << "·����" << G.getvalue(v) << "��·�ɱ�" << endl;
	cout << "Ŀ�ĵ�ַ      ��һ��" << endl;
	int i, j, k;
	int n = G.NumberOfVertices();
	int *d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (path[i] == -1 && i != v)
		{
			cout << "·����" << G.getvalue(i) << "        " << "���ɴ�\n";
			continue;
		}

		if (i != v)
		{
			j = i;
			k = 0;
			while (j != v)
			{
				d[k++] = j;
				j = path[j];
			}
			cout << "·����" << G.getvalue(i) << "        ";
			if (k > 0)
			{
				cout << G.getvalue(d[--k]) << " " << endl;
			}
			//				cout << "���·������Ϊ��" << dist[i] << endl;
		}
	}
	delete[] d;
}
//dijstra�㷨�����·��
void Manage::ShortestPath(Graph& G, int v, int *path, double *dist)
{//Graph��һ����Ȩ����ͼ�����㷨����һ�����飬dist[j],0<=j<n;�ǵ�ǰ�󵽵ĴӶ���v������j�����·�����ȣ�ͬʱ������path����󵽵����·��
 /*int n = G.NumberOfVertices();//�õ��ܵ���
 int j = v;//��ʼ��jΪ������
 int w;//������һ�ڵ�
 int *dis = new int(n+5);//��������
 int *p = new int(n+5);//·������
 bool *vis = new bool(n+5);//��������
 for (int i = 0; i < n; i++)//��ʼ����������
 {
 p[i] = -1;
 vis[i] = false;
 dis[i] = G.maxWeight;
 }
 //
 dis[v] = 0;//�����㵽�Լ��ľ���Ϊ0
 SeqQueue<int> Q;//����һ���������
 Q.EnQueue(v);//�����
 while (!Q.IsEmpty())//�����в�Ϊ����ִ�в���
 {
 w = G.getFirstNeighbor(j);//�õ�j�ĵ�һ���ھ�
 vis[j] = true;//��ǰ���Ѿ����ʹ���
 while (w != -1)//���ھ�
 {
 if (w != v&&vis[w] == false)//����ǰ�ھӽ��û�б����ʹ�
 {
 int d = G.getWeight(j, w);//�õ���������
 if (d + dis[j] <dis[w])//�������С��
 {
 dis[w] = d + dis[j];//����
 p[w] = j;//����·��
 }
 Q.EnQueue(w);//���ھӽ�������
 }
 w = G.getNextNeighbor(j, w);//������ȡj����һ���ھ�
 }
 Q.DeQueue(j);//��j�Ӷ����е���
 if (!Q.IsEmpty())
 {
 Q.getFront(j);
 };//��j��Ϊ����Ԫ��
 }
 print(G, v, dis, p);//�����С·��
 return ;//����*/
 //Graph��һ����Ȩ����ͼ�����㷨����һ�����飬dist[j],0<=j<n;�ǵ�ǰ�󵽵ĴӶ���v������j�����·�����ȣ�ͬʱ������path����󵽵����·��

	int n = G.NumberOfVertices();
	bool *S = new bool[n];
	int i, j, k;
	int w, min;
	for (i = 0; i<n; i++)
	{
		dist[i] = G.getWeight(v, i);
		S[i] = false;
		if (i != v && dist[i] <G.maxWeight)
			path[i] = v;
		else
		{
			path[i] = -1;
		}
	}
	S[v] = true;
	dist[v] = 0;
	for (i = 0; i<n - 1; i++)
	{
		min = G.maxWeight;
		int u = v;
		for (j = 0; j<n; j++)
		{
			if (S[j] == false && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		S[u] = true;
		for (k = 0; k<n; k++)
		{
			w = G.getWeight(u, k);
			//�������м�������·��
			if (S[k] == false && w <G.maxWeight && dist[u] + w<dist[k])
			{
				dist[k] = dist[u] + w;
				path[k] = u;
			}
		}
	}
	print(G, v, dist, path);
}
bool Manage::GetInformation()
{
	Vertex vertex;
	Edge edge;
	//�����
	ifstream out("vertex.txt", ios::in);
	if (!out)
	{
		cout << "fail to open the vertex file!" << endl;
		return false;
	}
	int ch = out.get();
	if (out.eof())
	{
		cout << "�ļ�Ϊ��\n";
		out.close();
	}
	else {
		ifstream out("vertex.txt", ios::in);
		out >> vertex.name >> vertex.id;
		vertex.adj = NULL;
		while (!out.eof())
		{
			Route.insertVertex(vertex);
			out >> vertex.name >> vertex.id;
			vertex.adj = NULL;
			{
				//	cout << "" << endl;
				//	return false;
			}
		}
		out.close();
	}
	//����
	ifstream OUT("Edge.txt", ios::in);
	if (!OUT)
	{
		cout << "fail to open the edge file!" << endl;
		return false;
	}
	ch = OUT.get();
	if (OUT.eof())
	{
		cout << "�ļ�Ϊ��\n";
		OUT.close();
	}
	else {
		ifstream OUT("Edge.txt", ios::in);
		while (!OUT.eof())
		{
			int v1, v2, cost;
			OUT >> v1 >> v2 >> cost;
			if (Route.insertEdge(v1, v2, cost) == false)
			{
				//cout << "fail to insert the vertex" << endl;
				//return false;
			}
		}
		OUT.close();
	}
	cout << "load data successfully!\n" << endl;
	return true;
}
bool Manage::shortestpath()
{
	int num = Route.NumberOfVertices();
	if (num == -1)
	{
		cout << "û�������㣡" << endl;
		return false;
	}
	//int *distance = new int[1000];
	//int *path = new int[1000];
	int ans;
	cout << "��������ʼ�����\n";
	cin >> ans;
	ans = Route.getVertexPos(ans);
	ShortestPath(Route, ans, path, dist);
	return true;
}
bool Manage::addVertex()
{

	Vertex a;
	cout << "������Ҫ��ӽ��ı�ţ�" << endl;
	cin >> a.id;
	if (Route.getVertexPos(a.id) != -1)
	{
		cout << "�ý���Ѵ��ڣ�\n";
		return false;
	}
	cout << "������Ҫ��ӽ������ƣ�" << endl;
	cin >> a.name;
	Route.insertVertex(a);
	write1();
	return true;
}
void Manage::write1()
{
	ofstream infile;
	infile.open("vertex.txt");
	for (int i = 0; i < Route.NumberOfVertices(); i++)
	{
		infile << Route.NodeTable[i].name << ' ' << Route.NodeTable[i].id << '\n';
	}
	infile.close();
}
bool Manage::addEdge()
{
	int b, c;
	double cost;
	cout << "������Ҫ��ӱߵĽ��1�ı�ţ�" << endl;
	cin >> b;
	cout << "������Ҫ��ӵıߵĽ��2�ı�ţ�" << endl;
	cin >> c;
	if (!check(b) || !check(c))
	{
		return false;
	}
	cout << "������ߵ�Ȩֵ��" << endl;
	cin >> cost;
	Route.insertEdge(b, c, cost);
	write2();
}
void Manage::write2()
{
	ofstream infile;
	infile.open("Edge.txt");
	for (int i = 0; i < Route.NumberOfVertices(); i++)
	{
		Edge *current = Route.NodeTable[i].adj;
		while (current != NULL)
		{
			infile << Route.NodeTable[i].id << ' ';
			infile << Route.getvalue(current->dest) << ' ' << current->cost << '\n';
			current = current->link;
		}
	}
	infile.close();
}
bool Manage::check(int id)
{
	if (Route.getVertexPos(id) == -1)
	{
		cout << "·�ɱ������޸ý�㣡\n\n";
		cout << "�Ƿ���Ӹý�㣿\n\n";
		cout << "1.��      2.��\n\n";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:cout << "����ʧ��,�������޷�ʶ���ָ��\n\n"; return false;
		case 1: {
			Vertex a;
			a.id = id;
			cout << "������Ҫ��ӽ������ƣ�\n\n" << endl;
			cin >> a.name;
			Route.insertVertex(a);
			write1();
		}break;
		case 2:cout << "���������棡\n\n"; return false;
		}
	}
	return true;
}
bool Manage::removeEdge()
{
	cout << "������Ҫɾ���ıߵĵ�һ�������\n";
	int a;
	cin >> a;
	cout << "������Ҫɾ���ıߵĵڶ��������\n";
	int b;
	cin >> b;
	if (!check(a) || !check(b))
	{
		return false;
	}
	if (!Route.removeEdge(a, b))
	{
		cout << "�˱߲�����\n";
		return false;
	}
	cout << "ɾ���ɹ���\n";
	write2();
}
bool Manage::removeVertex()
{
	cout << "������ɾ�����ı��\n";
	int a;
	cin >> a;
	if (!check(a))
	{
		return false;
	}
	a = Route.getVertexPos(a);
	if (Route.removeVertex(a))
		cout << "ɾ���ɹ���\n\n";
	write1();
}
void Manage::empty()
{
	Route.NodeTable = new Vertex[1000];
	Route.numVertices = 0;
	Route.numEdges = 0;
}