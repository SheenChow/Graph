/*
  AOV网 Activity On Vertex net 顶点表示活动的网 拓扑排序是用来判断有向图中是否有环，进而判断工程是否可以
        顺利进行

  拓扑排序的步骤：1.在有向图中选一个没有前驱的顶点且输出
                  2.从图中删除该顶点和所有以它为尾的弧

  重复上述两步，直至全部顶点已经输出，或者当前图中不存在无前驱的顶点为止。后一种情况说明有向图中存在环

  计算机中的实现：采用邻接表作为有向图的存储结构，且在头结点中增加一个存放顶点入度的数组（indegree）。
  入度为0的顶点即为没有前驱的顶点，删除顶点以及以它为尾的弧，则可以换以弧头顶点的入度减1来实现。
  为了避免重复检测入度为0的顶点，则可以另设一栈暂存所有入度为0的顶点
*/

  status TopologicalSort(GraphAdjList G)
  {
  	//若图无环，则输出一个拓扑序列并返回ok，否则返回error

  	FindDegree(G, indegree);                 //对各顶点求入度indgree[0...vernum-1]

  	InitStack(S);

  	for (int i = 0; i < G.numVertexes; ++i)  //建入度为0的顶点栈s
  	{
  		if (!indegree[i])                    //入度为0的入栈
  		{
  			push(S, i);                      
  		}
  	}

  	count = 0;                              //对输出顶点计数

  	while(!StackEmpty(S))
  	{
  		Pop(S, i);

  		printf(i, G.vexs[i].data);          //输出i号顶点并计数

  		count++;

  		for (p = G.vexs[i].firstedge; p; p = p->nextarc)
  		{
  			k = p->adjvex;

  			if (!(--indegree[k]))           //对i号顶点的每个临接点入度减一，若入度减为0，则入栈
  			{
  				Push(S, k);
  			}
  		}
  	}

  	if (count < G.numVertexes)             //该有向图有回路
  	{
  		return error;
  	}
  	else
  	{
  		return ok;
  	}

  }

  n个顶点，e条边的有向图而言，时间复杂度的计算：建立各顶点入度的时间复杂度为O(e);建0入度顶点栈的时间复杂度是O(n);
  在拓扑排序过程中，若有向图无环，每个顶点进一次栈，出一次栈，入度减1的操作在WHILE语句中总共执行e次

  当有向图无环时，还可以用深度优先算法遍历进行拓扑排序，因为图中无环，则由图中某点出发进行深度优先遍历的时候，
  最先退出DFS函数的顶点即出度为0的顶点，是拓扑有序序列中的最后一个顶点。由此，按退出DFS函数的先后记录下来的
  顶点序列即为逆向的拓扑有序序列