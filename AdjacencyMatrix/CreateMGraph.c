
/*typedef char VertexType;

  typedef int EdgeType;

  #define MAXVEX 100; //最大顶点数，其实应该由用户决定

  #define INFINITY 65535 //由6535来代表∞

  typedef struct {

  	//顶点表
  	VertexType vexs[MAXVEX];

    //邻接矩阵，可以看作表
  	EdgeType arc[MAXVEX][MAXVEX];

  	int numVertex, numEdges;

  } MGraph;*/

 /*有了邻接矩阵存储结构的定义，就可以来构造一个图，过程实质上就是给顶点和边表输入数据的过程。

 无向网的创建代码如下*/

  	void CreateMGraph (MGraph *G) {

  		int i, j, k, w;

  		printf("输入顶点数和边数:\n");

  		/*输入顶点和边数*/
  		scanf("%d,%d", &G->numVertex, &G->numEdges);

  		/*读入顶点信息，建立顶点表*/
  		for (int i = 0; i < G->numVertex; ++i)
  		{
  			scanf(&G->vexs[i]); //格式控制部分省略了，需要根据顶点元素类型决定格式
  		}

  		/*初始化邻接矩阵*/
  		for (int i = 0; i < G->numVertex; ++i)
  		{
  			for (int j = 0; j < numVertex; ++j)
  			{
  				G->arc[i][j] = INFINITY;
  			}
  		}

  		/*读入numEdges条边，建立邻接矩阵*/
  		for (int k = 0; k < numEdges; ++k)
  		{
  			printf("输入边<vi, vj>上的下标i,下标j以及权值w：\n");

  			scanf("%d,%d,%d", &i, &j, &w);
            
            /*无向图，对称矩阵*/
  			G->arc[i][j] = G->arc[j][i] = w;
  		}


  	}