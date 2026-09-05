# push_swap

**두 스택과 제한된 연산으로 정수를 오름차순으로 정렬하는 스택 연산 명령을 생성하는 C 프로그램입니다.** 42 Seoul 프로젝트로, 작은 입력 전용 분기와 두 기준값(pivot)을 사용하는 재귀 분할 정렬을 구현하고, 출력 전 명령을 결합·상쇄합니다.

## 핵심 구현

| 구현 | 방식 | 코드 |
|---|---|---|
| 스택 관리 | 이중 연결 리스트와 top·bottom 포인터로 swap·push·rotate 처리 | [push_swap.h](push_swap.h), [func_rotate.c](func_rotate.c) |
| 입력 검사 | 정수 형식·32비트 범위·중복 값 확인 | [argument_valid.c](argument_valid.c) |
| 크기별 정렬 | 5개 이하 전용 분기, 6개 이상 재귀 분할 | [sort_ascending.c](sort_ascending.c) |
| 두 pivot 분할 | 구간 값을 배열로 정렬해 두 기준값을 선택하고 A↔B 이동 | [pivot 선택](sort_more_five_tools.c), [A→B](sort_more_five_a_to_b.c), [B→A](sort_more_five_b_to_a.c) |
| 명령 후처리 | 별도 리스트에 저장한 명령을 결합하거나 상쇄한 뒤 출력 | [command_tools.c](command_tools.c), [delete_commands.c](delete_commands.c) |

## 저장소 구조

```text
.
├── main.c / push_swap.h       # 실행 흐름과 스택·명령 자료형
├── parsing*.c                # 인자 읽기
├── argument_valid.c          # 정수·중복 검사
├── func_*.c                  # 스택 연산
├── sort_not_more_five*.c      # 5개 이하 정렬
├── sort_more_five*.c          # 두 pivot 재귀 분할
├── command_tools.c           # 연산 실행·명령 저장
├── delete_commands.c         # 명령 후처리
├── print_commands.c          # 명령 문자열 출력
├── checker_Mac / checker_linux
└── Makefile
```

## 정렬과 명령 후처리

입력 정수는 스택 A에 넣고, 스택 B를 보조 공간으로 사용합니다.

| 연산 | 동작 |
|---|---|
| `sa` · `sb` | 해당 스택의 위쪽 두 원소 교환 |
| `pa` · `pb` | 다른 스택의 맨 위 원소를 각각 A·B로 이동 |
| `ra` · `rb` | 맨 위 원소를 맨 아래로 이동 |
| `rra` · `rrb` | 맨 아래 원소를 맨 위로 이동 |

5개 이하에서는 원소 위치와 최솟값·최댓값을 이용해 정렬합니다. 더 큰 입력은 현재 구간을 복사한 배열에서 두 pivot을 선택하고, push·rotate로 세 구간을 나눈 뒤 재귀적으로 처리합니다.

회전한 구간을 되돌릴 때 두 스택에 공통으로 필요한 횟수는 `rrr`로 처리합니다. 정렬 중 생성한 명령은 즉시 출력하지 않고 저장하여 다음 규칙을 적용합니다.

| 명령 조합 | 후처리 |
|---|---|
| `sa` + `sb` | `ss`로 결합 |
| `ra` + `rb` | `rr`로 결합 |
| `rra` + `rrb` | `rrr`로 결합 |
| 같은 스택의 rotate + reverse rotate | 서로 상쇄 |
| `pa` + `pb`, 같은 swap 두 번 | 서로 상쇄 |

삭제 대상으로 표시한 명령은 [print_commands.c](print_commands.c)에서 출력하지 않습니다.

## 빌드와 실행

GCC와 Make가 필요합니다.

```bash
make
./push_swap 3 2 1
```

```text
sa
rra
```

위 명령을 입력 스택에 적용하면 `1 2 3`으로 정렬됩니다. 입력값은 **각각 별도 인자**로 전달합니다.

```bash
./push_swap 4 -2 7 0 1
```

이미 정렬된 입력은 명령을 출력하지 않습니다. 중복·범위를 벗어난 정수·잘못된 문자 입력은 `Error` 출력과 종료 코드 `1`로 처리합니다.

## 결과 확인

저장소에는 Linux와 macOS용 checker 실행 파일이 포함되어 있습니다. Linux에서는 다음과 같이 같은 입력과 생성한 명령을 전달합니다.

```bash
chmod +x checker_linux
./push_swap 3 2 1 | ./checker_linux 3 2 1
```

checker의 `OK`는 명령 적용 후 A가 오름차순이고 B가 비어 있는 상태를 뜻합니다. 운영체제에 맞는 실행 파일을 사용합니다.

## 구현 기록

[분할 알고리즘 참고 기록](https://github.com/tjung03/push_swap/commit/e49ef92f3a54e5baa58b95d381599a9a1273991c)과 [명령 후처리 추가 커밋](https://github.com/tjung03/push_swap/commit/8d869394e8db1489481dd2bd33abc0e61c453837)에서 구현 과정을 확인할 수 있습니다.

`make clean`은 오브젝트, `make fclean`은 실행 파일까지 삭제하며, `make re`는 전체를 다시 빌드합니다.
