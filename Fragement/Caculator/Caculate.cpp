#include "Caculate.h"
using namespace std;

Caculate::Caculate() {

}
void Caculate::init() {
	char init_operate = '#';	//注意这里不能少，要在符号栈先存入一个#号，防止程序出错时，指空
	operate_stack.push(init_operate);
	char init_number = 0;
	number_stack.push(init_number); //在数字栈中输入初始值0,以便判断第一位是否为负数
}
long double Caculate::level(char str) {
	if (str == '(') {
		return 6;
	}
	else if ((str == '*') || (str == '/')) {
		return 5;
	}
	else if ((str == '+') || (str == '-')) {
		return 4;
	}
	else if ((str >= '0') || (str <= '9')) {
		return 3;
	}
	else if (str == ')'){
		return 2;
	}
	else if (str == '#') {
		return 1;
	}
	else {
		return 0;
	}
}
void Caculate::numberCaculate(char operate) {
	long double stack_first, stack_second;
	switch (operate)
	{
	case '*':
		stack_first = number_stack.top();
		number_stack.pop();
		stack_second = number_stack.top();
		number_stack.pop();
		number_stack.push(stack_second * stack_first);
		break;
	case '/':
		stack_first = number_stack.top();
		number_stack.pop();
		stack_second = number_stack.top();
		number_stack.pop();
		number_stack.push(stack_second / stack_first);
		break;
	case '+':
		stack_first = number_stack.top();
		number_stack.pop();
		stack_second = number_stack.top();
		number_stack.pop();
		number_stack.push(stack_second + stack_first);
		break;
	case '-':
		stack_first = number_stack.top();
		number_stack.pop();
		stack_second = number_stack.top();
		number_stack.pop();
		number_stack.push(stack_second - stack_first);
		break;
	default:
		break;
	}
}
int Caculate::judge(char str) {
	long double num = 0;
	char stack_top;
	int flag = 0; //用于判断括号的清除

	judge_time++;

	if ((str == '-') || (str == '(')) {
		ne_flag++;
	}
	if ((ne_flag == 2) && (str == '(')) {
		ne_flag = 1;
	}
	if ((str >= '0') && (str <= '9'))	//此处为数字栈的入栈口一，为1位数入栈口
	{
		num = (long double)str - 48;
		if (ne_flag == 2) {
			num = num * (-1);			//进行负数的转换
		}
		else { 
			ne_flag = 0; 
		}
		number_stack.push(num);
	}
	else if (((level(str) == 4) || (level(str) == 5) || (level(str) == 6)) &&
		((level(str) > level(operate_stack.top())) || ((operate_stack.top() == '(') && (level(str) >= 4))))
	{															
		if ((str != '(') && (str != '-')) {
			ne_flag = 0;
		}
		if ((ne_flag != 2) || ((str == '-') && (judge_time == 1))) {
			operate_stack.push(str);	//仅首个字符为'-'号时可进入
		}
		if ((str == '-') && (judge_time == 1)) {
			ne_flag = 0;
		}
		return num;
	}
	else if (((level(str) >= 4) && ((level(str) <= level((operate_stack.top())))) || (str == ')')))
	{															//即当仍有输入时的出栈规则
		if ((str != '(') && (str != '-'))ne_flag = 0;
		while (((level(str) <= level(operate_stack.top())) && (operate_stack.top() != '#')) && (operate_stack.top() != '('))
		{
			stack_top = operate_stack.top();
			operate_stack.pop();
			numberCaculate(stack_top);
			if ((operate_stack.top() == '(') && (str == ')')){
				operate_stack.pop();
				flag = 1;
				break;
			}
		}
		if (str != ')') { 
			operate_stack.push(str);
		}
		else if ((str == ')') && (operate_stack.top() == '(') && (flag == 0)) { 
			operate_stack.pop(); 
		}
		return num;
	}
	while ((operate_stack.top() != '#') && (str == 'z'))				//结束
	{
		stack_top = operate_stack.top();
		operate_stack.pop();
		numberCaculate(stack_top);
	}

	return num;
}
int Caculate::getResult() {
	return number_stack.top();
}