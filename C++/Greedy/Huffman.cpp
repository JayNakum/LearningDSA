#include <iostream>
#include <vector>
#include <math.h>

struct Alphabet
{
    char letter = '\0';
    int freq;

    Alphabet *left = nullptr;
    Alphabet *right = nullptr;
};

static int PARENT(int i)
{
    return floor(i / 2);
}

static int LEFT(int i)
{
    return (2 * i);
}

static int RIGHT(int i)
{
    return ((2 * i) + 1);
}

class MinHeap
{
public:
    int size;

public:
    MinHeap(int heapSize = 0)
        : size(heapSize) {}

public:
    void minHeapify(std::vector<Alphabet> &alphabets, int i)
    {
        int l = LEFT(i);
        int r = RIGHT(i);

        int smallest = i;

        if (l < size && alphabets[l].freq < alphabets[i].freq)
            smallest = l;

        else
            smallest = i;

        if (r < size && alphabets[r].freq < alphabets[smallest].freq)
            smallest = r;

        if (smallest != i)
        {
            Alphabet temp = alphabets[smallest];
            alphabets[smallest] = alphabets[i];
            alphabets[i] = temp;

            minHeapify(alphabets, smallest);
        }
    }

    void buildMinHeap(std::vector<Alphabet> &alphabets)
    {
        size = alphabets.size();
        for (int i = floor(size / 2); i >= 0; i--)
        {
            minHeapify(alphabets, i);
        }
    }

    Alphabet extractMin(std::vector<Alphabet> &alphabets)
    {
        if (size >= 0)
        {
            Alphabet min = alphabets[0];
            size -= 1;
            alphabets[0] = alphabets[size];
            alphabets.erase(alphabets.end() - 1);
            minHeapify(alphabets, 0);
            return min;
        }
        else
        {
            Alphabet underflow = {'\0', -1};
            return underflow;
        }
    }

    void insert(std::vector<Alphabet> &alphabets, Alphabet alphabet)
    {
        alphabets.insert(alphabets.begin(), alphabet);
        size++;
        minHeapify(alphabets, 0);
        // buildMinHeap(alphabets);
    }
};

Alphabet huffman(std::vector<Alphabet> &alphabets)
{
    MinHeap heap;
    heap.buildMinHeap(alphabets);

    while (alphabets.size() != 1)
    {
        Alphabet z;

        Alphabet *x = new Alphabet;
        *x = heap.extractMin(alphabets);
        z.left = x;

        Alphabet *y = new Alphabet;
        *y = heap.extractMin(alphabets);
        z.right = y;

        z.freq = x->freq + y->freq;

        heap.insert(alphabets, z);
    }
    return (heap.extractMin(alphabets));
}

void printCodes(int *code, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << code[i] << " ";
    }
    std::cout << std::endl;
}

void getCodes(Alphabet *root, int code[], int next)
{
    if (root->left)
    {
        code[next] = 0;
        getCodes(root->left, code, next + 1);
    }
    if (root->right)
    {
        code[next] = 1;
        getCodes(root->right, code, next + 1);
    }
    if (root->letter != '\0')
    {
        std::cout << root->letter << " : ";
        printCodes(code, next);
        delete root;
    }
}

int main()
{
    std::vector<Alphabet> alphabets;
    const int count = 6;
    alphabets.reserve(count);
    Alphabet A = {'A', 5};
    Alphabet B = {'B', 25};
    Alphabet C = {'C', 7};
    Alphabet D = {'D', 15};
    Alphabet E = {'E', 4};
    Alphabet F = {'F', 12};
    alphabets.emplace_back(A);
    alphabets.emplace_back(B);
    alphabets.emplace_back(C);
    alphabets.emplace_back(D);
    alphabets.emplace_back(E);
    alphabets.emplace_back(F);

    Alphabet root = huffman(alphabets);
    int code[count];
    getCodes(&root, code, 0);
}
