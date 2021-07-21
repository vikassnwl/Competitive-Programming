class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
        else:
            cur = self.head
            while cur.next:
                cur = cur.next
            cur.next = new_node

    def appendleft(self, data):
        new_node = Node(data)
        new_node.next = self.head
        self.head = new_node
    
    def remove(self, data):
        if self.head:
            if self.head.data == data:
                self.head = self.head.next
            else:
                cur = self.head
                while cur.next:
                    if cur.next.data == data:
                        cur.next = cur.next.next
                        break
                    cur = cur.next
    
    def pop(self):
        if self.head:
            if not self.head.next:
                self.head = None
            else:
                cur = self.head
                while cur.next.next:
                    cur = cur.next
                cur.next = None

    def popleft(self):
        if self.head:
            self.head = self.head.next

    def print_list(self):
        cur = self.head
        while cur:
            print(cur.data)
            cur = cur.next

ll = LinkedList()
ll.append(5)
ll.append(6)
ll.appendleft(7)
ll.pop()
ll.popleft()
ll.remove(5)
ll.print_list()
