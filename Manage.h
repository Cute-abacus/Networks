#pragma once
#include<iostream>
#include<fstream>
#include<string.h>
#include"SeqQueue.h"
#include"Graph.h"
using namespace std;
//这里是管理类，管理类的主要功能有
//1.读入结点链接关系
//2.生成图（这里可以调用Graph类）
//3.完成最小生成树
//4.输出路由表
//5.添加点和边关系（如果只添加点，需要完成一件情，当一个点不可达时，请给出相应回应）
//请在下面添加你们的代码
//函数的接口请你自行给出
class Manage
{
public:
	Graph Route;
	int path[1000];//最短路径
	double dist[1000];
	bool GetInformation();//你要告诉我读入信息是否成功
	bool shortestpath();//最短路径
	bool addVertex();//新建结点，也要改写文件哦~
	bool addEdge();//这里不仅会调用Graph的函数，同时也要改写文件
	void write1();//写入 结点
	void write2();//写入边
	bool check(int id);
	bool removeEdge();
	bool removeVertex();
	void empty();
	void print(Graph& G, int v, double dist[], int path[]);
	void ShortestPath(Graph& G, int v, int *path, double *dist);
};
