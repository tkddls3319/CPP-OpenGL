# OpenGL 공부 내용

## 주요 학습 항목

### GLFW
- OpenGL 초기화 및 창 관리 라이브러리.
- **RefreshCallBack**: 화면 갱신 처리.
- **KeyboardCallBack**: 키보드 입력 처리.

### 색상 및 쉐이더 프로그래밍
- **Color 변경**: OpenGL을 사용한 색상 변경.
- **쉐이더 프로그래밍**: GLSL을 사용한 쉐이더 작성.
- **쉐이더 파일 관리**: 쉐이더를 외부 파일로 분리하여 관리.
- **Old 쉐이더**: 기존 방식의 쉐이더 비교 및 활용.
- **3가지 색의 삼각형**: 서로 다른 색상의 삼각형 구현.
- **GLSL 오류 로그 방법**: 쉐이더 오류 로그 확인.

### 기본 도형 그리기
- **두 개의 삼각형 그리기**: 여러 삼각형 그리기.
- **Primitives**: 기본 도형의 정의 및 활용.
- **3차원 Pyramid**: 3D 피라미드 구현.
- **삼각형으로 구체 만들기**.
- **팔면체로 구체 만들기**.

### 고급 그래픽 기술
- **Uniforms 사용**: 쉐이더에서 Uniform 활용.
- **z-buffer 사용**: 깊이 버퍼를 활용한 깊이 테스트.
- **후면 컬링 기법**: 후면 컬링을 통한 렌더링 최적화.
- **glDrawElements**: 메모리 절감을 위한 요소 기반 렌더링.

### 애니메이션 및 변환
- **애니메이션 적용 방법**: OpenGL에서 애니메이션 구현.
- **GLM 사용 방법**: OpenGL 수학 라이브러리.
  - **GLM을 사용한 삼각형 그리기**.
  - **GLM으로 회전 주기 적용**.
- **3D Scale**: 3D 스케일링.
- **EulerAngle**: 오일러 각을 활용한 회전.
- **Quaternion 사용**: 쿼터니언을 사용한 회전.

### 타이머 및 이벤트 처리
- **GLFW Time**: 시간 계산 및 처리.
- **C++ Time Chrono**: C++ 표준 시간 라이브러리.
- **Mouse 이벤트**: 마우스 입력 처리.
- **Mouse Drag**: 마우스 드래그 처리.

### OpenGL 디버깅
- **디버그 방법**: OpenGL 디버깅 기법.
- **디버그 이벤트 사용**: 이벤트 기반 디버깅.

### 카메라 및 뷰포트
- **View Transform**: Look-At 변환 적용.
- **Orthographic**: 직교 투영 적용.
- **Perspective**: 원근 투영 적용.
- **MVP**: Model, View, Projection 매트릭스.
- **Viewport**: 뷰포트 설정.
- **ScissorBox**: 화면 잘라내기 설정.
- **Window Resize**: 창 크기 변경 처리.
