# python3
# Data Structures, 1.1
import sys

class Bracket:
    """
    Class for storing 'brackets'
    """
    def __init__(self, bracket_type, position):
        self.bracket_type = bracket_type
        self.position = position

    def Match(self, c):
        """
        Function to determine if the current bracket
         has a matching pair
        Returns True for a match
        """
        if self.bracket_type == '[' and c == ']':
            return True
        if self.bracket_type == '{' and c == '}':
            return True
        if self.bracket_type == '(' and c == ')':
            return True
        return False

if __name__ == "__main__":
    text = input()
    opening_brackets_stack = []
    pos = 0
    for i, next in enumerate(text):
        if next in ['(','[','{']:
            opening_brackets_stack.append(Bracket(next, i+1))
        elif next in [')',']','}']:
            if not len(opening_brackets_stack) or \
                      not opening_brackets_stack.pop().Match(next):
                pos = i+1
                break

    if (not pos and len(opening_brackets_stack) > 0):
        pos = opening_brackets_stack.pop().position
    if (pos):
        print (pos)
    else:
        print ("Success")
