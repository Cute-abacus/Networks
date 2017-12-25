#include<Graph.h>
void Manage::print(Graph& G, int v, double dist[], int path[])
{
	cout << endl << "路由器" << G.getvalue(v) << "的路由表：" << endl;
	cout << "目的地址      下一跳" << endl;
	int i, j, k;
	int n = G.NumberOfVertices();
	int *d = new int[n];
	for (i = 0; i < n; i++)
	{
		if (path[i] == -1 && i != v)
		{
			cout << "路由器" << G.getvalue(i) << "        "<< "不可达\n";
			continue;
		}

		if (i != v)
		{
			j = i;
			k = 0;
			while (j !=v )
			{
				d[k++] = j;
				j = path[j];
			}
			cout << "路由器" << G.getvalue(i) << "        ";
			if (k > 0)
			{
				cout << G.getvalue(d[--k]) << " " << endl;
			}
			//				cout << "最短路径长度为：" << dist[i] << endl;
		}
	}
	delete[] d;
}
/dijstra算法求最短路径
void Manage::ShortestPath(Graph& G, int v,int *path,double *dist)
{//Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径
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
			//更新有中间结点的最短路径
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
	//读结点
	ifstream out("vertex.txt", ios::in);
	if (!out)
	{
		cout << "fail to open the vertex file!" << endl;
		return false;
	}
	int ch = out.get();
	if (out.eof())
	{
		cout << "文件为空\n";
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
	//读边
	ifstream OUT("Edge.txt", ios::in);
	if (!OUT)
	{
		cout << "fail to open the edge file!" << endl;
		return false;
	}
	ch = OUT.get();
	if (OUT.eof())
	{
		cout << "文件为空\n";
		OUT.close();
	}
	else {
		ifstream OUT("Edge.txt", ios::in);
		while (!OUT.eof())
		{
			int v1, v2, cost;
			OUT >> v1 >> v2 >> cost;
		if(Route.insertEdge(v1, v2, cost) == false)
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
		cout << "没有这个结点！" << endl;
		return false;
	}
	//int *distance = new int[1000];
	//int *path = new int[1000];
	int ans;
	cout << "请输入起始结点编号\n";
	cin >> ans;
	ans = Route.getVertexPos(ans);
		ShortestPath(Route, ans,path, dist);
	return true;
}
