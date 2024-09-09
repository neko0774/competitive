N, K = map(int, input().split())
A = [int(i) for i in input().split()]
mod = 998244353


def find(ary):

  count = dict()

  ret = [0] * N
  cur = 0
  for i, a in enumerate(ary):
    if K - cur in count:
      ret[i] += count[K - cur]
    count[K - cur] += 1

  