class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
    
    def appendleft(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            self.tail = self.head
        else:
            self.head.prev = new_node
            new_node.next = self.head
            self.head = new_node
    
    def pop(self):
        if self.head:
            if not self.head.next:
                self.head = None
                self.tail = self.head
            else:
                self.tail = self.tail.prev
                self.tail.next = None
    
    def popleft(self):
        if self.head:
            if not self.head.next:
                self.head = None
                self.tail = self.head
            else:
                self.head = self.head.next
                self.head.prev = None

    def remove(self, data):
        cur = self.head
        while cur:
            if cur.data == data:
                if not cur.next or not cur.prev:
                    if not cur.next:
                        self.tail = self.tail.prev
                        if self.tail:
                            self.tail.next = None
                    if not cur.prev:
                        self.head = self.head.next
                        if self.head:
                            self.head.prev = None
                else:
                    cur.prev.next = cur.next
                    cur.next.prev = cur.prev
                break
            cur = cur.next

    def print_list(self):
        cur = self.head
        while cur:
            print(cur.data, end=' ')
            cur = cur.next
        print()

    def print_reverse(self):
        cur = self.tail
        while cur:
            print(cur.data, end=' ')
            cur = cur.prev
        print()

ll = LinkedList()
ll.append(4)
ll.append(5)
ll.append(6)
ll.append(7)
ll.append(8)
ll.remove(6)
ll.print_reverse()
