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
	//һ����λ��
	int num = 0;
	int temp = x;
	while (temp){
		temp /= 10;
		num++;
	}
	//������֣���num�η����ۼ�
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
	//����ˮ����(20Ԫ�ȶ���ƿ)
	int money = 20;
	int total = DrinkSoda(money);
	printf("total=%d\n",total);

	//��ӡˮ�ɻ���
	//for (int i = 0; i <= 100000; i++){
	//	if (IsDaffodil(i)){
	//		printf("%d ", i);
	//	}
	//}
	//printf("\n");

	//��Sn=a+aa+aaa+aaaa+aaaaa��ǰ5��֮��
	//int sn = SnTotal(2, 5);
	//printf("%d\n", sn);

	//��������ʹ����ȫ����λ��ż��ǰ��
	//int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	//int num = sizeof(arr) / sizeof(arr[0]);
	//Show(arr, num);
	//SwitchOdd2Even(arr, num);
	//Show(arr, num);


	//ʵ���ַ�������
	//const char *src = "lvry2347";
	//char dst[16] = {'\0'};
	//StrCpy(dst, src);
	//printf("%s\n", dst);
	system("pause");
	return 0;
}