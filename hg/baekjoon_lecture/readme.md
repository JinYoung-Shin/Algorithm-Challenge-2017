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

#### 4.4-dp-basis/11048-move
https://www.acmicpc.net/problem/11048    
이동하기. dp로 간단한 문제임.

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

#### etc/1373-bin2oct
문자열로 받아서 가장 뒤 부터 3개씩 끊어서 8진수로 만든 뒤 거꾸로 출력하면 된다.

### etc/1920-occur
입력값이 100만개 이상이므로, cin/cout을 쓰지 말고 scanf/printf를 사용하면 된다.
CPP코드는 정답이 나온다.
파이썬 코드는 런타임 에러가 났는데 왜 그런지는 아직은 모르겠다.

### etc/1927-min-heap
http://blog.eairship.kr/249   
해당 글을 보고 참조하여 구현했다. 소스코드는 참조하지 않고 알고리즘만 참조했다.

### etc/11279-max-heap
http://blog.eairship.kr/249   
해당 글을 보고 참조하여 구현했다. 소스코드는 참조하지 않고 알고리즘만 참조했다.

### 4.3-bfs/2206-breaking-wall
벽부수고 이동하기다. dp베이스의 bfs로 풀 수 있다. 3차원 배열을 잘못 선언해서 삽질을 많이 함.

### etc/1076-resistance
파이썬 딕셔너리로 string을 만든 뒤 정수로 evaluation 해서 풀면 된다.

### etc/1992-quad-tree
분할정복으로 풀면 된다. 재귀로 구현하면 생각보다 간단하다.

### etc/14889-start-link
dfs로 완전탐색을 하면 된다. 재귀로 구현하면 좋다.

### etc/11053-longest-increasing-subsequence
dp_correct.cpp는 맞는 dp이고, dp_wrong.cpp는 틀린 dp다. dp_correct.cpp는 1차원 dp로 dp[i]는 i번째 원소를 마지막으로 하는 최장 부분수열 길이이다.

### etc/1004-little-prince
기하학 문제이다. 원이 들어왔을 때, 시작점과 도착점이 해당 원에 포함되는지 확인하고, 하나만 포함된 경우 카운트가 1 증가하게 된다.

### etc/2751-sorting2
O(nlgn)의 소팅을 사용하면 풀 수 있는 문제이다. merge_sort.cpp는 머지소트이며 merge_sort(start, end)의 경우 [start, end]의 폐구간을 정렬한다. merge_sort2.cpp의 머지소트인 merge_sort(start, end)의 경우는, [start, end)의 반개구간을 사용한다. border case를 잘 따져야 한다.

### etc/1874-stack-seqeunce
언뜻 보면 어려워 보이지만, 가능한 경우만 상황에 따라서 따라가면 된다.    
문제에서 주어진 수열과, 1부터 증가하는 수열 두개를 비교해가면서 상황에 맞게 스택 연산을 하면된다.    
1. 두개 값이 같은 경우 push 와 pop을 한번씩 하고 두 수열 다 다음것으로 넘어감    
2. 주어진 수열이 스택의 top과 같다면 pop하고 주어진 수열만 다음것으로 넘어감.
3. 두개 값이 다른 경우 push를 한번 하고 1부터 증가하는 수열만 다음것으로 넘어감.

1부터 증가하는 수열이 먼저 끝날 것이기 때문에, 스택에 남은 수를 모두 덤프하면 된다.    
매치가 안 될 경우 fail이다.

### etc/2581-prime
1은 소수가 아니다. 이 부분만 잘 체크하면 된다. 특정수 n이 소수인지 아닌지는 2부터 sqrt(n)까지의 모든 수로 나누어보고 모두 나누어 떨어지지 않으면 소수다. Naive한 소수 판별 알고리즘

## etc/14924-von-neuman-fly
공식을 적용하면 간단하다.

## etc/1158-josephers
Circular Doubly Linked List를 이용하면 쉽게 해결할 수 있다. Doubly Linked List는 제공하지만, Circular한 부분은 직접 구현했다.

## etc/1406-editor
링크드 리스트를 자료구조로 가져가면, 삽입, 삭제 시 O(1)로 해결할 수 있다. emplace로 추가하고 erase로 삭제하면 된다.

## etc/1764-unknown
해시 자료구조를 이용하면 간단하게 해결 가능하다.

## etc/11655-rot13
13더해서 모듈러하면 된다.

## etc/10820-string-analysis
C++ getline을 이용하면 된다.

## etc/2743-wordlen
그냥 길이를 재면 된다.

## etc/10799-iron-pipe
알고리즘을 다음과 같이 짠다. 일단 ()를 1로 치환해서 레이저임을 확실하게 보이게 만든다.
앞으로 진행하면서 각각의 char이 무엇인지 비교한다.
1. '(' 인 경우 : opened에 1을 추가한다. 지금 진행중인 파이프개수가 나중에 레이져를 만날때 마다 파이프 개수만큼 조각이 늘어나기때문.
2. '1' 인 경우 : opened만큼 정답을 추가한다. 진행중인 파이프 개수만큼 잘린 파이프 조각 수가 늘어난다.
3. ')' 인 경우 : opened에 1을 감소시키고, 정답에 1을 추가한다. 끝났기 때문에 이제 진행중이지 않은 파이프가 되며, 그거 자체로 하나의 조각이 된다.

## etc/10808-alphabet-num
그냥 세면 된다.

## etc/11403-connectivity
dfs로 탐색하면 된다. 도달가능하다면 visited가 체크될 것이다.

## etc/1167-diameter-of-tree
트리의 지름은 dfs를 두번 하면 된다. 아무 점t에서 dfs를 해서 t에서 가장 먼 점 u를 찾는다. 그리고 u를 기준으로 dfs를 해서 u에서 가장 먼 점 v를 찾는다.
점 u와 v 사이의 거리는 트리의 지름이다.

## etc/5525-ioioi
DFA를 그려서 알아내면 된다. 상태는 3개로 OO / I / IO 만 있으면 된다.

## etc/1793-tiling
dp로 푼다. big integer가 필요하므로 python으로 풀었다. dp[0] = dp[1] = 1로 정의하고, dp[i] = dp[i-1] + dp[i-2]*2 로 점화식을 새우면 된다.

## etc/10826-fibo4
피보나치다. loop로 풀어도 되고 dp로 풀어도 되지만, 중요한 것은 64bit integer 범위를 매우 뛰어넘는다는 것이다.
입력값이 최대값인 10000이 들어가게 되면 답은 다음과 같다.
```
33644764876431783266621612005107543310302148460680063906564769974680081442166662368155595513633734025582065332680836159373734790483865268263040892463056431887354544369559827491606602099884183933864652731300088830269235673613135117579297437854413752130520504347701602264758318906527890855154366159582987279682987510631200575428783453215515103870818298969791613127856265033195487140214287532698187962046936097879900350962302291026368131493195275630227837628441540360584402572114334961180023091208287046088923962328835461505776583271252546093591128203925285393434620904245248929403901706233888991085841065183173360437470737908552631764325733993712871937587746897479926305837065742830161637408969178426378624212835258112820516370298089332099905707920064367426202389783111470054074998459250360633560933883831923386783056136435351892133279732908133732642652633989763922723407882928177953580570993691049175470808931841056146322338217465637321248226383092103297701648054726243842374862411453093812206564914032751086643394517512161526545361333111314042436854805106765843493523836959653428071768775328348234345557366719731392746273629108210679280784718035329131176778924659089938635459327894523777674406192240337638674004021330343297496902028328145933418826817683893072003634795623117103101291953169794607632737589253530772552375943788434504067715555779056450443016640119462580972216729758615026968443146952034614932291105970676243268515992834709891284706740862008587135016260312071903172086094081298321581077282076353186624611278245537208532365305775956430072517744315051539600905168603220349163222640885248852433158051534849622434848299380905070483482449327453732624567755879089187190803662058009594743150052402532709746995318770724376825907419939632265984147498193609285223945039707165443156421328157688908058783183404917434556270520223564846495196112460268313970975069382648706613264507665074611512677522748621598642530711298441182622661057163515069260029861704945425047491378115154139941550671256271197133252763631939606902895650288268608362241082050562430701794976171121233066073310059947366875
```
하핫 그래서 파이썬을 쓰면된다.

## etc/10844-easy-stair-num
쉬운 계단수이다. dp로 푸는데 식을 이렇게 정의한다 dp[l][sz][r] 로 해서, 왼쪽 끝 수, 길이, 오른쪽 끝 수로 한다.
그래서 오른쪽으로 한 숫자씩 늘어난다고 생각해서, 개수를 세면 된다.

## etc/9465-sticker
왼쪽부터 스티커를 때는데, 어차피 같은 x좌표라고 하면 위 아래 중 하나만 땔 수 있고, 하나를 땟을때 오른쪽 다음것의 상태가 (위만 가능, 아래만 가능, 둘만 가능)의 3가지 상태가 나타나는 것을 착안하여 2차원 dp로 해결 가능.
dp[x][stat] 으로 x좌표와 상태3개의 dp로 풀 수 있다.

## etc/15353-bignum
BigInteger 클래스를 덧셈 연산 가능하도록 C++에서 구현하면 된다.

## etc/2156-wine-drinking
dp[i][j]를 i번째까지 진행했으며, 최근 j개의 연속된 와인을 마셨을때의 최대 많이 마신 수라고 정의하면 된다.

## etc/11055-largest-increasing-subsequence
11053번 문제와 비슷하다. 길이 대신 값의 합으로 dp배열에 저장하면 된다. dp[i]는 i번째 원소를 마지막으로 하는 부분 수열 중, 수열의 합의 최대값으로 정의하면 된다.

## etc/1032-cmd-prompt
?문자밖에 없으므로 brute force로 풀면 된다. 같은 인덱스의 글자가 모두 같으면 그 글자로, 아니면 ?을 출력하면 된다.

## etc/1013-contact && etc/2671-submarine
Regular Expression 패턴 일치 확인 문제입니다. DFA를 그려서 해결하면 간단합니다.