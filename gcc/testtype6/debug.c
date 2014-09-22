/***
1.首先明白空指针异常编译时期是检查不错来的，所以才能开始下面的实验
2.既然空指针赋值为0为什么会出错哪，这是因为这是个指针，程序执行的时候，是取的真真指向的内容，而不是真真本身的内容，因为空指针指针没有指向内容，所以读取内容的时候，会不知所错。
下面如果更改为把p也即0的内容给y就不会出错啦
-----------------------------------
在gdb里输入print *p
(gdb) print *p
Cannot access memory at address 0x0
打印的这句话本身的意义其实就是一个断点，只是这个断点的直接后果就是程序停用，当然我们不希望自己的程序中被打上这样的断点:)

------------------------------
一直觉得java出错打印的异常堆栈很不错，对照错误很有用，本以为c不会有这种东西，:)c可是堆栈的始祖，当然有啦
(gdb) backtrace
#0  0x08048415 in a (p=0x0) at debug.c:12
#1  0x0804840a in main () at debug.c:9
这就是c追踪错误原因的命令 backtrace
***/
int a(int *p);
int main(){
	int *p=0;
	return a(p);
}
int a(int *p){
int y=*p;
//int y=p;
return y;
}



