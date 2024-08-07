# [get_next_line](https://github.com/seungwonme/get_next_line)

## char *get_next_line(int fd);

```c
	char	*get_next_line(int fd)
```

## file descriptor

- 파일 디스크립터(file descriptor)란, 운영체제에서 파일이나 소켓 같은 입출력 장치에 접근하기 위해 사용하는 식별자(identifier)
- 각 파일이나 소켓에 대해 유일한 파일 디스크립터가 할당되며, 이를 통해 프로그램은 해당 파일이나 소켓에 접근하여 입출력 작업을 수행
- 파일 디스크립터는 일반적으로 정수로 표현되며, 0부터 시작하여 할당된 파일이나 소켓마다 1씩 증가
- 가장 많이 사용되는 파일 디스크립터는 0, 1, 2로 각각 표준 입력(stdin), 표준 출력(stdout), 표준 에러(stderr)
- 파일 디스크립터는 주로 시스템 콜(system call)을 사용하여 생성
	- 예를 들어, open() 함수를 호출하여 파일을 열면 해당 파일에 대한 파일 디스크립터가 반환
	- 파일 디스크립터는 read(), write(), close() 등의 입출력 함수를 사용하여 파일에 대한 입출력 작업을 수행할 때 사용

## static 변수 (정적 변수)

- 메모리의 데이터 영역에 저장되어 프로그램이 종료될 때까지 남아있는 변수
- 함수의 시작 시 할당되며, 프로그램이 종료될 때 해제된다.
- 함수를 벗어나도 해당 변수는 사라지지 않고 계속 유지된다. 하지만 함수 내부에서 선언되었다면 다른 함수에서는 이 값을 참조할 수 없다.
- 함수 내에서 static int num = 0 이런 방식으로 초기화하면 프로그램이 시작될 때 변수를 초기화하며, 함수가 다시 호출될 때 변수를 초기화하지 않는다.
- 정적 변수는 초기값을 지정하지 않는다면 0으로 초기화된다.

## reference

- [Dangling Pointer](https://thinkpro.tistory.com/67)

```zsh
ulimit -a
```

```c
#include <limits.h>

OPEN_MAX -> 	10240
FD_SETSIEZE -> 1024
```
