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
책에 나온 알고리즘을 참조하여 구현함. Divide and conquer 방식인데, 같은 문제를 2번 이상 풀지 않으므로 DP의 memoization은 필요가 없다. Brute force시 O(N^2)이 걸리는데 비해, 이 방식은 O(NlgN)이 걸린다.