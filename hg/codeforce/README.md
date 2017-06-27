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