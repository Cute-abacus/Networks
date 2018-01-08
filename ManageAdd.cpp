#include"Manage.h"
bool Manage::addVertex()
{
	cout << "周思佳" << endl;
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
/*以写的方式打开文件，将图中结点以for循环形式写入文件，包括结点的id及name
实现了图的结点的更新
关闭文件*/
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
/*以写的方式打开文件，将图中的边以for循环形式写入文件，包括边的id及其权值
实现图的边的更新
关闭文件*/
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
/*检查添加结点或边时路由表中是否已存在该结点或边*/
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