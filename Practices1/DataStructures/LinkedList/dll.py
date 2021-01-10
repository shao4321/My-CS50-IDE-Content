class LinkedList:
    def __init__(self, nodes=None):
        self.head = None
        if nodes: # Same as: if nodes is not None
            node = Node(str(nodes.pop(0)))
            self.head = node
            for i in nodes:
                node.next = Node(str(i))
                node = node.next

    # return nodes' elements must be in string form
    def __repr__(self):
        node = self.head
        nodes = []
        while node: # Same as: while node is not None
            nodes.append(str(node.data))
            node = node.next
        nodes.insert(0, "None")
        nodes.append("None")
        return " <- -> ".join(nodes)

    def __iter__(self):
        node = self.head
        while node: # Same as: while node is not None
            yield node
            node = node.next

    def add_first(self, node):
        if not self.head: # Same as: if self.head is None
            self.head = node
            node.prev = None
        else:
            node.next = self.head
            self.head.prev = node
            self.head = node

    def add_last(self, node):
        if not self.head:
            self.head = node
        else:
            for current_node in self:
                pass
            node.prev = current_node
            current_node.next = node

    def add_after(self, target_node_data, new_node):
        if not self.head:
            raise Exception("List is empty")
        for node in self:
            if node.data == str(target_node_data):
                new_node.prev = node
                new_node.next = node.next
                node.next.prev = new_node
                node.next = new_node
                return
        raise Exception("Node with data '%s' is not found" %target_node_data)

    def add_before(self, target_node_data, new_node):
        if not self.head:
            raise Exception("List is empty")
        for node in self:
            if node.data == str(target_node_data):
                new_node.next = node
                new_node.prev = node.prev
                node.prev.next = new_node
                node.prev = new_node
                return
        raise Exception("Node with data '%s' is not found" %target_node_data)

    def remove_node(self, target_node_data):
        if not self.head:
            raise Exception("List is empty")
        for node in self:
            if node.data == str(target_node_data):
                node.prev.next = node.next
                node.next.prev = node.prev
                node = None
                return
        raise Exception("Node with data '%s' not found" %target_node_data)

    def get_pos_fromData(self, target_node_data):
        if not self.head:
            raise Exception("List is empty")
        index = 0
        for node in self:
            if node.data == str(target_node_data):
                return index
            index += 1
        raise Exception("Node with data '%s' not found" %target_node_data)

    def get_data_fromPos(self, index):
        if not self.head:
            raise Exception("List is empty")
        node = self.head
        for i in range(index):
            node = node.next
            if not node:
                raise Exception("Node with index '%s' not found" %index)
        return node.data

    def reverse(self):
        if not self.head.next:
            return
        prev = None
        current = self.head
        while current:
            nex = current.next
            current.next = prev
            if prev:
                prev.prev = current
            prev = current
            current = nex
        self.head = prev
        prev.prev = None

class Queue(LinkedList):
    def enqueue(self, node):
        self.add_last(node)

    def dequeue(self):
        if not self.head:
            raise Exception("List is empty!")
        else:
            self.head = self.head.next


class Node:
    def __init__(self, data):
        self.data = str(data)
        self.next = None
        self.prev = None

    def __repr__(self):
        return self.data


if __name__ == "__main__":

    # Create a new linkedlist
    ll = LinkedList([1, 2, 3, 4, 5])

    # for elem in ll:
    #     print(elem)
    # print(ll)

    # ll2 = LinkedList()

    n1 = Node('a')
    n2 = Node('b')
    n3 = Node('c')
    n4 = Node('d')
    n5 = Node('e')
    n6 = Node(9)

    # ll2.add_first(n1)
    # ll2.add_first(n2)
    # ll2.add_first(n3)
    # ll2.add_last(n4)
    # ll2.add_last(n5)
    # ll2.add_before('b', n6)
    # ll2.remove_node(9)

    # print(ll2)
    # print(n2.prev)
    # print(n3.next)
    # print(n6.next)
    # print(ll2.get_pos_fromData('d'))
    # print(ll2.get_data_fromPos(5))
    # ll2.reverse()

    queue = Queue()
    # queue.enqueue(n1)
    # queue.enqueue(n2)
    # queue.dequeue()
    # queue.enqueue(n6)
    print(queue)