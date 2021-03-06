# 카카오 코드페스티벌 2017
http://tech.kakao.com/2017/08/11/code-festival-round-1/

## 1번문제
https://www.kakaocode.com/tryouts/1353/challenge_algorithm_codes/2780
### 카카오 프렌즈 컬러링북
출판사의 편집자인 어피치는 네오에게 컬러링북에 들어갈 원화를 그려달라고 부탁하여 여러 장의 그림을 받았다. 여러 장의 그림을 난이도 순으로 컬러링북에 넣고 싶었던 어피치는 영역이 많으면 색칠하기가 까다로워 어려워진다는 사실을 발견하고 그림의 난이도를 영역의 수로 정의하였다. (영역이란 상하좌우로 연결된 같은 색상의 공간을 의미한다.)

그림에 몇 개의 영역이 있는지와 가장 큰 영역의 넓이는 얼마인지 계산하는 프로그램을 작성해보자.

![apeach](https://github.com/JinYoung-Shin/Algorithm-Challenge-2017/blob/master/hg/kakao_festival/img/apeach.png)    
위의 그림은 총 12개 영역으로 이루어져 있으며, 가장 넓은 영역은 어피치의 얼굴면으로 넓이는 120이다.

##### 입력 형식
입력은 그림의 크기를 나타내는 `m`과 `n`, 그리고 그림을 나타내는 `m × n` 크기의 2차원 배열 `picture`로 주어진다. 제한조건은 아래와 같다.
- `1 <= m, n <= 100`
- `picture`의 원소는 `0`이상 `2^31 - 1`이하의 임의의 값이다.
- `picture`의 원소 중 값이 `0`인 경우는 색칠하지 않는 영역을 뜻한다.

##### 출력 형식
리턴 타입은 원소가 두 개인 정수 배열이다. 그림에 몇 개의 영역이 있는지와 가장 큰 영역은 몇 칸으로 이루어져 있는지를 리턴한다.

##### 예제 입출력
|m|n|picture|answer|
|-|-|-------|------|
|6|4|[[1, 1, 1, 0], [1, 2, 2, 0], [1, 0, 0, 1], [0, 0, 0, 1], [0, 0, 0, 3], [0, 0, 0, 3]]|[4,5]|

##### 예제에 대한 설명
예제로 주어진 그림은 총 4개의 영역으로 구성되어 있으며, 왼쪽 위의 영역과 오른쪽의 영역은 모두 `1`로 구성되어 있지만 상하좌우로 이어져있지 않으므로 다른 영역이다. 가장 넓은 영역은 왼쪽 위 `1`이 차지하는 영역으로 총 5칸이다.

## 2번문제
https://www.kakaocode.com/tryouts/1359/challenge_algorithm_codes/2778
### 보행자 천국
카카오내비 개발자인 제이지는 시내 중심가의 경로 탐색 알고리즘 개발 업무를 담당하고 있다. 최근 들어 보행자가 자유롭고 편리하게 걸을 수 있도록 보행자 중심의 교통 체계가 도입되면서 도심의 일부 구역은 자동차 통행이 금지되고, 일부 교차로에서는 보행자 안전을 위해 좌회전이나 우회전이 금지되기도 했다. 복잡해진 도로 환경으로 인해 기존의 경로 탐색 알고리즘을 보완해야 할 필요가 생겼다.

도시 중심가의 지도는 `m × n` 크기의 격자 모양 배열 `city_map`으로 주어진다. 자동차는 오른쪽 또는 아래 방향으로 한 칸씩 이동 가능하다.

`city_map[i][j]`에는 도로의 상황을 나타내는 값이 저장되어 있다.

- `0`인 경우에는 자동차가 자유롭게 지나갈 수 있다.
- `1`인 경우에는 자동차 통행이 금지되어 지나갈 수 없다.
- `2`인 경우는 보행자 안전을 위해 좌회전이나 우회전이 금지된다. (왼쪽에서 오던 차는 오른쪽으로만, 위에서 오던 차는 아래쪽으로만 진행 가능하다)    
![oneway500](https://github.com/JinYoung-Shin/Algorithm-Challenge-2017/blob/master/hg/kakao_festival/img/oneway500.png)   
도시의 도로 상태가 입력으로 주어졌을 때, 왼쪽 위의 출발점에서 오른쪽 아래 도착점까지 자동차로 이동 가능한 전체 가능한 경로 수를 출력하는 프로그램을 작성하라. 이때 가능한 경로의 수는 컴퓨터가 표현할 수 있는 정수의 범위를 넘어설 수 있으므로, 가능한 경로 수를 `20170805`로 나눈 나머지 값을 출력하라.
##### 입력 형식
입력은 도시의 크기를 나타내는 `m`과 `n`, 그리고 지도를 나타내는 2차원 배열 `city_map`으로 주어진다. 제한조건은 아래와 같다.
- `1 <= m, n <= 500`
- `city_map`의 크기는 `m × n`이다.
- 배열의 모든 원소의 값은 `0`, `1`, `2` 중 하나이다.
- 출발점의 좌표는 `(0, 0)`, 도착점의 좌표는 `(m - 1, n - 1)`이다.
- 출발점과 도착점의 `city_map[i][j]` 값은 0이다.
##### 출력 형식
출발점에서 도착점까지 이동 가능한 전체 경로의 수를 `20170805`로 나눈 나머지를 리턴한다.
##### 예제 입출력
|m|n|city_map|answer|
|-|-|--------|------|
|3|3|[[0, 0, 0], [0, 0, 0], [0, 0, 0]]|6|
|3|6|[[0, 2, 0, 0, 0, 2], [0, 0, 2, 0, 1, 0], [1, 0, 0, 2, 2, 0]]|2|
##### 예제에 대한 설명
첫 번째 예제는 모든 도로가 제한 없이 통행 가능한 경우로, 가능한 경우의 수는 6가지이다.
두 번째 예제는 문제 설명에 있는 그림의 경우이다. 가능한 경우의 수는 빨간 실선과 노란 점선 2가지뿐이다.