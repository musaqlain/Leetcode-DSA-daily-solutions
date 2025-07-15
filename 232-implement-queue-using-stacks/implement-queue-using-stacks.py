class MyQueue:

    def __init__(self):
        # stacks
        self.stack1 = []
        self.stack2 = []
        

    def push(self, x: int) -> None:
        self.stack1.append(x)

    def pop(self) -> int:
        if not self.stack2:
            # if stack2 is empty
            # move here...
            while self.stack1:
                element_to_shift = self.stack1.pop()
                self.stack2.append(element_to_shift)

        return self.stack2.pop()
        

    def peek(self) -> int:

        # stack2 is empty
        if not self.stack2:
            # if stack2 is empty
            # move here...
            while self.stack1:
                element_to_shift = self.stack1.pop()
                self.stack2.append(element_to_shift)

        # let's suppose stack2 is not empty
        # return top element
        return self.stack2[-1]
        

    def empty(self) -> bool:
        # stack1 is empty -> 0
        # not self.stack1 -> 1
        return not self.stack1 and not self.stack2
        # 1 -> 
        # 0 -> not empty
        


# Your MyQueue object will be instantiated and called as such:
# obj = MyQueue()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.peek()
# param_4 = obj.empty()