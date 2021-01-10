class Node:
    def __init__(self, val=0, next_node=None):
        self.val = val
        self.next_node = next_node

    def get_val(self):
        return self.val

    def get_next(self):
        return self.next_node

    def set_next(self, new_next):
        self.next_node = new_next

class LinkedList:
    def __init__(self, head=None):
        self.head = head

    def insert(self, val):
        new_node = Node(val)
        new_node.set_next(self.head)
        self.head = new_node

    def remove_nth_startPos(self, index):
        tmp1 = self.head
        tmp2 = tmp1.next_node
        if index == 0:
            self.head = tmp2
            return
        elif index == 1:
            tmp2 = tmp2.next_node
            tmp1.next_node = tmp2
            self.head = tmp1
            return
        elif index > 1:
            try:
                i = 1
                while i < index:
                    tmp1 = tmp1.next_node
                    tmp2 = tmp2.next_node
                    i += 1
                tmp1.next_node = tmp2.next_node
            except AttributeError:
                print("\nOut of index bounds!")
                return None
            return
        else:
            print("Invalid Index")

    def remove_nth_endPos(self, index):
        tmp = self.head
        cnt = 0
        while tmp is not None:
            tmp = tmp.next_node
            cnt += 1
        startPosIndex = cnt - index - 1
        self.remove_nth_startPos(startPosIndex)

    def print_List(self):
        temp = self.head
        cnt = 0
        while temp is not None:
            print(temp.val, end=" ")
            temp = temp.next_node
            cnt += 1
        return cnt
# class Solution:
#     def removeNthFromEnd(self, head: ListNode, n: int):

lst = LinkedList()
lst.insert(4)
lst.insert(3)
lst.insert(2)
lst.insert(1)
print(f"\nCount = {lst.print_List()}")
print()
lst.remove_nth_endPos(2)
print(f"\nCount = {lst.print_List()}")
print()
# lst.print_List()
# print()
# lst.remove_nth_startPos(0)
# print()
# lst.print_List()