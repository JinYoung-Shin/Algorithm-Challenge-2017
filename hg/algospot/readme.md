### algospot
https://book.algospot.com/problems.html    
위 페이지에서 나타난 문제들을 풀이한 소스코드들이다.

#### 01_festival

https://algospot.com/judge/problem/read/FESTIVAL

brute.cpp 는 brute-force 방식으로 정답처리 받은 코드이다.

sum_ver.cpp는 summation 방식을 적용하여 c언어 방식으로 코딩하여 정답처리 받은 코드이다.

main.cpp는 c++ stl을 사용하여 summation 방식을 사용하여 풀이하였는데, 오답처리가 나타난 코드이다. vector 객체를 사용했는데 해당 부분에서 논리 에러가 나타난듯 함.

#### 02_boggle

https://algospot.com/judge/problem/read/BOGGLE

brute.cpp는 brute-force 방식으로 문제 풀이한 코드이다. 제출하면 시간제한으로 오답 처리된다.    

memoization.cpp는 brute-force방식에서 이미 검사한 부분을 메모하는 dynamic programming 의 원리를 이용하여 푼 소스코드이다. 정답 처리가 나온다. 방식은, 3차원 dp인데, \[x\]\[y\]\[len\]로 저장을 하며, 시작하는 좌표와, 해당 단어의 몇번째 index의 단어부터 만족하는지 아닌지를 bool 형태로 저장한다.

#### 03_picnic
https://algospot.com/judge/problem/read/PICNIC    
brute.cpp는 모든 케이스를 다 해보는 방식으로 푼 소스코드이다.    
정답처리 받았다.

#### 04_boardcover
https://algospot.com/judge/problem/read/BOARDCOVER    
brute.cpp는 모든 케이스를 다 해보는 방식이며, 책을 참조한 소스코드이다. 뭔가 간단해보이지만, 직접 아이디어를 생각해내려면 생각보다 꽤나 어려운 문제였다. 그리고 블록을 놓는 기준도 잘 정해야 한다.    
brute_copy0.cpp는 혼자서 짜 보려다가 실패한 소스코드이다.

#### 05_clocksync
https://algospot.com/judge/problem/read/CLOCKSYNC    
책에서 낸 아이디어와 같이 완전탐색을 실시하였다. 4^10=2^20=1024^2는 10^6에 근사하며, 이는 100만으로 1억인 10^8보다 100배 작다. 할만했다. 실행시간은 2초로 꽤 긴편이었다.

#### 06_quadtree
https://algospot.com/judge/problem/read/QUADTREE    
쿼드트리 트리 자료구조를 직접 구현해서, 출력 순서를 1,2,3,4 가 아닌 3,4,1,2 로 하면 된다.

#### 07_fence
https://algospot.com/judge/problem/read/FENCE    
분할정복을 이용하여 O(NlgN)만에 문제를 해결한다. 왼쪽에서만 포함된 경우, 오른쪽에서만 포함된 경우, 양쪽에 걸치는 경우를 따져서 문제를 풀면 되며, 양쪽에 걸치는 경우는 좌우로 확장해나가게 구성하면 된다.

#### 09_jumpgame
https://algospot.com/judge/problem/read/JUMPGAME    
다이나믹 프로그래밍으로 풀면 된다. dp[i][j]는 i,j에서 끝점까지 도달가능한지를 여부를 저장하는 dp 메모이다.

#### 10_wildcard
https://algospot.com/judge/problem/read/WILDCARD    
다이나믹 프로그래밍으로 풀면 된다. \*패턴의 경우는 와일드카드 패턴 인덱스만 전진하는 경우와(더이상 \*에 매칭 안되는 경우), 스트링 인덱스만 전진하는 경우(\*에 매칭되는 경우) 둘다 따져주면 간단하게 해결된다.

#### 11_trianglepath
https://algospot.com/judge/problem/read/TRIANGLEPATH    
다이나믹 프로그래밍으로 풀면 된다. 점화식을 forward식으로 짜도 되도 backward식으로 짜도 된다. 초반에 틀린것은 기저사례를 정해주지 않았기 때문이다. 흑흑 get(x,y)에서 x와 y가 out of range가 되었을때 처리를 해줘야 한다.