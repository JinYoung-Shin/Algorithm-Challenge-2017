# google-code-jam-kickstart-2018

구글 코드잼 킥스타트 2018년.


## practice-round/A.GBus\_Count
해당 정류장을 지나는 버스 개수를 찾는 것인데, 노선 개수랑 쿼리 개수가 많지 않으므로
brute force로 하면 그냥 풀린다. 노선별로 해당 정류장을 지나는지 확인해서 개수를 센 뒤
출력하면 된다.

## practice-round/B.Googol\_String
구골이라는 큰 숫자에 쫄 수 있는데, 어차피 앞에부분은 똑같고 k값이 1e5인가 밖에 안된다.
재귀로 overlapping 되는 부분을 트래킹하면서 찾아가면 된다.


## practice-round/C.Sort\_a\_scrambled_itineary
링크드 리스트로 하나하나 찾아가면서 앞 뒤에 붙는 녀석들을 갓다가 붙인다. hash\_map(unordered\_map)으로
쉽게 인덱싱이 가능하다.


## practice-round/D.Sums\_of\_Sums
어려웠다. Small case는 brute force로 하나하나 그대로 해서 풀었는데,
Large Case는 Time complexity도 그렇고 space complexity가 장난아니다. 10GB메모리..ㅎㄷㄷ
정답좀 알려주오!