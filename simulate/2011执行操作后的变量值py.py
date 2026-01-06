from typing import List
class Solution:
    def finalValueAfterOperations(self, operations: List[str]) -> int:
        oper={"X++":1,"++X":1,"X--":-1,"--X":-1}
        X=0
        for now in operations:
            X+=oper[now]
        return X