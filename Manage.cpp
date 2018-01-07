#include"Manage.h"
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
			cout << "路由器" << G.getvalue(i) << "        " << "不可达\n";
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
//dijstra算法求最短路径
void Manage::ShortestPath(Graph& G, int v, int *path, double *dist)
{//Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径
 /*int n = G.NumberOfVertices();//得到总点数
 int j = v;//初始化j为出发点
 int w;//定义下一节点
 int *dis = new int(n+5);//距离数组
 int *p = new int(n+5);//路径数组
 bool *vis = new bool(n+5);//访问数组
 for (int i = 0; i < n; i++)//初始化各个数组
 {
 p[i] = -1;
 vis[i] = false;
 dis[i] = G.maxWeight;
 }
 //
 dis[v] = 0;//出发点到自己的距离为0
 SeqQueue<int> Q;//定义一个缓存队列
 Q.EnQueue(v);//入队列
 while (!Q.IsEmpty())//当队列不为空是执行操作
 {
 w = G.getFirstNeighbor(j);//得到j的第一个邻居
 vis[j] = true;//当前点已经访问过了
 while (w != -1)//有邻居
 {
 if (w != v&&vis[w] == false)//当当前邻居结点没有被访问过
 {
 int d = G.getWeight(j, w);//得到两点连边
 if (d + dis[j] <dis[w])//当距离变小是
 {
 dis[w] = d + dis[j];//更新
 p[w] = j;//更新路径
 }
 Q.EnQueue(w);//将邻居结点入队列
 }
 w = G.getNextNeighbor(j, w);//继续获取j的下一个邻居
 }
 Q.DeQueue(j);//将j从队列中弹出
 if (!Q.IsEmpty())
 {
 Q.getFront(j);
 };//将j赋为队首元素
 }
 print(G, v, dis, p);//输出最小路径
 return ;//返回*/
 //Graph是一个带权有向图，本算法建立一个数组，dist[j],0<=j<n;是当前求到的从顶点v到顶点j的最短路径长度，同时用数组path存放求到的最短路径

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
		cout << "没有这个结点！" << endl;
		return false;
	}
	//int *distance = new int[1000];
	//int *path = new int[1000];
	int ans;
	cout << "请输入起始结点编号\n";
	cin >> ans;
	ans = Route.getVertexPos(ans);
	ShortestPath(Route, ans, path, dist);
	return true;
}
bool Manage::addVertex()
{

	Vertex a;
	cout << "请输入要添加结点的编号：" << endl;
	cin >> a.id;
	if (Route.getVertexPos(a.id) != -1)
	{
		cout << "该结点已存在！\n";
		return false;
	}
	cout << "请输入要添加结点的名称：" << endl;
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
	cout << "请输入要添加边的结点1的编号：" << endl;
	cin >> b;
	cout << "请输入要添加的边的结点2的编号：" << endl;
	cin >> c;
	if (!check(b) || !check(c))
	{
		return false;
	}
	cout << "请输入边的权值：" << endl;
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
		cout << "路由表中尚无该结点！\n\n";
		cout << "是否添加该结点？\n\n";
		cout << "1.是      2.否\n\n";
		int ans;
		cin >> ans;
		switch (ans)
		{
		default:cout << "操作失败,输入了无法识别的指令\n\n"; return false;
		case 1: {
			Vertex a;
			a.id = id;
			cout << "请输入要添加结点的名称：\n\n" << endl;
			cin >> a.name;
			Route.insertVertex(a);
			write1();
		}break;
		case 2:cout << "返回主界面！\n\n"; return false;
		}
	}
	return true;
}
bool Manage::removeEdge()
{
	cout << "请输入要删除的边的第一个结点编号\n";
	int a;
	cin >> a;
	cout << "请输入要删除的边的第二个结点编号\n";
	int b;
	cin >> b;
	if (!check(a) || !check(b))
	{
		return false;
	}
	if (!Route.removeEdge(a, b))
	{
		cout << "此边不存在\n";
		return false;
	}
	cout << "删除成功！\n";
	write2();
}
bool Manage::removeVertex()
{
	cout << "请输入删除结点的编号\n";
	int a;
	cin >> a;
	if (!check(a))
	{
		return false;
	}
	a = Route.getVertexPos(a);
	if (Route.removeVertex(a))
		cout << "删除成功！\n\n";
	write1();
}
void Manage::empty()
{
	Route.NodeTable = new Vertex[1000];
	Route.numVertices = 0;
	Route.numEdges = 0;
}