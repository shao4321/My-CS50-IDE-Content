class Node:


    def __init__(self, data=None):
        self.left = None
        self.right = None
        self.data = data

    def insert(self, data):
        if self.data:
            if data < self.data:
                if not self.left:
                    self.left = Node(data)
                else:
                    self.left.insert(data)
            elif data > self.data:
                if not self.right:
                    self.right = Node(data)
                else:
                    self.right.insert(data)
        else:
            self.data = data

    def search(self, val):
        if val < self.data:
            if not self.left:
                return f'{val} is not found'
            return self.left.search(val)
        elif val > self.data:
            if not self.right:
                return f'{val} is not found'
            return self.right.search(val)
        else:
            return f'{val} is found'

    def PrintTree(self):
        if self.left:
            self.left.PrintTree()
        print(self.data)
        if self.right:
            self.right.PrintTree()

root = Node()

for i in range(10):
    root.insert(i)

print(root.search(10))
