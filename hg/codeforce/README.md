# codeforce
코드포스의 문제를 풀이한 폴더이다.


## problemset
problemset에 있는 문제를 풀이한 폴더이다.

### 1a-theatre-square
1A번 문제 THEATRE SQUARE 문제이다. 알고리즘 자체는 간단하나, big decimal이 필요하다.

## contest-411-div2
2017년 5월 4일(목) 11시 50분부터 익일 새벽 1시 50분까지 진행된 코드포스 콘테스트이다.

### contest-411-div2/A.Fake-NP
같을때는 l을 출력, 그 외에는 2를 출력하면 답이다.

### contest-411-div2/B.3-palindrome
aabbaabb이런식으로 출력하면 답이다.

## contest-420-div2

### contest-420-div2/A.good-lab
O(n^4)로 모든 케이스를 다 해보면 정답이 나온다.    
n값이 50으로 제한이 작아서, 비벼볼만 하다

### contest-420-div2/B.banana-tree
등비수열의 합 공식을 사용해서 점을 하나 지정했을 때, 바나나 수확량을 O(1)로 구할 수 있다.    
직선따라서 x좌표 값을 바꾸어가면서 최대 y좌표 값에다가 적용하면 구할 수 있다.

### contest-420-div2/C.box-stack
하나하나 따라가다가, reorder가 필요할때 소팅하는 방식으로 하면 시간 초과가 난다.    
greedy method를 따라서 reorder를 실제로 실시하지 않고, 알아서 optimal하게 reorder했다고 가정하고 풀면 정답이다.

## contest-421-div2

### contest-421-div2/A.book-reading
하나하나 따라가면 되는 문제. 간단한 시뮬레이션 문제이다.

### contest-421-div2/B.angle
정N각형에서 나타날 수 있는 각도에 대한 패턴을 파악하면 된다.    
숫자처리 부분을 잘 못 해주어서 오답이 계속 났었다.

### contest-424-div2/A.unimodal
dfa만들어서 풀면 된다. transition만 적당히 설계하면 됨. prev값을 업데이트 해주는 것을 까먹어서 틀렸다.. 지금은 수정하여 맞춤

### contest-424-div2/B.keyboard
mapping 해주는 table을 만들어서 하나하나 1-to-1 translate 해주면 된다.

### contest-424-div2/C.jury_mark
생길 수 있는 값들을, 초기값을 임의로 두고 offset만 저장을 한다. 그리고 맵핑이 될 것들을 bias를 주어서 하나하나 모든 케이스를 고려한다.   
exhaustive search이다. 모든 케이스를 다 따진다.

### contest-426-div2/A.useless_toy
돌리는것을 모듈러 연산으로 처리하면 된다. 마이너스 값일 경우 음수가 나오는 것은 4의 배수를 더해주는 방법을 사용함.
### contest-426-div2/B.festival_evening
시작과 끝을 세서, 최대로 열린 문의 수를 센 뒤 가드 수와 비교하면 된다. 시작할때 끝도 체크를 안해줘서 계속틀렸었음.

### contest-427-div2/A.key-race
그냥 계산하면 되는문제. 문제수\*타이핑속도 + 핑\*2이 사용하는 시간이다.

### contest-427-div2/B.number
한땀한땀 새보면된다. digit 숫자개수별로 새서, 걔가 9가될때 얼만큼 add가 될 수 있는지를 계산하면 됨.

### contest-427-div2/C.stars
한땀 한땀 세보는 코드가 calc.cpp이다. 근데 이거는 timeout이 난다.    
따라서 누적합을 적용한 accum.cpp으로 풀었다. 고로 정답이다. 이거는 그래픽스에서 나왔던 개념인데, 정확하게 어디서 나왔는지는 기억이 안남..

### contest-428-div2/A
사탕을 주는 것을 하나하나 시뮬레이션 하면 된다. 첫번째 문제 답게 어렵지 않다.

### contest-428-div2/B
2번문제치고 생각보다 어렵다.    
Seat를 4명이 앉을 수 있는 경우, 2명이 앉을 수 있는 경우, 1명이 앉을 수 있는 경우로 나누어서    
그리디로 할당을 하면 되는데, 우선순위를 잘 정해줘야 한다. 딱 맞게 떨어지는 경우, best fit의 경우는 그대로 할당한다.    
그 외의 경우는 최대한 큰 seat에 할당을 하도록 해서, separate가 많이 되도록 하는 것이 유리하다.    
즉 3명을 할당해야 하는경우 1명 seat, 2명 seat가 하나이상씩 있으면 그대로 할당하는 것이 좋으나, 이 조건이 충족되지 않으면 4명짜리 seat에 앉히는 것이 1명짜리 seat 3개애 앉히는 것 보다 우선되야 한다는 것이다.   
코드포스 2~3번은 항상 그리디가 나왔던 것 같다.

### contest-428-div2/C
N이 커서 dfs로 다 안 풀릴 것 같은 우려가 될 수도 있는데, path수가 N-1개이므로, dfs로 모두 시간 안에 순회가 가능하다.    
다만 확률적으로 계속 계산을 해줘야 하는 것이, 지금 city에서 visited되지 않고 갈 수 있는 path의 수를 세서 확률을 잘 계산해줘야 한다.    
초반에 모든 경로를 다 개수를 센 뒤 평균값을 구했다가 오답이 나왔다. 착오없이 해야 한다.

## educational-27/A
첫번째 그룹의 가장 rating 낮은놈과, 두번째 그룹의 가장 rating 높은놈을 비교해주면 된다. 그룹 나눌 때는 소팅해서 높은 rating을 A팀에 몰아주면 된다.

## educational-27/B
앞쪽 뒤쪽 합을 구한뒤, 케이스를 나누어 생각한다. 예를들어 뒤쪽놈 값이 더 클 경우, 앞쪽놈의 값을 올리는 것과 뒤쪽놈의 값을 낮추는 것 중 더 효율적인 것을 찾아서 횟수를 새면 된다.

## educational-27/C
그리디로 풀 수 있다. 구간이 l, r로 나올 시 배열에 pair<int, int> (l, +1) (r+1, -1)을 넣는다. 그리고 pair.first 기준으로 정렬한다. 그리고 순서대로 second 값을 cnt에 저장해서, cnt가 3이상 값이 나오면 NO 아니면 YES이다.

## aim-tech-4-div2/A
k값 - 있는 알파뱃 수를 빼서 출력하면 된다. 길이보다 k가 클 시 impossible이다. 단, k-알파뱃수 값이 음수일때 0으로 처리를 안해주면 Hack 된다 ㅠ

## aim-tech-4-div2/B
한 열이나 행애 해당 색이 2개 이상일 경우 2^n-1 을 적용하고, 그외에 원소가 1개인 집합들은 가로,세로에서 샐 때 중복될 수 있으므로 나중에 한번씩만 더해준다. 그것이 n\*m이다.

## aim-tech-4-div2/C
pair<값, index> 로 만든 뒤 정렬을 해서, 정렬 하기 전과 정렬 한 후의 index들을 비교해본다. 집합을 만들어서 원래 인덱스 자리에 있는 놈들 집합 합쳐서 같은 집합이 되면 그놈들만 subsequence만들어서 sorting해도 정렬 이후와 동치가 된다.

## contest-432-div2/A
상수값의 범위에 따라서 답을 출력하면 된다. 간단한 문제이다.

## contest-432-div2/B
외심과 관련된 문제이다. abc 선이 한 직선위에 있지 않고, ab길이와 bc길이가 같으면 YES이다. 위 조건중 하나라도 만족되지 않으면 NO이다.

## contest-432-div2/C
모든 경우를 다 구해서 내적의 값이 음수가 아니면 실패이다. cosine 그래프를 그려보면 대충 보인다. 선형대수학과 관련이 깊은 문제이다.

## contest-434-div2/B
n값이 작기 때문에 완전탐색을 해도 된다. 층 별로 있는 flat의 수를 모두 고려해서, 만족하는 경우에 한해서 해당 층의 번호가 일정한 경우 정답, 일정하지 않는 경우 오답이다.

# icpc-2017-2018
2017-2018 ACM-ICPC, NEERC, Southern Subregional Contest, qualification stage (Online Mirror, ACM-ICPC Rules, Teams Preferred)이다.    
http://codeforces.com/contest/847

## icpc-2017-2018/A
링크드 리스트를 dfs방식으로 모두 찾은 뒤, 각각의 리스트들의 꼬리와 머리를 이어주면 된다.

## icpc-2017-2018/G
개수 모두 더해서 최대값을 출력하면 되는 문제. 간단하다

## icpc-2017-2018/M
등차수열인지 아닌지 확인해서 조건에 맞게 출력하면 된다. 간단하다.
