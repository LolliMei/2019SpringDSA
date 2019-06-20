//
// Created by ������ on 2019-06-20.
//

#include "GraphAlgorithm.h"
#include "ALGraph.h"

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

    for (int k = 0; k < edge_index; ++k) {
        Edge *edge = &edges[k];
        printf("���ɵı�:%d<-->%d, Ȩ��:%d\n", edge->begin + 1, edge->end + 1, edge->weight);

    }
    printf("------------------------\n");
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

void DFS_Recursive(ALGraph graph,int vertex,int* visited){
    if(visited[vertex] == 1)
        return;
    //���ʵ���ǰ�ڵ�
    visited[vertex] = 1;
    printf("��ǰ���ʽڵ�:%d\n",vertex);
    //��������ڵ�������ڽӵ�
    ALLink* list = graph->vertexs[vertex].nextadj;
    while (list != NULL){
        DFS_Recursive(graph,list->vertex,visited);
        list = list->nextadj;
    }
}


void DFS(ALGraph graph, int vertex) {
    int* visited = (int*)malloc(sizeof(int) * graph->vertexNum);
    memset(visited,0, sizeof(int) * graph->vertexNum);
    DFS_Recursive(graph,vertex,visited);

    for (int i = 0; i < graph->vertexNum; ++i) {
        if(visited[i] == 0){
            printf("���ڷ���ͨ����,���:%d",i);
            DFS_Recursive(graph,i,visited);
        }

    }
}



void BFS(ALGraph graph, int vertex){

    //��ʼ����������
    int* visited = (int*)malloc(sizeof(int) * graph->vertexNum);
    memset(visited,0, sizeof(int) * graph->vertexNum);

    //���ʶ���
    int* queue = (int*)malloc(sizeof(int) * graph->vertexNum);
    int front = 0;
    int end = 0;


    queue[end++] = vertex;

    //����ѭ��
    while(front < end){
        //��ȡ��ǰ�ڵ��
        int current = queue[front++];

        //��ֹ�����Ѿ����ʹ��Ľڵ�
        if(visited[current] == 1)
            continue;

        //���ʵ�ǰ�ڵ�
        printf("��ǰ����:%d\n",current);
        visited[current] = 1;

        //��ȡ�ڵ�ĳ�������
        ALLink* list = graph->vertexs[current].nextadj;
        while (list != NULL)
        {
            queue[end++] = list->vertex;
            list = list->nextadj;
        }
    }

}