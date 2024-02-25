#include "Caculate.h"
using namespace std;
#define MAX_SIZE 100

int main() {
    Caculate *caculate = new Caculate();
    caculate->init();
	cout << "Please input:\n";
	char str[MAX_SIZE];//在这里编辑需要计算的算式
	fgets(str, MAX_SIZE, stdin);
	int len = strlen(str);
	char str_last = 'z';//用于判断结束

	for (int i = 0; i < len; i++)
		caculate->judge(str[i]);
	caculate->judge(str_last);
	cout << "result:" << caculate->getResult() << endl;

    delete caculate;
    caculate = NULL;
    return 0;
}