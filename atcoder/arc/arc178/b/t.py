MOD = 998244353

def count_ways(A1, A2, A3):
    # 各桁ごとの計算
    count = [0] * (A1 + A2 + A3 + 1)

    # 各桁の可能な値の組み合わせを計算
    for i in range(1, 10):
        for j in range(1, 10):
            for k in range(1, 10):
                total = i + j
                if total <= A1 + A2 and k <= A3:
                    count[total + k] += 1

    # 動的計画法の最適化
    dp = [0] * (A1 + A2 + A3 + 1)
    dp[0] = 1

    for i in range(1, A1 + A2 + A3 + 1):
        for j in range(i):
            dp[i] += dp[j] * count[i - j]
            dp[i] %= MOD

    return dp[A1 + A2 + A3]

# 例: A1 = 2, A2 = 2, A3 = 3 の場合
A1, A2, A3 = 1, 1, 1
result = count_ways(A1, A2, A3)
print(result)