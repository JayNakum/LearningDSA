# Huffman Coding in python

class Node(object):
    def __init__(self, left=None, right=None):
        self.left = left
        self.right = right

    def children(self):
        return (self.left, self.right)

    def nodes(self):
        return (self.left, self.right)

    def __str__(self):
        return '%s_%s' % (self.left, self.right)


def getFrequency(string: str) -> list:

    freq = {}
    for c in string:
        if c in freq:
            freq[c] += 1
        else:
            freq[c] = 1

    freq = sorted(freq.items(), key=lambda x: x[1], reverse=True)
    return freq


def getNodes(freq: list) -> list:
    nodes = freq

    while len(nodes) > 1:
        (key1, c1) = nodes[-1]
        (key2, c2) = nodes[-2]
        nodes = nodes[:-2]
        node = Node(key1, key2)
        nodes.append((node, c1 + c2))

    nodes = sorted(nodes, key=lambda x: x[1], reverse=True)
    return nodes

def huffman_code_tree(node, left=True, binaryString=''):
    if type(node) is str:
        return {node: binaryString}
    (l, r) = node.children()
    d = dict()
    d.update(huffman_code_tree(l, True, binaryString + '0'))
    d.update(huffman_code_tree(r, False, binaryString + '1'))
    return d

if __name__ == '__main__':
    string = input('Enter your message: ')
    freq = getFrequency(string)
    nodes = getNodes(freq)

    huffmanCode = huffman_code_tree(nodes[0][0])

    print('\nHuffman Code:')
    print('--------------')
    for (char, frequency) in freq:
        print('%s | %s' % (char, huffmanCode[char]))
    print()