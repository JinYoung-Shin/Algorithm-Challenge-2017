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
<<<<<<< HEAD
책에 나온 알고리즘을 참조하여 구현함. Divide and conquer 방식인데, 같은 문제를 2번 이상 풀지 않으므로 DP의 memoization은 필요가 없다. Brute force시 O(N^2)이 걸리는데 비해, 이 방식은 O(NlgN)이 걸린다.
=======
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

#### 12_lis
https://algospot.com/judge/problem/read/LIS    
다이나믹 프로그래밍으로 푼다. main.cpp는 O(N^2)로 푸는 풀이코드이다. dp[i]를 arr[i]를 마지막 수열로 하는 증가하는 부분 수열 중 최장 길이를 뜻한다. 부분수열 문제를
sub-problem으로 분해할 때, 수열의 마지막 숫자와 그 숫자로 끝나는 수열 중 가장 긴놈의 길이를 같이 저장해야 한다.

#### 13_jlis
https://algospot.com/judge/problem/read/JLIS    
다이나믹 프로그래밍으로 푼다. -1 인덱스를 줘서 호출을 간단하게 하는 부분은 부차적인것이고, 지금 index의 값 중 최대값을 구해서 그놈보다 큰놈에 대하여 체크하는 방식이다. LIS문제를 2차원으로 확장해서 풀었다.    
dp-2.cpp는 -1인덱스 대신 0 인덱스가 모두 탐색하도록 바꾼 코드이다.

#### 14_pi
https://algospot.com/judge/problem/read/PI    
역시 다이나믹 프로그래밍으로 푼다. dp[i]는 시퀀스의 l번째 index부터 외우는 가장 낮은 난이도의 난이도 합을 가지고 있다.

#### 16_tiling2
https://algospot.com/judge/problem/read/TILING2    
다이나믹 프로그래밍이다. dp[i] = dp[i-1] + dp[i-2]의 점화식을 갖는다. dp[i-2]는 두개 전에 가로로 2개 쌓인 경우, dp[i-1]은 하나 전에  새로로 하나 쌓은 경우이다.

#### 17_tripathcnt
https://algospot.com/judge/problem/read/TRIPATHCNT    
삼각형위의 최대 경로만 구하는게 아니라 그 경로의 개수도 새야 한다. dp로 풀 수 있다.    
이전 까지 위에서 최대경로이여야지 밑에가서도 최대라는 것을 이용할 수 있다. dp[i][j].first는 해당 경로까지
가는 최대 값이고, dp[i][j].second는 해당 경로를 최대 경로로 가는 가짓수이다.
위에서 내려온거랑 오른쪽위에서 내려온게 같은 값이면 경우의수를 더해버리면 된다.
정답 도출시에는 최대값 훑어서 최대값과 같은녀석들의 경우의 수를 더해버리면 된다.

#### 18_snail
https://algospot.com/judge/problem/read/SNAIL    
counting은 이항계수를 이용해서 경우의 수를 모두 세어서 계산한 방법이다. floating-point error때문에 1000 900의 tc의 경우
1에 수렴한 값이 나와야 하는데 0에 가까운 값이 나타난다.
dp는 subproblem으로 나누어서 해결하는 dp방법으로 해결한 솔루션이다. 책에서 나타난 솔루션이며, 정답처리가 된다.
dp[day][meter]는 day날동안 meter 만큼 올라왔을 때, 최종적으로 탈출할 수 있는 확률을 저장한다.

#### 19_asymtiling
https://algospot.com/judge/problem/read/ASYMTILING    
dp로 일단 대칭과 상관없이 타일링 할 수 있는 경우의 수를 구한다. 피보나치 수열형태로 구할 수 있다.
거기서 대칭인 경우를 빼주는 식으로 개수를 셀 수 있는데, 홀수길이와 짝수길이의 경우를 따로 구한다.
홀수 너비의 경우 가운데에 새로 하나 우뚝솟은놈 빼고 양 사이드가 floor(n/2)너비이므로, 해당 개수만큼이 대칭이다.
짝수너비의 경우 두가지 경우가 있는데 하나는 n/2너비로 반반 대칭인 경우와, 하나는 가운대에 가로2개짜리가 있어서
양 쪽이 n/2-1로 반반인 경우가 있다. 가로2개짜리는 반 찢어지지가 않으므로 각각의 경우에 세어져 있지 않다.
전체 개수에서 대칭인 경우를 빼 주면 정답이 나온다.

#### 20_poly
https://algospot.com/judge/problem/read/POLY    
dp로 풀 수 있는 문제이다. 3차원 dp이며 뜻은 dp[i][j][k] -> i층까지 총 j개의 블럭을 놓고, 
최근에 k개의 블럭을 놓을 수 있는 가짓수이다.    
이전에 j개의 블럭을 놓았으면 다음 줄에 l개의 블럭을 놓는다 했을 때 , 위치를 (j+l-1)가지만큼 할 수 있으므로
곱해서 더하면 된다.

#### 21_numb3rs
https://algospot.com/judge/problem/read/NUMB3RS    
dp로 풀 수 있는 문제이다. 2차원 dp이며, dp[i][j]이면, i번째날에 j번 마을에 두니발이 있을 확률이다.
dp[i][j]는 i-1날에 j와 인접한 모든 마을에 대하여 그 마을이 k라 하면 dp[i-1][k] / \# of edge of kth
마을 만큼을 더하면 된다.
