
### e-palindrome
https://www.acmicpc.net/problem/8892    
모든 쌍 조합을 따져서 펠린드롬인지 하나하나 확인하면 되는 문제이다.    
순서가 바뀐것이 의미있으므로 잘 샐것

### f-pandora
https://www.acmicpc.net/problem/8893    
FA(Finite Automata)로 풀 수 있다.    
한가지 주의할 점은, 마지막에 R이 나타난다면 처음의 R과 연결될 수 있다는 점이다. => 요놈때문에 엄청 삽질했다.

### h-pole-arrangement
https://www.acmicpc.net/problem/    
dp로 푼다. 새로 배치하는 bar를 가장 긴 놈으로 생각하면 점화식이 어려워지는데, 가장 짧은 놈으로 생각하면 점화식이 괜찮게 나온다.    
dp.cpp는 오답, dp-shortest.cpp는 정답

### i-rock-scissor-paper
https://www.acmicpc.net/problem/8896    
하나하나 시뮬레이션 하면 되는 문제이다.