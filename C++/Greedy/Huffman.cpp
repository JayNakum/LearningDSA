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
        alphabets.insert(alphabets.end(), alphabet);
        size++;
        // minHeapify(alphabets, alphabets.size() - 1);
        buildMinHeap(alphabets);
    }
};

Alphabet huffman(std::vector<Alphabet> &alphabets)
{
    MinHeap heap;
    heap.buildMinHeap(alphabets);

    while(alphabets.size() != 1)
    {
        Alphabet z;
        
        Alphabet x = heap.extractMin(alphabets);
        z.left = &x;
        
        Alphabet y = heap.extractMin(alphabets);
        z.right = &y;

        z.freq = x.freq + y.freq;

        heap.insert(alphabets, z);
    }
    return (heap.extractMin(alphabets));
}

int main()
{
    std::vector<Alphabet> alphabets;
    alphabets.reserve(5);
    Alphabet a = {'a', 3};
    Alphabet b = {'b', 8};
    Alphabet c = {'c', 4};
    Alphabet d = {'d', 2};
    Alphabet e = {'e', 10};
    alphabets.emplace_back(a);
    alphabets.emplace_back(b);
    alphabets.emplace_back(c);
    alphabets.emplace_back(d);
    alphabets.emplace_back(e);

    Alphabet root = huffman(alphabets);
}