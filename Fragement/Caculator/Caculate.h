#include <iostream>
#include "Stack.h"
class Caculate{
public :
	Caculate();
	void init();
	void numberCaculate(char op);
	int judge(char str);
	long double level(char str);
	int getResult();
private:
	Stack number_stack;
	Stack operate_stack;
	int nu_flag = 0;	//用于判断是否为多位数
	int	ne_flag = 1;	//用于判断负数
	int judge_time = 0;  //用于判断使用judge_time的次数

};