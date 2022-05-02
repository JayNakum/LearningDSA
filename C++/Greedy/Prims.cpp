#include <iostream>
#include <limits.h>

struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int V;
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int dest, int weight)
{
    struct AdjListNode *newNode = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph *createGraph(int V)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;

    graph->array = (struct AdjList *)malloc(V * sizeof(struct AdjList));

    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

void newEdge(struct Graph *graph, int src, int dest, int weight)
{
    struct AdjListNode *newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

struct MinHeapNode
{
    int v;
    int key;
};

struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode *newNode(int v, int key)
{
    struct MinHeapNode *heapNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    heapNode->v = v;
    heapNode->key = key;
    return heapNode;
}

struct MinHeap *buildMinHeap(int capacity)
{
    struct MinHeap *heap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    heap->pos = (int *)malloc(capacity * sizeof(int));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode **)malloc(capacity * sizeof(struct MinHeapNode *));
    return heap;
}

void swapNode(struct MinHeapNode **a, struct MinHeapNode **b)
{
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap *heap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

    if (left < heap->size && heap->array[left]->key < heap->array[smallest]->key)
        smallest = left;

    if (right < heap->size && heap->array[right]->key < heap->array[smallest]->key)
        smallest = right;

    if (smallest != idx)
    {
        MinHeapNode *smallestNode = heap->array[smallest];
        MinHeapNode *idxNode = heap->array[idx];

        heap->pos[smallestNode->v] = idx;
        heap->pos[idxNode->v] = smallest;

        swapNode(&heap->array[smallest], &heap->array[idx]);

        minHeapify(heap, smallest);
    }
}

int isEmpty(struct MinHeap *heap)
{
    return heap->size == 0;
}

struct MinHeapNode *extractMin(struct MinHeap *heap)
{
    if (isEmpty(heap))
        return NULL;

    struct MinHeapNode *root = heap->array[0];

    struct MinHeapNode *lastNode = heap->array[heap->size - 1];
    heap->array[0] = lastNode;

    heap->pos[root->v] = heap->size - 1;
    heap->pos[lastNode->v] = 0;

    --heap->size;
    minHeapify(heap, 0);

    return root;
}

void decreaseKey(struct MinHeap *heap, int v, int key)
{
    int i = heap->pos[v];

    heap->array[i]->key = key;

    while (i && heap->array[i]->key < heap->array[(i - 1) / 2]->key)
    {
        heap->pos[heap->array[i]->v] = (i - 1) / 2;
        heap->pos[heap->array[(i - 1) / 2]->v] = i;
        swapNode(&heap->array[i], &heap->array[(i - 1) / 2]);

        i = (i - 1) / 2;
    }
}

bool isInMinHeap(struct MinHeap *heap, int v)
{
    if (heap->pos[v] < heap->size)
        return true;
    return false;
}

void printArr(int arr[], int n)
{
    for (int i = 1; i < n; ++i)
        std::cout << arr[i] << " - " << i;
    std::cout << std::endl;
}

void primsMST(struct Graph *graph)
{
    int V = graph->V;
    int parent[V];
    int key[V];

    struct MinHeap *heap = buildMinHeap(V);

    for (int v = 1; v < V; ++v)
    {
        parent[v] = -1;
        key[v] = INT_MAX;
        heap->array[v] = newNode(v, key[v]);
        heap->pos[v] = v;
    }

    key[0] = 0;
    heap->array[0] = newNode(0, key[0]);
    heap->pos[0] = 0;

    heap->size = V;

    while (!isEmpty(heap))
    {
        struct MinHeapNode *heapNode = extractMin(heap);
        int u = heapNode->v;

        struct AdjListNode *traverse = graph->array[u].head;
        while (traverse != NULL)
        {
            int v = traverse->dest;

            if (isInMinHeap(heap, v) && traverse->weight < key[v])
            {
                key[v] = traverse->weight;
                parent[v] = u;
                decreaseKey(heap, v, key[v]);
            }
            traverse = traverse->next;
        }
    }

    printArr(parent, V);
}

int main()
{
    int V = 9;
    struct Graph *graph = createGraph(V);
    newEdge(graph, 0, 1, 4);
    newEdge(graph, 0, 7, 8);
    newEdge(graph, 1, 2, 8);
    newEdge(graph, 1, 7, 11);
    newEdge(graph, 2, 3, 7);
    newEdge(graph, 2, 8, 2);
    newEdge(graph, 2, 5, 4);
    newEdge(graph, 3, 4, 9);
    newEdge(graph, 3, 5, 14);
    newEdge(graph, 4, 5, 10);
    newEdge(graph, 5, 6, 2);
    newEdge(graph, 6, 7, 1);
    newEdge(graph, 6, 8, 6);
    newEdge(graph, 7, 8, 7);

    primsMST(graph);
}
