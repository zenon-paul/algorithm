#include <stdio.h>
void disp(const int x){
	int rest = x;
	int size = sizeof(rest) * 8;//バイトサイズが返ってくる
	for(int i = size - 1;i >= 0;i--)
	{
		printf("%d ",(rest>>i) & 1 ? 1 : 0);//逆になること覚え
	}
}
int bit_swap(const int x){
	int rest0 = x;
	rest0 = ((0xaaaaaaaa & rest0) >> 1) | ((0x55555555 & rest0) << 1);
	rest0 = ((0xcccccccc & rest0) >> 2) | ((0x33333333 & rest0) << 2);
	rest0 = ((0xf0f0f0f0 & rest0) >> 4) | ((0x0f0f0f0f & rest0) << 4);
	rest0 = ((0xff00ff00 & rest0) >> 8) | ((0x00ff00ff & rest0) << 8);
	rest0 = ((0xffff0000 & rest0) >> 16) | ((0x0000ffff & rest0) << 16);
	return rest0;
}
int get_max_des(const int x){
	int  rest = x;
	rest = rest & 0xffff0000 ? rest & 0xffff0000 : rest;
	rest = rest & 0xff00ff00 ? rest & 0xff00ff00 : rest;
	rest = rest & 0xf0f0f0f0 ? rest & 0xf0f0f0f0 : rest;
	rest = rest & 0xcccccccc ? rest & 0xcccccccc : rest;
	rest = rest & 0xaaaaaaaa ? rest & 0xaaaaaaaa : rest;
	return rest;
}
int count_on_bit(const int x){
	int count = 0;
	int rest = (unsigned int)x;
	
	return count;
}
int main(){
	int result = bit_swap(1024);
	disp(result);
}
