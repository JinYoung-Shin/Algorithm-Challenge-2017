### KOI
https://www.acmicpc.net/lecture/56    
위 페이지에서 나타난 문제들을 풀이한 소스코드들이다.
(백준 마지막 강의)

#### 4.3-bfs/1697-catch-that-cow
https://www.acmicpc.net/problem/1697    
4월 3일 bfs 강의 1번문제, 소 잡기 문제이다.    
bfs.cpp는 포인터를 이용해 노드를 만들어서 bfs로 푼 코드이다. 메모리 초과로 오답이다.    
ids.cpp는 Iterative-deepending depth-first-search로 푼 코드이다. 시간 초과가 난다.    
new_bfs.cpp는 bfs를 malloc을 사용하지 않고 푼 코드이나 똑같이 메모리 초과로 오답이다 ㅠㅠ    
bfs_with_memo.cpp는 bfs에 visited node를 flag로 기록한 방식인데... 왜 이걸로는 풀리는지 좀더 연구가 필요할듯 하다 ㅠㅠ(정답)
