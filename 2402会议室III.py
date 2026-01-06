from typing import List
import heapq
#我的想法:先把会议排序，然后整一个优先队列，所有会议室放进去，排序应该按end，id来排
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort(key=lambda x:x[0])
        avail_rooms = list(range(n))
        heapq.heapify(avail_rooms)
        used_rooms = []
        used_count = [0] * n
        cur_time = 0
        for start, end in meetings:
            cur_time = max(cur_time, start)
            while used_rooms and used_rooms[0][0] <= cur_time:#当前时间内已经开完会的房间，弹出放在可用房间里
                _, room = heapq.heappop(used_rooms)
                heapq.heappush(avail_rooms, room)
            if not avail_rooms:#当前时间下没有可用房间
                cur_time = used_rooms[0][0]#推进到有结束会议的房间的时间
                while used_rooms and used_rooms[0][0] <= cur_time:
                    _, room = heapq.heappop(used_rooms)
                    heapq.heappush(avail_rooms, room)
            room = heapq.heappop(avail_rooms)
            used_count[room] += 1
            heapq.heappush(used_rooms, (cur_time + end - start, room))
        return max(range(n),key = lambda i: used_count[i])