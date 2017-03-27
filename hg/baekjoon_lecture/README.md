### KOI
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