# atcoder
http://atcoder.jp/ 에 있는 문제들을 풀이하거나, 해당 사이트에서 주최하는 콘테스트에 대한 풀이입니다.    

일본에서 주최하는 Programming Competition 플랫폼입니다.

## beginner-084/A
48에서 입력값을 빼면 된다.

## beginner-084/B
문자열 패턴을 확인하면 된다.

## beginner-084/C
F가 S를 나눈다는 점을 착안해서, 현재 시간을 F로 나눈 뒤 올림한 시간이 출발 시간이고, 만약 이 값이 S보다 작다면 S를 취한다.
출발 시간에 이동시간 C를 더하면 다음 역 도착 시간이다. 이런식으로 모두 시뮬레이션 하면 된다.

## beginner-084/D
에라토스테네스의 채를 이용해서 해당 범위에 있는 모든 소수를 구한 뒤, simlar 수의 개수를 누적합으로 저장해서 쿼리를 빠르게 수행한다.

# grand-020
Solution: https://img.atcoder.jp/agc020/editorial.pdf

## grand-020/A
차가 짝수일때랑 홀수일때만 알아내면 된다.

## grand-020/B
brute.cpp 는 브루트 포스로 모든 경우를 다 따지는데 TLE다 당연히    
linear_search.cpp 는 정답에 있는 선형탐색을 구현한 것인데 이것도 TLE다 ㅠㅠ.

## regular-089/C
시간 diff와 이전 위치와의 맨하탄 거리를 잰 다음에, 거리가 시간 diff보다 크면 fail. 그리고 시간diff - 맨하탄 거리가 짝수이면 해당 step은 성공이고, 홀수이면 해당 step 실패이다. 짝수일 경우 한칸을 왓다리 갓다리 해서 시간을 때울 수 있기 때문이다.

## regular-089/D
Modular해서 한 공간에 몰아넣은 뒤, 2차원 배열로 겹치는 개수를 세고, 2차원 누적합을 이용해서 빠르게 Desire Maximum을 모두 구하면 된다. 이 때 조심해야 할 것이,
Modular하는 것이 k값이 아니라 2k값으로 해야한다는 것. 그리고 그에 따라서 공간이 9등분으로 나뉠 수 있고, for-loop으로 bruto-forcing을 할 경우 기준점이 완전 탐색을
할 때, 2k값까지 하는 것이 아니라 k값까지 하되, 색을 바꿔서 둘다 봐야한다. 정확한 풀이의 중요함을 다시 깨달을 수 있는 문제였다. ㅠㅠ