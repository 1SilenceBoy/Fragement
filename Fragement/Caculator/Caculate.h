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
	int	ne_flag = 1;	//�����жϸ���
	int judge_time = 0;  //�����ж�ʹ��judge_time�Ĵ���

};