### baekjoon_lecture
https://www.acmicpc.net/lecture/56    
위 페이지에서 나타난 문제들을 풀이한 소스코드들이다.
(백준 마지막 강의)

#### 4.3-bfs/1697-catch-that-cow
https://www.acmicpc.net/problem/1697    
4월 3일 bfs 강의 첫번째 문제, 소 잡기 문제이다.    
bfs.cpp는 포인터를 이용해 노드를 만들어서 bfs로 푼 코드이다. 메모리 초과로 오답이다.    
ids.cpp는 Iterative-deepending depth-first-search로 푼 코드이다. 시간 초과가 난다.    
new_bfs.cpp는 bfs를 malloc을 사용하지 않고 푼 코드이나 똑같이 메모리 초과로 오답이다 ㅠㅠ    
bfs_with_memo.cpp는 bfs에 visited node를 flag로 기록한 방식인데... 왜 이걸로는 풀리는지 좀더 연구가 필요할듯 하다 ㅠㅠ(정답)

#### 4.3-bfs/12851-catch-that-cow-2
https://www.acmicpc.net/problem/12851    
숨바꼭질 두번째 문제이다. 최적해의 개수도 같이 구해야하는데, 범위를 [0, MAX]로 주어야 한다는 점을 간과해서 꽤나 해맸다. 왜그런거지..

#### 4.3-bfs/13549-catch-that-cow-3
https://www.acmicpc.net/problem/13549    
4월 3일 bfs 강의 세번째 문제, 숨바꼭질3번 문제이다.    
child node를 만들어서 사용을 할 경우 느려질 수 있다??    
(이 부분은 맞는지, 아니면 단지 자료구조가 더 편한건지 모르겠다)    
그래서 array를 활용한 bfs를 이용하여 풀었다.    
bfs_with_memo.cpp는 숨바꼭질 문제를 푸는 방식을 적용해서 풀어보려다가 오답이 난 코드이다.    
bfs_arr_ver.cpp는 bfs를 배열 자료구조를 활용하여 적용한 소스코드이다.(정답코드) 

#### 4.3-bfs/19313-catch-that-cow-4
https://www.acmicpc.net/problem/13913     
4월 3일 bfs 강의 네번째 문제, 숨바꼭질4번 문제이다.    
기존의 숨바꼭질 문제와 다른 점은, 가는 경로를 알려줘야 한다는 점이다.    
bfs_with_memo.cpp는 1697번 문제를 푸는 해법에서, trace를 포인터를 이용해서 기록을 한 뒤, 마지막에 그 경로를 출력해준다는 부분만 다르다.    

#### 4.3-bfs/2178-maze-search
https://www.acmicpc.net/problem/2178     
4월 3일 bfs 강의 다섯번째 문제, 미로탐색이다.    
bfs.cpp는 bfs 알고리즘을 이용해서 최적해를 구한 소스코드다.    
한 번 지나간 길을 재탐색할 필요는 없다.        

#### 4.3-bfs/5014-elevator-trouble
https://www.acmicpc.net/problem/5014    
4월 3일 bfs강의 여덟번째 문제, 스타트링크(엘리베이터 트러블)문제이다.    
bfs.cpp는 bfs를 이용하여 최적해를 구한다.    
한번 탐색한 층은 다시 탐색하지 않는다.

#### 4.3-bfs/3055-slikar
https://www.acmicpc.net/problem/3055    
4월 3일 bfs강의 아홉번째 문제, 탈출문제이다.
bfs.cpp는 bfs를 이용하여 최적해를 구한다.    
기존 미로찾기와 다른 부분은 스택을 2개를 써서 step by step으로 접근한다는 점

#### 4.3-bfs/14226-emoticon
https://www.acmicpc.net/problem/14226    
4월 3일 bfs강의 열세번째 문제, 이모티콘 문제이다.    
bfs.cpp는 bfs를 이용하여 최적해를 구한다.

#### 4.4-dp-basis/1463-make1
https://www.acmicpc.net/problem/1463    
4월 4일 dp 기초 강의 첫번째 문제, 1로 만들기 문제이다.    
bfs.cpp는 bfs에 memoization 개념을 적용해서 푼 소스코드이다.

#### 4.4-dp-basis/12852-make1-2
https://www.acmicpc.net/problem/12852    
4월 4일 dp 기초 강의 두번째 문제, 1로 만들기 2 문제이다.    
bfs.cpp는 bfs에 memoization 개념을 적용해서 푼 소스코드이다.

#### 4.4-dp-basis/9095-adding-123
https://www.acmicpc.net/problem/9095    
점화식만 잘 만들면 쉬운 문제    

#### 4.4-dp-basis/11726-2n-tile
https://www.acmicpc.net/problem/11726    
전형적인 피보나치 문제. 산술 오버플로를 잘 고려하지 않으면 오답이 난다. 조심할 것!

#### 4.4-dp-basis/2193-pinary-number
https://www.acmicpc.net/problem/2193    
점화식으로 푼다. An,0 -> n자리 0으로 끝나는 이친수 개수 / An,1 -> n자리 1로 끝나는 이친수 개수    
An+1,0 = An,0 + An,1    
An+1,1 = An,0    
이다.

#### 4.4-dp-basis/11048-moving
https://www.acmicpc.net/problem/11048    
bfs로 풀어보았더니 메모리 초과가 나온다. (bfs.cpp) 큐가 터진 듯 하다.

#### 4.4-dp-basis/2225-sum-decomp
https://www.acmicpc.net/problem/2225    
dp로 풀 되, 수가 너무 커서 산술 오버플로가 날 수 있으므로 중간중간에 모듈러 연산을 해 주어야 한다.    
점화식으로 푼다. A(i,j) => i개 수를 더해서 j를 만들 수 있는 경우의 수    
A(i,j) = A(i-1,j) + A(i-1,j-1) + ... + A(i-1, 0);임을 이용한다.

#### 4.4-dp-basis/11066-merge-files
https://www.acmicpc.net/problem/11066    
greedy로 풀려고 했으나, 한글 문제 내용에 인접한 챕터만 합칠 수 있다는 내용이 빠져서 잘못된 접근을 하였다. greedy접근은 모두 오답.    
dp.cpp에서 dp의 관점으로 풀었다. 기저사례를 잘못 지정하여 또 해맸으나 결국 정답 나옴.

#### 4.4-dp-basis/1912-accu-sum
https://www.acmicpc.net/problem/1912    
dp[i]를 i번째 항의 합으로 끝나는 연속 합의 최대값으로 정의하면 된다. 최소 1개 이상의 항을 선택해야 한다는 조건을 잊으면 안된다.

#### 4.5-dfs-all-case/1759-mk-crypto
https://www.acmicpc.net/problem/1759    
dfs를 이용하여 모든 케이스를 다 탐색한다.    
자음과 모음 개수 체크하는 조건을 잘 확인해야 한다.

#### 4.5-dfs-all-case/1182-subset-sum
https://www.acmicpc.net/problem/1182    
dfs를 이용하여 모든 케이스를 다 탐색한다.    
공집합인 경우를 빼야하므로, S가 0이면 하나를 빼준다.

#### 4.5-dfs-all-case/10971-tsp2
https://www.acmicpc.net/problem/10971    
외판원순회2 문제이다. dfs로 풀수 있도록 N값이 작다. 0이면 갈 수 없다는 조건을 빠져먹어서 한번 틀렸다.

#### 4.5-dfs-all-case/9095-adding-123
https://www.acmicpc.net/problem/9095    
1,2,3더하기 문제이다. dp로도 풀 수 있지만 dfs로도 풀 수 있다.

#### 4.6-dp-mid/5557-1st-grade
https://www.acmicpc.net/problem/5557    
dp를 이용하여 풀었다.

#### 4.7-dp-bitmask/1562-stair-num
https://www.acmicpc.net/problem/1562    
비트마스크를 이용한 dp를 사용해서 풀었다.    
마지막에 정답을 구할 때, 다 구한 뒤 mod 연산을 제대로 안 해줘서 많이 해맸다 ㅠㅠ    
잘 확인할것!

#### 4.10-shortest-path-algorithm/1916-dijkstra
https://www.acmicpc.net/problem/1916    
최소비용 구하기 문제. 대놓고 다익스트라 최단거리 알고리즘 문제이다.    
주의할 점은 STL의 priority_queue를 사용할 경우, 최소값 코스트를 뿜은 우선순위 큐를 만들어야하는데    
선언 시 세번째 인자로 greater를 넣어줘야 한다는 점!    
dijkstra.cpp는 다익스트라 최단거리 알고리즘으로 푼 코드이다.

#### 4.10-shortest-path-algorithm/1504-specific-shortest-path
https://www.acmicpc.net/problem/1504    
특정한 최단 경로 구하기 문제. 다익스트라 알고리즘을 조금 활용하면 된다.    
1->a->b->n 의 경우와 1->b->a->n의 경우를 따져서 둘 중 작은 값을 취하면 된다.    
다만, 중간에 갈 수 없는 경우가 있을 수 있으므로 해당 부분을 잘 처리해야한다.

#### 4.10-shortest-path-algorithm/1753-shortest-path
https://www.acmicpc.net/problem/1753    
해당 시작점에서 다익스트라 알고리즘을 수행한 뒤, 각 vertex별로 거리값을 출력하면 된다.

#### 4.13-codeground-1/01-select-number
https://www.codeground.org/practice/practiceProbView.do?probId=1    
C++ stl SET을 이용하거나, XOR의 성질을 이용하여 풀면 된다.

#### 4.14-codeground-2/04-3n-plus-1
https://www.codeground.org/practice/practiceProbView.do?probId=25    
unsigned long long int를 사용하지 않으면 정답 처리를 받을 수 없다. 유의할 것!    
모든 케이스를 백트래킹으로 찾아도 케이스가 많지 않으므로 그렇게 처리하면 된다. 컷팅때문에 2^64만큼은 나오지 않음.

#### 4.14-codeground-2/07-kim
https://www.codeground.org/practice/practiceProbView.do?probId=44    
Indirect graph에서 cycle을 찾는 문제로 간주했는데, 아닌 반례가 존재한다.    
따라서 cycle\_chk.cpp는 60점, gfg.cpp는 70점을 받는다.(만점이 아니야 ㅠㅠ)    
gfg는 geeksforgeeks에 있는 알고리즘을 그대로 가져다 쓴 경우이다.    
cycle 찾는 알고리즘은 geeksforgeeks에서 참고함. <[링크](http://www.geeksforgeeks.org/detect-cycle-undirected-graph/)>    
따라서 다른 정답을 찾아봐야한다.

#### 4.12-segment-tree/2042-segment-sum
https://www.acmicpc.net/problem/2042    
세그먼트 트리를 쓰는 기본 문제이다. 세그먼트 트리와, 팬윅트리를 이용해서 풀어보았다. 관련된 설명 글이 꽤 많아서 좋다.    
[백준저지 세그먼트트리 설명글](https://www.acmicpc.net/blog/view/9)    
[GeeksforGeeks 세그먼트 트리 설명글](http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/)    
[GeeksforGeeks 팬윅트리\(바이너리 인덱스트 트리\) 설명글](http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/)    
[탑코더 Binary Indexed Tree 설명글](https://www.topcoder.com/community/data-science/data-science-tutorials/binary-indexed-trees/)

#### etc/14719-rain-water
brute force로 모든 셀을 순회해서, black 사이의 거리만큼 더하면 된다.

#### etc/2629-pan-balance
양팔저울 문제. 추로 나타낼 수 있는 무게가 15000g이하이므로, 각각의 경우에 대하여 가능한지 아닌지를 기록한 다이나믹 프로그래밍으로 문제를 풀 수 있다. 새로운 추가 추가되었을 때, 가능한 무게에 해당 추를 추가한 경우, 반대편에 추를 추가한 경우를 고려해서 무게를 표현할 수 있는지를 확인하면 된다.