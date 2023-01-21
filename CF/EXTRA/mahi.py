#Stack using array
class Stack:
    stack = []
    pointer = -1
    size = 0

    def push(self, element):
        self.stack.append(element)
        self.pointer += 1
        self.size += 1

    def peek(self):
        return self.stack[self.pointer]

    def pop(self):
        value = self.stack[self.pointer]
        self.stack = self.stack[:-1]
        self.size -= 1
        return value

#Stack using linked list

class Node:
    def __init__(self, value):
        self.value = value
        self.next = None

class Stack:
    head = None
    size = 0
    
    def __init__(self):
        head = None

    def push(self, value):
        if self.head == None:
            self.head = Node(value)
            self.size += 1
        else:
            node = Node(value)
            node.next = self.head
            self.head = node
            self.size += 1
    def peek(self):
        return self.head.value

    def pop(self):
        temp = self.head
        self.head = self.head.next
        #temp.value = None
        #temp.next = None
        self.size -= 1
        return temp.value

    def underFlow(self):
        return self.head == None


def checkParanthesis(expression):
    open_list = ["[", "{", "("]
    close_list = ["]", "}", ")"]
    all_list = ["[", "{", "(", "]", "}", ")"]
    stack = Stack()
    for i in expression:
        if i in all_list:
            stack.push(i)
    for i in expression:
        if i in all_list:
            if i in  open_list:
                stack.push(i)

def is_open(c):
    return (c == '(' or c == '{' or c == '{')

def is_closing(c):
    return (c == ')' or c == '}' or c == ']')

def paranthesisBalance(expression):
    parans = {')':'(', '}':'{', ']':'['}
    stack = Stack()

    flag = True
    pos = 1
    error = ''

    for i in expression:
        if is_open(i):
            stack.push(i)
        elif is_closing(i):
            if stack.underFlow():
                flag = False
                error = i
                break
            else:
                temp = stack.pop()
                if temp != parans[i]:
                    flag = False
                    error = i
                    break
        pos += 1
    
    if not flag:
        print("This expression is NOT correct.\nError at character #" + str(pos), end = " ")
        print(".\'"+ error + "\' -", end = " ")
        if is_open(error):
            print("not closed")
        else:
            print("not opened")
    else:
        print("This expression is correct.")



paranthesisBalance('1+2*(3/4)')
paranthesisBalance("1+2]*[3*3+{4–5(6(7/8/9)+10)–11+(12*8)]+14")