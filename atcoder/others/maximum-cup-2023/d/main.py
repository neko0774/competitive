N, M, K, S = map(int, input().split())
segment_len = (N+M)//K
#繰り返される部分の長さ
times = (N+M)//segment
#繰り返される回数
reminder_len = N+M-segment*times
#あまり
segment = '1'*S+'0'*(S-segment_len)
print(segment*times)
