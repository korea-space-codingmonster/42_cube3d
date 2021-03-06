# Project Title : 42seoul_cube3d

## 1. 소개  
이번 과제는 cube3d라는 과제이다. cube3d 서브젝트를 소개하면 원시적인 3D 그래픽게임을 구현하는 과제이다.
이 게임을 구현하기 위해  "레이캐스팅"이라는 기술을 살펴볼 것이며, 원리에 대해서 상세히 알아보고 적용해볼 것이다.

그리고 이 게임을 두현하기 위해서 42SEOUL에서는 몇가지 라이브러리를 제공하고있는데 그 라이브러리 사용법에 대해서도 알아보자.

## 2. 공부할 것들....

0. [Cube 3D 소개](https://codingmonsters.tistory.com/23)
1. [mlx 사용법](https://codingmonsters.tistory.com/manage/newpost/?type=post&returnURL=%2Fmanage%2Fposts%2F)


cub3d 초기화와 관련된 코드들을 작성했다.
mlx 초기화는 taelee님의 mlx_example을 참고했고
키 입력, 화면 초기화 부분은 minckim님의 강의자료 pdf와 깃헙 코드를 보고 작성했다.
(좋은 예제와 가이드를 제공해주셔서 감사합니다. 필사가 되지 않게 최대한 노력했어요^^.. )

구현한 부분 :
화면 초기화하기 (mlx, window 초기화, 픽셀 초기화)
키 입력받기
천장과 바닥 그리기
References :
- cub3d 가이드 by minckim
- cub3d Glagan 깃헙 레포
- mlx_example by taelee
cub3d 구현하기
화면 초기화
mlx 초기화하기
typedef struct          s_window
{
        void                    *mlx;
        void                    *win;
        t_img                   img;
        int                     width;
        int                     height;
}                       t_window; 

typedef struct          s_img
{
        void                    *ptr;
        unsigned int    *addr;
        int                             width;
        int                             height;
        int                             size_l;
        int                             bpp;
        int                             endian;
}                                       t_img;

void                            init_window(t_window *window)
{
        window->mlx = mlx_init();
        window->win = mlx_new_window(
                                        window->mlx, window->width, window->height, "cub3d");
        window->img.ptr = mlx_new_image(window->mlx, window->width, window->height);
        window->img.addr = (unsigned int *)mlx_get_data_addr(
                                        window->img.ptr, &(window->img.size_l),
                                        &(window->img.bpp), &(window->img.endian));
}
window 구조체와 img 구조체를 선언했다.
init_window() 함수를 만들어 mlx와 window, 이미지를 초기화한다.
img 구조체의 size_l, bpp, endian 변수는 mlx_get_data_addr() 메소드에 인자로 넘기면 메소드 안에서 초기화된다.
img 주소를 가져와서 구조체에 저장해둔다. (가져온 주소에 픽셀을 그려야함)
window의 타이틀은 "cub3d"로 지정했다.
픽셀 초기화하기
픽셀 구조체
typedef	struct		s_pixel
{
	double			distance;
	unsigned int	*color;
}					t_pixel;
픽셀 초기화 : init_pixel()
t_pixel				**init_pixel(int width, int height, t_img *img)
{
	t_pixel			**pixel;
	int				x;
	int				y;

	pixel = malloc(sizeof(t_pixel *) * width);
	x = 0;
	while (x < width)
	{
		pixel[x] = malloc(sizeof(t_pixel) * height);
		y = 0;
		while (y < height)
		{
			pixel[x][y].distance = INFINITY;
			pixel[x][y].color = (unsigned int *)((char *)img->addr \
							+ img->size_l * y + img->bpp / 8 * x);
			y++;
		}
		x++;
	}
}
이제 초기화된 윈도우 상의 이미지에 픽셀을 올려야 하므로, 픽셀을 초기화해준다.

픽셀 구조체 하나는 픽셀 한 개를 나타낸다.

픽셀 구조체들을 담는 2차원 배열을 만든다. 배열의 열과 행의 크기는 각각
이미지의 width, height만큼이다.

픽셀은 malloc으로 할당해줬기 때문에 사용이 끝나면 free시켜줘야한다.

Reference :
- 42docs - MiniLibX
- 42docs - MiniLibX 번역본 by kchoi


천장과 바닥 그리기
void		draw_sky_floor(t_window *win, int color_floor, int color_ceiling)
{
	int		x;
	int		y;
	t_pixel	**pixel;
	
	pixel = win->pixel;
	y = 0;
	while (y < win->height / 2)
	{
		x = 0;
		while (x < win->width)
		{
			*(pixel[x][y].color) = color_ceiling;
			x++;
		}
		y++;
	}
	while (y < win->height)
	{
		x = 0;
		while (x < win->width)
		{
			*(pixel[x][y].color) = color_floor;
			x++;
		}
		y++;
	}
}
height 기준 2분의 1씩 색을 칠해줬다.

키 입력받기
key 구조체 만들기
    typedef struct	s_key
    {
        char		w;
        char		a;
        char		s;
        char		d;
        char		left;
        char		right;
    }			t_key;
subject에서 요구하는 w, a, s, d 키와 왼쪽 화살표 키, 오른쪽 화살표 키를 저장할 구조체를 만들었다.

ESC 키 입력이 들어온 경우 바로 게임을 종료하면 되기 때문에 저장할 필요가 없다고 생각해서 ESC 키는 구조체에 포함시키지 않았다.

key_press(), key_release() 함수로 키 입력 저장하기

    void			key_press(int keycode, t_key *key)
    {
        if (keycode == KEY_W)
            key->w = 1;
        if (keycode == KEY_A)
            key->a = 1;
        if (keycode == KEY_S)
            key->s = 1;
        if (keycode == KEY_D)
            key->d = 1;
        if (keycode == KEY_LEFT)
            key->left = 1;
        if (keycode == KEY_RIGHT)
            key->right = 1;
        if (keycode == KEY_ESC)
            exit_game();
    }

    void			key_release(int keycode, t_key *key)
    {
        if (keycode == KEY_W)
            key->w = 0;
        if (keycode == KEY_A)
            key->a = 0;
        if (keycode == KEY_S)
            key->s = 0;
        if (keycode == KEY_D)
            key->d = 0;
        if (keycode == KEY_LEFT)
            key->left = 0;
        if (keycode == KEY_RIGHT)
            key->right = 0;
    }
key_press(), key_release() 함수로 입력된 키코드를 키 구조체에 저장한다.

키가 눌렸을 때 1, 키가 풀렸을 때 0이 저장되어 키 입력에 따라 적절한 처리를 할 수 있도록 했다.

키코드들은 가독성 향상을 위해 헤더 파일에 따로 정의해뒀다.

    # define KEY_LEFT	123
    # define KEY_RIGHT	124
    # define KEY_W		13
    # define KEY_A		0
    # define KEY_S		1
    # define KEY_D		2
    # define KEY_ESC	53









 
