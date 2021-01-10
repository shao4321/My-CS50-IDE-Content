front = None
rear = None

class Node:
    def __init__(self, data, nxt):
        self._data = data
        self._nxt = nxt

def Enqueue(data):
    global front, rear
    temp = Node(data, None)
    if front == None and rear == None:
        front = rear = temp
        return
    rear._nxt = temp
    rear = temp

def Dequeue():
    global front, rear
    if front == None:
        return
    if front == rear:
        front = rear = None
    else:
        front = front._nxt

if __name__== "__main__":
    Enqueue(2)
    Enqueue(3)
    Enqueue(4)
    Enqueue(5)
    Enqueue(6)
    Enqueue(7)
    Enqueue(8)
    Dequeue()
    Enqueue(9)
    Dequeue()
    while front != rear:
        print(front._data, end=", ")
        front = front._nxt
    print(rear._data)