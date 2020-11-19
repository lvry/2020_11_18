#include<stdio.h>
#include<windows.h>
#include<math.h>

int DrinkSoda(int money)
{
	int total = money;
	int empty = money;
	while (empty > 1){
		total += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	return total;
}

int IsDaffodil(int x)
{
	//一、求位数
	int num = 0;
	int temp = x;
	while (temp){
		temp /= 10;
		num++;
	}
	//二、拆分，求num次方，累加
	int res = 0;
	temp = x;
	while (temp){
		int data = temp % 10;
		res += (int)pow(data, num);
		temp /= 10;
	}
	return x == res;
}

int SnTotal(int base, int num)
{
	int total = 0;
	for (int i = 0; i < num; i++){
		int count = base;
		for (int j = 0; j < i; j++){
			count = count * 10 + base;
		}
		total += count;
	}
	return total;
}

void SwitchOdd2Even(int arr[], int num)
{
	int lift = 0;
	int right = num - 1;
	while (lift<right){
		while (lift < right && (arr[lift] & 1)){
			lift++;
		}
		while (lift < right && !(arr[right] & 1)){
			right--;
		}
		if (lift < right){
			arr[lift] ^= arr[right];
			arr[right] ^= arr[lift];
			arr[lift] ^= arr[right];
		}
	}
}
void Show(int arr[],int num)
{
	for (int i = 0; i < num;i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

char *StrCpy(char *dst, const char *src)
{
	char *ret = *dst;
	while (*dst=*src){
		dst++;
		src++;
	}
	return ret;
}

int main()
{
	//喝汽水问题(20元喝多少瓶)
	int money = 20;
	int total = DrinkSoda(money);
	printf("total=%d\n",total);

	//打印水仙花数
	//for (int i = 0; i <= 100000; i++){
	//	if (IsDaffodil(i)){
	//		printf("%d ", i);
	//	}
	//}
	//printf("\n");

	//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和
	//int sn = SnTotal(2, 5);
	//printf("%d\n", sn);

	//调整数组使奇数全部都位于偶数前面
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//Show(arr, num);
	//SwitchOdd2Even(arr, num);
	//Show(arr, num);


	//实现字符串拷贝
	//const char *src = "lvry2347";
	//char dst[16] = {'\0'};
	//StrCpy(dst, src);
	//printf("%s\n", dst);
	system("pause");
	return 0;
}