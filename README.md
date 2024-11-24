# 區間前綴最小值 (rpmq)

This problem is used in IONC 2023 Day3 Practice Contest.

## Problem Statement

你會算前綴最小值，你也會算區間和。那現在問題來了... 你會算區間前綴最小值的和嗎？

給你一個陣列 $a_1, a_2, \ldots, a_n$。你需要回答 $q$ 筆詢問，其中第 $i$ 筆詢問包含兩個整數 $\ell_i, r_i$。

對於每筆詢問，我們定義一個長度為 $r_i - \ell_i + 1$ 的陣列 $b_1, b_2, \ldots, b_{r_i - \ell_i + 1}$， 其中， $b_j = \min(a_{\ell_i}, a_{\ell_i+1}, \ldots, a_{\ell_i+j-1})$，也就是 $a$ 陣列從第 $\ell_i$ 項開始數 $j$ 項的最小值。

對於每筆詢問，請你輸出其 $b$ 陣列的和： $\sum\limits_{j=1}^{r_i - \ell_i + 1} b_j$。

## Input Format

第一行包含兩個正整數： $n \ \ \  q$。

第二行包含 $n$ 個正整數： $a_1 \ \ a_2 \ \ \ldots \ \ a_n$。

第 $2+i$ 行包含兩個正整數 ($1 \le i \le q$)： $\ell_i \ \ r_i$。

## Output Format

輸出 $q$ 行：在第 $i$ 行 ($1 \le i \le q$)輸出第 $i$ 筆詢問的答案。

## Constraints

$1 \le n, q \le 300\,000$。

$1 \le a_i \le 10^9$($1 \le i \le n$)。

$1 \le \ell_i \le r_i \le n$ ($1 \le i \le q$)。

所有輸入皆為整數。
