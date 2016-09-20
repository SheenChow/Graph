/*图的深度优先遍历DFS（Depth First Search）：

连通图：  从图中的某个顶点v出发，访问此顶点，然后从v的未被访问的邻接点出发深度优先遍历图，直至图中所有和v有路径相通的顶点都被访问到。

非连通图：对于非连通图，只需要对它的连通分量分别进行深度优先遍历，即在先前一个顶点进行一次深度优先遍历后，若图中尚有顶点未被访问，则另选图中一个未曾访问过的顶点作为起始点，重复上述过程，直至图中所有顶点都被访问到为止。*/


/*定义访问标志数组*/
int visited[numVertexes];

/*邻接矩阵的深度优先递归算法*/
void DFS(MGraph G, int i) 
{
	int j;
    
    /*代表i结点已经被访问了*/
	visited[i] = 1; 

	printf("%c\n", G.vexs[i]);
    
    for (int j = 0; j < G.numVertexes; ++j) 
    {
    	if (G.arc[i][j] == 1 && !visited[j])
    	{

    		/*对未访问的邻接顶点递归调用*/
    		DFS(G, j);

    	}
    }

}
/*对邻接矩阵的深度优先遍历操作*/
void DFSTraverse(MGraph G)
{
	int i;
	for (int i = 0; i < G.numVertexes; ++i)
	{
		/*出事所有顶点状态都是未访问状态*/
		visited[i] = 0;
	}

	for (int i = 0; i < G.numVertexes; ++i)
	{
		/*对未访问的顶点调用DFS,若是连通图，只需要遍历一次*/
		if (!visited[i])
		{
			DFS(G, i);
		}
	}
}

邻接矩阵是二维数组，要查找每个顶点的邻接点需要访问矩阵中的所有元素，因此需要O（n^2）的时间
