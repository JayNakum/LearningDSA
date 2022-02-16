class Stack:
    def __init__(self, size) -> None:
        self.stack = []
        self.top = -1
        self.size = size - 1
    
    def push(self):
        if(self.top == self.size):
            print("Overflow")
        else:
            value = int(input("Enter Value: "))
            self.top += 1
            self.stack.append(value)
    
    def pop(self):
        if(self.top == -1):
            print("Underflow")
            return
        else:
            poped = self.stack.pop()
            self.top -= 1
            return poped

    def peek(self):
        print(self.stack[self.top])

    def traverse(self):
        print(self.stack)


size = int(input("Enter the size of Stack: "))
stack = Stack(size)

print("""
STACK OPERATIONS
    1. Traverse
    2. Push
    3. Pop
    4. Peek
""")

while True:
    choice = int(input("Enter your choice: "))
    if(choice == 1):
        stack.traverse()
    elif(choice == 2):
        stack.push()
    elif(choice == 3):
        value = stack.pop()
        print("Popped:", value)
    elif(choice == 4):
        stack.peek()
    else:
        break
