# Project Title : 42seoul_cube3d

## 1. 소개  
이번 과제는 cube3d라는 과제이다. cube3d 서브젝트를 소개하면 원시적인 3D 그래픽게임을 구현하는 과제이다.
이 게임을 구현하기 위해  "레이캐스팅"이라는 기술을 살펴볼 것이며, 원리에 대해서 상세히 알아보고 적용해볼 것이다.

그리고 이 게임을 두현하기 위해서 42SEOUL에서는 몇가지 라이브러리를 제공하고있는데 그 라이브러리 사용법에 대해서도 알아보자.

## 2. 공부할 것들....

0. [Cube 3D 소개](https://codingmonsters.tistory.com/23)
1. [mlx 사용법](https://codingmonsters.tistory.com/manage/newpost/?type=post&returnURL=%2Fmanage%2Fposts%2F)



MiniLibX 컴파일 옵션

컴파일 옵션

cc -L /opengl폴더 -lmlx -framework OpenGL -framework AppKit file.c
-L 옵션: 라이브러리의 경로를 지정

예시

cc -L ./minilibx_opengl_20191021 -lmlx -framework OpenGL -framework AppKit main.c

MLX의 다양한 함수들

MLX 시작 함수

1. mlx_init


윈도우 관리 함수

2. mlx_new_window

3. mlx_clear_window

4.
4. mlx_destroy_window


드로잉 함수

5. mlx_pixel_put

6. mlx_string_put


이미지 관리 함수

7. mlx_new_image

8. mlx_put_image_to_window

9. mlx_get_data_addr

10. mlx_get_color_value

11. mlx_xpm_to_image

12. mlx_xpm_file_to_image

13. mlx_png_file_to_image

14. mlx_destroy_image


이벤트 관리 함수

15. mlx_loop

16. mlx_key_hook

17. mlx_mouse_hook

18. mlx_expose_hook

19. mlx_loop_hook


그 외의 이벤트 관리 함수

20. mlx_hook

21. mlx_mouse_hide

22. mlx_mouse_show

23. mlx_mouse_move

24. mlx_mouse_get_pos

25. mlx_do_key_autorepeatoff

26. mlx_do_key_autorepeaton

27. mlx_do_sync


mlx_init

#include <mlx.h>

void *mlx_init ();
기능

- mlx 모든 함수 사용 이전에 사용해야 하는 함수

- 소프트웨어와 디스플레이를 연결한다.

- 연결이 되면, MiniLibX를 사용해 디스플레이와 메시지를 주고 받을 수 있다. 예를 들어 "이 창에 노란색 픽셀을 그리고 싶다." 또는 "사용자가 키를 쳤습니까?" 와 같은 기능이다.

반환값

- 연결 성공: 연결 식별자인 non-null 포인터

- 연결 실패: NULL




윈도우 관리 함수

함수들

- mlx_new_window: 새 창을 생성하는 함수

- mlx_clear_window: 창을 검은색으로 초기화하는 함수

- mlx_destroy_window: 창을 삭제하는 함수

mlx_new_window

void *mlx_new_window (void *mlx_ptr, int size_x, int size_y, char *title);
MiniLibX는 n개의 각기 다른 창들을 제어할 수 있다.

매개 변수

mlx_ptr: 연결 식별자이다.
size_x, size_y: 새 창의 사이즈이다.
title: 창의 타이틀바에 보일 문자열이다.
반환값

이것 또한 다른 함수에서 사용할 수 있는 연결 확인용의 non-null 포인터를 반환한다.
MiniLibX는 임의의 수의 개별 창을 처리할 수 있다.
생성 성공: void *win_ptr: 창 사용 식별자인 non-null pointer
생성 실패: NULL
mlx_clear_window

int mlx_clear_window (void *mlx_ptr, void *win_ptr);
매개 변수

win_ptr: 창 사용 식별자이다.
반환값

X
mlx_destroy_window

int mlx_destroy_window (void *mlx_ptr, void *win_ptr);
반환값

X


드로잉 함수

여기서 매개 변수 color는 int이다.

표시된 색은 정의된 체계에 따라 이 정수로 인코딩해야 한다.

표시 가능한 모든 색상은 빨강, 녹색, 파랑의 3 가지 기본 색상으로 나눌 수 있다.

0~255 범위의 세 가지 관련 값은 색상이 혼합되어 원래 색상을 만드는 정도를 나타낸다.

이 세 값은 정수 안에 설정되어 올바른 색상을 표시해야 한다.

이 정수의 최하위 3바이트는 아래와 같이 채워진다.

| 0 | R | G | B |

int를 채울 때 엔디언 문제를 잘 처리했는지 확실히 하자
Blue 바이트가 최하위 비트임을 기억하자
하드웨어 기능에 따라 최상위 비트는 투명도를 처리할 수 있다.
주의: OpenGL 클래식과는 반대로 불투명도를 나타내지 않는다.
함수들

- mlx_pixel_put: 지정된 픽셀을 그리는 함수

- mlx_string_put: 지정된 문자열을 그리는 함수

두 기능 모두 창 밖의 모든 디스플레이를 삭제한다. 이로 인해 mlx_pixel_put 속도가 느려진다. 그러므로 대신 이미지 사용을 고려해보라

mlx_pixel_put

int mlx_pixel_put (void *mlx_ptr, void *win_ptr, int x, int y, int color);
(0, 0): 창의 좌측 상단

x는 오른쪽으로, y는 아래를 향해 포인팅한다. (y 아래가 양수)

매개 변수

x, y: 화면의 x, y 좌표 값이다.
color: 바이트 단위로 000-255 사이의 |투명도|R|G|B| (0x00RRGGBB) 값이 저장된다.
mlx_string_put

int mlx_string_put (void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);
매개 변수

string: 나타낼 문자열


이미지 함수

함수들

- mlx_new_image: 메모리에 새로운 이미지를 생성한다.

- mlx_put_image_to_window: 이미지를 스크린에 출력한다.

- mlx_get_data_addr: 생성된 이미지의 정보를 반환하는 함수이다. 이 정보를 이용해 이미지를 수정할 수도 있다.

- mlx_get_color_value: 이미지 내부에 색상을 저장한다.

- mlx_xpm_to_image: 포멧에 맞는 새 이미지를 생성한다.

- mlx_xpm_file_to_image: 포멧에 맞는 새 이미지를 생성한다.

- mlx_png_file_to_image: 포멧에 맞는 새 이미지를 생성한다.

- mlx_destroy_image: 주어진 이미지(img ptr)를 삭제한다.

mlx_new_image

void *mlx_new_image(void *mlx_ptr, int width, int height);
매개 변수

width: 생성될 이미지의 길이
height: 생성될 이미지의 높이
반환값

성공: void *img_ptr 이미지 식별자 반환
실패: NULL
mlx_put_image_to_window

int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
매개 변수

img_ptr: 사용할 이미지
x, y: 이미지가 위치할 창 내의 x, y좌표
mlx_get_data_addr

char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);
매개 변수

bits_per_pixel: 비트로 표현된 픽셀 색깔(이미지의 깊이)
size_line: 이미지의 한 줄을 메모리에 저장하는 데 사용되는 바이트 수이다. 이 정보는 이미지에서 한 줄에서 다른 줄로 이동하는 데 필요하다.
endian: 픽셀 색깔을 저장하는 변수가 리틀엔디안(endian == 0)인지 혹은 빅엔디안(endian == 1) 방식인지 나타낸다. (MacOS에서는 필요없다. 클라이언트와 그래픽 프레임워크가 동일한 엔디언을 갖는다.)
리틀엔디안: 앞 주소에 작은 바이트부터 기록한다. 인텔 계열
빅엔디안: 앞 주소에 큰 바이트부터 기록한다. 사람과 비슷하다.
반환값

char *ptr: 이미지가 저장된 메모리 영역의 시작을 나타내는 주소를 반환한다.
이 주소로부터 첫 번째 bits_per_pixel 비트가 이미지의 제일 첫 줄의 첫 번째 픽셀의 색상을 나타낸다.
두 번째 그룹의 bits_per_pixel 비트는 첫 째줄의 두 번째 픽셀을 나타내고.... 이런 식으로 진행된다.
주소에 size_line을 추가해서 두 번째 줄 시작점을 얻는다.
이런 방식으로 이미지의 모든 픽셀에 도달할 수 있다.
mlx_get_color_value

unsigned int mlx_get_color_value(void *mlx_ptr, int color);
디스플레이에 따라 픽셀 색상을 저장하는 데 사용되는 비트 수가 변경될 수 있다.

사용자는 일반적으로 각 구성 요소에 1바이트를 사용하여 RGB 모드에서 색상을 나타낸다.

이것은 이미지의 bits_per_pixel 요구사항에 맞게 변환되어야 하며, 디스플레이에서 색상을 이해할 수 있도록 해야 한다.

이것이 이 함수의 역할이다.

표준 RGB 색상 매개 변수를 사용하고 unsigned int 값을 리턴한다.

이 값의 bits_per_pixel 최하위 비트는 이미지에 저장될 수 있다.

변환이 필요하지 않은 경우 - 24비트깊이 혹은 32비트깊이의 경우 이 함수를 사용하지 않아도 된다.

최하위 비트 위치는 로컬 컴퓨터의 엔디안에 따라 다르다.

이미지의 엔디안이 로컬 엔디안과 다른 경우(=X11 네트워크 환경일 때), 값을 사용하기 전에 변환해야 한다.

반환값

int color를 unsinged int color로 변환해 반환한다.
mlx_xpm_to_image

mlx_xpm_file_to_image

mlx_png_file_to_image

void *mlx_xpm_to_image(void *mlx_ptr, char **xpm_data, int *width, int *height);

void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);

void *mlx_png_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
이 세 함수는 같은 방식으로 새 이미지를 생성한다.

어느 함수를 사용하는 지에 따라 각각 xpm_data, filename이 지정된다.

MiniLibX는 xpm과 png를 다룰 때, 표준 xpm과 png 라이브러리를 사용하지 않는다.

모든 타입의 xpm과 png 이미지를 읽지는 못할 수도 있다. 어쨌거나 투명도는 제어된다.

반환값

성공: img_ptr 이미지 식별자를 반환한다.
실패: NULL반환
mlx_destroy_image

int *mlx_destroy_image(void *mlx_ptr, void *img_ptr);



이벤트 관리 함수

그래픽 시스템은 양방향이다. 한 쪽은 화면에 명령을 전송하여 픽셀, 이미지 등을 표시한다. 반면, 다른 쪽은 화면에 연결된 키보드와 마우스로부터 "이벤트" 를 받는다.

함수들

- mlx_loop: 이벤트를 받는 함수

- mlx_key_hook

- mlx_mouse_hook

- mlx_expose_hook

- mlx_loop_hook: 이벤트가 발생하지 않을 때 지정된 함수가 호출된다

mlx_loop

int mlx_loop(void *mlx_ptr);
반환값이 없다. 이벤트를 기다린 다음 이 이벤트와 연결된 사용자 정의 함수를 호출하는 무한 루프

다음 세 가지 이벤트에 다른 함수를 할당 할 수 있다.

- 키 입력

- 마우스버튼 입력

- 창의 일부분을 다시 그리는 expose - (유닉스/리눅스 X11 환경에서 처리하는 것은 프로그램의 일이다. 그러나 MacOS에서는 절대 발생하지 않는 이벤트이다)

mlx_key_hook

16. mlx_mouse_hook

16. mlx_expose_hook

int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);

int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
이 세 가지 변수는 모두 같은 방식으로 작동한다.

매개 변수

funct_ptr: 이벤트 발생 시 내가 호출하고 싶은 함수를 가리키는 함수 포인터이다. 이 할당은 win_ptr에 의해 특정된 윈도우에만 적용된다.
param: 호출될 때마다 함수에 전달되며, 필요한 매개 변수를 저장하는 데 사용된다.
mlx_loop_hook

int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);
아무 이벤트도 일어나지 않을 경우 매개 변수로 받았던 함수가 호출된다.

이벤트를 포착했을 경우, MiniLibX는 아래와 같이 해당 함수를 고정 파라미터로 호출한다.

expose_hook(void *param);
key_hook(int keycode, void *param);
mouse_hook(int button, int x, int y, void *param);
loop_hook(void *param);
함수의 이름은 임의로 쓴 것이다. 함수들은 이벤트에 따라 매개 변수를 구분하는 데 사용된다. 이러한 기능은 MiniLibX의 일부가 아니다.

param: "mlx_XXX_hook" 호출에 지정된 주소이다. 이 주소는 MiniLibX에 의해 사용되거나 수정되지 않는다.
kecode: 어떤 키를 눌렀는지 알려준다.
x, y: 창에서 마우스를 클릭하는 좌표이다. (X11의 경우 include 파일 "keysymdef.h" 를 확인한다. MacOS의 경우 그냥 해보자)
button: 어떤 마우스 버튼을 눌렀는지 알려준다.
그 외의 이벤트 관리 함수

int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

int mlx_mouse_hide();
int mlx_mouse_show();
int mlx_mouse_move(void *win_ptr, int x, int y);
int mlx_mouse_get_pos(void *win_ptr, int *x, int *y);

int mlx_do_key_autorepeatoff(void *mlx_ptr);
int mlx_do_key_autorepeaton(void *mlx_ptr);
int mlx_do_sync(void *mlx_ptr);












 
