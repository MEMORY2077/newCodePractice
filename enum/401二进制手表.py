class Solution:
    def readBinaryWatch(self, turnedOn: int) -> List[str]:
        res = []
        for h in range(0,12):
            for m in range(0,60):
                if m.bit_count()+h.bit_count() == turnedOn:
                    res.append(f"{h}:{m:02d}")
        return res
