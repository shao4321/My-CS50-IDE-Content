def IsEmpty():
    return queue_list == []

def Enqueue(num:int):
    queue_list.append(num)
    
def Dequeue():
    queue_list.pop(0)
    
if __name__== "__main__":
    queue_list = list()
    Enqueue(3)
    Enqueue(5)
    Enqueue(9)
    Dequeue()
    Dequeue()
    Dequeue()
    if queue_list == []:
        print("List is empty")
    else:
        print(queue_list)
