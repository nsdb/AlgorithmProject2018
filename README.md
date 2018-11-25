# AlgorithmProject2018

알고리즘개론 팀프로젝트입니다.



* 필요한 데이터들을 우리가 만들어야 한다



* 먼저 데이터가 만들어져야 하는 구조체

- 부지(사이트) : 100개, ID, 여행기간(24시간 이상으로 구성), 하루 여행비용, [포함된 호텔, 연결된 교통수단]
시작점은 항상 1번 도시로 (여기가 공항임)

- 호텔 : 각 부지당 100개, ID, 하루 숙박비용(24시간 이상일 경우 무조건 투숙)

- 교통수단 : 300개, ID, 이동기간(시간), 이동비용, 시작점과 도착점(부지 간)
교통수단 설정은 수동으로 (랜덤으로 생성하기 어려움)



* 목적지 관련 
- 목적지는 항상 최종 도착지이다
- 일정 요청시, 기간 내에/비용 내에 목적지에 갈 수 있는 모든 경로를 표시한다.
- 중간에 거치는 모든 도시에 대해서는 여행기간과 여행비용을 계산한다.



