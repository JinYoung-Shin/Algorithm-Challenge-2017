# swexpertacademy
https://www.swexpertacademy.com/ 의 문제들을 풀이한 저장소입니다.


## 1204 최빈수 구하기
brute force로 풀면 된다.


## 1493 수의 새로운 연산
https://www.swexpertacademy.com/main/solvingProblem/solvingProblem.do    
연산자를 정의하면 됨.

## 1952 수영장
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5PpFQaAQMDFAUq&categoryId=AV5PpFQaAQMDFAUq&categoryType=CODE    
dfs로 완전탐색 하면 됩니다.

## 3750 Digit Sum
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPiSYKAD0DFAUn&categoryId=AWHPiSYKAD0DFAUn&categoryType=CODE    
cin으로 하면 TLE가 나고 scanf로 하면 받아지는 더러운세상!

## 3752 가능한 시험점수
https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AWHPkqBqAEsDFAUn&categoryId=AWHPkqBqAEsDFAUn&categoryType=CODE    
2^100으로 하면 당연히 TLE가 날 것이다. 근데 가능한 점수가 100*100점이니 10000점이하일 것이라는것을 알수 있다.
이 점을 이용해서 크기가 10000인 bool 배열로 dp를 돌리면 된다. 루프 100만번 돈다고 보면 된다.

## 2072 홀수만 더하기
홀수만 더하면 된다. 몸풀기 문제

## 3347 올림픽 종목 투표
O(N^2)로 완전탐색하면 쉽게 풀린다. 문제를 제대로 안읽어서 삽질을 좀 하였다.

## 3316 동아리실 관리하기
dp로 풀 수 있다. 첫번째 날에 동아리 실 열쇠를 A가 가지고 있다는 것을 빠져먹어서 삽질을 많이 했다.
dp[bitset][len]라고 할 때, len번째 날까지 bitset만큼 멤버를 가지고 동아리실 유지하는 경우의 수로 정의하면 된다.
이전날 bitset과 bit-wise and 연산해서 0이 아니면 열쇠를 주고받을 사람이 있다는 뜻이므로, 그렇게 계산하면 된다.