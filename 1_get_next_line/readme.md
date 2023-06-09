# get_next_line

## char *get_next_line(int fd);

```c
	char	*get_next_line(int fd)
```

1. 매개변수로 들어온 fd에 해당하는 리스트를 탐색한다.
	1. 없다면 마지막 노드에 fd가 매개변수, next가 0인 리스트를 새로 만들어준다.
2. fd의 값이 매개변수 fd와 일치하는 리스트의 백업에 개행문자가 있는 지 확인한다.
	1. 있다면 개행문자 후의 문자열을 백업에 저장하고 개행문자 전의 문자열을 반환한다. (없다면 3으로 간다.)
3. 백업의 문자열과 read로 받은 버퍼의 문자열을 합치고 2로 돌아간다. (만약 read의 반환값이 음수이거나 BUFFER_SIZE보다 작다면 반환한다.)

read의 반환값이 음수라면 실패, BUFFER_SIZE보다 작은 음이 아닌 정수의 경우 파일을 다 읽은 것!
## file descriptor

- 파일 디스크립터(file descriptor)란, 운영체제에서 파일이나 소켓 같은 입출력 장치에 접근하기 위해 사용하는 식별자(identifier)입니다.
- 각 파일이나 소켓에 대해 유일한 파일 디스크립터가 할당되며, 이를 통해 프로그램은 해당 파일이나 소켓에 접근하여 입출력 작업을 수행할 수 있습니다.
- 파일 디스크립터는 일반적으로 정수로 표현되며, 0부터 시작하여 할당된 파일이나 소켓마다 1씩 증가합니다.
- 가장 많이 사용되는 파일 디스크립터는 0, 1, 2로 각각 표준 입력(stdin), 표준 출력(stdout), 표준 에러(stderr)를 나타냅니다.
- 파일 디스크립터는 주로 시스템 콜(system call)을 사용하여 생성됩니다.
- 예를 들어, open() 함수를 호출하여 파일을 열면 해당 파일에 대한 파일 디스크립터가 반환됩니다.
- 파일 디스크립터는 read(), write(), close() 등의 입출력 함수를 사용하여 파일에 대한 입출력 작업을 수행할 때 사용됩니다.

### int	open(const char *path, int oflag, ...);

- open() 함수는 파일을 읽기 및 쓰기 용도로 열고, 호출한 프로세스에 파일 디스크립터를 반환합니다. oflag 인자는 파일이 존재하지 않는 경우 생성할 것인지 여부를 나타낼 수 있습니다(O_CREAT 플래그 사용을 통해)
- oflag 인자로 지정된 플래그는 반드시 다음 파일 액세스 모드 중 하나를 정확히 포함해야 합니다:

	- O_RDONLY: 읽기 전용으로 열기
	- O_WRONLY: 쓰기 전용으로 열기
	- O_RDWR: 읽기 및 쓰기 용도로 열기

### ssize_t	read(int fildes, void *buf, size_t nbyte)

- read() 함수는 파일 디스크립터 fd로 지정된 파일에서 nbyte 만큼의 데이터를 buf로 읽어옵니다.
- read() 함수는 읽은 데이터가 buf에 저장됩니다. buf는 최소한 nbyte 바이트 크기여야 하며, 읽은 데이터의 크기보다 작을 수도 있습니다. 이 경우, 반환 값은 실제로 읽은 바이트 수가 됩니다.
- read() 함수는 읽기 시도가 끝날 때까지(데이터가 읽힐 때까지) 블로킹됩니다.
- 만약 파일 디스크립터가 블록 모드(blocking mode)로 열렸다면, 파일의 끝에 도달할 때까지 블로킹됩니다.
- 또한, read() 함수가 호출되면 파일의 끝까지 읽을 때까지 블로킹됩니다. 따라서 블로킹하지 않도록 주의해야 합니다. 만약 파일 디스크립터가 넌블록 모드로 열려 있고 데이터가 없으면 바로 -1을 반환합니다.
- 블로킹(blocking)은 I/O 작업이 완료될 때까지 프로세스가 대기하는 것을 의미합니다. 즉, I/O 작업이 완료되지 않으면 다른 작업을 수행하지 못하고 대기하게 됩니다. 반면, 논블로킹(non-blocking)은 I/O 작업을 수행하는 동안 다른 작업을 수행할 수 있습니다.
- buf는 버퍼(buffer)의 약어로, 데이터를 일시적으로 저장하는 메모리 영역을 말합니다. read 함수는 파일 디스크립터(fd)가 가리키는 파일로부터 데이터를 읽어와 buf에 저장합니다. buf에 저장된 데이터는 프로세스가 이를 처리하거나 출력하는 데 사용될 수 있습니다. buf는 일반적으로 char 배열로 선언되며, 읽어들일 데이터의 크기에 따라 크기를 동적으로 할당하거나 미리 고정 크기로 할당할 수 있습니다.

## static 변수 (정적 변수)

- 메모리의 데이터 영역에 저장되어 프로그램이 종료될 때까지 남아있는 변수다.
- 함수의 시작 시 할당되며, 프로그램이 종료될 때 해제된다.
- 함수를 벗어나도 해당 변수는 사라지지 않고 계속 유지된다. 하지만 함수 내부에서 선언되었다면 다른 함수에서는 이 값을 참조할 수 없다.
- 함수 내에서 static int num = 0 이런 방식으로 초기화하면 프로그램이 시작될 때 변수를 초기화하며, 함수가 다시 호출될 때 변수를 초기화하지 않는다.
- 정적 변수는 초기값을 지정하지 않는다면 0으로 초기화된다.

### 참고자료
* [gnl 준비: 기본 개념](https://velog.io/@pig005/gnl-%EC%A4%80%EB%B9%84-%EA%B8%B0%EB%B3%B8-%EA%B0%9C%EB%85%90)

```zsh
ulimit -a
```

```c
#include <limits.h>

OPEN_MAX -> 	10240
FD_SETSIEZE -> 1024

```
