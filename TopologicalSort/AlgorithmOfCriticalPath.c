/*关键路径

与AOV网对应的是AOE网（Activity On Edge net）即边表示活动的网。是一个带权的有向无环图（AOV不带权，
仅以弧表示优先关系），顶点表示事件（Event），弧表示活动（Activity），权表示活动持续的时间。

AOV网用来检测工程是否可行，而AOE网则用来测算工程的完成时间。

AOE网有待解决的问题：1.完成整项工程需要多长时间
                     2.哪些活动是影响工程进度的关键

由于在AOE网中有些活动可以并行的进行，所以完成工程的最短时间是从开始点（源点）到完成点（汇点）的最长路径的长度
（不过，最长路径指的是路径上活动持续的时间之和，而不是路径上弧的数目）。
路径长度最长的路径叫做关键路径（Critical Path）*/

Status TopologicalOrder(ALGraph G, Statck &T)
{
	//有向网G采用邻接表存储结构，求各顶点事件的最早发生时间ve（全局变量）。
	//T为拓扑序列顶点栈，S为零点入度顶点栈。
	//若G无回路，则用栈T返回G中的一个拓扑序列，切函数值为OK，否则为ERROR

	FindIndegree(G, indegree);//入度

    //零入度定点入栈
	InitStack(s);

	for (int i = 0; i < G.numVertexes; ++i)
	{
		if(!indegree[i])
		{
			Push(S, i);
		}
	}

    //记录拓扑排序的逆序列
	InitStack(T);

	count = 0;

	ve[0..G.vexnum - 1] = 0;//初始化

	while(!StackEmpty(S))
	{
		Pop(S, j);

		Push(S, j);

		++count;

		for (p = G.Vertexes[j].firstedge; p; p = p->nextarc)
		{
			k = p->adjvex;//对j号顶点的每个邻接点的入度减一

			if (--indegree[k] == 0)
			{
				Push(S, k);
			}

			if (ve[j] + *(p->info) > ve[k])
			{
				ve[k] = ve[j] + *(p->info);
			}


		}
	}

	if (count < G.vexnum)
	{
		return ERROR;
	}

	else
	{
		return OK;
	}

}

由于逆拓扑排序必定在网中无环的情况下进行，则亦可以利用DFS函数，
在推出DFS函数之前按照公式vl(i) = Min{vl(j)-dut(<i,j>)} i, j∈S计算顶点v的vl值（此时
v的所有直接后继的vl值都已经求出）。

这两种算法的时间复杂度均为O(n+e),显然，前一种算法的常数因子要小一些。由于计算弧的最早开始时间和
最迟开始时间的复杂度均为O(e),所以总的求关键路径时间复杂度为O(n+e)[TopologicalSort的时间复杂度是O(n+e)]

