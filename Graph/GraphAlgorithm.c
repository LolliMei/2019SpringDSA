//
// Created by ������ on 2019-06-20.
//


#include "GraphAlgorithm.h"
#include "ALGraph.h"
#include "ArrayGraph.h"

//DEBUG���ƺ궨��
#define DEBUG

#define min(a, b) (a<b?a:b)

/*
 * ��³˹�����㷨
 */
int edge_cmp(const void *a, const void *b) {
    return (*(Edge *) a).weight - (*(Edge *) b).weight;
}

int get_parent(int *parent, int vertex) {
    while (parent[vertex] != -1) {
        vertex = parent[vertex];
    }
    return vertex;
}

void kruskal(MatGraph graph) {

    int vertexNum = graph->vertexNum;
    int edgeCount = graph->edgeNum;

    //���ɵ㼯��,������Ϊ-1
    int *parent = (int *) malloc(sizeof(int) * vertexNum);
    memset(parent, -1, sizeof(int) * vertexNum);

    //���ɱߵļ���

    //�����㹻�Ŀռ�
    Edge *edges = (Edge *) malloc(sizeof(Edge) * edgeCount);
    int edge_index = 0;
    for (int i = 0; i < graph->vertexNum; ++i) {
        for (int j = i + 1; j < graph->vertexNum; ++j) {
            if (graph->mat[i][j] != 0) {
                edges[edge_index].begin = i;
                edges[edge_index].end = j;
                edges[edge_index].weight = graph->mat[i][j];
                edge_index++;
            }
        }
    }

    //����ߵļ���
    qsort(edges, edgeCount, sizeof(Edge), edge_cmp);
#ifdef DEBUG
    for (int k = 0; k < edge_index; ++k) {
        Edge *edge = &edges[k];
        printf("���ɵı�:%d<-->%d, Ȩ��:%d\n", edge->begin + 1, edge->end + 1, edge->weight);

    }
    printf("------------------------\n");
#endif
    //�������㷨
    for (int i = 0; i < edge_index; ++i) {
        Edge *edge = &edges[i];
        //�ж��޻�
        int n = get_parent(parent, edge->begin);
        int m = get_parent(parent, edge->end);

        if (n != m) {
            printf("���ɵı�:%d<-->%d, Ȩ��:%d\n", edge->begin + 1, edge->end + 1, edge->weight);
            parent[n] = m;
        }


    }


}


/*
 * �����������
 */

void DFS_Recursive(ALGraph graph, int vertex, int *visited) {
    if (visited[vertex] == 1)
        return;
    //���ʵ���ǰ�ڵ�
    visited[vertex] = 1;
    printf("��ǰ���ʽڵ�:%d\n", vertex);
    //��������ڵ�������ڽӵ�
    ALLink *list = graph->vertexs[vertex].nextadj;
    while (list != NULL) {
        DFS_Recursive(graph, list->vertex, visited);
        list = list->nextadj;
    }
}


void DFS(ALGraph graph, int vertex) {

    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    DFS_Recursive(graph, vertex, visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if (visited[i] == 0) {
            printf("���ڷ���ͨ����,���:%d", i);
            DFS_Recursive(graph, i, visited);
        }

    }
}

/*
 * �����������
 */

void BFS_Recursive(ALGraph graph, int vertex, int *visited) {

    //���ʶ���
    int *queue = (int *) malloc(sizeof(int) * graph->vertexNum);
    int front = 0;
    int end = 0;


    queue[end++] = vertex;

    //����ѭ��
    while (front < end) {
        //��ȡ��ǰ�ڵ��
        int current = queue[front++];

        //��ֹ�����Ѿ����ʹ��Ľڵ�
        if (visited[current] == 1)
            continue;

        //���ʵ�ǰ�ڵ�
        visited[current] = 1;
        printf("��ǰ����:%d\n", current);

        //��ȡ�ڵ�ĳ�������
        ALLink *list = graph->vertexs[current].nextadj;
        while (list != NULL) {
            queue[end++] = list->vertex;
            list = list->nextadj;
        }
    }

}

void BFS(ALGraph graph, int vertex) {
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    BFS_Recursive(graph, vertex, visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if (visited[i] == 0) {
            printf("���ڷ���ͨ����,���:%d", i);
            BFS_Recursive(graph, i, visited);
        }

    }
}


/*
 * ��������
 */

int select(ALGraph graph, int *degrees) {
    for (int i = 0; i < graph->vertexNum; ++i) {
        if (degrees[i] == 0)
            return i;
    }
}

void toposort_algraph(ALGraph graph) {

    // ��ʼ��ջ
    int *stack = (int *) malloc(sizeof(int) * graph->vertexNum);
    int top = -1;

    // ��ʼ������
    int *degrees = (int *) malloc(sizeof(int) * (graph->vertexNum));
    for (int i = 0; i < graph->vertexNum; ++i) {
        degrees[i] = graph->vertexs[i].indegree;
        if (degrees[i] == 0) {
            stack[++top] = i;
        }
    }


    // ��ʼ����־
    int vexNum = 0;

    while (top != -1) {
        int vertex = stack[top--];
        printf("%d  ", vertex);
        vexNum++;
        ALLink *vertexlink = graph->vertexs[vertex].nextadj;
        while (vertexlink != NULL) {
            degrees[vertexlink->vertex]--;
            if (degrees[vertexlink->vertex] == 0)
                stack[++top] = vertexlink->vertex;
            vertexlink = vertexlink->nextadj;
        }
    }

    if (vexNum != graph->vertexNum)
        printf("ͼ���ڻ�\n");
}


/*
 * �ؼ�·��
 */

void critical_path(ALGraph graph) {

    // ��ʼ������ջ
    int *stack = (int *) malloc(sizeof(int) * graph->vertexNum);
    int top = -1;


    int *degrees = (int *) malloc(sizeof(int) * graph->vertexNum);
    //��ʼ���������
    for (int i = 0; i < graph->vertexNum; ++i) {
        degrees[i] = graph->vertexs[i].indegree;
        if (degrees[i] == 0)
            stack[++top] = i;
    }

    //��������
    while (top != -1) {
        int i = stack[top--];
        ALVertex vertex = graph->vertexs[i];
        printf("��ǰ���ʽڵ�%d,ʱ��%d", i, vertex.data);

        ALLink *link = vertex.nextadj;
        while (link != NULL) {

            ALVertex *nextVertex = &graph->vertexs[link->vertex];
            nextVertex->data = min(nextVertex->data, vertex.data + link->weight);
            link = link->nextadj;

            if (--degrees[link->vertex] == 0)
                stack[++top] = link->vertex;
        }
    }



}

/*
 * �ҽ�˹������Դ���·��
 */

void dijkstra(MatGraph graph, int src) {

    int *dist = malloc(sizeof(int) * graph->vertexNum);
    int *pre = malloc(sizeof(int) * graph->vertexNum);
    int *visited = malloc(sizeof(int) * graph->vertexNum);


    for (int i = 0; i < graph->vertexNum; ++i) {
        visited[i] = 0;
        pre[i] = 0;
        int dst = graph->mat[src][i];
        dist[i] = dst;
    }

    visited[src] = 1;
    dist[src] = 0;


#ifdef DEBUG
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", visited[l]);
    }
    printf("\n");
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", pre[l]);
    }
    printf("\n");
    for (int l = 0; l < graph->vertexNum; ++l) {
        printf("%d ", dist[l]);
    }
#endif

    for (int i = 0; i < graph->vertexNum; ++i) {

        int min = INT32_MAX;
        int tail = 0;
        for (int j = 0; j < graph->vertexNum; ++j) {
            if (visited[j] == 0 && dist[j] < min) {
                min = dist[j];
                tail = j;
            }
        }
        visited[tail] = 1;

        //����·��
        for (int k = 0; k < graph->vertexNum; ++k) {
            if (visited[k] == 0 && graph->mat[tail][k] != INT32_MAX
                && dist[tail] + graph->mat[tail][k] < dist[k]) {
                dist[k] = dist[tail] + graph->mat[tail][k];
                pre[k] = tail;
            }

        }

    }

    //��ӡ���
    for (int i = 0; i < graph->vertexNum; ++i) {
        printf("��%d�����·�����ȣ�%d", i, dist[i]);
        //��ӡ·��
        int dest = i;
        printf("·��Ϊ:");
        while (dest != src) {
            printf("%d ", dest);
            dest = pre[dest];
        }
        printf("\n");
    }

}

/*
 * ��С������Prim
 * O(n^3) ��ʵ�ַ�ʽ���Ƚϵļ��׶�����������õ�ʵ�ַ�ʽ
 */

void prim(MatGraph graph, int src) {

    //��ʼ����Դ�㵽��������ľ���
    int *dist = (int *) malloc(sizeof(int) * graph->vertexNum);
    for (int i = 0; i < graph->vertexNum; ++i) {
        dist[i] = graph->mat[src][i];
    }

    //����visited����
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);
    visited[src] = 1;

    //���нڵ�û�б����ʵ���ʱ��,����ѭ��
    int count = 1;
    while (count != graph->vertexNum) {
        // ѡ��һ����С�ı�
        int minweight = INT32_MAX;
        int head = -1;
        int tail = -1;

        // ��������[i,j]��
        for (int i = 0; i < graph->vertexNum; ++i) {
            for (int j = 0; j < graph->vertexNum; ++j) {
                //ѡ��V->S�ı�
                if (visited[i] == 1 && visited[j] == 0) {
                    if (graph->mat[i][j] < INT32_MAX) {
                        minweight = graph->mat[i][j];
                        head = i;
                        tail = j;
                    }
                }
            }
        }

        //��ӽ�����С��������
        printf("������%d<->%d\n��Ȩ��:%d", head, tail, minweight);

        //���Ϊ�Ѿ�����
        visited[tail] = 1;
        //�����Ѿ�������С�������Ľڵ����
        count++;
    }

}


/*
 * �Ż���Prim
 * O(n^2)
 */

void prim_optimize(MatGraph graph, int src) {

    //��ʼ��dist����
    int *dist = (int *) malloc(sizeof(int) * (graph->vertexNum));
    for (int i = 0; i < graph->vertexNum; ++i) {
        dist[i] = graph->mat[src][i];
    }

    //��ʼ��visited����
    int *visited = (int *) malloc(sizeof(int) * graph->vertexNum);
    memset(visited, 0, sizeof(int) * graph->vertexNum);

    visited[src] = 1;
    printf("ѡ��Դ�ڵ�%d", src);

    // �������ȫ���㶼�����У����������
    int count = 1;
    while (count != graph->vertexNum) {

        int tail = 0;
        int minval = INT32_MAX;
        //ѡ����С�ı�
        for (int i = 0; i < graph->vertexNum; ++i) {
            if (dist[i] < minval)
                tail = i;
        }

        printf("ѡ��ڵ�%d,Ȩ��%d", tail, minval);
        visited[tail] = 1;

        //������tail�ڵ����Ӱ���dist
        for (int j = 0; j < graph->vertexNum; ++j) {
            if (graph->mat[tail][j] < dist[j]) {
                dist[j] = graph->mat[tail][j];
            }
        }

    }
}

