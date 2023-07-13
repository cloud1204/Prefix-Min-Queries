# Prefix Min Queries
*你會算前綴最小值，你也會算區間和。那現在問題來了...你會算區間前綴最小值的和嗎？*

給你一個陣列$a_1, a_2, a_3, ...,a_n$。你需要回答$q$ 筆詢問，其中第 $i$ 筆詢問包含兩個整數$l_i, r_i$。

對於每筆詢問，我們定義一個長度為$r_i-l_i+1$的陣列$b_1,b_2,b_3,...b_{r_i-l_i+1}$。

其中，$b_j = min(a_{l_i},a_{l_i+1},a_{l_i+2},...,a_{l_i+j-1})$，也就是$a$陣列從第$l_i$項開始數$j$項的最小值。對於每筆詢問，請你輸出其$b$陣列的和: $\sum\limits_{j=1}^{r_i-l_i+1} b_j$。

## 實作細節

### 輸入格式

* line $1$: $\;\;n\;\;q$
* line $2$: $\;\;a_1,a_2,a_3,...,a_n$
* line $2+i$ ($1 \le i \le q$): $\;\;l_i \;\;r_i$

### 輸出格式

* line $i$ ($1 \le i \le q$): $\;\;ans_i$

## 條件限制

- $1 \le n,q \le 3\times 10^5$。
- $1 \leq a_i \leq 10^9$。
- $1 \leq l_i \leq r_i \leq n$。

## 子任務

1. (30 points) $r_i = n$。
2. (70 points) 無額外限制。

## 範例

### 範例輸入 1

```
7 5
2 3 1 4 7 2 5
1 6
5 7
3 7
2 4
4 6
```

該範例輸入符合全部子任務的限制。

### 範例輸出 1

```
8
11
5
5
10
```

第一筆詢問，$b$陣列為：$[2, 2, 1, 1, 1, 1]$ 因此總和為$8$。
第二比詢問，$b$陣列為：$[7,2,2]$ 因此總和為$11$。

### 範例輸入 2

```
5 3
1 3 2 5 4
1 5
3 5
4 5
```

該範例輸入符合子任務 1 的限制。

### 範例輸出 2

```
5
6
9
```