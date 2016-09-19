/*邻接表（Adjacency List）
    是对邻接矩阵的改进，减少了存储空间浪费的情况

存储结构*/

typedef char VertexType;

typedef char EdgeType;

#define MAXVEX 65535

/*边表结点*/
typedef struct EdgeNode 
{
	int adjvex; //邻接点域，就是顶点的下标值

	EdgeType weight;//用于存储权值

	struct NextNode *next;/*链域，指向下一个结点*/
} EdgeNode;


/*顶点表结点*/
typedef struct VertextNode
{
	VertexType data;  /*顶点域，存储顶点信息*/

	EdgeNode *firstEdge;/*边表头指针*/
	
} VertexNode, AdjList[MAXVEX];

typedef struct 
{
	AdjList adjList;

	int numVertexes, numEdges;/*图中当前顶点数和边数*/
	
} GraphAdjList;