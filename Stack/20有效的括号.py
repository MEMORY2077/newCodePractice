class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        for now in s:
            if now == '[' or now == '{' or now == '(':
                stack.append(now)
                continue
            if now == ']':
                if len(stack) == 0 or stack[-1] !='[':
                    return False
            if now == '}':
                if len(stack) == 0 or stack[-1] != '{':
                    return False
            if now == ')':
                if len(stack) == 0 or stack[-1] != '(':
                    return False
            stack.pop()
        if len(stack) != 0:
            return False
        return True