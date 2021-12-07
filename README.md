# arduino-squid-game

넷플릭스 오리지널 '오징어 게임'의 첫번째 게임, **무궁화 꽃이 피었습니다**를 아두이노와 3D/레이저 프린터, 컴퓨터비전 등으로 구현한 프로젝트

![KakaoTalk_Photo_2021-12-06-21-07-25](https://user-images.githubusercontent.com/71601985/144843472-eb196843-e14b-4eb7-8a2b-9147f6167c8d.jpeg)

<br/>

## 구동 테스트 영상  
https://user-images.githubusercontent.com/71601985/144843485-3b44ed56-78ea-4a30-9f1c-9227c498082c.mp4

<br/>

## 영희 인형 - 3D 모델링 & 프린팅, 아두이노
- 영희 인형 모델을 오픈소스로 구해, 인형의 몸통을 반으로 가르고 안쪽에 모터가 들어갈 자리를 만드는 모델링 작업 진행 
- 오픈소스 3D 모델: https://cults3d.com/en/3d-model/various/squid-game-doll

![image](https://user-images.githubusercontent.com/71601985/145066728-652f8b7a-2cd3-4df1-8cb6-2f4e9a41c8a7.png)
![image](https://user-images.githubusercontent.com/71601985/145067368-6709dfe9-adf8-41f5-9bba-2d08951dbad5.png)
![image](https://user-images.githubusercontent.com/71601985/145076129-dbae536c-c9b8-4e87-991d-3d90269f7703.png)
![image](https://user-images.githubusercontent.com/71601985/145076170-bf2dd3fc-2518-480a-a3d8-337f5522a0df.png)
![image](https://user-images.githubusercontent.com/71601985/145076191-76d26813-c4a2-4b99-970f-94c1fda7498e.png)

- 몸 속 넓게 뚫은 공간에 서보모터를 설치하고 긴 봉으로 모터와 영희 인형의 목을 연결, 모터가 목을 돌릴 수 있게 설계



<br/>

## Utils - 2D 좌표 -> 3D 각도 변환
CV로 인식한 물체 움직임(2D 좌표 - x, y)을 2축 모터 레이저건의 타겟점(3D 각도 - X°, Y°)으로 변환하는 코드 작성

(아래는 물체 움직임 인식)

https://user-images.githubusercontent.com/71601985/145070927-3d9b1492-358d-4610-8f49-bf7e5f65d542.mp4

(아래는 2축 모터 레이저건 설계도)

<img src="https://user-images.githubusercontent.com/71601985/145080200-383e9b7d-53af-4a5e-a2b5-ac3ea3c62f55.png" width="50%">

- (x, y, X), (x, y, Y) 벡터로 사상해 충분한 양의 (x, y, X)와 (x, y, Y) 입력값이 들어왔을 경우, (x, y) 쌍으로 X°, Y° 값 예측
<br/>

**[작동 알고리즘]**  
- 젯슨나노에 장착된 카메라가 물체가 움직인 위치를 탐지해 (x, y) 좌표쌍을 계산
- 변환 코드로 (X°, Y°) 각도 쌍 예측
- 시리얼 통신을 통해 레이저건 아두이노 보드로 전송
- 2축 레이저건을 가로축으로 X°, 세로축으로 Y°만큼 움직여 움직인 물체 사격
- (사격하는 모습은 위 <a href="https://github.com/Daeun-Danna-Lee/arduino-squid-game/blob/main/README.md#%EA%B5%AC%EB%8F%99-%ED%85%8C%EC%8A%A4%ED%8A%B8-%EC%98%81%EC%83%81">'구동 테스트 영상'</a>에서 볼 수 있음)





<br/>

## 플레이어 모듈 - 레이저 프린팅, 아두이노
- 360도 회전 서보 모터 활용해 플레이어 RC카 제작
- 합판을 레이저 프린터로 절단해 외형 완성
- 블루투스 모듈을 활용한 조종
