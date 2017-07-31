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