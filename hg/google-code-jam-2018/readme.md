# google-code-jam-2018

## QualificationRound

### A.SavingTheUniversityAgain

CS 와 같은 형식으로 인접해있을 경우 swap을 시킨 뒤 데미지를 계산해본다.

### B.TroubleSort
홀수번째 원소와 짝수번째 원소들을 따로 배열로 뺀 뒤 정렬해서 정렬이 제대로 되면 Ok 아니면 Fail이다.

### C.GoGopher
인접 9개 중 prepared된 개수가 가장 적은놈들에다가 때려박으면 된다.

## Round1A

### A.WaffleChopper
초코칩이 균등하게 들어가도록 잘라야 한다. 자료구조는 2차원 구간합을 사용한다.
알고리즘은 다음과 같다.
Row 기준으로 일정한 개수의 초코칩이 나눠지도록 자르는 Index를 추가해놓는다.(sero_slice)
Col 기준 일정한 개수의 초코칩이 나누어지도록 자르는 Index를 추가해놓는다.(garo_slice)
만약 가로 세로로 정확히 N빵되는 Index가 없는 경우 도중에 Fail.

해당 가로세로 인댁스로 나누어서 구간합을 구했을 때 전체 초코칩 개수 / 구간 개수로 다 나누어지면
Possible이고 아니면 Impossible이다.