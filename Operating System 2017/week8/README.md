# 과제

동시에 실행하고 싶은 명령어

> ps -A + ls + top

#### cmd.cmd

```
ps -A
who
ls -l
top
```

`fork()`를 사용하여 여러 명령을 실행하기

```bash
echo ls -l + ps -A | ./pipe_cmd
```

위의 명령 실행시.. parent process가 각 명령별로 fork()실행하여 명령 인자 처;리
