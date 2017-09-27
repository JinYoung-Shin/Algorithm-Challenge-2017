### KOI
https://www.acmicpc.net/category/55    
위 페이지에서 나타난 문제들을 풀이한 소스코드들이다.
(한국 정보 올림피아드)

#### 1996/e_01_danji
https://www.acmicpc.net/problem/2667    
1996년 초등부 1번문제, 단지번호붙이기 문제 풀이이다.
first.cpp는 첫번째 풀이 시도이다.    
bfs의 개념을 조금 사용한 풀이방법이다.

#### 1996/e_02_number
https://www.acmicpc.net/problem/2668    
1996년 초등부 2번문제, 숫자고르기 문제 풀이이다.
first.cpp는 첫번째 풀이 시도이다. STL set을 이용하여 풀이하였다.
알고리즘은 다음과 같다.
1. 두번째 줄의 숫자 집합을 구한다. 이를 A라고 한다.
2. A의 원소를 인덱스(첫번째 줄의 숫자기준)로 하는 숫자 집합 B를 구한다.
3. A집합과 B집합이 일치하면 이(A집합 혹은 B집합)를 리턴한다. 그렇지 않으면(B집합이 더 작으면) 다음 단계로 간다.
4. B집합을 A집합으로 두고, B집합은 초기화한다. A집합을 기준으로 스텝 2를 다시 시도한 뒤 3번으로 간다.

#### 1996/m_01_maxmult
https://www.acmicpc.net/problem/2670    
dp[i]는 i번째 수열에서 끝나는 부분수열의 최대곱을 저장하는 방식의 dp로 해결함


#### 1996/e_03_rectangle
https://www.acmicpc.net/problem/2669    
matrix.cpp는 좌표평면을 2차원 메트릭스에 그리드 모델링 시켜서 총 넓이를 계산하는 방식으로 푼 소스코드이다.

#### 2006/e_03_magicpaper
https://www.acmicpc.net/problem/2574    
steps.cpp는 색종이를 자르는 스탭을 하나하나 찾아가는 방식으로 푼 풀이법 코드입니다.

#### 2006/e_01_templeader
https://www.acmicpc.net/problem/1268    
임시반장 정하기 문제    
brute.cpp는 하나하나 다 세어서 최고값을 구하는 방식으로 푼 풀이법 코드입니다.

#### 2016/e_01_room
https://www.acmicpc.net/problem/13300    
방 배정 문제. 그냥 하나하나 개수 샌 뒤 필요한 방 수를 더하면 된다.

#### 2016/e_02_tile
https://www.acmicpc.net/problem/13301    
타일 장식물 문제. 가로 세로 길이가 늘어나는 패턴만 찾으면 간단하다.

#### 2016/e_03_resort
https://www.acmicpc.net/problem/13302    
리조트 문제    
dp.cpp 는 동적 프로그래밍(Dynamic Programming)으로 푼 풀이법이다.

#### 2016/e_04_barrier
https://www.acmicpc.net/problem/13303    
장애물 경기 문제. 공식 사이트에 나와있는 풀이법으로 풀었다.    
https://www.digitalculture.or.kr/koi/selectOlymPiadDissentList.do    

#### 2015/e_01_apple
https://www.acmicpc.net/problem/10833    
사과 세기 문제. 그냥 계산하면 된다. apple수를 사람수로 나누면 1인당 지급되는 사과수가 된다.

#### 2015/e_02_belt
https://www.acmicpc.net/problem/10834    
바퀴 회전수 문제. 정수로 떨어지게 되어있으므로 그냥 계산하면 된다.

#### 2015/e_03_card
https://www.acmicpc.net/problem/10835    
완전탐색을 하면 시간 초과가 난다. O(3^n)이 된다. 하지만 중복탐색되는 부분을 줄이면, 즉 Memoziation원리를 적용한 Dynamic programming으로 풀 시에는 나타나는 좀더 효율적으로 풀 수 있다. dp\[왼쪽남은카드수\]\[오른쪽남은카드수\]로 한다면 최악의경우 O(n^2)이므로 2000^2 = 400만으로 1초안에 풀 수 있다.

#### 2015/e_04_bee
https://www.acmicpc.net/problem/10836    
dfs로는 Time out이 난다. 그러므로 더 좋은 성능의 방법을 찾아봐야 한다.    
숫자가 감소하지 않는 방향이라고 했으니 규칙을 잘 보면, 왼쪽 끝과 위쪽 끝을 제외하고 내부쪽은 결과적으로 위쪽 값과 같은 값을 갖게 된다.    
이러한 규칙을 이용하면 O(MN)으로 해결 가능